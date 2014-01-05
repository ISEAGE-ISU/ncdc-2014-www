/*
    Copyright (C) 2011 Raphters authors,
    
    This file is part of Raphters.
    
    Raphters is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Raphters is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "raphters.h"
#include "utils.h"

START_HANDLER (webapp, POST, "login", res, 0, matches) {
  response_add_header(res, "content-type", "text/html");
  //write_page_template_header(res);
  response_write(res, "todo");
  //write_page_template_footer(res);
} END_HANDLER

START_HANDLER (default_handler, GET, "", res, 0, matches) {
  response_add_header(res, "content-type", "text/html");
  //write_page_template_header(res);
  const char *login_form = read_file("./templates/login.html.template");
  response_write(res, login_form);
  //write_page_template_footer(res);
} END_HANDLER

int main() {
    add_handler(webapp);
    add_handler(default_handler);
    serve_forever();
    return 0;
}

void write_template(response *res) {
  const char *header = "HEADER";
  response_write(res, header);
}

void write_page_template_header(response *res) {
  const char *header = "HEADER";
  response_write(res, header);
}

void write_page_template_footer(response *res) {
  const char *footer = "FOOTER";
  response_write(res, footer);
}