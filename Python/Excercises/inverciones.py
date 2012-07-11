import math

inversion_inicial = int(raw_input("Inversion Inicial: "))
tasa_descuento = (float(raw_input("%"" tasa de descuento: "))/100)
tasa_descuento = tasa_descuento+1
mes = 1
van = -inversion_inicial

while True:
	flujo = float(raw_input("Flujo Mes "+str(mes)+" "))
	van = van + (flujo/(math.pow(tasa_descuento,mes)) )
	print flujo/(math.pow(tasa_descuento,mes))
	print "VAN: "+str(van)
	if van > 0:
		break;
	mes = mes + 1
