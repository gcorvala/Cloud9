#ifndef __COLOR_H__
#define __COLOR_H__

class Color {
  public:
    Color ();
    Color (double _r, double _g, double _b);
    virtual ~Color ();

    Color operator* (double s) const;
    Color operator* (const Color c) const;
    Color operator+= (const Color c);

    double getR () const;
    double getG () const;
    double getB () const;
    double getY () const;
    double getU () const;
    double getV () const;

    double r;
    double g;
    double b;
};

#endif