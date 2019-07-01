/*
 * Copyright 2012, Gregg Tavares.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Gregg Tavares. nor the names of his
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


// Provides: createGLContext
function createGLContext() {
    var tag = document.createElement('canvas');
    document.body.appendChild(tag);
    tag.addEventListener('webglcontextlost', function(e) {
        var err_img = document.createElement('img');
        //TODO: make context lost graphic. sad mac but asleep
        err_img.setAttribute('src', 'context_lost.png');
        err_img.width = '100';
        err_img.height = '200';
        err_img.style.position = 'absolute';
        err_img.style.offsetLeft = '50%';
        err_img.style.offsetRight = '50%';
        err_img.style.marginLeft = '-50px';
        err_img.style.marginTop = '-100px';
        err_img.style.zIndex = '100';
        document.body.appendChild(err_img);
    });
    tag.addEventListener('webglcontextrestored', function() {
        window.location.reload();
    });

    var res = tag.getContext('webgl');
    if (!res) res = tag.getContext('experimental-webgl');
    if (!res) throw 'webgl not supported';
    res.canvas = tag;
    return res;

}

/**
   * Computes a 4-by-4 orthographic projection matrix given the coordinates of the
   * planes defining the axis-aligned, box-shaped viewing volume.  The matrix
   * generated sends that box to the unit box.  Note that although left and right
   * are x coordinates and bottom and top are y coordinates, near and far
   * are not z coordinates, but rather they are distances along the negative
   * z-axis.  We assume a unit box extending from -1 to 1 in the x and y
   * dimensions and from -1 to 1 in the z dimension.
   * @param {number} left The x coordinate of the left plane of the box.
   * @param {number} right The x coordinate of the right plane of the box.
   * @param {number} bottom The y coordinate of the bottom plane of the box.
   * @param {number} top The y coordinate of the right plane of the box.
   * @param {number} near The negative z coordinate of the near plane of the box.
   * @param {number} far The negative z coordinate of the far plane of the box.
   * @param {Matrix4} [dst] optional matrix to store result
   * @return {Matrix4} dst or a new matrix if none provided
   * @memberOf module:webgl-3d-math
   */

  // Provides: m4_orthographic
  function m4_orthographic(left, right, bottom, top, near, far, dst) {
    dst = dst || new Float32Array(16);

    dst[ 0] = 2 / (right - left);
    dst[ 1] = 0;
    dst[ 2] = 0;
    dst[ 3] = 0;
    dst[ 4] = 0;
    dst[ 5] = 2 / (top - bottom);
    dst[ 6] = 0;
    dst[ 7] = 0;
    dst[ 8] = 0;
    dst[ 9] = 0;
    dst[10] = 2 / (near - far);
    dst[11] = 0;
    dst[12] = (left + right) / (left - right);
    dst[13] = (bottom + top) / (bottom - top);
    dst[14] = (near + far) / (near - far);
    dst[15] = 1;

    return dst;
  }

// Provides: orthographicMat
// Requires: m4_orthographic
function orthographicMat(width, height) {
  return m4_orthographic(0, width, height, 0, -1, 0);
}

  /**
   * Mutliply by translation matrix.
   * @param {Matrix4} m matrix to multiply
   * @param {number} tx x translation.
   * @param {number} ty y translation.
   * @param {number} tz z translation.
   * @param {Matrix4} [dst] optional matrix to store result
   * @return {Matrix4} dst or a new matrix if none provided
   * @memberOf module:webgl-3d-math
   */
// Provides: m4_translate
function m4_translate(m, tx, ty, tz, dst) {
  // This is the optimized version of
  // return multiply(m, translation(tx, ty, tz), dst);
  dst = dst || new Float32Array(16);

  var m00 = m[0];
  var m01 = m[1];
  var m02 = m[2];
  var m03 = m[3];
  var m10 = m[1 * 4 + 0];
  var m11 = m[1 * 4 + 1];
  var m12 = m[1 * 4 + 2];
  var m13 = m[1 * 4 + 3];
  var m20 = m[2 * 4 + 0];
  var m21 = m[2 * 4 + 1];
  var m22 = m[2 * 4 + 2];
  var m23 = m[2 * 4 + 3];
  var m30 = m[3 * 4 + 0];
  var m31 = m[3 * 4 + 1];
  var m32 = m[3 * 4 + 2];
  var m33 = m[3 * 4 + 3];

  if (m !== dst) {
    dst[0] = m00;
    dst[1] = m01;
    dst[2] = m02;
    dst[3] = m03;
    dst[4] = m10;
    dst[5] = m11;
    dst[6] = m12;
    dst[7] = m13;
    dst[8] = m20;
    dst[9] = m21;
    dst[10] = m22;
    dst[11] = m23;
  }

  dst[12] = m00 * tx + m10 * ty + m20 * tz + m30;
  dst[13] = m01 * tx + m11 * ty + m21 * tz + m31;
  dst[14] = m02 * tx + m12 * ty + m22 * tz + m32;
  dst[15] = m03 * tx + m13 * ty + m23 * tz + m33;

  return dst;
}

