import os

scriptPath = os.path.dirname(os.path.realpath(__file__))

templateFile = open(scriptPath+"/WS2812_PIN_._c")
templateContent = templateFile.read()
templateFile.close()

generatePinP1 = ("P1_0", "P1_1", "P1_2", "P1_3", "P1_4", "P1_5", "P1_6", "P1_7")
generatePinP3 = ("P3_0", "P3_1", "P3_2", "P3_3", "P3_4", "P3_5", "P3_6", "P3_7")
generatePins = generatePinP1 + generatePinP3

for pin in generatePins:
    generateFileContent = "//This file is generated by a script. \r\n" +templateContent.replace("PX_X",pin);
    #print generateFileContent
    outputFile = open(scriptPath+"/optionalLink_WS2812_"+pin+".c", "w")
    outputFile.write(generateFileContent)
    outputFile.close()

#generateHeader
outputFile = open(scriptPath+"/WS2812_pins_header.h", "w")
outputFile.write("//This file is generated by a script. \r\n")
outputFile.write("#ifndef _WS2812_PIND_HEADER_H_INCLUDED\r\n")
outputFile.write("#define _WS2812_PIND_HEADER_H_INCLUDED\r\n")

for pin in generatePins:
    outputFile.write("void neopixel_show_long_"+pin+"(uint32_t dataAndLen); \r\n")
    outputFile.write("#define neopixel_show_"+pin+"(ADDR,LEN) neopixel_show_long_"+pin+"((((uint16_t)(ADDR)) & 0xFFFF) | (((uint32_t)(LEN) & 0xFF) << 16)); \r\n")

outputFile.write("#endif \r\n")
outputFile.close()
