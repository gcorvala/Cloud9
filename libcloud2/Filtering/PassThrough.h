#ifndef __PASS_THROUGH_H__
#define __PASS_THROUGH_H__

class PassThrough : public FilterIndices {
  public:
    PassThrough ();
    virtual ~PassThrough ();

    std::string getFieldName () const;
    void setFieldName (const std::string& field_name);

  protected:
    std::string m_field_name;
};

#endif