// Provides: translateMat
// Requires: m4_translate
function translateMat(mat, x, y) {
  return function(w, h) {
    return m4_translate(mat(w, h), x, y, 0);
  };
}
 /**
   * Multiply by a scaling matrix
   * @param {Matrix4} m matrix to multiply
   * @param {number} sx x scale.
   * @param {number} sy y scale.
   * @param {number} sz z scale.
   * @param {Matrix4} [dst] optional matrix to store result
   * @return {Matrix4} dst or a new matrix if none provided
   * @memberOf module:webgl-3d-math
   */

// Provides: m4_scale
  function m4_scale(m, sx, sy, sz, dst) {
    // This is the optimized verison of
    // return multiply(m, scaling(sx, sy, sz), dst);
    dst = dst || new Float32Array(16);

    dst[ 0] = sx * m[0 * 4 + 0];
    dst[ 1] = sx * m[0 * 4 + 1];
    dst[ 2] = sx * m[0 * 4 + 2];
    dst[ 3] = sx * m[0 * 4 + 3];
    dst[ 4] = sy * m[1 * 4 + 0];
    dst[ 5] = sy * m[1 * 4 + 1];
    dst[ 6] = sy * m[1 * 4 + 2];
    dst[ 7] = sy * m[1 * 4 + 3];
    dst[ 8] = sz * m[2 * 4 + 0];
    dst[ 9] = sz * m[2 * 4 + 1];
    dst[10] = sz * m[2 * 4 + 2];
    dst[11] = sz * m[2 * 4 + 3];

    if (m !== dst) {
      dst[12] = m[12];
      dst[13] = m[13];
      dst[14] = m[14];
      dst[15] = m[15];
    }

    return dst;
  }

// Provides: scaleMat
// Requires: m4_scale
function scaleMat(mat, scaleX, scaleY) {
  return function(w, h) {
    return m4_scale(mat(w, h), scaleX, scaleY, 0);
  };
}
 /**
   * Multiply by an x rotation matrix
   * @param {Matrix4} m matrix to multiply
   * @param {number} angleInRadians amount to rotate
   * @param {Matrix4} [dst] optional matrix to store result
   * @return {Matrix4} dst or a new matrix if none provided
   * @memberOf module:webgl-3d-math
   */

// Provides: m4_xRotate
  function m4_xRotate(m, angleInRadians, dst) {
    // this is the optimized version of
    // return multiply(m, xRotation(angleInRadians), dst);
    dst = dst || new Float32Array(16);

    var m10 = m[4];
    var m11 = m[5];
    var m12 = m[6];
    var m13 = m[7];
    var m20 = m[8];
    var m21 = m[9];
    var m22 = m[10];
    var m23 = m[11];
    var c = Math.cos(angleInRadians);
    var s = Math.sin(angleInRadians);

    dst[4]  = c * m10 + s * m20;
    dst[5]  = c * m11 + s * m21;
    dst[6]  = c * m12 + s * m22;
    dst[7]  = c * m13 + s * m23;
    dst[8]  = c * m20 - s * m10;
    dst[9]  = c * m21 - s * m11;
    dst[10] = c * m22 - s * m12;
    dst[11] = c * m23 - s * m13;

    if (m !== dst) {
      dst[ 0] = m[ 0];
      dst[ 1] = m[ 1];
      dst[ 2] = m[ 2];
      dst[ 3] = m[ 3];
      dst[12] = m[12];
      dst[13] = m[13];
      dst[14] = m[14];
      dst[15] = m[15];
    }

    return dst;
  }

