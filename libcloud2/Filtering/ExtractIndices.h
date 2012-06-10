#ifndef __EXTRACT_INDICES_H__
#define __EXTRACT_INDICES_H__

#include "FilterIndices.h"

class ExtractIndices : public FilterIndices {
  public:
    ExtractIndices ();
    virtual ~ExtractIndices ();

    using FilterIndices::compute;
    void compute (Indices &indices) const;

    const Indices& getExtractIndices () const;
    void setExtractIndices (const Indices& indices);

  protected:
    Indices m_extract_indices;
    Boolean m_negative_extraction;
};

#endif