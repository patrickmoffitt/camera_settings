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

#include "html_css_js_util.hpp"

/**
 * The HTML body for the camera settings user interface.
 *
 * @return HTML
 */
const std::string html_css_js_util::body_html = R"END(
<body>
<h1>0V5642 Camera Settings</h1>
    <div class="feature" id="brightness"><h2>Brightness</h2>
        <div class="option" id="brightness_0">Brightness +4</div>
        <div class="option" id="brightness_1">Brightness +3</div>
        <div class="option" id="brightness_2">Brightness +2</div>
        <div class="option" id="brightness_3">Brightness +1</div>
        <div class="option" id="brightness_4">Brightness 0</div>
        <div class="option" id="brightness_5">Brightness -1</div>
        <div class="option" id="brightness_6">Brightness -2</div>
        <div class="option" id="brightness_7">Brightness -3</div>
        <div class="option" id="brightness_8">Brightness -4</div>
    </div>
    <div class="feature" id="color_saturation"><h2>Color Saturation</h2>
        <div class="option" id="color_saturation_0">Saturation +4</div>
        <div class="option" id="color_saturation_1">Saturation +3</div>
        <div class="option" id="color_saturation_2">Saturation +2</div>
        <div class="option" id="color_saturation_3">Saturation +1</div>
        <div class="option" id="color_saturation_4">Saturation 0</div>
        <div class="option" id="color_saturation_5">Saturation -1</div>
        <div class="option" id="color_saturation_6">Saturation -2</div>
        <div class="option" id="color_saturation_7">Saturation -3</div>
        <div class="option" id="color_saturation_8">Saturation -4</div>
    </div>
    <div class="feature" id="contrast"><h2>Contrast</h2>
        <div class="option" id="contrast_0">Contrast +4</div>
        <div class="option" id="contrast_1">Contrast +3</div>
        <div class="option" id="contrast_2">Contrast +2</div>
        <div class="option" id="contrast_3">Contrast +1</div>
        <div class="option" id="contrast_4">Contrast 0</div>
        <div class="option" id="contrast_5">Contrast -1</div>
        <div class="option" id="contrast_6">Contrast -2</div>
        <div class="option" id="contrast_7">Contrast -3</div>
        <div class="option" id="contrast_8">Contrast -4</div>
    </div>
    <div class="feature" id="effect"><h2>Special Effect</h2>
        <div class="option" id="effect_0">Antique</div>
        <div class="option" id="effect_1">Bluish</div>
        <div class="option" id="effect_2">Greenish</div>
        <div class="option" id="effect_3">Reddish</div>
        <div class="option" id="effect_4">Black &amp; White</div>
        <div class="option" id="effect_5">Negative</div>
        <div class="option" id="effect_6">B&amp;W Negative</div>
        <div class="option" id="effect_7">Normal</div>
        <div class="option" id="effect_8">Sepia</div>
        <div class="option" id="effect_9">Overexposure</div>
        <div class="option" id="effect_10">Solarize</div>
        <div class="option" id="effect_11">Blueish</div>
        <div class="option" id="effect_12">Yellowish</div>
    </div>
    <div class="feature" id="exposure"><h2>Exposure</h2>
        <div class="option" id="exposure_0">Exposure_17_EV</div>
        <div class="option" id="exposure_1">Exposure_13_EV</div>
        <div class="option" id="exposure_2">Exposure_10_EV</div>
        <div class="option" id="exposure_3">Exposure_07_EV</div>
        <div class="option" id="exposure_4">Exposure_03_EV</div>
        <div class="option" id="exposure_5">Exposure_default</div>
        <div class="option" id="exposure_6">Exposure03_EV</div>
        <div class="option" id="exposure_7">Exposure07_EV</div>
        <div class="option" id="exposure_8">Exposure10_EV</div>
        <div class="option" id="exposure_9">Exposure13_EV</div>
        <div class="option" id="exposure_10">Exposure17_EV</div>
    </div>
    <div class="feature" id="frames"><h2>Frames</h2>
        <div class="option" id="frames_0">One</div>
        <div class="option" id="frames_1">Two</div>
        <div class="option" id="frames_2">Three</div>
        <div class="option" id="frames_3">Four</div>
        <div class="option" id="frames_4">Five</div>
        <div class="option" id="frames_5">Six</div>
        <div class="option" id="frames_255">Movie</div>
    </div>
    <div class="feature" id="hue"><h2>Hue</h2>
        <div class="option" id="hue_0">degree_180</div>
        <div class="option" id="hue_1">degree_150</div>
        <div class="option" id="hue_2">degree_120</div>
        <div class="option" id="hue_3">degree_90</div>
        <div class="option" id="hue_4">degree_60</div>
        <div class="option" id="hue_5">degree_30</div>
        <div class="option" id="hue_6">degree_0</div>
        <div class="option" id="hue_7">degree30</div>
        <div class="option" id="hue_8">degree60</div>
        <div class="option" id="hue_9">degree90</div>
        <div class="option" id="hue_10">degree120</div>
        <div class="option" id="hue_11">degree150</div>
    </div>
    <div class="feature" id="jpeg_size"><h2>Size</h2>
        <div class="option" id="jpeg_size_0">OV5642_320x240</div>
        <div class="option" id="jpeg_size_1">OV5642_640x480</div>
        <div class="option" id="jpeg_size_2">OV5642_1024x768</div>
        <div class="option" id="jpeg_size_3">OV5642_1280x960</div>
        <div class="option" id="jpeg_size_4">OV5642_1600x1200</div>
        <div class="option" id="jpeg_size_5">OV5642_2048x1536</div>
        <div class="option" id="jpeg_size_6">OV5642_2592x1944</div>
    </div>
    <div class="feature" id="light_mode"><h2>Light Mode</h2>
        <div class="option" id="light_mode_0">Advanced_AWB</div>
        <div class="option" id="light_mode_1">Simple_AWB</div>
        <div class="option" id="light_mode_2">Manual_day</div>
        <div class="option" id="light_mode_3">Manual_A</div>
        <div class="option" id="light_mode_4">Manual_cwf</div>
        <div class="option" id="light_mode_5">Manual_cloudy</div>
    </div>
    <div class="feature" id="mirror"><h2>Mirror</h2>
        <div class="option" id="mirror_7">Normal</div>
        <!--- Only Flip works at present 05 June 2020.
        https://github.com/ArduCAM/Arduino/issues/448
        <div class="option" id="mirror_0">MIRROR</div> -->
        <div class="option" id="mirror_1">FLIP</div>
        <!---
        <div class="option" id="mirror_2">MIRROR_FLIP</div>
                                                       -->
    </div>
    <div class="feature" id="quality"><h2>Quality</h2>
        <div class="option" id="quality_0">high_quality</div>
        <div class="option" id="quality_1">default_quality</div>
        <div class="option" id="quality_2">low_quality</div>
    </div>
    <div class="feature" id="sharpness"><h2>Sharpness</h2>
        <div class="option" id="sharpness_0">Auto_Sharpness_default</div>
        <div class="option" id="sharpness_1">Auto_Sharpness1</div>
        <div class="option" id="sharpness_2">Auto_Sharpness2</div>
        <div class="option" id="sharpness_3">Manual_Sharpness_off</div>
        <div class="option" id="sharpness_4">Manual_Sharpness1</div>
        <div class="option" id="sharpness_5">Manual_Sharpness2</div>
        <div class="option" id="sharpness_6">Manual_Sharpness3</div>
        <div class="option" id="sharpness_7">Manual_Sharpness4</div>
        <div class="option" id="sharpness_8">Manual_Sharpness5</div>
    </div>
    <div class="feature" id="test_pattern"><h2>Test Pattern</h2>
        <div class="option" id="test_pattern_7">Normal</div>
        <div class="option" id="test_pattern_0">Color_bar</div>
        <div class="option" id="test_pattern_1">Color_square</div>
        <div class="option" id="test_pattern_2">BW_square</div>
        <!--- Does not work.
        https://github.com/ArduCAM/Arduino/issues/486
        <div class="option" id="test_pattern_3">DLI</div> -->
    </div>
    <div class="control">
        <div class="center">
            <div class="option button" id="reset">Load Defaults</div>
            <div class="option button" id="new">Load Latest</div>
            <div class="option button" id="save">Save</div>
        </div>
    </div>)END";

/**
 * The JavaScript user interface for the camera settings.
 *
 * @return JavaScript
 */