// Provides: rotateMat
// Requires: m4_xRotate
function rotateMat(mat, angleInRadians) {
  return function(w, h) {
    return m4_xRotate(mat(w, h), angleInRadians);
  };
}

/**
 * Creates and compiles a shader.
 *
 * @param {!WebGLRenderingContext} gl The WebGL Context.
 * @param {string} shaderSource The GLSL source code for the shader.
 * @param {number} shaderType The type of shader, VERTEX_SHADER or
 *     FRAGMENT_SHADER.
 * @return {!WebGLShader} The shader.
 */
// Provides: compileShader
function compileShader(gl, shaderSource, shaderType) {
    // Create the shader object
    var shader = gl.createShader(shaderType);
   
    // Set the shader source code.
    gl.shaderSource(shader, shaderSource);
   
    // Compile the shader
    gl.compileShader(shader);
   
    // Check if it compiled
    var success = gl.getShaderParameter(shader, gl.COMPILE_STATUS);
    if (!success) {
      // Something went wrong during compilation; get the error
      throw "could not compile shader: " + gl.getShaderInfoLog(shader) + '\n' + shaderSource;
    }
   
    return shader;
  }

  /**
 * Creates a program from 2 shaders.
 *
 * @param {!WebGLRenderingContext) gl The WebGL context.
 * @param {!WebGLShader} vertexShader A vertex shader.
 * @param {!WebGLShader} fragmentShader A fragment shader.
 * @return {!WebGLProgram} A program.
 */
// Provides: createProgram
function createProgram(gl, vertexShader, fragmentShader) {
  // create a program.
  var program = gl.createProgram();
 
  // attach the shaders.
  gl.attachShader(program, vertexShader);
  gl.attachShader(program, fragmentShader);
 
  // link the program.
  gl.linkProgram(program);
 
  // Check if it linked.
  var success = gl.getProgramParameter(program, gl.LINK_STATUS);
  if (!success) {
      // something went wrong with the link
      throw ("program filed to link:" + gl.getProgramInfoLog (program));
  }
 
  return program;
};

// Provides: compileShaders 
// Requires: compileShader
// Requires: createProgram
function compileShaders(gl, vertex_source, fragment_source) {
    var vertexShader = compileShader(gl, vertex_source, gl.VERTEX_SHADER);
    var fragmentShader = compileShader(gl, fragment_source, gl.FRAGMENT_SHADER);
    return createProgram(gl, vertexShader, fragmentShader);
}


// Provides: makeShader
// Requires: compileShaders
function makeShader(gl, vertex_source, fragment_source) {
  var vertexShaderHead =
      "attribute vec4 a_position;\n" + 
      "attribute vec2 a_texcoord;\n" + 
      
      "uniform mat4 u_matrix;\n" + 

      "varying vec2 v_texcoord;\n" + 

      "void main() {\n";

  var vertexShaderTail = "}";

  var fragmentShaderHead = 
      "precision mediump float;\n" + 
      "varying vec2 v_texcoord;\n" + 
      "uniform sampler2D u_texture;\n" + 
      "void main() { "

  var fragmentShaderTail = "}";
    var vertex_source_preamble;
    var vertex_source_body;
    if ((typeof vertex_source) === 'string') {
        vertex_source_preamble = '';
        vertex_source_body = vertex_source;
    } else {
        vertex_source_preamble = vertex_source[0];
        vertex_source_body = vertex_source[1];
    }
    var fragment_source_preamble;
    var fragment_source_body;
    if ((typeof fragment_source) === 'string') {
        fragment_source_preamble = '';
        fragment_source_body = fragment_source;
    } else {
        fragment_source_preamble = fragment_source[0];
        fragment_source_body = fragment_source[1];
    }
    var progn = compileShaders(gl, 
        vertex_source_preamble + vertexShaderHead + vertex_source + vertexShaderTail,
        fragment_source_preamble + fragmentShaderHead + fragment_source + fragmentShaderTail);
    return {
        program: progn,
        positionLocation: gl.getAttribLocation(progn, "a_position"),
        texcoordLocation: gl.getAttribLocation(progn, "a_texcoord"),
        matrixLocation: gl.getUniformLocation(progn, "u_matrix"),
        textureLocation: gl.getUniformLocation(progn, "u_texture")
    };
}

