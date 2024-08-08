#include "Color.h"


Color::Color(){}

Color::Color(CodeColor pCode){
    this->code=pCode;
}

ostream& operator<<(ostream& os, const Color& mod){
    return os << "\033[" << mod.code << "m";
}

Color::~Color(){}