const std::string html_css_js_util::camera_settings_js = R"END(
<!-- BEGIN camera_settings.js --->
<script>
const cameraSettings = {
    jpeg_size: 0,         // OV5642_320x240
    quality: 1,           // default_quality
    frames:  0,
    light_mode: 0,        // Advanced_AWB
    color_saturation: 4,  // Saturation0
    brightness: 4,        // Brightness0
    contrast: 4,          // Contrast0
    hue: 6,               // degree_0
    effect: 7,            // Normal
    exposure: 5,          // Exposure_default
    sharpness: 0,         // Auto_Sharpness_default
    mirror: 7,            // Normal
    test_pattern: 7,      // Normal
    init: function(settings) {
        this.jpeg_size = settings.jpegSize();
        this.optionOnOff("jpeg_size", "jpeg_size_" + this.jpeg_size);
        this.quality = settings.quality();
        this.optionOnOff("quality", "quality_" + this.quality);
        this.frames = parseInt(settings.frames());
        this.optionOnOff("frames", "frames_" + this.frames);
        this.light_mode = settings.lightMode();
        this.optionOnOff("light_mode", "light_mode_" + this.light_mode);
        this.color_saturation = settings.colorSaturation();
        this.optionOnOff("color_saturation", "color_saturation_" + this.color_saturation);
        this.brightness = settings.brightness();
        this.optionOnOff("brightness", "brightness_" + this.brightness);
        this.contrast = settings.contrast();
        this.optionOnOff("contrast", "contrast_" + this.contrast);
        this.hue = settings.hue();
        this.optionOnOff("hue", "hue_" + this.hue);
        this.effect = settings.effect();
        this.optionOnOff("effect", "effect_" + this.effect);
        this.exposure = settings.exposure();
        this.optionOnOff("exposure", "exposure_" + this.exposure);
        this.sharpness = settings.sharpness();
        this.optionOnOff("sharpness", "sharpness_" + this.sharpness);
        this.mirror = settings.mirror();
        this.optionOnOff("mirror", "mirror_" + this.mirror);
        this.test_pattern = settings.testPattern();
        this.optionOnOff("test_pattern", "test_pattern_" + this.test_pattern);
    },
    newBuffer: new Uint8Array(52),
    defaultBuffer: new Uint8Array([ 36,  0,  0,  0,  0,  0, 30,  0, 16,  0,  0,  0, 15,  0,  0,  0,
                                     0,  0, 14,  0, 13,  0, 12,  0, 11,  0, 10,  0,  9,  0,  0,  0,
                                     8,  0,  7,  0, 30,  0,  0,  0,  0,  0,  0,  7,  7,  5,  7,  6,
                                     4,  4,  4, 1 ]),
    optionOnOff: function(feature, option) {
        const options = document.getElementById(feature).children;
        for (const option of options) {
            option.classList.remove("on");
            option.classList.add("off");
        }
        document.getElementById(option).classList.add("on");
        document.getElementById(option).classList.remove("off");
    },
    reset: function() {
        var buf = new flatbuffers.ByteBuffer(this.defaultBuffer);
        var defaultSettings = OV5642_Settings.Settings.getRootAsSettings(buf);
        this.init(defaultSettings);
    },
    new: function() {
        var ws = new WebSocket(wsUrl);
        ws.onopen = function() {
            ws.send("getNew");
        };
        ws.onmessage = function(evt) {
            var eventUint8Array  = null;
            var eventArrayBuffer = null;
            var fileReader       = new FileReader();
            fileReader.onload    = function(event) {
                eventArrayBuffer = event.target.result;
                this.newBuffer  = new Uint8Array(eventArrayBuffer);
                buf = new flatbuffers.ByteBuffer(this.newBuffer);
                var new_settings = OV5642_Settings.Settings.getRootAsSettings(buf);
                cameraSettings.init(new_settings);
            };
            fileReader.readAsArrayBuffer(evt.data);
            ws.close();
        };
        ws.onerror = function(event) {
            console.error("WebSocket error observed:", event);
        };
    },
    save: function() {
        var builder = new flatbuffers.Builder(48);
        var buffer = OV5642_Settings.Settings.createSettings(
            builder,
            this.jpeg_size,
            this.quality,
            parseInt(this.frames),
            this.light_mode,
            this.color_saturation,
            this.brightness,
            this.contrast,
            this.hue,
            this.effect,
            this.exposure,
            this.sharpness,
            this.mirror,
            this.test_pattern);
        builder.finish(buffer);
        this.newBuffer = builder.asUint8Array();
    }
};
</script>
<!-- END camera_settings.js --->
)END";

/**
 * The FlatBuffers JavaScript interface library.
 *
 * @return JavaScript
 */
const std::string html_css_js_util::flat_buffers_js = R"END(
<!-- BEGIN flatbuffers.js --->
<script>
/// @file
/// @addtogroup flatbuffers_javascript_api
/// @{
/// @cond FLATBUFFERS_INTERNAL

/**
 * @fileoverview
 *
 * Need to suppress 'global this' error so the Node.js export line doesn't cause
 * closure compile to error out.
 * @suppress {globalThis}
 */

/**
 * @const
 * @namespace
 */
var flatbuffers = {};

/**
 * @typedef {number}
 */
flatbuffers.Offset;

/**
 * @typedef {{
 *   bb: flatbuffers.ByteBuffer,
 *   bb_pos: number
 * }}
 */
flatbuffers.Table;

/**
 * @type {number}
 * @const
 */
flatbuffers.SIZEOF_SHORT = 2;

/**
 * @type {number}
 * @const
 */
flatbuffers.SIZEOF_INT = 4;

/**
 * @type {number}
 * @const
 */
flatbuffers.FILE_IDENTIFIER_LENGTH = 4;

/**
 * @type {number}
 * @const
 */
flatbuffers.SIZE_PREFIX_LENGTH = 4;

/**
 * @param {number} low
 * @param {number} high
 * @returns {flatbuffers.Long}
 */
flatbuffers.createLong = function(low, high) {
  return flatbuffers.Long.create(low, high);
};

/**
 * @enum {number}
 */
flatbuffers.Encoding = {
  UTF8_BYTES: 1,
  UTF16_STRING: 2
};

/**
 * @type {Int32Array}
 * @const
 */
flatbuffers.int32 = new Int32Array(2);

/**
 * @type {Float32Array}
 * @const
 */
flatbuffers.float32 = new Float32Array(flatbuffers.int32.buffer);

/**
 * @type {Float64Array}
 * @const
 */
flatbuffers.float64 = new Float64Array(flatbuffers.int32.buffer);

/**
 * @type {boolean}
 * @const
 */
flatbuffers.isLittleEndian = new Uint16Array(new Uint8Array([1, 0]).buffer)[0] === 1;

////////////////////////////////////////////////////////////////////////////////

/**
 * @constructor
 * @param {number} low
 * @param {number} high
 */
flatbuffers.Long = function(low, high) {
  /**
   * @type {number}
   * @const
   */
  this.low = low | 0;

  /**
   * @type {number}
   * @const
   */
  this.high = high | 0;
};

/**
 * @param {number} low
 * @param {number} high
 * @returns {!flatbuffers.Long}
 */
flatbuffers.Long.create = function(low, high) {
  // Special-case zero to avoid GC overhead for default values
  return low == 0 && high == 0 ? flatbuffers.Long.ZERO : new flatbuffers.Long(low, high);
};

/**
 * @returns {number}
 */
flatbuffers.Long.prototype.toFloat64 = function() {
  return (this.low >>> 0) + this.high * 0x100000000;
};

/**
 * @param {flatbuffers.Long} other
 * @returns {boolean}
 */
flatbuffers.Long.prototype.equals = function(other) {
  return this.low == other.low && this.high == other.high;
};

/**
 * @type {!flatbuffers.Long}
 * @const
 */
flatbuffers.Long.ZERO = new flatbuffers.Long(0, 0);

/// @endcond
////////////////////////////////////////////////////////////////////////////////
/**
 * Create a FlatBufferBuilder.
 *
 * @constructor
 * @param {number=} opt_initial_size
 */
