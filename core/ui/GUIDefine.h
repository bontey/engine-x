/****************************************************************************
 Copyright (c) 2014 cocos2d-x.org
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 https://axis-project.github.io/

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

#ifndef __TestCpp__GUIDefine__
#define __TestCpp__GUIDefine__

#include <string>
#include "base/ObjectFactory.h"

///@cond DO_NOT_SHOW
//
//// Widget macro
//

#define DECLARE_CLASS_GUI_INFO                   \
public:                                          \
    static cocos2d::ObjectFactory::TInfo __Type; \
    static cocos2d::Ref* createInstance();

#define IMPLEMENT_CLASS_GUI_INFO(className)                                   \
    cocos2d::Ref* className::createInstance() { return className::create(); } \
    cocos2d::ObjectFactory::TInfo className::__Type(#className, &className::createInstance);

#define CREATE_CLASS_GUI_INFO(className) cocos2d::ObjectFactory::TInfo(#className, &className::createInstance)

//
//// Reader macro
//

#define DECLARE_CLASS_WIDGET_READER_INFO         \
public:                                          \
    static cocos2d::ObjectFactory::TInfo __Type; \
    static cocos2d::Ref* createInstance();

#define IMPLEMENT_CLASS_WIDGET_READER_INFO(className)                              \
    cocos2d::Ref* className::createInstance() { return className::getInstance(); } \
    cocos2d::ObjectFactory::TInfo className::__Type(#className, &className::createInstance);

#define CREATE_CLASS_WIDGET_READER_INFO(className) cocos2d::ObjectFactory::TInfo(#className, &className::createInstance)

#define CC_VIDEOPLAYER_DEBUG_DRAW 0

#define __LAYOUT_COMPONENT_NAME "__ui_layout"
///@endcond

NS_CC_BEGIN
struct CC_DLL ResourceData
{
    int type;
    std::string file;
    std::string plist;

    ResourceData()
    {
        type  = 0;
        file  = "";
        plist = "";
    }
    ResourceData(const ResourceData& rv)
    {
        type  = rv.type;
        file  = rv.file;
        plist = rv.plist;
    }
    ResourceData(ResourceData&& rv)
    {
        type  = rv.type;
        file  = std::move(rv.file);
        plist = std::move(rv.plist);
    }

    ResourceData(int iType, std::string sFile, std::string sPlist)
    {
        type  = iType;
        file  = std::move(sFile);
        plist = std::move(sPlist);
    }
    ResourceData& operator=(const ResourceData& rv)
    {
        type  = rv.type;
        file  = rv.file;
        plist = rv.plist;
        return *this;
    }
    ResourceData& operator=(ResourceData&& rv)
    {
        type  = rv.type;
        file  = std::move(rv.file);
        plist = std::move(rv.plist);
        return *this;
    }
};
NS_CC_END

#endif /* defined(__TestCpp__GUIDefine__) */