// Provides: vanillaTextureShader
// Requires: makeShader
function vanillaTextureShader(gl) {
    if (gl.__vanillaTextureShader) {
        return gl.__vanillaTextureShader;
    }
    var res = makeShader(gl, 
        "gl_Position = u_matrix * a_position;\n" +
        "v_texcoord = a_texcoord;\n",

        "gl_FragColor = texture2D(u_texture, v_texcoord);"
    );
    gl.__vanillaTextureShader = res;
    return res;
}


// Provides: renderCanvasTexture
function renderCanvasTexture(gl, width, height, renderFn) {
    var canvas = document.createElement('canvas');
    canvas.width = width;
    canvas.height = height;
    var ctx = canvas.getContext('2d');
    ctx.clearRect(0, 0, width, height); 
    renderFn(ctx);
    var tex = gl.createTexture();
    gl.bindTexture(gl.TEXTURE_2D, tex);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR);
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA,  gl.RGBA, gl.UNSIGNED_BYTE, canvas);
    return tex;
}

// Provides: textTexture
// Requires: renderCanvasTexture
function textTexture(gl, width, height, text, textSize, font, lineHeight, color, textAlign, textBaseline) {
    var textSize = textSize || 12;
    var lineHeight = lineHeight || textSize + 5;
    var font = font || 'sans-serif';
    var color = color || 'black';
    var textAlign = textAlign || 'left';
    var textBaseline = textBaseline || 'middle';
    var lines = text.split('\n');
    return renderCanvasTexture(gl, width, height, function(ctx){
        ctx.font = textSize + 'px ' + font;
        ctx.fillStyle = color;
        ctx.textAlign = textAlign;
        ctx.textBaseline = textBaseline;
        var lineWidths = [];
        var splitLines = [];
        for (var i=0; i < lines.length; i++) {
            var size = ctx.measureText(lines[i]);
            if (size > width) {
                var words = lines[i].split(/\s+/);
                var totalWordSize = 0;
                var rangeStart = 0;
                for (var j=0; j < words.length; j++) {
                    var wordSize = ctx.measureText(words[i]);
                    if ((totalWordSize + wordSize) > width) {
                        splitLines.push(words.slice(rangeStart, j).join(' '));
                        lineWidths.push(totalWordSize);
                        rangeStart = j;
                        totalWordSize = 0;
                    } else {
                        totalWordSize += wordSize;
                    }
                }
                splitLines.push(words.slice(rangeStart, words.length).join(' '));
                lineWidths.push(totalWordSize);
            } else {
                splitLines.push(lines[i]);
                lineWidths.push(size);
            }
        }

        var textY = lineHeight / 2;
        for (var i=0; i < splitLines.length; i++) {
            ctx.fillText(splitLines[i], 0, textY);
            textY += lineHeight;
        }

    });
}

// Provides: vanillaQuad
// Requires: vanillaTextureShader
// Requires: orthographicMat
// Requires: scaleMat
function vanillaQuad(gl, width, height, tex) {
    var shader = vanillaTextureShader(gl);

    var res = {
        texture: tex,
        shader: shader,
        matrix: scaleMat(orthographicMat, width, height)
    };
    return res;
}

// Provides: textQuad
// Requires: vanillaQuad
// Requires: textTexture
function textQuad(gl, width, height) {

    return vanillaQuad(gl, width, height, textTexture.apply(this, arguments));

}

// Provides: colorQuad
// Requires: vanillaQuad 
// Requires: renderCanvasTexture
function colorQuad(gl, width, height, color) {
    return vanillaQuad(gl, width, height, renderCanvasTexture(gl, width, height, function(ctx){
        ctx.fillStyle = color;
        ctx.fillRect(0, 0, width, height);
    }));
}

// Provides: loadImageUrl 
function loadImageUrl(url, cb) {
    var img = new Image();
    img.onload = function() {
        cb(img);
    };
    img.src = url;
}

// Provides: imageTexture
// Requires: renderCanvasTexture
function imageTexture(gl, img) {
    var width = img.width;
    var height = img.height;
    return renderCanvasTexture(gl, width, height, function(ctx) {
        ctx.drawImage(img, 0, 0);
    });
}