flatbuffers.Builder = function(opt_initial_size) {
  if (!opt_initial_size) {
    var initial_size = 1024;
  } else {
    var initial_size = opt_initial_size;
  }

  /**
   * @type {flatbuffers.ByteBuffer}
   * @private
   */
  this.bb = flatbuffers.ByteBuffer.allocate(initial_size);

  /**
   * Remaining space in the ByteBuffer.
   *
   * @type {number}
   * @private
   */
  this.space = initial_size;

  /**
   * Minimum alignment encountered so far.
   *
   * @type {number}
   * @private
   */
  this.minalign = 1;

  /**
   * The vtable for the current table.
   *
   * @type {Array.<number>}
   * @private
   */
  this.vtable = null;

  /**
   * The amount of fields we're actually using.
   *
   * @type {number}
   * @private
   */
  this.vtable_in_use = 0;

  /**
   * Whether we are currently serializing a table.
   *
   * @type {boolean}
   * @private
   */
  this.isNested = false;

  /**
   * Starting offset of the current struct/table.
   *
   * @type {number}
   * @private
   */
  this.object_start = 0;

  /**
   * List of offsets of all vtables.
   *
   * @type {Array.<number>}
   * @private
   */
  this.vtables = [];

  /**
   * For the current vector being built.
   *
   * @type {number}
   * @private
   */
  this.vector_num_elems = 0;

  /**
   * False omits default values from the serialized data
   *
   * @type {boolean}
   * @private
   */
  this.force_defaults = false;
};

flatbuffers.Builder.prototype.clear = function() {
  this.bb.clear();
  this.space = this.bb.capacity();
  this.minalign = 1;
  this.vtable = null;
  this.vtable_in_use = 0;
  this.isNested = false;
  this.object_start = 0;
  this.vtables = [];
  this.vector_num_elems = 0;
  this.force_defaults = false;
};

/**
 * In order to save space, fields that are set to their default value
 * don't get serialized into the buffer. Forcing defaults provides a
 * way to manually disable this optimization.
 *
 * @param {boolean} forceDefaults true always serializes default values
 */
flatbuffers.Builder.prototype.forceDefaults = function(forceDefaults) {
  this.force_defaults = forceDefaults;
};

/**
 * Get the ByteBuffer representing the FlatBuffer. Only call this after you've
 * called finish(). The actual data starts at the ByteBuffer's current position,
 * not necessarily at 0.
 *
 * @returns {flatbuffers.ByteBuffer}
 */
flatbuffers.Builder.prototype.dataBuffer = function() {
  return this.bb;
};

/**
 * Get the bytes representing the FlatBuffer. Only call this after you've
 * called finish().
 *
 * @returns {!Uint8Array}
 */
flatbuffers.Builder.prototype.asUint8Array = function() {
  return this.bb.bytes().subarray(this.bb.position(), this.bb.position() + this.offset());
};

/// @cond FLATBUFFERS_INTERNAL
/**
 * Prepare to write an element of `size` after `additional_bytes` have been
 * written, e.g. if you write a string, you need to align such the int length
 * field is aligned to 4 bytes, and the string data follows it directly. If all
 * you need to do is alignment, `additional_bytes` will be 0.
 *
 * @param {number} size This is the of the new element to write
 * @param {number} additional_bytes The padding size
 */
flatbuffers.Builder.prototype.prep = function(size, additional_bytes) {
  // Track the biggest thing we've ever aligned to.
  if (size > this.minalign) {
    this.minalign = size;
  }

  // Find the amount of alignment needed such that `size` is properly
  // aligned after `additional_bytes`
  var align_size = ((~(this.bb.capacity() - this.space + additional_bytes)) + 1) & (size - 1);

  // Reallocate the buffer if needed.
  while (this.space < align_size + size + additional_bytes) {
    var old_buf_size = this.bb.capacity();
    this.bb = flatbuffers.Builder.growByteBuffer(this.bb);
    this.space += this.bb.capacity() - old_buf_size;
  }

  this.pad(align_size);
};

/**
 * @param {number} byte_size
 */
flatbuffers.Builder.prototype.pad = function(byte_size) {
  for (var i = 0; i < byte_size; i++) {
    this.bb.writeInt8(--this.space, 0);
  }
};

/**
 * @param {number} value
 */
flatbuffers.Builder.prototype.writeInt8 = function(value) {
  this.bb.writeInt8(this.space -= 1, value);
};

/**
 * @param {number} value
 */
flatbuffers.Builder.prototype.writeInt16 = function(value) {
  this.bb.writeInt16(this.space -= 2, value);
};

/**
 * @param {number} value
 */
flatbuffers.Builder.prototype.writeInt32 = function(value) {
  this.bb.writeInt32(this.space -= 4, value);
};

/**
 * @param {flatbuffers.Long} value
 */
flatbuffers.Builder.prototype.writeInt64 = function(value) {
  this.bb.writeInt64(this.space -= 8, value);
};

/**
 * @param {number} value
 */
flatbuffers.Builder.prototype.writeFloat32 = function(value) {
  this.bb.writeFloat32(this.space -= 4, value);
};

/**
 * @param {number} value
 */
flatbuffers.Builder.prototype.writeFloat64 = function(value) {
  this.bb.writeFloat64(this.space -= 8, value);
};
/// @endcond

/**
 * Add an `int8` to the buffer, properly aligned, and grows the buffer (if necessary).
 * @param {number} value The `int8` to add the the buffer.
 */
flatbuffers.Builder.prototype.addInt8 = function(value) {
  this.prep(1, 0);
  this.writeInt8(value);
};

/**
 * Add an `int16` to the buffer, properly aligned, and grows the buffer (if necessary).
 * @param {number} value The `int16` to add the the buffer.
 */
flatbuffers.Builder.prototype.addInt16 = function(value) {
  this.prep(2, 0);
  this.writeInt16(value);
};

/**
 * Add an `int32` to the buffer, properly aligned, and grows the buffer (if necessary).
 * @param {number} value The `int32` to add the the buffer.
 */
flatbuffers.Builder.prototype.addInt32 = function(value) {
  this.prep(4, 0);
  this.writeInt32(value);
};

/**
 * Add an `int64` to the buffer, properly aligned, and grows the buffer (if necessary).
 * @param {flatbuffers.Long} value The `int64` to add the the buffer.
 */
flatbuffers.Builder.prototype.addInt64 = function(value) {
  this.prep(8, 0);
  this.writeInt64(value);
};

/**
 * Add a `float32` to the buffer, properly aligned, and grows the buffer (if necessary).
 * @param {number} value The `float32` to add the the buffer.
 */
flatbuffers.Builder.prototype.addFloat32 = function(value) {
  this.prep(4, 0);
  this.writeFloat32(value);
};

/**
 * Add a `float64` to the buffer, properly aligned, and grows the buffer (if necessary).
 * @param {number} value The `float64` to add the the buffer.
 */
flatbuffers.Builder.prototype.addFloat64 = function(value) {
  this.prep(8, 0);
  this.writeFloat64(value);
};

/// @cond FLATBUFFERS_INTERNAL
/**
 * @param {number} voffset
 * @param {number} value
 * @param {number} defaultValue
 */
flatbuffers.Builder.prototype.addFieldInt8 = function(voffset, value, defaultValue) {
  if (this.force_defaults || value != defaultValue) {
    this.addInt8(value);
    this.slot(voffset);
  }
};

/**
 * @param {number} voffset
 * @param {number} value
 * @param {number} defaultValue
 */
flatbuffers.Builder.prototype.addFieldInt16 = function(voffset, value, defaultValue) {
  if (this.force_defaults || value != defaultValue) {
    this.addInt16(value);
    this.slot(voffset);
  }
};

/**
 * @param {number} voffset
 * @param {number} value
 * @param {number} defaultValue
 */
flatbuffers.Builder.prototype.addFieldInt32 = function(voffset, value, defaultValue) {
  if (this.force_defaults || value != defaultValue) {
    this.addInt32(value);
    this.slot(voffset);
  }
};

/**
 * @param {number} voffset
 * @param {flatbuffers.Long} value
 * @param {flatbuffers.Long} defaultValue
 */
flatbuffers.Builder.prototype.addFieldInt64 = function(voffset, value, defaultValue) {
  if (this.force_defaults || !value.equals(defaultValue)) {
    this.addInt64(value);
    this.slot(voffset);
  }
};

/**
 * @param {number} voffset
 * @param {number} value
 * @param {number} defaultValue
 */
flatbuffers.Builder.prototype.addFieldFloat32 = function(voffset, value, defaultValue) {
  if (this.force_defaults || value != defaultValue) {
    this.addFloat32(value);
    this.slot(voffset);
  }
};

