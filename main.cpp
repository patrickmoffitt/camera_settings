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

//
// WebSocketServer.cpp
//
// This sample demonstrates the WebSocket class.
//
// Copyright (c) 2012, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/WebSocket.h"
#include "Poco/Net/NetException.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Format.h"
#include "motion_camera_settings_generated.h"
#include "html_css_js_util.hpp"
#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace OV5642_Settings;
using html = html_css_js_util;

using Poco::Net::ServerSocket;
using Poco::Net::WebSocket;
using Poco::Net::WebSocketException;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPServerParams;
using Poco::Timestamp;
using Poco::ThreadPool;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;


class PageRequestHandler: public HTTPRequestHandler
    /// Return a HTML document with some JavaScript creating
    /// a WebSocket connection.
{
public:
    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
    {
        response.setChunkedTransferEncoding(true);
        response.setContentType("text/html");
        std::ostream& ostr = response.send();
        ostr << html::render(request.serverAddress().toString());
        /*
        ostr << "<!doctype html>";
        ostr << "<html lang=\"en-US\">";
        ostr << "<head>";
        ostr << "<meta charset=\"utf-8\">";
        ostr << "<title>WebSocketServer</title>";
        ostr << flatbuffers_js;
        ostr << motion_camera_settings_generated_js;
        ostr << "<script type=\"text/javascript\">";
        ostr << "function WebSocketTest()";
        ostr << "{";
        ostr << "  if (\"WebSocket\" in window)";
        ostr << "  {";
        ostr << "    var ws = new WebSocket(\"ws://" << request.serverAddress().toString() << "/ws\");";
        ostr << "    ws.onopen = function()";
        ostr << "      {";
        ostr << "        ws.send(\"Hello, world!\");";
        ostr << "      };";
        ostr << "    ws.onmessage = function(evt)";
        ostr << "      { ";
        ostr << "        evt.data.arrayBuffer().then(function(result) { ";
        ostr << "            const bytes = new Uint8Array(result);";
        ostr << "            var buf = new flatbuffers.ByteBuffer(bytes);";
        ostr << "            settings = OV5642_Settings.Settings.getRootAsSettings(buf);";
        ostr << "            console.log(settings.event"
        ostr << "        });";
        //ostr << "        var msg = evt.data;";
        //ostr << "        alert(\"Message received: \" + msg);";
        ostr << "        alert(\"Message received: \");";
        ostr << "        ws.close();";
        ostr << "      };";
        ostr << "    ws.onclose = function()";
        ostr << "      { ";
        ostr << "        alert(\"WebSocket closed.\");";
        ostr << "      };";
        ostr << "  }";
        ostr << "  else";
        ostr << "  {";
        ostr << "     alert(\"This browser does not support WebSockets.\");";
        ostr << "  }";
        ostr << "}";
        ostr << "</script>";
        ostr << "</head>";
        ostr << "<body>";
        ostr << "  <h1>WebSocket Server</h1>";
        ostr << "  <p><a href=\"javascript:WebSocketTest()\">Run WebSocket Script</a></p>";
        ostr << "</body>";
        ostr << "</html>";
         */
        ostr.flush();
    }
};