// Provides: setupUnitQuadBuffers
function setupUnitQuadBuffers(gl) {
    if (!gl.__unit_position_buffer) {
        var positionBuffer = gl.createBuffer();
        gl.bindBuffer(gl.ARRAY_BUFFER, positionBuffer);
      
        // Put a unit quad in the buffer
        var positions = [
          0, 0,
          0, 1,
          1, 0,
          1, 0,
          0, 1,
          1, 1,
        ];
        gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(positions), gl.STATIC_DRAW);
        gl.__unit_position_buffer = positionBuffer;
    }
    if (!gl.__unit_texcoord_buffer) {
        var texcoordBuffer = gl.createBuffer();
        gl.bindBuffer(gl.ARRAY_BUFFER, texcoordBuffer);
      
        // Put texcoords in the buffer
        var texcoords = [
          0, 0,
          0, 1,
          1, 0,
          1, 0,
          0, 1,
          1, 1,
        ];
        gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(texcoords), gl.STATIC_DRAW);
        gl.__unit_texcoord_buffer = texcoordBuffer;
    }
}

// Provides: renderQuads
// Requires: setupUnitQuadBuffers
function renderQuads(gl, quads) {

    /*
    quad: {
        matrix: m4 orthographic projection matrix -> m4 projection matrix
        texture: WebGLTexture
        shader: {
          program: WebGLProgram
          positionLocation: position shader attrib
          texcoordLocation: texture coordinate shader attrib
          matrixLocation: matrix attrib
          textureLocation: texture attrib
        }
    }
    */

    setupUnitQuadBuffers(gl);
    var positionBuffer = gl.__unit_position_buffer;
    var texcoordBuffer = gl.__unit_texcoord_buffer;

    var width = gl.canvas.width;
    var height = gl.canvas.height;

    gl.blendFunc(gl.SRC_ALPHA, gl.ONE_MINUS_SRC_ALPHA);

    for (var i=0; i < quads.length; i++) {

        var quad = quads[i];
        var shader = quad.shader;
        gl.bindTexture(gl.TEXTURE_2D, quad.texture);

        gl.useProgram(shader.program);

        gl.bindBuffer(gl.ARRAY_BUFFER, positionBuffer);
        gl.enableVertexAttribArray(shader.positionLocation);
        gl.vertexAttribPointer(shader.positionLocation, 2, gl.FLOAT, false, 0, 0);
        gl.bindBuffer(gl.ARRAY_BUFFER, texcoordBuffer);
        gl.enableVertexAttribArray(shader.texcoordLocation);
        gl.vertexAttribPointer(shader.texcoordLocation, 2, gl.FLOAT, false, 0, 0);

         // this matirx will convert from pixels to clip space
        var matrix = quad.matrix(width, height);
        gl.uniformMatrix4fv(shader.matrixLocation, false, matrix);

        // Tell the shader to get the texture from texture unit 0
        gl.uniform1i(shader.textureLocation, 0);

        // draw the quad (2 triangles, 6 vertices)
        gl.drawArrays(gl.TRIANGLES, 0, 6);

    }
}

// Provides: getPageWidth
function getPageWidth() {
    var doc = document.documentElement;
    return Math.max(
        document.body.scrollWidth || 0,
        doc.scrollWidth || 0,
        document.body.offsetWidth || 0,
        doc.offsetWidth || 0,
        doc.cientWidth || 0);
}

// Provides: getPageHeight
function getPageHeight() {
    var doc = document.documentElement;
    return Math.max(
        document.body.scrollHeight || 0,
        doc.scrollHeight || 0,
        document.body.offsetHeight || 0,
        doc.offsetHeight || 0,
        doc.cientHeight || 0);
}

// Provides: resizeCanvasToDisplaySize
// Requires: getPageWidth
// Requires: getPageHeight
function resizeCanvasToDisplaySize(canvas) {
    var width = getPageWidth();
    var height = getPageHeight();
    if (canvas.width !== width ||  canvas.height !== height) {
      canvas.width  = width;
      canvas.height = height;
      return true;
    }
    return false;
  }

// Provides: render
// Requires: resizeCanvasToDisplaySize
function render(gl, renderFn, frameInterval) {

    resizeCanvasToDisplaySize(gl.canvas);
    gl.viewport(0, 0, gl.canvas.width, gl.canvas.height);
    gl.clear(gl.COLOR_BUFFER_BIT);
    renderFn(gl, frameInterval);

}

// Provides: renderLoop
// Requires: render
function renderLoop(gl, renderFn, frameInterval) {
    var frameInterval = frameInterval || 0;
    render(gl, renderFn, frameInterval);
    window.requestAnimationFrame(function(i) { renderLoop(gl, renderFn, i);});
}