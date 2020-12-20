/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <fonts/ApplicationFontProvider.hpp>
#include <touchgfx/InternalFlashFont.hpp>

#ifndef NO_USING_NAMESPACE_TOUCHGFX
    using namespace touchgfx;
#endif

extern touchgfx::InternalFlashFont &getFont_Asap_Regular_12_4bpp();
extern touchgfx::InternalFlashFont &getFont_Asap_Regular_11_4bpp();
extern touchgfx::InternalFlashFont &getFont_Asap_Regular_12_4bpp();
extern touchgfx::InternalFlashFont &getFont_Asap_Regular_18_4bpp();
extern touchgfx::InternalFlashFont &getFont_ipaexg_12_4bpp();
extern touchgfx::InternalFlashFont &getFont_ipaexg_18_4bpp();
extern touchgfx::InternalFlashFont &getFont_NotoSans_Regular_12_4bpp();
extern touchgfx::InternalFlashFont &getFont_NotoSans_Regular_18_4bpp();
extern touchgfx::InternalFlashFont &getFont_Asap_Bold_otf_12_4bpp();
extern touchgfx::InternalFlashFont &getFont_Asap_Bold_otf_18_4bpp();
extern touchgfx::InternalFlashFont &getFont_Asap_Regular_12_4bpp();
extern touchgfx::InternalFlashFont &getFont_Asap_Bold_otf_46_4bpp();
extern touchgfx::InternalFlashFont &getFont_Asap_Regular_15_4bpp();
extern touchgfx::InternalFlashFont &getFont_Asap_Bold_otf_15_4bpp();
extern touchgfx::InternalFlashFont &getFont_Asap_Bold_otf_18_4bpp();
extern touchgfx::InternalFlashFont &getFont_Asap_Regular_15_4bpp();
extern touchgfx::InternalFlashFont &getFont_Asap_Regular_15_4bpp();
extern touchgfx::InternalFlashFont &getFont_Asap_Regular_12_4bpp();
extern touchgfx::InternalFlashFont &getFont_Asap_Bold_otf_12_4bpp();

touchgfx::Font *ApplicationFontProvider::getFont( touchgfx::FontId fontId )
{
    switch( fontId )
    {

    case Typography::DEMOVIEW_MCULOAD_TEXT:
        return &( getFont_Asap_Regular_12_4bpp() );

    case Typography::DEMOVIEW_MCULOAD_TEXT_SMALL:
        return &( getFont_Asap_Regular_11_4bpp() );

    case Typography::POSTERTEXT:
        return &( getFont_Asap_Regular_12_4bpp() );

    case Typography::POSTERHEADLINE:
        return &( getFont_Asap_Regular_18_4bpp() );

    case Typography::POSTERTEXTJAPANESE:
        return &( getFont_ipaexg_12_4bpp() );

    case Typography::POSTERHEADLINEJAPANESE:
        return &( getFont_ipaexg_18_4bpp() );

    case Typography::POSTERTEXTUKR:
        return &( getFont_NotoSans_Regular_12_4bpp() );

    case Typography::POSTERHEADLINEUKR:
        return &( getFont_NotoSans_Regular_18_4bpp() );

    case Typography::THREEWAYPROGRESSBARPERCENTAGE:
        return &( getFont_Asap_Bold_otf_12_4bpp() );

    case Typography::THREEWAYPROGRESSBARBUTTON:
        return &( getFont_Asap_Bold_otf_18_4bpp() );

    case Typography::CUSTOMCONTROLSSTATUS:
        return &( getFont_Asap_Regular_12_4bpp() );

    case Typography::PERCENTAGEBARREADOUT:
        return &( getFont_Asap_Bold_otf_46_4bpp() );

    case Typography::PERCENTAGEBARHEADLINE:
        return &( getFont_Asap_Regular_15_4bpp() );

    case Typography::DATEPICKER:
        return &( getFont_Asap_Bold_otf_15_4bpp() );

    case Typography::EASINGEQUATION:
        return &( getFont_Asap_Bold_otf_18_4bpp() );

    case Typography::EASINGEQUATIONBUTTON:
        return &( getFont_Asap_Regular_15_4bpp() );

    case Typography::GRAPH_Y_VALUE:
        return &( getFont_Asap_Regular_15_4bpp() );

    case Typography::GRAPH_LEGEND:
        return &( getFont_Asap_Regular_12_4bpp() );

    case Typography::GRAPH_LEGEND_VALUE:
        return &( getFont_Asap_Bold_otf_12_4bpp() );

    default:
        return 0;
    }
}
