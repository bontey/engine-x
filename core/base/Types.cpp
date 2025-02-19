/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2016 Chukong Technologies Inc.
Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 https://axmolengine.github.io/

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "base/Types.h"
#include "renderer/backend/Types.h"

NS_AX_BEGIN

const std::string STD_STRING_EMPTY("");
const ssize_t AX_INVALID_INDEX = -1;

/**
 * Color3B
 */

Color3B::Color3B() {}

Color3B::Color3B(uint8_t _r, uint8_t _g, uint8_t _b) : r(_r), g(_g), b(_b) {}

Color3B::Color3B(const Color4B& color) : r(color.r), g(color.g), b(color.b) {}

Color3B::Color3B(const Color4F& color) : r(color.r * 255.0f), g(color.g * 255.0f), b(color.b * 255.0f) {}

bool Color3B::operator==(const Color3B& right) const
{
    return (r == right.r && g == right.g && b == right.b);
}

bool Color3B::operator==(const Color4B& right) const
{
    return (r == right.r && g == right.g && b == right.b && 255 == right.a);
}

bool Color3B::operator==(const Color4F& right) const
{
    return (right.a == 1.0f && Color4F(*this) == right);
}

bool Color3B::operator!=(const Color3B& right) const
{
    return !(*this == right);
}

bool Color3B::operator!=(const Color4B& right) const
{
    return !(*this == right);
}

bool Color3B::operator!=(const Color4F& right) const
{
    return !(*this == right);
}

/**
 * Color4B
 */

Color4B::Color4B() {}

Color4B::Color4B(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a) : r(_r), g(_g), b(_b), a(_a) {}

Color4B::Color4B(const Color3B& color, uint8_t _a) : r(color.r), g(color.g), b(color.b), a(_a) {}

Color4B::Color4B(const Color4F& color) : r(color.r * 255), g(color.g * 255), b(color.b * 255), a(color.a * 255) {}

bool Color4B::operator==(const Color4B& right) const
{
    return (r == right.r && g == right.g && b == right.b && a == right.a);
}

bool Color4B::operator==(const Color3B& right) const
{
    return (r == right.r && g == right.g && b == right.b && a == 255);
}

bool Color4B::operator==(const Color4F& right) const
{
    return (*this == Color4B(right));
}

bool Color4B::operator!=(const Color4B& right) const
{
    return !(*this == right);
}

bool Color4B::operator!=(const Color3B& right) const
{
    return !(*this == right);
}

bool Color4B::operator!=(const Color4F& right) const
{
    return !(*this == right);
}

/**
 * Color4F
 */

Color4F::Color4F() {}

Color4F::Color4F(float _r, float _g, float _b, float _a) : r(_r), g(_g), b(_b), a(_a) {}

Color4F::Color4F(const Color3B& color, float _a) : r(color.r / 255.0f), g(color.g / 255.0f), b(color.b / 255.0f), a(_a)
{}

Color4F::Color4F(const Color4B& color)
    : r(color.r / 255.0f), g(color.g / 255.0f), b(color.b / 255.0f), a(color.a / 255.0f)
{}

bool Color4F::operator==(const Color4F& right) const
{
    return (r == right.r && g == right.g && b == right.b && a == right.a);
}

bool Color4F::operator==(const Color3B& right) const
{
    return (a == 1.0f && Color3B(*this) == right);
}

bool Color4F::operator==(const Color4B& right) const
{
    return (*this == Color4F(right));
}

bool Color4F::operator!=(const Color4F& right) const
{
    return !(*this == right);
}

bool Color4F::operator!=(const Color3B& right) const
{
    return !(*this == right);
}

bool Color4F::operator!=(const Color4B& right) const
{
    return !(*this == right);
}

Color4F& operator+=(Color4F& lhs, const Color4F& rhs)
{
    lhs.r += rhs.r;
    lhs.g += rhs.g;
    lhs.b += rhs.b;
    lhs.a += rhs.a;
    return lhs;
}
Color4F operator+(Color4F lhs, const Color4F& rhs)
{
    return lhs += rhs;
}
Color4F& operator-=(Color4F& lhs, const Color4F& rhs)
{
    lhs.r -= rhs.r;
    lhs.g -= rhs.g;
    lhs.b -= rhs.b;
    lhs.a -= rhs.a;
    return lhs;
}
Color4F operator-(Color4F lhs, const Color4F& rhs)
{
    return lhs -= rhs;
}