class FlatBufferHandler {
    /// A utility class for loading, saving and comparing flatBuffer files.
public:
    /// Compare to flatBuffers stored in fixed-name files.
    static void compareBuffers(Poco::Util::LayeredConfiguration *config, Poco::Logger *logger){
        using namespace OV5642_Settings;
        using namespace flatbuffers;
        size_t buf_size{0};
        auto default_filename = config->getString("WebSocketServer.default_buffer",
                                               "/tmp/default_buffer.bin");
        auto new_filename = config->getString("WebSocketServer.new_buffer",
                                                  "/tmp/new_buffer.bin");
        logger->information(Poco::format("Comparing: %s, %s", default_filename, new_filename));
        std::ifstream ifs;
        ifs.open(default_filename, std::ios_base::binary | std::ios_base::in | std::ios_base::ate);
        buf_size = ifs.tellg();
        ifs.seekg(std::ios_base::beg);
        if (not ifs.is_open()) {
            logger->error(Poco::format("\nCannot open: %s", default_filename));
            Poco::Util::ServerApplication::terminate();
        }
        uint8_t default_buf[buf_size];
        for (unsigned char & i : default_buf) {
            i = ifs.get();
        }
        ifs.close();

        auto def_v = Verifier(default_buf, buf_size);
        bool def_ok = VerifySettingsBuffer(def_v);
        if(def_ok) {
            logger->information("\nflatbuffers::VerifySettingsBuffer PASSED for default_buffer.bin");
        } else {
            logger->error("\nflatbuffers::VerifySettingsBuffer FAILED for default_buffer.bin");
            Poco::Util::ServerApplication::terminate();
        }
        auto default_settings = GetSettings(default_buf);

        ifs.open(new_filename, std::ios_base::binary | std::ios_base::in | std::ios_base::ate);
        buf_size = ifs.tellg();
        ifs.seekg(std::ios_base::beg);
        if (not ifs.is_open()) {
            logger->error(Poco::format("\nCannot open: %s", new_filename));
            Poco::Util::ServerApplication::terminate();
        }
        uint8_t new_buf[buf_size];
        for (unsigned char & i : new_buf) {
            i = ifs.get();
        }
        ifs.close();
        auto new_v = Verifier(new_buf, buf_size);
        bool new_ok = VerifySettingsBuffer(new_v);
        if(new_ok) {
            logger->information("\nflatbuffers::VerifySettingsBuffer PASSED for new_buffer.bin");
        } else {
            logger->error("\nflatbuffers::VerifySettingsBuffer FAILED for new_buffer.");
            Poco::Util::ServerApplication::terminate();
        }
        auto new_settings = GetSettings(new_buf);

        std::map<std::string, uint8_t> map_d {
                {"jpeg_size",        default_settings->jpeg_size()},
                {"quality",          default_settings->quality()},
                {"frames",           default_settings->frames()},
                {"light_mode",       default_settings->light_mode()},
                {"color_saturation", default_settings->color_saturation()},
                {"brightness",       default_settings->brightness()},
                {"contrast",         default_settings->contrast()},
                {"hue",              default_settings->hue()},
                {"effect",           default_settings->effect()},
                {"exposure",         default_settings->exposure()},
                {"sharpness",        default_settings->sharpness()},
                {"mirror",           default_settings->mirror()},
                {"test_pattern",     default_settings->test_pattern()}
        };

        std::map<std::string, uint8_t> map_n {
                {"jpeg_size",        new_settings->jpeg_size()},
                {"quality",          new_settings->quality()},
                {"frames",           new_settings->frames()},
                {"light_mode",       new_settings->light_mode()},
                {"color_saturation", new_settings->color_saturation()},
                {"brightness",       new_settings->brightness()},
                {"contrast",         new_settings->contrast()},
                {"hue",              new_settings->hue()},
                {"effect",           new_settings->effect()},
                {"exposure",         new_settings->exposure()},
                {"sharpness",        new_settings->sharpness()},
                {"mirror",           new_settings->mirror()},
                {"test_pattern",     new_settings->test_pattern()}
        };
    
        std::unordered_set<std::string> keys{ // Order is reversed at compile time.
            "test_pattern", "mirror", "sharpness", "exposure", "effect", "hue",
            "contrast", "brightness", "color_saturation", "light_mode", "frames",
            "quality", "jpeg_size"
        };
        std::string h1{"key"};
        std::string h2{"default"};
        std::string h3{"new"};
        std::string h4{"match"};
        logger->information(Poco::format("\n%-18s%-10s%-10s%-10s", h1, h2, h3, h4));
        logger->information("-------------------------------------------");
        std::string result_en{"true"};
        int matches{0};
        for (auto &k: keys) {
            if (map_d[k] != map_n[k]) {
                result_en = "false";
            } else {
                result_en = "true";
                matches++;
            }
            logger->information(
                    Poco::format("%-18s%-10d%-10d%-10s", k, int(map_d[k]), int(map_n[k]), result_en));
        }
        if (matches < keys.size()) {
            logger->error("\nCompare result: buffers DO NOT match.");
        } else {
            logger->information("\nCompare result: buffers match.");
        }
        Poco::Util::ServerApplication::terminate();
    }
    /// Load a flatBuffer from a file.
    static void loadBuffer(uint8_t *buf, int &buf_size, std::string &filename, Poco::Logger *logger) {
        std::ifstream ifs;
        ifs.open(filename, std::ios_base::binary | std::ios_base::in | std::ios_base::ate);
        if (not ifs.is_open()) {
            logger->error(Poco::format("\nCannot open: %s", filename));
            buf_size = 0;
        }
        auto size = ifs.tellg();
        ifs.seekg(0);
        for (int i=0; i<size; i++) {
            buf[i] = ifs.get();
        }
        ifs.close();
        buf_size = size;
    }
    /// Save a flatBuffer to a file.
    static void saveBuffer(uint8_t *buf, size_t size, std::string &filename) {
        std::ofstream ofs;
        ofs.open(filename, std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);
        for (int i=0; i<size; i++) {
            ofs << buf[i];
        }
        ofs.flush();
        ofs.close();
    }

};

