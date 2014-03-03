#pragma once

#include <iosfwd>
#include <cpdoccore/CPOptional.h>
#include <cpdoccore/xml/xmlelement.h>
#include <cpdoccore/xml/nodetype.h>

#include "office_elements.h"
#include "office_elements_create.h"

#include "common_attlists.h"


namespace cpdoccore { 
namespace odf {


///         style:header-footer-properties-attlist
class style_header_footer_properties_attlist
{
public:

    _CP_OPT(length) svg_height_;
    _CP_OPT(length) fo_min_height_;
    common_horizontal_margin_attlist common_horizontal_margin_attlist_;
    common_vertical_margin_attlist common_vertical_margin_attlist_;
    common_margin_attlist common_margin_attlist_;
    common_border_attlist common_border_attlist_;
    common_border_line_width_attlist common_border_line_width_attlist_;
    common_padding_attlist common_padding_attlist_;
    common_background_color_attlist common_background_color_attlist_;
    common_shadow_attlist common_shadow_attlist_;
    _CP_OPT(bool) style_dynamic_spacing_;
    
};

///         style:header-footer-properties
class style_header_footer_properties : public office_element_impl<style_header_footer_properties>
{
public:
    static const wchar_t * ns;
    static const wchar_t * name;
    static const xml::NodeType xml_type = xml::typeElement;
    static const ElementType type = typeStyleHeaderFooterProperties;
    CPDOCCORE_DEFINE_VISITABLE();

    virtual void add_child_element(const ::std::wstring & Ns, const ::std::wstring & Name);
	virtual void serialize(std::wostream & strm){}

    style_header_footer_properties_attlist style_header_footer_properties_attlist_;
    office_element_ptr style_background_image_;
    
};
CP_REGISTER_OFFICE_ELEMENT2(style_header_footer_properties);


///         common:style-header-footer-attlist
class common_style_header_footer_attlist
{
public:

    bool style_display_; // default true
    
};

///         header:footer-content
class header_footer_content
{
public:
    void add_child_element( const ::std::wstring & Ns, const ::std::wstring & Name, odf_conversion_context * Context);

    office_element_ptr_array content_;
    
};

}
}