Color4F& operator*=(Color4F& lhs, const Color4F& rhs)
{
    lhs.r *= rhs.r;
    lhs.g *= rhs.g;
    lhs.b *= rhs.b;
    lhs.a *= rhs.a;
    return lhs;
}
Color4F& operator*=(Color4F& lhs, float rhs)
{
    lhs.r *= rhs;
    lhs.g *= rhs;
    lhs.b *= rhs;
    lhs.a *= rhs;
    return lhs;
}
Color4F operator*(Color4F lhs, const Color4F& rhs)
{
    return lhs *= rhs;
}

Color4F operator*(Color4F lhs, float rhs)
{
    return lhs *= rhs;
}

Color4F& operator/=(Color4F& lhs, const Color4F& rhs)
{
    lhs.r /= rhs.r;
    lhs.g /= rhs.g;
    lhs.b /= rhs.b;
    lhs.a /= rhs.a;
    return lhs;
}
Color4F& operator/=(Color4F& lhs, float rhs)
{
    lhs.r /= rhs;
    lhs.g /= rhs;
    lhs.b /= rhs;
    lhs.a /= rhs;
    return lhs;
}
Color4F operator/(Color4F lhs, const Color4F& rhs)
{
    return lhs /= rhs;
}

Color4F operator/(Color4F lhs, float rhs)
{
    return lhs /= rhs;
}

/**
 * Color constants
 */


const Color3B Color3B::WHITE(255, 255, 255);
const Color3B Color3B::YELLOW(255, 255, 0);
const Color3B Color3B::GREEN(0, 255, 0);
const Color3B Color3B::BLUE(0, 0, 255);
const Color3B Color3B::RED(255, 0, 0);
const Color3B Color3B::MAGENTA(255, 0, 255);
const Color3B Color3B::BLACK(0, 0, 0);
const Color3B Color3B::ORANGE(255, 127, 0);
const Color3B Color3B::GRAY(166, 166, 166);

const Color4B Color4B::WHITE(255, 255, 255, 255);
const Color4B Color4B::YELLOW(255, 255, 0, 255);
const Color4B Color4B::GREEN(0, 255, 0, 255);
const Color4B Color4B::BLUE(0, 0, 255, 255);
const Color4B Color4B::RED(255, 0, 0, 255);
const Color4B Color4B::MAGENTA(255, 0, 255, 255);
const Color4B Color4B::BLACK(0, 0, 0, 255);
const Color4B Color4B::ORANGE(255, 127, 0, 255);
const Color4B Color4B::GRAY(166, 166, 166, 255);
const Color4B Color4B::AX_TRANSPARENT(0, 0, 0, 0);

const Color4F Color4F::WHITE(1, 1, 1, 1);
const Color4F Color4F::YELLOW(1, 1, 0, 1);
const Color4F Color4F::GREEN(0, 1, 0, 1);
const Color4F Color4F::BLUE(0, 0, 1, 1);
const Color4F Color4F::RED(1, 0, 0, 1);
const Color4F Color4F::MAGENTA(1, 0, 1, 1);
const Color4F Color4F::BLACK(0, 0, 0, 1);
const Color4F Color4F::ORANGE(1, 0.5f, 0, 1);
const Color4F Color4F::GRAY(0.65f, 0.65f, 0.65f, 1);
const Color4F Color4F::AX_TRANSPARENT(0, 0, 0, 0);

HSV::HSV() {}

HSV::HSV(float _h, float _s, float _v, float _a) : h(_h), s(_s), v(_v), a(_a) {}

HSV::HSV(const Color3B& c)
{
    fromRgba(Color4F(c));
};

HSV::HSV(const Color4B& c)
{
    fromRgba(Color4F(c));
}

HSV::HSV(const Color4F& c)
{
    fromRgba(c);
}

bool HSV::operator==(const HSV& right) const
{
    return (h == right.h && s == right.s && v == right.v && a == right.a);
}

bool HSV::operator!=(const HSV& right) const
{
    return !(h != right.h || s != right.s || v != right.v || a == right.a);
}

HSV& operator+=(HSV& lhs, const HSV& rhs)
{
    lhs.h += rhs.h;
    lhs.s += rhs.s;
    lhs.v += rhs.v;
    lhs.a += rhs.a;
    return lhs;
}
HSV operator+(HSV lhs, const HSV& rhs)
{
    return lhs += rhs;
}
HSV& operator-=(HSV& lhs, const HSV& rhs)
{
    lhs.h -= rhs.h;
    lhs.s -= rhs.s;
    lhs.v -= rhs.v;
    lhs.a -= rhs.a;
    return lhs;
}
HSV operator-(HSV lhs, const HSV& rhs)
{
    return lhs -= rhs;
}

