import ctypes

lib = ctypes.CDLL("./reverse.so")
lib.reverse.argtypes = [ctypes.c_char_p]
lib.reverse.restype = ctypes.c_char_p

def reverseText(text):
    textEncoded = text.encode('utf8')

    reversedText = lib.reverse(textEncoded)

    print(reversedText.decode('utf8', 'strict'))

text1 = "Sistemas Operacionais"
text2 = "Centro Universitário Senac"
text3 = "Reversão de Textos Bênção"

reverseText(text1)

reverseText(text2)

reverseText(text3)