class WebSocketRequestHandler: public HTTPRequestHandler
    /// Handle a WebSocket connection.
{
public:
    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
    {
        Application& app = Application::instance();
        try
        {
            WebSocket ws(request, response);
            app.logger().information("WebSocket connection established.");
            uint8_t buffer[1024];
            int flags;
            int bytes_received;
            do
            {
                bytes_received = ws.receiveFrame(buffer, sizeof(buffer), flags);
                app.logger().information(
                        Poco::format("Frame received (length=%d, flags=0x%x).",
                                bytes_received, unsigned(flags))
                );
                bool request_handled{false};
                /// Send default settings.
                if (not request_handled
                    and std::string(reinterpret_cast<char*>(buffer)) == "getDefault") {
                    memset(buffer, '\0', sizeof(buffer));
                    flatbuffers::FlatBufferBuilder builder(64);

                    uint8_t jpeg_size = 0;         // OV5642_320x240
                    uint8_t quality = 1;           // default_quality
                    uint8_t frames = 0;            // one frame
                    uint8_t light_mode = 0;        // Advanced_AWB
                    uint8_t color_saturation = 4;  // Saturation0
                    uint8_t brightness = 4;        // Brightness0
                    uint8_t contrast = 4;          // Contrast0
                    uint8_t hue = 6;               // degree_0
                    uint8_t effect = 7;            // Normal
                    uint8_t exposure = 5;          // Exposure_default
                    uint8_t sharpness = 0;         // Auto_Sharpness_default
                    uint8_t mirror = 7;            // Normal
                    uint8_t test_pattern = 7;      // Normal
                    auto build_buffer = CreateSettings(builder,
                                                       jpeg_size, quality, frames, light_mode,
                                                       color_saturation, brightness, contrast,
                                                       hue, effect, exposure, sharpness,
                                                       mirror, test_pattern);
                    builder.Finish(build_buffer);
                    uint8_t *buf = builder.GetBufferPointer();
                    int size = builder.GetSize();
                    if (not app.config().getBool("application.runAsDaemon", false)) {
                        auto filename = app.config().getString("WebSocketServer.default_buffer",
                                                               "/tmp/default_buffer.bin");
                        FlatBufferHandler::saveBuffer(buf, size, filename);
                    }
                    flags = WebSocket::FRAME_BINARY;
                    ws.sendFrame(buf, size, flags);
                    request_handled = true;
                    app.logger().information("Default settings sent.");
                }
                /// Send new settings.
                if (not request_handled
                    and std::string(reinterpret_cast<char*>(buffer)) == "getNew") {
                    auto filename = app.config().getString("WebSocketServer.new_buffer",
                                                           "/tmp/new_buffer.bin");
                    int buf_size{0};
                    FlatBufferHandler::loadBuffer(buffer, buf_size, filename, &app.logger());
                    flags = WebSocket::FRAME_BINARY;
                    ws.sendFrame(buffer, buf_size, flags);
                    request_handled = true;
                    app.logger().information("New settings sent.");
                }
                /// Save a new settings buffer.
                if (not request_handled and bytes_received > 0 ) {
                    app.logger().information("Received Flatbuffer size: " + std::to_string(bytes_received));
                    // We received a byteArray, save it.
                    auto filename = app.config().getString("WebSocketServer.new_buffer",
                                                           "/tmp/new_buffer.bin");
                    FlatBufferHandler::saveBuffer(buffer, bytes_received, filename);
                    request_handled = true;
                    app.logger().information("New settings buffer saved.");
                }
            }
            while (bytes_received > 0 && (flags & WebSocket::FRAME_OP_BITMASK) != WebSocket::FRAME_OP_CLOSE);
            app.logger().information("WebSocket connection closed.");
        }
        catch (WebSocketException& exc)
        {
            app.logger().log(exc);
            switch (exc.code())
            {
                case WebSocket::WS_ERR_HANDSHAKE_UNSUPPORTED_VERSION:
                    response.set("Sec-WebSocket-Version", WebSocket::WEBSOCKET_VERSION);
                    // fallthrough
                case WebSocket::WS_ERR_NO_HANDSHAKE:
                case WebSocket::WS_ERR_HANDSHAKE_NO_VERSION:
                case WebSocket::WS_ERR_HANDSHAKE_NO_KEY:
                    response.setStatusAndReason(HTTPResponse::HTTP_BAD_REQUEST);
                    response.setContentLength(0);
                    response.send();
                    break;
            }
        }
    }
};