HSV& operator*=(HSV& lhs, const HSV& rhs)
{
    lhs.h *= rhs.h;
    lhs.s *= rhs.s;
    lhs.v *= rhs.v;
    lhs.a *= rhs.a;
    return lhs;
}
HSV& operator*=(HSV& lhs, float rhs)
{
    lhs.h *= rhs;
    lhs.s *= rhs;
    lhs.v *= rhs;
    lhs.a *= rhs;
    return lhs;
}
HSV operator*(HSV lhs, const HSV& rhs)
{
    return lhs *= rhs;
}

HSV operator*(HSV lhs, float rhs)
{
    return lhs *= rhs;
}

HSV& operator/=(HSV& lhs, const HSV& rhs)
{
    lhs.h /= rhs.h;
    lhs.s /= rhs.s;
    lhs.v /= rhs.v;
    lhs.a /= rhs.a;
    return lhs;
}
HSV& operator/=(HSV& lhs, float rhs)
{
    lhs.h /= rhs;
    lhs.s /= rhs;
    lhs.v /= rhs;
    lhs.a /= rhs;
    return lhs;
}
HSV operator/(HSV lhs, const HSV& rhs)
{
    return lhs /= rhs;
}

HSV operator/(HSV lhs, float rhs)
{
    return lhs /= rhs;
}

void HSV::fromRgba(const Color4F& rgba)
{
    float fcmax  = MAX(MAX(rgba.r, rgba.g), rgba.b);
    float fcmin  = MIN(MIN(rgba.r, rgba.g), rgba.b);
    float fdel   = fcmax - fcmin;

    if (fdel > 0)
    {
        if (fcmax == rgba.r)
        {
            h = 60 * (fmod(((rgba.g - rgba.b) / fdel), 6));
        }
        else if (fcmax == rgba.g)
        {
            h = 60 * (((rgba.b - rgba.r) / fdel) + 2);
        }
        else if (fcmax == rgba.b)
        {
            h = 60 * (((rgba.r - rgba.g) / fdel) + 4);
        }

        if (fcmax > 0)
        {
            s = fdel / fcmax;
        }
        else
        {
            s = 0;
        }

        v = fcmax;
    }
    else
    {
        h = 0;
        s = 0;
        v = fcmax;
    }

    if (h < 0)
    {
        h = 360 + h;
    }

    this->a = rgba.a;
}

Color4F HSV::toRgba() const
{
    auto rgba = Color4F(0, 0, 0, a);

    float hue = remainder(std::fabs(h), 360);
    hue += 360;

    float fc      = v * s;
    float fhprime = fmod(hue / 60.0, 6);
    float fx      = fc * (1 - fabs(fmod(fhprime, 2) - 1));
    float fm      = v - fc;

    if (0 <= fhprime && fhprime < 1)
    {
        rgba.r = fc;
        rgba.g = fx;
        rgba.b = 0;
    }
    else if (1 <= fhprime && fhprime < 2)
    {
        rgba.r = fx;
        rgba.g = fc;
        rgba.b = 0;
    }
    else if (2 <= fhprime && fhprime < 3)
    {
        rgba.r = 0;
        rgba.g = fc;
        rgba.b = fx;
    }
    else if (3 <= fhprime && fhprime < 4)
    {
        rgba.r = 0;
        rgba.g = fx;
        rgba.b = fc;
    }
    else if (4 <= fhprime && fhprime < 5)
    {
        rgba.r = fx;
        rgba.g = 0;
        rgba.b = fc;
    }
    else if (5 <= fhprime && fhprime < 6)
    {
        rgba.r = fc;
        rgba.g = 0;
        rgba.b = fx;
    }
    else
    {
        rgba.r = 0;
        rgba.g = 0;
        rgba.b = 0;
    }

    rgba.r += fm;
    rgba.g += fm;
    rgba.b += fm;

    return rgba;
}

Color3B HSV::toColor3B() const 
{
    return Color3B(toRgba());
}

Color4B HSV::toColor4B() const
{
    return Color4B(toRgba());
}

Color4F HSV::toColor4F() const
{
    return toRgba();
}

HSL::HSL() {}
HSL::HSL(float _h, float _s, float _l, float _a) : h(_h), s(_s), l(_l), a(_a) {}

HSL::HSL(const Color3B& c)
{
    fromRgba(Color4F(c));
}

HSL::HSL(const Color4B& c)
{
    fromRgba(Color4F(c));
}

HSL::HSL(const Color4F& c)
{
    fromRgba(c);
}

bool HSL::operator==(const HSL& right) const
{
    return (h == right.h && s == right.s && l == right.l && a == right.a);
}

bool HSL::operator!=(const HSL& right) const
{
    return !(h != right.h || s != right.s || l != right.l || a == right.a);
}

