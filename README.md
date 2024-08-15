# R909-VFO
To remodel the convensional analog radio kits, the digital VFO is nesessary. 
I derived such VFO circuit PCB from the DSP radio design of R909-DSP.
R909-DSP is composed with Arduino-Si5351a of the panel-PCB and TA2003-Si4732 of RF-PCB.
The panel-PCB was designed to be installed in 88x38x70 aluminum case.
This VFO is combined panel-PCB with AdaFruits Si5351a module.
I will introduce the schematic, Arduino sketch, and case installation as a R909-VFO.
Please note that you shall use 8Mhz crystal for stable operation instead of 16Mhz crystal.
Please refer the manual as [https://github.com/Nobcha/R909-VFO/R909ーVFO_Manual_en.pdf](https://github.com/Nobcha/R909-VFO/blob/main/R909%E3%83%BCVFO_Manual_en.pdf) .

（日本語版）
アナログ式の無線機をデジタル化改造するのに利用できるVFOです。
DSPを使う受信機R909-DSPを設計試作した時に構成したVFOを独立させたものです。
R909-DSPはArduino制御のSi5351aと操作部・表示部が載ったPanel基板とTA2003-Si4732が載ったRF基板に分かれています。
このPanel基板部にもSi5351aモジュールがつながるようにしてあり、独立したVFOとして使えます。
ここでは回路図、部品表、Arduinoのスケッチ、組み立て方について説明します。
回路図、部品表では16MHzの水晶発振器を示していますが、バッテリー電源供給で安定な動作のためには8MHzの水晶発振器を使用してください。

詳しい説明は”R909ーVFO_Manual_ja.pdf”にまとめましたので、参照してください。