/**
 * @param {number} voffset
 * @param {number} value
 * @param {number} defaultValue
 */
flatbuffers.Builder.prototype.addFieldFloat64 = function(voffset, value, defaultValue) {
  if (this.force_defaults || value != defaultValue) {
    this.addFloat64(value);
    this.slot(voffset);
  }
};

/**
 * @param {number} voffset
 * @param {flatbuffers.Offset} value
 * @param {flatbuffers.Offset} defaultValue
 */
flatbuffers.Builder.prototype.addFieldOffset = function(voffset, value, defaultValue) {
  if (this.force_defaults || value != defaultValue) {
    this.addOffset(value);
    this.slot(voffset);
  }
};

/**
 * Structs are stored inline, so nothing additional is being added. `d` is always 0.
 *
 * @param {number} voffset
 * @param {flatbuffers.Offset} value
 * @param {flatbuffers.Offset} defaultValue
 */
flatbuffers.Builder.prototype.addFieldStruct = function(voffset, value, defaultValue) {
  if (value != defaultValue) {
    this.nested(value);
    this.slot(voffset);
  }
};

/**
 * Structures are always stored inline, they need to be created right
 * where they're used.  You'll get this assertion failure if you
 * created it elsewhere.
 *
 * @param {flatbuffers.Offset} obj The offset of the created object
 */
flatbuffers.Builder.prototype.nested = function(obj) {
  if (obj != this.offset()) {
    throw new Error('FlatBuffers: struct must be serialized inline.');
  }
};

/**
 * Should not be creating any other object, string or vector
 * while an object is being constructed
 */
flatbuffers.Builder.prototype.notNested = function() {
  if (this.isNested) {
    throw new Error('FlatBuffers: object serialization must not be nested.');
  }
};

/**
 * Set the current vtable at `voffset` to the current location in the buffer.
 *
 * @param {number} voffset
 */
flatbuffers.Builder.prototype.slot = function(voffset) {
  this.vtable[voffset] = this.offset();
};

/**
 * @returns {flatbuffers.Offset} Offset relative to the end of the buffer.
 */
flatbuffers.Builder.prototype.offset = function() {
  return this.bb.capacity() - this.space;
};

/**
 * Doubles the size of the backing ByteBuffer and copies the old data towards
 * the end of the new buffer (since we build the buffer backwards).
 *
 * @param {flatbuffers.ByteBuffer} bb The current buffer with the existing data
 * @returns {!flatbuffers.ByteBuffer} A new byte buffer with the old data copied
 * to it. The data is located at the end of the buffer.
 *
 * uint8Array.set() formally takes {Array<number>|ArrayBufferView}, so to pass
 * it a uint8Array we need to suppress the type check:
 * @suppress {checkTypes}
 */
flatbuffers.Builder.growByteBuffer = function(bb) {
  var old_buf_size = bb.capacity();

  // Ensure we don't grow beyond what fits in an int.
  if (old_buf_size & 0xC0000000) {
    throw new Error('FlatBuffers: cannot grow buffer beyond 2 gigabytes.');
  }

  var new_buf_size = old_buf_size << 1;
  var nbb = flatbuffers.ByteBuffer.allocate(new_buf_size);
  nbb.setPosition(new_buf_size - old_buf_size);
  nbb.bytes().set(bb.bytes(), new_buf_size - old_buf_size);
  return nbb;
};
/// @endcond

/**
 * Adds on offset, relative to where it will be written.
 *
 * @param {flatbuffers.Offset} offset The offset to add.
 */
flatbuffers.Builder.prototype.addOffset = function(offset) {
  this.prep(flatbuffers.SIZEOF_INT, 0); // Ensure alignment is already done.
  this.writeInt32(this.offset() - offset + flatbuffers.SIZEOF_INT);
};

/// @cond FLATBUFFERS_INTERNAL
/**
 * Start encoding a new object in the buffer.  Users will not usually need to
 * call this directly. The FlatBuffers compiler will generate helper methods
 * that call this method internally.
 *
 * @param {number} numfields
 */
flatbuffers.Builder.prototype.startObject = function(numfields) {
  this.notNested();
  if (this.vtable == null) {
    this.vtable = [];
  }
  this.vtable_in_use = numfields;
  for (var i = 0; i < numfields; i++) {
    this.vtable[i] = 0; // This will push additional elements as needed
  }
  this.isNested = true;
  this.object_start = this.offset();
};

/**
 * Finish off writing the object that is under construction.
 *
 * @returns {flatbuffers.Offset} The offset to the object inside `dataBuffer`
 */
flatbuffers.Builder.prototype.endObject = function() {
  if (this.vtable == null || !this.isNested) {
    throw new Error('FlatBuffers: endObject called without startObject');
  }

  this.addInt32(0);
  var vtableloc = this.offset();

  // Trim trailing zeroes.
  var i = this.vtable_in_use - 1;
  for (; i >= 0 && this.vtable[i] == 0; i--) {}
  var trimmed_size = i + 1;

  // Write out the current vtable.
  for (; i >= 0; i--) {
    // Offset relative to the start of the table.
    this.addInt16(this.vtable[i] != 0 ? vtableloc - this.vtable[i] : 0);
  }

  var standard_fields = 2; // The fields below:
  this.addInt16(vtableloc - this.object_start);
  var len = (trimmed_size + standard_fields) * flatbuffers.SIZEOF_SHORT;
  this.addInt16(len);

  // Search for an existing vtable that matches the current one.
  var existing_vtable = 0;
  var vt1 = this.space;
outer_loop:
  for (i = 0; i < this.vtables.length; i++) {
    var vt2 = this.bb.capacity() - this.vtables[i];
    if (len == this.bb.readInt16(vt2)) {
      for (var j = flatbuffers.SIZEOF_SHORT; j < len; j += flatbuffers.SIZEOF_SHORT) {
        if (this.bb.readInt16(vt1 + j) != this.bb.readInt16(vt2 + j)) {
          continue outer_loop;
        }
      }
      existing_vtable = this.vtables[i];
      break;
    }
  }

  if (existing_vtable) {
    // Found a match:
    // Remove the current vtable.
    this.space = this.bb.capacity() - vtableloc;

    // Point table to existing vtable.
    this.bb.writeInt32(this.space, existing_vtable - vtableloc);
  } else {
    // No match:
    // Add the location of the current vtable to the list of vtables.
    this.vtables.push(this.offset());

    // Point table to current vtable.
    this.bb.writeInt32(this.bb.capacity() - vtableloc, this.offset() - vtableloc);
  }

  this.isNested = false;
  return vtableloc;
};
/// @endcond

/**
 * Finalize a buffer, poiting to the given `root_table`.
 *
 * @param {flatbuffers.Offset} root_table
 * @param {string=} opt_file_identifier
 * @param {boolean=} opt_size_prefix
 */
flatbuffers.Builder.prototype.finish = function(root_table, opt_file_identifier, opt_size_prefix) {
  var size_prefix = opt_size_prefix ? flatbuffers.SIZE_PREFIX_LENGTH : 0;
  if (opt_file_identifier) {
    var file_identifier = opt_file_identifier;
    this.prep(this.minalign, flatbuffers.SIZEOF_INT +
      flatbuffers.FILE_IDENTIFIER_LENGTH + size_prefix);
    if (file_identifier.length != flatbuffers.FILE_IDENTIFIER_LENGTH) {
      throw new Error('FlatBuffers: file identifier must be length ' +
        flatbuffers.FILE_IDENTIFIER_LENGTH);
    }
    for (var i = flatbuffers.FILE_IDENTIFIER_LENGTH - 1; i >= 0; i--) {
      this.writeInt8(file_identifier.charCodeAt(i));
    }
  }
  this.prep(this.minalign, flatbuffers.SIZEOF_INT + size_prefix);
  this.addOffset(root_table);
  if (size_prefix) {
    this.addInt32(this.bb.capacity() - this.space);
  }
  this.bb.setPosition(this.space);
};

/**
 * Finalize a size prefixed buffer, pointing to the given `root_table`.
 *
 * @param {flatbuffers.Offset} root_table
 * @param {string=} opt_file_identifier
 */
flatbuffers.Builder.prototype.finishSizePrefixed = function (root_table, opt_file_identifier) {
  this.finish(root_table, opt_file_identifier, true);
};

/// @cond FLATBUFFERS_INTERNAL
/**
 * This checks a required field has been set in a given table that has
 * just been constructed.
 *
 * @param {flatbuffers.Offset} table
 * @param {number} field
 */