HSL& operator+=(HSL& lhs, const HSL& rhs)
{
    lhs.h += rhs.h;
    lhs.s += rhs.s;
    lhs.l += rhs.l;
    lhs.a += rhs.a;
    return lhs;
}
HSL operator+(HSL lhs, const HSL& rhs)
{
    return lhs += rhs;
}
HSL& operator-=(HSL& lhs, const HSL& rhs)
{
    lhs.h -= rhs.h;
    lhs.s -= rhs.s;
    lhs.l -= rhs.l;
    lhs.a -= rhs.a;
    return lhs;
}
HSL operator-(HSL lhs, const HSL& rhs)
{
    return lhs -= rhs;
}

HSL& operator*=(HSL& lhs, const HSL& rhs)
{
    lhs.h *= rhs.h;
    lhs.s *= rhs.s;
    lhs.l *= rhs.l;
    lhs.a *= rhs.a;
    return lhs;
}
HSL& operator*=(HSL& lhs, float rhs)
{
    lhs.h *= rhs;
    lhs.s *= rhs;
    lhs.l *= rhs;
    lhs.a *= rhs;
    return lhs;
}
HSL operator*(HSL lhs, const HSL& rhs)
{
    return lhs *= rhs;
}

HSL operator*(HSL lhs, float rhs)
{
    return lhs *= rhs;
}

HSL& operator/=(HSL& lhs, const HSL& rhs)
{
    lhs.h /= rhs.h;
    lhs.s /= rhs.s;
    lhs.l /= rhs.l;
    lhs.a /= rhs.a;
    return lhs;
}
HSL& operator/=(HSL& lhs, float rhs)
{
    lhs.h /= rhs;
    lhs.s /= rhs;
    lhs.l /= rhs;
    lhs.a /= rhs;
    return lhs;
}
HSL operator/(HSL lhs, const HSL& rhs)
{
    return lhs /= rhs;
}

HSL operator/(HSL lhs, float rhs)
{
    return lhs /= rhs;
}

void HSL::fromRgba(const Color4F& rgba)
{
    float max = MAX(MAX(rgba.r, rgba.g), rgba.b);
    float min = MIN(MIN(rgba.r, rgba.g), rgba.b);

    h = s = l = (max + min) / 2;

    if (max == min)
    {
        h = s = 0;  // achromatic
    }
    else
    {
        float d  = max - min;
        s = (l > 0.5) ? d / (2 - max - min) : d / (max + min);

        if (max == rgba.r)
        {
            h = (rgba.g - rgba.b) / d + (rgba.g < rgba.b ? 6 : 0);
        }
        else if (max == rgba.g)
        {
            h = (rgba.b - rgba.r) / d + 2;
        }
        else if (max == rgba.b)
        {
            h = (rgba.r - rgba.g) / d + 4;
        }

        h /= 6;
    }
    
    this->a = rgba.a;
}

float HSL::hue2rgb(float p, float q, float t)
{
    if (t < 0)
        t += 1;
    if (t > 1)
        t -= 1;
    if (t < 1. / 6)
        return p + (q - p) * 6 * t;
    if (t < 1. / 2)
        return q;
    if (t < 2. / 3)
        return p + (q - p) * (2. / 3 - t) * 6;

    return p;
}

Color4F HSL::toRgba() const
{
    auto rgba = Color4F(0, 0, 0, a);

    float hue = remainder(std::fabs(h), 360);
    hue += 360;
    hue /= 360.0F;

    if (0 == s)
    {
        rgba.r = rgba.g = rgba.b = l;
    }
    else
    {
        float q  = l < 0.5 ? l * (1 + s) : l + s - l * s;
        float p  = 2 * l - q;
        rgba.r   = hue2rgb(p, q, hue + 1. / 3);
        rgba.g   = hue2rgb(p, q, hue);
        rgba.b   = hue2rgb(p, q, hue - 1. / 3);
    }

    return rgba;
}

Color3B HSL::toColor3B() const
{
    return Color3B(toRgba());
}

Color4B HSL::toColor4B() const
{
    return Color4B(toRgba());
}

Color4F HSL::toColor4F() const
{
    return Color4F(toRgba());
}

const BlendFunc BlendFunc::DISABLE             = {backend::BlendFactor::ONE, backend::BlendFactor::ZERO};
const BlendFunc BlendFunc::ALPHA_PREMULTIPLIED = {backend::BlendFactor::ONE, backend::BlendFactor::ONE_MINUS_SRC_ALPHA};
const BlendFunc BlendFunc::ALPHA_NON_PREMULTIPLIED = {backend::BlendFactor::SRC_ALPHA,
                                                      backend::BlendFactor::ONE_MINUS_SRC_ALPHA};
const BlendFunc BlendFunc::ADDITIVE                = {backend::BlendFactor::SRC_ALPHA, backend::BlendFactor::ONE};

NS_AX_END

