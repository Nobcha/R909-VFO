# R909-VFO
To remodel the convensional analog radio kits, the digital VFO is nesessary. 
I derived such VFO circuit PCB from the DSP radio design of R909-DSP.
R909-DSP is composed with Arduino-Si5351a of the panel-PCB and TA2003-Si4732 of RF-PCB.
The panel-PCB was designed to be installed in 88x38x70 aluminum case.
I will introduce the schematic, Arduino sketch, and case installation for R909-VFO.

日本語版
アナログ式の無線機をデジタル化改造するのに利用できるVFOです。
DSPを使う受信機R909-DSPを設計試作した時に構成したVFOを独立させたものです。
R909-DSPはArduino制御のSi5351aと操作部・表示部が載ったPanel基板とTA2003-Si4732が載ったRF基板に分かれています。
このPanel基板部にもSi5351aモジュールがつながるようにしてあり、独立してVFOとして使えます。
ここでは回路図、部品表、Arduinoのスケッチ、組み立て方について説明します。
