/*
    Copyright (c) 2020 Patrick Moffitt

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#ifndef HTML_CSS_JS_UTIL_HPP
#define HTML_CSS_JS_UTIL_HPP

#include <string>

/**
 * A utility class implementing separation-of-concerns for the HTML, CSS, and
 * JavaScript assets of the camera settings user interface.
 *
 * @see https://en.wikipedia.org/wiki/Separation_of_concerns
 */
class html_css_js_util {
public:
    static const std::string body_html;
    static const std::string flat_buffers_js;
    static const std::string motion_camera_settings_generated_js;
    static const std::string camera_settings_js;
    static const std::string page_head_html;
    static std::string on_load_js(std::basic_string<char> &request_server_addr);
    static std::string render(std::basic_string<char> request_server_addr);
    static const std::string css;

};


#endif //HTML_CSS_JS_UTIL_HPP