flatbuffers.Builder.prototype.requiredField = function(table, field) {
  var table_start = this.bb.capacity() - table;
  var vtable_start = table_start - this.bb.readInt32(table_start);
  var ok = this.bb.readInt16(vtable_start + field) != 0;

  // If this fails, the caller will show what field needs to be set.
  if (!ok) {
    throw new Error('FlatBuffers: field ' + field + ' must be set');
  }
};

/**
 * Start a new array/vector of objects.  Users usually will not call
 * this directly. The FlatBuffers compiler will create a start/end
 * method for vector types in generated code.
 *
 * @param {number} elem_size The size of each element in the array
 * @param {number} num_elems The number of elements in the array
 * @param {number} alignment The alignment of the array
 */
flatbuffers.Builder.prototype.startVector = function(elem_size, num_elems, alignment) {
  this.notNested();
  this.vector_num_elems = num_elems;
  this.prep(flatbuffers.SIZEOF_INT, elem_size * num_elems);
  this.prep(alignment, elem_size * num_elems); // Just in case alignment > int.
};

/**
 * Finish off the creation of an array and all its elements. The array must be
 * created with `startVector`.
 *
 * @returns {flatbuffers.Offset} The offset at which the newly created array
 * starts.
 */
flatbuffers.Builder.prototype.endVector = function() {
  this.writeInt32(this.vector_num_elems);
  return this.offset();
};
/// @endcond

/**
 * Encode the string `s` in the buffer using UTF-8. If a Uint8Array is passed
 * instead of a string, it is assumed to contain valid UTF-8 encoded data.
 *
 * @param {string|Uint8Array} s The string to encode
 * @return {flatbuffers.Offset} The offset in the buffer where the encoded string starts
 */
flatbuffers.Builder.prototype.createString = function(s) {
  if (s instanceof Uint8Array) {
    var utf8 = s;
  } else {
    var utf8 = [];
    var i = 0;

    while (i < s.length) {
      var codePoint;

      // Decode UTF-16
      var a = s.charCodeAt(i++);
      if (a < 0xD800 || a >= 0xDC00) {
        codePoint = a;
      } else {
        var b = s.charCodeAt(i++);
        codePoint = (a << 10) + b + (0x10000 - (0xD800 << 10) - 0xDC00);
      }

      // Encode UTF-8
      if (codePoint < 0x80) {
        utf8.push(codePoint);
      } else {
        if (codePoint < 0x800) {
          utf8.push(((codePoint >> 6) & 0x1F) | 0xC0);
        } else {
          if (codePoint < 0x10000) {
            utf8.push(((codePoint >> 12) & 0x0F) | 0xE0);
          } else {
            utf8.push(
              ((codePoint >> 18) & 0x07) | 0xF0,
              ((codePoint >> 12) & 0x3F) | 0x80);
          }
          utf8.push(((codePoint >> 6) & 0x3F) | 0x80);
        }
        utf8.push((codePoint & 0x3F) | 0x80);
      }
    }
  }

  this.addInt8(0);
  this.startVector(1, utf8.length, 1);
  this.bb.setPosition(this.space -= utf8.length);
  for (var i = 0, offset = this.space, bytes = this.bb.bytes(); i < utf8.length; i++) {
    bytes[offset++] = utf8[i];
  }
  return this.endVector();
};

/**
 * A helper function to avoid generated code depending on this file directly.
 *
 * @param {number} low
 * @param {number} high
 * @returns {!flatbuffers.Long}
 */
flatbuffers.Builder.prototype.createLong = function(low, high) {
  return flatbuffers.Long.create(low, high);
};

/**
 * A helper function to pack an object
 *
 * @returns offset of obj
 */
flatbuffers.Builder.prototype.createObjectOffset = function(obj) {
  if(obj === null) {
    return 0
  }

  if(typeof obj === 'string') {
    return this.createString(obj);
  } else {
    return obj.pack(this);
  }
}

/**
 * A helper function to pack a list of object
 *
 * @returns list of offsets of each non null object
 */
flatbuffers.Builder.prototype.createObjectOffsetList = function(list) {
  let ret = [];

  for(let i = 0; i < list.length; ++i) {
    let val = list[i];

    if(val !== null) {
      ret.push(this.createObjectOffset(val));
    } else {
      throw new Error(
        'FlatBuffers: Argument for createObjectOffsetList cannot contain null.');
    }
  }

  return ret;
};

flatbuffers.Builder.prototype.createStructOffsetList = function(list, startFunc) {
  startFunc(this, list.length);
  this.createObjectOffsetList(list);
  return this.endVector();
}

////////////////////////////////////////////////////////////////////////////////
/// @cond FLATBUFFERS_INTERNAL
/**
 * Create a new ByteBuffer with a given array of bytes (`Uint8Array`).
 *
 * @constructor
 * @param {Uint8Array} bytes
 */
flatbuffers.ByteBuffer = function(bytes) {
  /**
   * @type {Uint8Array}
   * @private
   */
  this.bytes_ = bytes;

  /**
   * @type {number}
   * @private
   */
  this.position_ = 0;
};

/**
 * Create and allocate a new ByteBuffer with a given size.
 *
 * @param {number} byte_size
 * @returns {!flatbuffers.ByteBuffer}
 */
flatbuffers.ByteBuffer.allocate = function(byte_size) {
  return new flatbuffers.ByteBuffer(new Uint8Array(byte_size));
};

flatbuffers.ByteBuffer.prototype.clear = function() {
  this.position_ = 0;
};

/**
 * Get the underlying `Uint8Array`.
 *
 * @returns {Uint8Array}
 */
flatbuffers.ByteBuffer.prototype.bytes = function() {
  return this.bytes_;
};

/**
 * Get the buffer's position.
 *
 * @returns {number}
 */
flatbuffers.ByteBuffer.prototype.position = function() {
  return this.position_;
};

/**
 * Set the buffer's position.
 *
 * @param {number} position
 */
flatbuffers.ByteBuffer.prototype.setPosition = function(position) {
  this.position_ = position;
};

/**
 * Get the buffer's capacity.
 *
 * @returns {number}
 */
flatbuffers.ByteBuffer.prototype.capacity = function() {
  return this.bytes_.length;
};

/**
 * @param {number} offset
 * @returns {number}
 */
flatbuffers.ByteBuffer.prototype.readInt8 = function(offset) {
  return this.readUint8(offset) << 24 >> 24;
};

/**
 * @param {number} offset
 * @returns {number}
 */
flatbuffers.ByteBuffer.prototype.readUint8 = function(offset) {
  return this.bytes_[offset];
};

/**
 * @param {number} offset
 * @returns {number}
 */
flatbuffers.ByteBuffer.prototype.readInt16 = function(offset) {
  return this.readUint16(offset) << 16 >> 16;
};

/**
 * @param {number} offset
 * @returns {number}
 */
flatbuffers.ByteBuffer.prototype.readUint16 = function(offset) {
  return this.bytes_[offset] | this.bytes_[offset + 1] << 8;
};

/**
 * @param {number} offset
 * @returns {number}
 */
flatbuffers.ByteBuffer.prototype.readInt32 = function(offset) {
  return this.bytes_[offset] | this.bytes_[offset + 1] << 8 | this.bytes_[offset + 2] << 16 | this.bytes_[offset + 3] << 24;
};

/**
 * @param {number} offset
 * @returns {number}
 */
flatbuffers.ByteBuffer.prototype.readUint32 = function(offset) {
  return this.readInt32(offset) >>> 0;
};

/**
 * @param {number} offset
 * @returns {!flatbuffers.Long}
 */
flatbuffers.ByteBuffer.prototype.readInt64 = function(offset) {
  return new flatbuffers.Long(this.readInt32(offset), this.readInt32(offset + 4));
};

/**
 * @param {number} offset
 * @returns {!flatbuffers.Long}
 */
flatbuffers.ByteBuffer.prototype.readUint64 = function(offset) {
  return new flatbuffers.Long(this.readUint32(offset), this.readUint32(offset + 4));
};

/**
 * @param {number} offset
 * @returns {number}
 */
flatbuffers.ByteBuffer.prototype.readFloat32 = function(offset) {
  flatbuffers.int32[0] = this.readInt32(offset);
  return flatbuffers.float32[0];
};

/**
 * @param {number} offset
 * @returns {number}
 */
