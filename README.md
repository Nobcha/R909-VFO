# R909-VFO
To remodel the convensional analog radio kits, the digital VFO is nesessary. 
I derived such VFO circuit PCB from the DSP radio design of R909-DSP.
R909-DSP is composed with Arduino-Si5351a of the panel-PCB and TA2003-Si4732 of RF-PCB.
The panel-PCB was designed to be installed in 88x38x70 aluminum case.
This VFO is combined panel-PCB with AdaFruits Si5351a module.
I will introduce the schematic, Arduino sketch, and case installation as a R909-VFO.
Please refer the manual as https://github.com/Nobcha/R909-VFO/R909ーVFO_Manual_en.pdf .

（日本語版）
アナログ式の無線機をデジタル化改造するのに利用できるVFOです。
DSPを使う受信機R909-DSPを設計試作した時に構成したVFOを独立させたものです。
R909-DSPはArduino制御のSi5351aと操作部・表示部が載ったPanel基板とTA2003-Si4732が載ったRF基板に分かれています。
このPanel基板部にもSi5351aモジュールがつながるようにしてあり、独立したVFOとして使えます。
ここでは回路図、部品表、Arduinoのスケッチ、組み立て方について説明します。

詳しい説明は”R909ーVFO_Manual_ja.pdf”にまとめましたので、参照してください。

The uploaded file list
R909-DSP_VFO	name	address	note
Panel PCB For VFO
	Gerber　	https://github.com/Nobcha/R909-VFO/5531_ATm_25.kicad_pcb.zip  PCBGOGO
 
	Block diagram	https://github.com/Nobcha/R909-VFO/	
 
	BOM	https://github.com/Nobcha/R909-VFO/	
 
	schematic	https://github.com/Nobcha/R909-VFO/ R909-VFO_scm_rev.jpg
 

Sketch	i2c scanner @3.3	https://github.com/Nobcha/R909-VFO/ i2c_scanner_R909PANEL-OLED_4732.ino

      	JCR VFO	https://github.com/Nobcha/R909-VFO/ Changed to KPA-5351 sketch.txt  Port change
       
	R909‗VFO	https://github.com/Nobcha/R909-VFO/ R909-VFO_sketch_0628.zip

Manual		https://github.com/Nobcha/R909-VFO/R909ーVFO_Manual_en.pdf


F-panel PCB	Gerber　	https://github.com/Nobcha/R909-VFO/front-p.kicad_pcb.zip  PCBGOGO

B-panel PCB	Gerber　	https://github.com/Nobcha/R909-VFO/back-p.kicad_pcb.zip   PCBGOGO


R909-DSP_VFO	ファイルの種類	GITHUBアドレス	注記
VFO用の基板データ
	   基板発注用	https://github.com/Nobcha/R909-VFO/5531_ATm_25.kicad_pcb.zip   PCBGOGO
    
	   ブロックダイヤ	https://github.com/Nobcha/R909-VFO/	
    
	   部品表　1頁	https://github.com/Nobcha/R909-VFO/R909-VFO_BOM_1_2_ja.jpg
    
	   部品表　2頁	https://github.com/Nobcha/R909-VFO/R909-VFO_BOM_2_2_ja.jpg
    
    	　　回路図	https://github.com/Nobcha/R909-VFO/ R909-VFO_scm_rev.jpg

Sketch	i2c scanner @3.3	https://github.com/Nobcha/R909-VFO/ i2c_scanner_R909PANEL-OLED_4732.ino

      	JCR VFO	https://github.com/Nobcha/R909-VFO/ Changed to KPA-5351 sketch.txt  Port change
       
	R909‗VFO	https://github.com/Nobcha/R909-VFO/ R909-VFO_sketch_0628.zip

取扱説明書	組立操作説明書	https://github.com/Nobcha/R909-VFO/R909ーVFO_Manual_ja.jpg


F-panel PCB	Gerber　	https://github.com/Nobcha/R909-VFO/front-p.kicad_pcb.zip  PCBGOGO

B-panel PCB	Gerber　	https://github.com/Nobcha/R909-VFO/back-p.kicad_pcb.zip   PCBGOGO
