/*
 * Copyright (c) 2020, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/DOM/Document.h>
#include <LibWeb/HTML/HTMLLabelElement.h>
#include <LibWeb/Layout/Label.h>

namespace Web::HTML {

HTMLLabelElement::HTMLLabelElement(DOM::Document& document, DOM::QualifiedName qualified_name)
    : HTMLElement(document, move(qualified_name))
{
    set_prototype(&Bindings::cached_web_prototype(realm(), "HTMLLabelElement"));
}

HTMLLabelElement::~HTMLLabelElement() = default;

RefPtr<Layout::Node> HTMLLabelElement::create_layout_node(NonnullRefPtr<CSS::StyleProperties> style)
{
    return adopt_ref(*new Layout::Label(document(), this, move(style)));
}

}