flatbuffers.ByteBuffer.prototype.readFloat64 = function(offset) {
  flatbuffers.int32[flatbuffers.isLittleEndian ? 0 : 1] = this.readInt32(offset);
  flatbuffers.int32[flatbuffers.isLittleEndian ? 1 : 0] = this.readInt32(offset + 4);
  return flatbuffers.float64[0];
};

/**
 * @param {number} offset
 * @param {number|boolean} value
 */
flatbuffers.ByteBuffer.prototype.writeInt8 = function(offset, value) {
  this.bytes_[offset] = /** @type {number} */(value);
};

/**
 * @param {number} offset
 * @param {number} value
 */
flatbuffers.ByteBuffer.prototype.writeUint8 = function(offset, value) {
  this.bytes_[offset] = value;
};

/**
 * @param {number} offset
 * @param {number} value
 */
flatbuffers.ByteBuffer.prototype.writeInt16 = function(offset, value) {
  this.bytes_[offset] = value;
  this.bytes_[offset + 1] = value >> 8;
};

/**
 * @param {number} offset
 * @param {number} value
 */
flatbuffers.ByteBuffer.prototype.writeUint16 = function(offset, value) {
    this.bytes_[offset] = value;
    this.bytes_[offset + 1] = value >> 8;
};

/**
 * @param {number} offset
 * @param {number} value
 */
flatbuffers.ByteBuffer.prototype.writeInt32 = function(offset, value) {
  this.bytes_[offset] = value;
  this.bytes_[offset + 1] = value >> 8;
  this.bytes_[offset + 2] = value >> 16;
  this.bytes_[offset + 3] = value >> 24;
};

/**
 * @param {number} offset
 * @param {number} value
 */
flatbuffers.ByteBuffer.prototype.writeUint32 = function(offset, value) {
    this.bytes_[offset] = value;
    this.bytes_[offset + 1] = value >> 8;
    this.bytes_[offset + 2] = value >> 16;
    this.bytes_[offset + 3] = value >> 24;
};

/**
 * @param {number} offset
 * @param {flatbuffers.Long} value
 */
flatbuffers.ByteBuffer.prototype.writeInt64 = function(offset, value) {
  this.writeInt32(offset, value.low);
  this.writeInt32(offset + 4, value.high);
};

/**
 * @param {number} offset
 * @param {flatbuffers.Long} value
 */
flatbuffers.ByteBuffer.prototype.writeUint64 = function(offset, value) {
    this.writeUint32(offset, value.low);
    this.writeUint32(offset + 4, value.high);
};

/**
 * @param {number} offset
 * @param {number} value
 */
flatbuffers.ByteBuffer.prototype.writeFloat32 = function(offset, value) {
  flatbuffers.float32[0] = value;
  this.writeInt32(offset, flatbuffers.int32[0]);
};

/**
 * @param {number} offset
 * @param {number} value
 */
flatbuffers.ByteBuffer.prototype.writeFloat64 = function(offset, value) {
  flatbuffers.float64[0] = value;
  this.writeInt32(offset, flatbuffers.int32[flatbuffers.isLittleEndian ? 0 : 1]);
  this.writeInt32(offset + 4, flatbuffers.int32[flatbuffers.isLittleEndian ? 1 : 0]);
};

/**
 * Return the file identifier.   Behavior is undefined for FlatBuffers whose
 * schema does not include a file_identifier (likely points at padding or the
 * start of a the root vtable).
 * @returns {string}
 */
flatbuffers.ByteBuffer.prototype.getBufferIdentifier = function() {
  if (this.bytes_.length < this.position_ + flatbuffers.SIZEOF_INT +
      flatbuffers.FILE_IDENTIFIER_LENGTH) {
    throw new Error(
        'FlatBuffers: ByteBuffer is too short to contain an identifier.');
  }
  var result = "";
  for (var i = 0; i < flatbuffers.FILE_IDENTIFIER_LENGTH; i++) {
    result += String.fromCharCode(
        this.readInt8(this.position_ + flatbuffers.SIZEOF_INT + i));
  }
  return result;
};

/**
 * Look up a field in the vtable, return an offset into the object, or 0 if the
 * field is not present.
 *
 * @param {number} bb_pos
 * @param {number} vtable_offset
 * @returns {number}
 */
flatbuffers.ByteBuffer.prototype.__offset = function(bb_pos, vtable_offset) {
  var vtable = bb_pos - this.readInt32(bb_pos);
  return vtable_offset < this.readInt16(vtable) ? this.readInt16(vtable + vtable_offset) : 0;
};

/**
 * Initialize any Table-derived type to point to the union at the given offset.
 *
 * @param {flatbuffers.Table} t
 * @param {number} offset
 * @returns {flatbuffers.Table}
 */
flatbuffers.ByteBuffer.prototype.__union = function(t, offset) {
  t.bb_pos = offset + this.readInt32(offset);
  t.bb = this;
  return t;
};

/**
 * Create a JavaScript string from UTF-8 data stored inside the FlatBuffer.
 * This allocates a new string and converts to wide chars upon each access.
 *
 * To avoid the conversion to UTF-16, pass flatbuffers.Encoding.UTF8_BYTES as
 * the "optionalEncoding" argument. This is useful for avoiding conversion to
 * and from UTF-16 when the data will just be packaged back up in another
 * FlatBuffer later on.
 *
 * @param {number} offset
 * @param {flatbuffers.Encoding=} opt_encoding Defaults to UTF16_STRING
 * @returns {string|!Uint8Array}
 */
flatbuffers.ByteBuffer.prototype.__string = function(offset, opt_encoding) {
  offset += this.readInt32(offset);

  var length = this.readInt32(offset);
  var result = '';
  var i = 0;

  offset += flatbuffers.SIZEOF_INT;

  if (opt_encoding === flatbuffers.Encoding.UTF8_BYTES) {
    return this.bytes_.subarray(offset, offset + length);
  }

  while (i < length) {
    var codePoint;

    // Decode UTF-8
    var a = this.readUint8(offset + i++);
    if (a < 0xC0) {
      codePoint = a;
    } else {
      var b = this.readUint8(offset + i++);
      if (a < 0xE0) {
        codePoint =
          ((a & 0x1F) << 6) |
          (b & 0x3F);
      } else {
        var c = this.readUint8(offset + i++);
        if (a < 0xF0) {
          codePoint =
            ((a & 0x0F) << 12) |
            ((b & 0x3F) << 6) |
            (c & 0x3F);
        } else {
          var d = this.readUint8(offset + i++);
          codePoint =
            ((a & 0x07) << 18) |
            ((b & 0x3F) << 12) |
            ((c & 0x3F) << 6) |
            (d & 0x3F);
        }
      }
    }

    // Encode UTF-16
    if (codePoint < 0x10000) {
      result += String.fromCharCode(codePoint);
    } else {
      codePoint -= 0x10000;
      result += String.fromCharCode(
        (codePoint >> 10) + 0xD800,
        (codePoint & ((1 << 10) - 1)) + 0xDC00);
    }
  }

  return result;
};

/**
 * Handle unions that can contain string as its member, if a Table-derived type then initialize it,
 * if a string then return a new one
 *
 * WARNING: strings are immutable in JS so we can't change the string that the user gave us, this
 * makes the behaviour of __union_with_string different compared to __union
 *
 * @param {flatbuffers.Table|string} o
 * @param {number} offset
 * @returns {flatbuffers.Table|string}
 */
flatbuffers.ByteBuffer.prototype.__union_with_string = function(o, offset) {
  if(typeof o === 'string') {
    return this.__string(offset);
  }
  return this.__union(o, offset);
};

/**
 * Retrieve the relative offset stored at "offset"
 * @param {number} offset
 * @returns {number}
 */
flatbuffers.ByteBuffer.prototype.__indirect = function(offset) {
  return offset + this.readInt32(offset);
};

/**
 * Get the start of data of a vector whose offset is stored at "offset" in this object.
 *
 * @param {number} offset
 * @returns {number}
 */
flatbuffers.ByteBuffer.prototype.__vector = function(offset) {
  return offset + this.readInt32(offset) + flatbuffers.SIZEOF_INT; // data starts after the length
};

/**
 * Get the length of a vector whose offset is stored at "offset" in this object.
 *
 * @param {number} offset
 * @returns {number}
 */
flatbuffers.ByteBuffer.prototype.__vector_len = function(offset) {
  return this.readInt32(offset + this.readInt32(offset));
};

/**
 * @param {string} ident
 * @returns {boolean}
 */
