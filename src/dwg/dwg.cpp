#include <OdaCommon.h>
#include <XRefMan.h>
#include <Ge/GePlane.h>
#include <iostream>
#include <DbObjectId.h>
#include <DbLine.h>
#include <DbLayerTable.h>
#include <DbBlockTable.h>
#include <DbViewport.h>
#include <DbViewportTable.h>
#include <DbViewportTableRecord.h>

#include <ExServices/OdFileBuf.h>
#include <ExServices/ExSystemServices.h>
#include <ExServices/ExHostAppServices.h>
#include <ExServices/ExPageController.h>
#include <StaticRxObject.h>

class MyServices : public ExSystemServices, public ExHostAppServices
{
protected:
  ODRX_USING_HEAP_OPERATORS(ExSystemServices);
  OdGsDevicePtr gsBitmapDevice()
  {
    try
    {
      OdGsModulePtr pGsModule = ::odrxDynamicLinker()->loadModule(OdWinBitmapModuleName);
      return pGsModule->createBitmapDevice();
    }
    catch(const OdError&)
    {
      std::cout << "aie" << std::endl;
    }
    return OdGsDevicePtr();
  }
};

int
main (int argc, char** argv)
{
  OdString f ("test.dwg");
  OdWrFileBuf fb (f.c_str ());
  OdStaticRxObject<MyServices> svcs;

  odInitialize(&svcs);

  OdDbDatabasePtr pDb = svcs.createDatabase();

  //pDb->deleteLayout (L"Layout1");
  //pDb->deleteLayout (L"Layout2");

  // Add layout
  OdDbObjectId layout_id = pDb->createLayout ("Gab Layout");
  OdDbLayoutPtr pLayout = layout_id.safeOpenObject ();
  pDb->setCurrentLayout (layout_id);

  // Add layer
  OdDbLayerTablePtr pLayers = pDb->getLayerTableId ().safeOpenObject (OdDb::kForWrite);
  OdDbLayerTableRecordPtr pLayer = OdDbLayerTableRecord::createObject ();
  pLayer->setName ("Hello World");
  pLayer->setColorIndex (123);
  OdDbObjectId layer_id = pLayers->add (pLayer);

  OdDbLayerTableRecordPtr pLayer2 = OdDbLayerTableRecord::createObject ();
  pLayer2->setName ("Hello World 2");
  //pLayer2->setColorIndex (321);
  OdDbObjectId layer_id2 = pLayers->add (pLayer2);

  // Add block
  OdDbBlockTablePtr pBlocks = pDb->getBlockTableId ().safeOpenObject (OdDb::kForWrite);
  OdDbBlockTableRecordPtr pBlock = OdDbBlockTableRecord::createObject();
  pBlock->setName ("Block blabla");
  OdDbObjectId blokc_id = pBlocks->add (pBlock);

  // Add line
  OdGePoint3d start (0.0, 0.0, 0.0);
  OdGePoint3d end (100.0, 200.0, 0.0);
  OdDbLinePtr pLine = OdDbLine::createObject();
  OdDbObjectId id = pDb->getModelSpaceId ();
  pBlock = id.safeOpenObject (OdDb::kForWrite);
  pLine->setDatabaseDefaults (pBlock->database());
  pBlock->appendOdDbEntity (pLine);
  pLine->setStartPoint (start);
  pLine->setEndPoint (end);

  OdGePoint3d start2 (100.0, 200.0, 0.0);
  OdGePoint3d end2 (-100.0, 150.0, 0.0);
  OdDbLinePtr pLine2 = OdDbLine::createObject();
  pLine2->setDatabaseDefaults (pBlock->database());
  pBlock->appendOdDbEntity (pLine2);
  pLine2->setStartPoint (start2);
  pLine2->setEndPoint (end2);

  OdDbViewportPtr pOverallViewport = pLayout->overallVportId().safeOpenObject();
  OdGePoint3d overallCenter   = pOverallViewport->centerPoint();
  const double margin = 0.25;
  double overallWidth         = pOverallViewport->width()  / 1.058 - 2 * margin;
  double overallHeight        = pOverallViewport->height() / 1.058 - 2 * margin;
  OdGePoint3d overallLLCorner = overallCenter -                         
    OdGeVector3d( 0.5 * overallWidth, 0.5 * overallHeight, 0.0 );
  OdDbBlockTableRecordPtr pPS = pLayout->getBlockTableRecordId().safeOpenObject(OdDb::kForWrite);
  
  OdDbViewportPtr pViewport = OdDbViewport::createObject();
  pViewport->setDatabaseDefaults(pDb);
  pPS->appendOdDbEntity(pViewport);

  pViewport->setWidth         (overallWidth);
  pViewport->setHeight        (overallHeight);
  pViewport->setCenterPoint   (overallCenter);
  pViewport->setViewCenter    (pOverallViewport->viewCenter());
  pViewport->zoomExtents();

  pDb->writeFile(&fb, OdDb::kDwg, OdDb::vAC24, false);

  OdGePlane plane;
  OdGePoint3d uPoint(1.0, 1.0, 1.0), origin(0.0, 0.0, 0.0), vPoint(1.0, 1.0, -1.0);
  double a, b, c, d;
  OdGePoint3d point1, point2, point3;

  plane.set(uPoint, origin, vPoint);
  plane.get(point1, point2, point3);
  plane.getCoefficients(a, b, c, d);

  std::cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << std::endl;

  return 0;
}