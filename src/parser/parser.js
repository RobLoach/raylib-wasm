/**
 * Parser - Will read raylib_api.json and will attempt to write the API.
 *
 * https://github.com/raysan5/raylib/blob/master/parser/raylib_api.json
 */
const api = require('./raylib_api.json')

function enums_header() {
    return `void raylib_enums() {\n`
}

function enums_footer() {
    return '}\n'
}

function enums_body(allEnums) {
    let output = `    // Colors
    constant("LIGHTGRAY", LIGHTGRAY);
    constant("GRAY", GRAY);
    constant("DARKGRAY", DARKGRAY);
    constant("YELLOW", YELLOW);
    constant("GOLD", GOLD);
    constant("ORANGE", ORANGE);
    constant("PINK", PINK);
    constant("RED", RED);
    constant("MAROON", MAROON);
    constant("GREEN", GREEN);
    constant("LIME", LIME);
    constant("DARKGREEN", DARKGREEN);
    constant("SKYBLUE", SKYBLUE);
    constant("BLUE", BLUE);
    constant("DARKBLUE", DARKBLUE);
    constant("PURPLE", PURPLE);
    constant("VIOLET", VIOLET);
    constant("DARKPURPLE", DARKPURPLE);
    constant("BEIGE", BEIGE);
    constant("BROWN", BROWN);
    constant("DARKBROWN", DARKBROWN);
    constant("WHITE", WHITE);
    constant("BLACK", BLACK);
    constant("BLANK", BLANK);
    constant("MAGENTA", MAGENTA);
    constant("RAYWHITE", RAYWHITE);
    \n`

    for (let family of allEnums) {
        for (let val of family.values) {
            output += `    constant("${val.name}", ${val.name});\n`
        }
    }
    return output;
}

function enums(allEnums) {
    return enums_header() + enums_body(allEnums) + enums_footer();
}

function structs_header() {
    return `void raylib_structs() {\n`
}

function structs_footer() {
    return '}\n'
}

function structs_body(allStructs) {
    let output = ''
    for (let struct of allStructs) {
        switch (struct.name) {
            case 'CharInfo':
                break;
            case 'Matrix':
                output += '    value_object<Matrix>("Matrix")\n';
                for (let i = 0; i < 16; i++) {
                    output += `        .field("m${i}", &Matrix::m${i})\n`
                }
                output += '    ;\n'
                break;
            default:
                output += `    value_object<${struct.name}>("${struct.name}")\n`
                for (let field of struct.fields) {
                    if (!(
                            field.name.includes('[') ||
                            field.type == 'void *'
                        )) {
                        output += `        .field("${field.name}", &${struct.name}::${field.name})\n`
                    }
                }
                output += '    ;\n'
                break;
        }
    }
    return output;
}

function structs(allStructs) {
    return structs_header() + structs_body(allStructs) + structs_footer();
}

function functions_header() {
    return `void raylib_functions() {\n`
}

function functions_footer() {
    return `}\n`
}

function functions_body(allFunctions) {
    output = ''
    let wrapperFunctions = [
        "InitWindow",
        "GetMonitorName",
        "SetClipboardText",
        "GetClipboardText",
        "SetWindowTitle",
        "TakeScreenshot",
        "LoadFileText",
        "SaveFileText",
        "FileExists",
        "DirectoryExists",
        "IsFileExtension",
        "GetFileExtension",
        "GetFileName",
        "GetFileNameWithoutExt",
        "GetDirectoryPath",
        "GetPrevDirectoryPath",
        "GetWorkingDirectory",
        "GetDirectoryFiles",
        "ChangeDirectory",
        "GetDroppedFiles",
        "GetFileModTime",
        "OpenURL",
        "UpdateCamera",
        "LoadImage",
        "LoadImageRaw",
        "LoadImageAnim",
        "LoadImageFromMemory",
        "ExportImage",
        "ExportImageAsCode"
    ]
    for (let func of allFunctions) {
        switch (func.name) {
            // Skipped functions
            case 'TraceLog':
                break;
            default:
                let finalFuncName = func.name
                if (wrapperFunctions.includes(finalFuncName)) {
                    finalFuncName = 'raylib::' + finalFuncName
                }

                // Ensure it's valid function
                let valid = true;
                if (func.params) {
                    if (func.params["callback"]) {
                        valid = false
                    }
                }
                if (func.returnType == "void *") {
                    valid = false
                }

                if (valid) {
                    output += `    function("${func.name}", &${finalFuncName});\n`
                }
                else {
                    output += `    // function("${func.name}", &${finalFuncName});\n`
                }
                break
        }
    }
    return output
}

function functions(allFunctions) {
    return functions_header() + functions_body(allFunctions) + functions_footer()
}

// TODO: Have the parser write to the files directly.
console.log(enums(api.enums))
console.log(structs(api.structs))
console.log(functions(api.functions))