flatbuffers.ByteBuffer.prototype.__has_identifier = function(ident) {
  if (ident.length != flatbuffers.FILE_IDENTIFIER_LENGTH) {
    throw new Error('FlatBuffers: file identifier must be length ' +
                    flatbuffers.FILE_IDENTIFIER_LENGTH);
  }
  for (var i = 0; i < flatbuffers.FILE_IDENTIFIER_LENGTH; i++) {
    if (ident.charCodeAt(i) != this.readInt8(this.position_ + flatbuffers.SIZEOF_INT + i)) {
      return false;
    }
  }
  return true;
};

/**
 * A helper function to avoid generated code depending on this file directly.
 *
 * @param {number} low
 * @param {number} high
 * @returns {!flatbuffers.Long}
 */
flatbuffers.ByteBuffer.prototype.createLong = function(low, high) {
  return flatbuffers.Long.create(low, high);
};

/**
 * A helper function for generating list for obj api
 * @param listAccessor function that accepts an index and return data at that index
 * @param {number} listLength
 * @returns {any[]}
 */
flatbuffers.ByteBuffer.prototype.createScalarList = function(listAccessor, listLength) {
  let ret = [];
  for(let i = 0; i < listLength; ++i) {
    if(listAccessor(i) !== null) {
      ret.push(listAccessor(i));
    }
  }

  return ret;
};

/**
 * This function is here only to get around typescript type system
 */
flatbuffers.ByteBuffer.prototype.createStringList = function(listAccessor, listLength) {
  return this.createScalarList(listAccessor, listLength);
};

/**
 * A helper function for generating list for obj api
 * @param listAccessor function that accepts an index and return data at that index
 * @param listLength {number} listLength
 * @param res any[] result list
 */
flatbuffers.ByteBuffer.prototype.createObjList = function(listAccessor, listLength) {
  let ret = [];
  for(let i = 0; i < listLength; ++i) {
    let val = listAccessor(i);
    if(val !== null) {
      ret.push(val.unpack());
    }
  }

  return ret;
};

// Exports for Node.js and RequireJS
this.flatbuffers = flatbuffers;

/// @endcond
/// @}
</script>
<!-- END flatbuffers.js --->
)END";

/**
 * The FlatBuffers generated JavaScript interface for the
 * camera settings user interface.
 *
 * @return JavaScript
 */
const std::string html_css_js_util::motion_camera_settings_generated_js = R"END(
<!-- BEGIN motion_camera_settings_generated.js --->
<script type="text/javascript">
// automatically generated by the FlatBuffers compiler, do not modify

/**
 * @const
 * @namespace
 */
var OV5642_Settings = OV5642_Settings || {};

/**
 * @constructor
 */
OV5642_Settings.Settings = function() {
  /**
   * @type {flatbuffers.ByteBuffer}
   */
  this.bb = null;

  /**
   * @type {number}
   */
  this.bb_pos = 0;
};

/**
 * @param {number} i
 * @param {flatbuffers.ByteBuffer} bb
 * @returns {OV5642_Settings.Settings}
 */
OV5642_Settings.Settings.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {OV5642_Settings.Settings=} obj
 * @returns {OV5642_Settings.Settings}
 */
OV5642_Settings.Settings.getRootAsSettings = function(bb, obj) {
  return (obj || new OV5642_Settings.Settings).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {OV5642_Settings.Settings=} obj
 * @returns {OV5642_Settings.Settings}
 */
OV5642_Settings.Settings.getSizePrefixedRootAsSettings = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new OV5642_Settings.Settings).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @returns {number}
 */
OV5642_Settings.Settings.prototype.jpegSize = function() {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? this.bb.readUint8(this.bb_pos + offset) : 0;
};

/**
 * @returns {number}
 */
OV5642_Settings.Settings.prototype.quality = function() {
  var offset = this.bb.__offset(this.bb_pos, 6);
  return offset ? this.bb.readUint8(this.bb_pos + offset) : 0;
};

/**
 * @returns {number}
 */
OV5642_Settings.Settings.prototype.frames = function() {
  var offset = this.bb.__offset(this.bb_pos, 8);
  return offset ? this.bb.readUint8(this.bb_pos + offset) : 0;
};

/**
 * @returns {number}
 */
OV5642_Settings.Settings.prototype.lightMode = function() {
  var offset = this.bb.__offset(this.bb_pos, 10);
  return offset ? this.bb.readUint8(this.bb_pos + offset) : 0;
};

/**
 * @returns {number}
 */
OV5642_Settings.Settings.prototype.colorSaturation = function() {
  var offset = this.bb.__offset(this.bb_pos, 12);
  return offset ? this.bb.readUint8(this.bb_pos + offset) : 0;
};

/**
 * @returns {number}
 */
OV5642_Settings.Settings.prototype.brightness = function() {
  var offset = this.bb.__offset(this.bb_pos, 14);
  return offset ? this.bb.readUint8(this.bb_pos + offset) : 0;
};

/**
 * @returns {number}
 */
OV5642_Settings.Settings.prototype.contrast = function() {
  var offset = this.bb.__offset(this.bb_pos, 16);
  return offset ? this.bb.readUint8(this.bb_pos + offset) : 0;
};

/**
 * @returns {number}
 */
OV5642_Settings.Settings.prototype.hue = function() {
  var offset = this.bb.__offset(this.bb_pos, 18);
  return offset ? this.bb.readUint8(this.bb_pos + offset) : 0;
};

/**
 * @returns {number}
 */
OV5642_Settings.Settings.prototype.effect = function() {
  var offset = this.bb.__offset(this.bb_pos, 20);
  return offset ? this.bb.readUint8(this.bb_pos + offset) : 0;
};

/**
 * @returns {number}
 */
OV5642_Settings.Settings.prototype.exposure = function() {
  var offset = this.bb.__offset(this.bb_pos, 22);
  return offset ? this.bb.readUint8(this.bb_pos + offset) : 0;
};

/**
 * @returns {number}
 */
OV5642_Settings.Settings.prototype.sharpness = function() {
  var offset = this.bb.__offset(this.bb_pos, 24);
  return offset ? this.bb.readUint8(this.bb_pos + offset) : 0;
};

/**
 * @returns {number}
 */
OV5642_Settings.Settings.prototype.mirror = function() {
  var offset = this.bb.__offset(this.bb_pos, 26);
  return offset ? this.bb.readUint8(this.bb_pos + offset) : 0;
};

/**
 * @returns {number}
 */
OV5642_Settings.Settings.prototype.testPattern = function() {
  var offset = this.bb.__offset(this.bb_pos, 28);
  return offset ? this.bb.readUint8(this.bb_pos + offset) : 0;
};

/**
 * @param {flatbuffers.Builder} builder
 */
OV5642_Settings.Settings.startSettings = function(builder) {
  builder.startObject(13);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} jpegSize
 */