class RequestHandlerFactory: public HTTPRequestHandlerFactory
{
public:
    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request)
    {
        Application& app = Application::instance();
        app.logger().information("Request from "
                                 + request.clientAddress().toString()
                                 + ": "
                                 + request.getMethod()
                                 + " "
                                 + request.getURI()
                                 + " "
                                 + request.getVersion());

        for (HTTPServerRequest::ConstIterator it = request.begin(); it != request.end(); ++it)
        {
            app.logger().information(it->first + ": " + it->second);
        }

        if(request.find("Upgrade") != request.end() && Poco::icompare(request["Upgrade"], "websocket") == 0)
            return new WebSocketRequestHandler;
        else
            return new PageRequestHandler;
    }
};


class WebSocketServer: public Poco::Util::ServerApplication
    /// The main application class.
    ///
    /// This class handles command-line arguments and
    /// configuration files.
    /// Start the WebSocketServer executable with the help
    /// option (/help on Windows, --help on Unix) for
    /// the available command line options.
    ///
    /// To use the sample configuration file (WebSocketServer.properties),
    /// copy the file to the directory where the WebSocketServer executable
    /// resides. If you start the debug version of the WebSocketServer
    /// (WebSocketServerd[.exe]), you must also create a copy of the configuration
    /// file named WebSocketServerd.properties. In the configuration file, you
    /// can specify the port on which the server is listening (default
    /// 9980) and the format of the date/time string sent back to the client.
    ///
    /// To test the WebSocketServer you can use any web browser (http://localhost:9980/).
{
public:
    WebSocketServer(): _helpRequested(false)
    {
    }

    ~WebSocketServer()
    {
    }

protected:
    void initialize(Application& self)
    {
        loadConfiguration(); // load default configuration files, if present

        ServerApplication::initialize(self);
    }

    void uninitialize()
    {
        ServerApplication::uninitialize();
    }

    void defineOptions(OptionSet& options)
    {
        ServerApplication::defineOptions(options);

        options.addOption(
                Option("help", "h", "display help information on command line arguments")
                        .required(false)
                        .repeatable(false));
        options.addOption(
                Option("compare", "c", "compare default_buffer.bin to new_buffer.bin")
                        .required(false)
                        .repeatable(false));
    }

    void handleOption(const std::string& name, const std::string& value)
    {
        ServerApplication::handleOption(name, value);

        if (name == "help")
            _helpRequested = true;
        /// Implement FlatBufferHandler::compareBuffers
        if (name == "compare") {
            loadConfiguration();
            FlatBufferHandler::compareBuffers(&config(), &logger());
        }

    }

    void displayHelp()
    {
        HelpFormatter helpFormatter(options());
        helpFormatter.setCommand(commandName());
        helpFormatter.setUsage("OPTIONS");
        helpFormatter.setHeader("A 5MP Camera Settings server supporting the WebSocket protocol.");
        helpFormatter.format(std::cout);
    }

    int main(const std::vector<std::string>& args)
    {
        if (_helpRequested)
        {
            displayHelp();
        }
        else
        {
            // get parameters from configuration file
            unsigned short port = (unsigned short) config().getInt("WebSocketServer.port", 9980);
            // set-up a server socket
            ServerSocket svs(port);
            // set-up a HTTPServer instance
            HTTPServer srv(new RequestHandlerFactory, svs, new HTTPServerParams);
            // start the HTTPServer
            srv.start();
            // wait for CTRL-C or kill
            waitForTerminationRequest();
            // Stop the HTTPServer
            srv.stop();
        }
        return Application::EXIT_OK;
    }

private:
    bool _helpRequested;
};


POCO_SERVER_MAIN(WebSocketServer)
