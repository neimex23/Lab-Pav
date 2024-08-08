#ifndef COLOR
#define COLOR

#include "CodeColor.h"
#include <ostream>
using namespace std; 
 
class Color{
    private:
        CodeColor code;
    public:
        Color();
        Color(CodeColor pCode);
        friend ostream& operator<<(ostream& os, const Color& mod);
        ~Color();
};

#endif