OV5642_Settings.Settings.addJpegSize = function(builder, jpegSize) {
  builder.addFieldInt8(0, jpegSize, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} quality
 */
OV5642_Settings.Settings.addQuality = function(builder, quality) {
  builder.addFieldInt8(1, quality, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} frames
 */
OV5642_Settings.Settings.addFrames = function(builder, frames) {
  builder.addFieldInt8(2, frames, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} lightMode
 */
OV5642_Settings.Settings.addLightMode = function(builder, lightMode) {
  builder.addFieldInt8(3, lightMode, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} colorSaturation
 */
OV5642_Settings.Settings.addColorSaturation = function(builder, colorSaturation) {
  builder.addFieldInt8(4, colorSaturation, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} brightness
 */
OV5642_Settings.Settings.addBrightness = function(builder, brightness) {
  builder.addFieldInt8(5, brightness, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} contrast
 */
OV5642_Settings.Settings.addContrast = function(builder, contrast) {
  builder.addFieldInt8(6, contrast, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} hue
 */
OV5642_Settings.Settings.addHue = function(builder, hue) {
  builder.addFieldInt8(7, hue, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} effect
 */
OV5642_Settings.Settings.addEffect = function(builder, effect) {
  builder.addFieldInt8(8, effect, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} exposure
 */
OV5642_Settings.Settings.addExposure = function(builder, exposure) {
  builder.addFieldInt8(9, exposure, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} sharpness
 */
OV5642_Settings.Settings.addSharpness = function(builder, sharpness) {
  builder.addFieldInt8(10, sharpness, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} mirror
 */
OV5642_Settings.Settings.addMirror = function(builder, mirror) {
  builder.addFieldInt8(11, mirror, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} testPattern
 */
OV5642_Settings.Settings.addTestPattern = function(builder, testPattern) {
  builder.addFieldInt8(12, testPattern, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
OV5642_Settings.Settings.endSettings = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} offset
 */
OV5642_Settings.Settings.finishSettingsBuffer = function(builder, offset) {
  builder.finish(offset);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} offset
 */
OV5642_Settings.Settings.finishSizePrefixedSettingsBuffer = function(builder, offset) {
  builder.finish(offset, undefined, true);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} jpegSize
 * @param {number} quality
 * @param {number} frames
 * @param {number} lightMode
 * @param {number} colorSaturation
 * @param {number} brightness
 * @param {number} contrast
 * @param {number} hue
 * @param {number} effect
 * @param {number} exposure
 * @param {number} sharpness
 * @param {number} mirror
 * @param {number} testPattern
 * @returns {flatbuffers.Offset}
 */
OV5642_Settings.Settings.createSettings = function(builder, jpegSize, quality, frames, lightMode, colorSaturation, brightness, contrast, hue, effect, exposure, sharpness, mirror, testPattern) {
  OV5642_Settings.Settings.startSettings(builder);
  OV5642_Settings.Settings.addJpegSize(builder, jpegSize);
  OV5642_Settings.Settings.addQuality(builder, quality);
  OV5642_Settings.Settings.addFrames(builder, frames);
  OV5642_Settings.Settings.addLightMode(builder, lightMode);
  OV5642_Settings.Settings.addColorSaturation(builder, colorSaturation);
  OV5642_Settings.Settings.addBrightness(builder, brightness);
  OV5642_Settings.Settings.addContrast(builder, contrast);
  OV5642_Settings.Settings.addHue(builder, hue);
  OV5642_Settings.Settings.addEffect(builder, effect);
  OV5642_Settings.Settings.addExposure(builder, exposure);
  OV5642_Settings.Settings.addSharpness(builder, sharpness);
  OV5642_Settings.Settings.addMirror(builder, mirror);
  OV5642_Settings.Settings.addTestPattern(builder, testPattern);
  return OV5642_Settings.Settings.endSettings(builder);
}

// Exports for Node.js and RequireJS
this.OV5642_Settings = OV5642_Settings;

</script>
<!-- END motion_camera_settings_generated.js --->
)END";

/**
 * The JavaScript on-load event handler for the camera settings user interface.
 *
 * @param request_server_addr The IP address of the WebSocket server in IPv4
 * dotted-quad notation.
 * @return JavaScript
 */
std::string html_css_js_util::on_load_js(std::basic_string<char> &request_server_addr) {
    std::string script = R"END(
<!-- BEGIN on_load.js --->
    <script>
    var wsUrl = "ws://)END";
    script.append(request_server_addr);
    script.append(R"END(/ws";)END");
    script.append(R"END(
    window.addEventListener('load', (event) => {
        if (!"WebSocket" in window) {
            alert("This browser does not support WebSockets.");
        } else {
            const options = document.querySelectorAll('div.feature > div.option');
            for (const option of options) {
                option.addEventListener('click', function (event) {
                    const key = event.target.id.substring(0, event.target.id.lastIndexOf('_'));
                    const value = event.target.id.substring(event.target.id.lastIndexOf('_') + 1);
                    cameraSettings.optionOnOff(key, event.target.id);
                    cameraSettings[key] = value;
                });
            }
            document.getElementById("save").addEventListener('click', function (event) {
                event.target.classList.add("on");
                cameraSettings.save();
                setTimeout(function () {
                    event.target.classList.remove("on");},
                    2000
                );
                var ws = new WebSocket(wsUrl);
                ws.binaryType = "arraybuffer";
                ws.onopen = function() {
                    ws.send(cameraSettings.newBuffer);
                    ws.close();
                };
                ws.onerror = function(event) {
                    console.error("WebSocket error observed:", event);
                };
            });
            document.getElementById("reset").addEventListener('click', function (event) {
                event.target.classList.add("on");
                cameraSettings.reset();
                setTimeout(function () {
                    event.target.classList.remove("on");},
                    2000
                );
            });
            document.getElementById("new").addEventListener('click', function (event) {
                event.target.classList.add("on");
                cameraSettings.new();
                setTimeout(function () {
                    event.target.classList.remove("on");},
                    2000
                );
            });
        }
        var ws = new WebSocket(wsUrl);
        ws.onopen = function() {
            ws.send("getDefault");
        };
        ws.onmessage = function(evt) {
            var eventUint8Array  = null;
            var eventArrayBuffer = null;
            var fileReader       = new FileReader();
            fileReader.onload    = function(event) {
                eventArrayBuffer = event.target.result;
                eventUint8Array  = new Uint8Array(eventArrayBuffer);
                buf = new flatbuffers.ByteBuffer(eventUint8Array);
                var settings = OV5642_Settings.Settings.getRootAsSettings(buf);
                cameraSettings.init(settings);
            };
            fileReader.readAsArrayBuffer(evt.data);
            ws.close();
        };
        ws.onerror = function(event) {
            console.error("WebSocket error observed:", event);
        };
    });
    </script>
<!-- END on_load.js --->
)END");
    return script;
}

/**
 * The HTML head for the camera settings user interface.
 *
 * @return HTML
 */
const std::string html_css_js_util::page_head_html = R"END(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>OV5642 Settings</title>)END";

/**
 * The code entry point for rendering the fully composed web-page as a string.
 *
 * @param request_server_addr The IP address of the WebSocket server in IPv4
 * dotted-quad notation.
 * @return HTML, CSS, and JavaScript
 */
std::string html_css_js_util::render(std::basic_string<char> request_server_addr) {
    std::string page{page_head_html};
    page.append(flat_buffers_js);
    page.append(motion_camera_settings_generated_js);
    page.append(camera_settings_js);
    page.append("</head>");
    page.append(css);
    page.append(body_html);
    page.append(on_load_js(request_server_addr));
    page.append("</body>");
    page.append("</html>");
    return page;
};

/**
 * The CSS for the camera settings user interface.
 *
 * @return CSS
 */
const std::string html_css_js_util::css = R"END(
<style>
    body {
        font-family: "Noto Sans", Monospace, sans-serif;
        background-color: lightgrey;
    }
    div.feature {
        float: left;
        width: 100%;
    }
    div.option {
        float: left;
        margin: .5em .5em;
        border: 1px black solid;
        padding: .25em;
        border-radius: .4em;
        background-color: oldlace;
    }
    div.option:hover {
        cursor: pointer;
    }
    div.control {
        display: inline-block;
        width: 100%;
        text-align: center;
        margin: 3em 0;
    }
    div.center {
        display: inline-block;
    }
    @media only screen and (min-width: 320px) {
        h1 {
            text-align: center;
            font-size: 1.1em;
        }
        h2 {
            font-size: 0.85em;
        }
        div.feature {
            margin-bottom: 0.85em;
        }
        div.option {
            font-size: 0.75em;
        }
    }
    @media only screen and (min-width: 568px) {
        h1 {
            text-align: center;
            font-size: 1.1em;
        }
        h2 {
            font-size: 0.85em;
        }
        div.feature {
            margin-bottom: 0.85em;
        }
        div.option {
            font-size: 0.75em;
        }
    }
    @media only screen and (min-width: 740px) {
        h1 {
            text-align: center;
            font-size: 1.5em;
        }
        h2 {
            font-size: 1.1em;
        }
        div.feature {
            margin-bottom: 1.1em;
        }
        div.option {
            font-size: 0.9em;
        }
    }
    @media only screen and (min-width: 823px) {
        h1 {
            text-align: center;
            font-size: 1.4em;
        }
        h2 {
            font-size: 1.0em;
        }
        div.feature {
            margin-bottom: 1.0em;
        }
        div.option {
            font-size: 0.85em;
        }
    }
    @media only screen and (min-width: 1024px) {
        h1 {
            text-align: center;
            font-size: 1.5em;
        }
        h2 {
            font-size: 1.0em;
        }
        div.feature {
            margin-bottom: 0.8em;
        }
        div.option {
            font-size: 0.9em;
        }
    }
    @media only screen and (min-width: 1280px) {...}
    div.off {
        background-color: oldlace;
    }
    div.on {
        background-color: gold;
    }
</style>
)END";