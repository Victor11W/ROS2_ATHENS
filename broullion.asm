
insertion-sort.elf:     file format elf32-littleriscv


Disassembly of section .text:

00010094 <minIndex>:
   10094:	00050813          	mv	a6,a0
   10098:	04b05063          	blez	a1,100d8 <minIndex+0x44>
   1009c:	00050693          	mv	a3,a0
   100a0:	00000513          	li	a0,0
   100a4:	00000713          	li	a4,0
   100a8:	0100006f          	j	100b8 <minIndex+0x24>
   100ac:	00170713          	add	a4,a4,1
   100b0:	00468693          	add	a3,a3,4
   100b4:	02e58063          	beq	a1,a4,100d4 <minIndex+0x40>
   100b8:	00251793          	sll	a5,a0,0x2
   100bc:	00f807b3          	add	a5,a6,a5
   100c0:	0006a603          	lw	a2,0(a3)
   100c4:	0007a783          	lw	a5,0(a5)
   100c8:	fef652e3          	bge	a2,a5,100ac <minIndex+0x18>
   100cc:	00070513          	mv	a0,a4
   100d0:	fddff06f          	j	100ac <minIndex+0x18>
   100d4:	00008067          	ret
   100d8:	00000513          	li	a0,0
   100dc:	00008067          	ret

000100e0 <main>:
   100e0:	e5010113          	add	sp,sp,-432
   100e4:	1a112623          	sw	ra,428(sp)
   100e8:	1a812423          	sw	s0,424(sp)
   100ec:	1a912223          	sw	s1,420(sp)
   100f0:	1b212023          	sw	s2,416(sp)
   100f4:	19312e23          	sw	s3,412(sp)
   100f8:	000117b7          	lui	a5,0x11
   100fc:	1a478793          	add	a5,a5,420 # 111a4 <input>
   10100:	00410413          	add	s0,sp,4
   10104:	18c78613          	add	a2,a5,396
   10108:	00040713          	mv	a4,s0
   1010c:	0007a683          	lw	a3,0(a5)
   10110:	00d72023          	sw	a3,0(a4)
   10114:	00478793          	add	a5,a5,4
   10118:	00470713          	add	a4,a4,4
   1011c:	fec798e3          	bne	a5,a2,1010c <main+0x2c>
   10120:	00000493          	li	s1,0
   10124:	06300993          	li	s3,99
   10128:	06200913          	li	s2,98
   1012c:	409985b3          	sub	a1,s3,s1
   10130:	00040513          	mv	a0,s0
   10134:	f61ff0ef          	jal	10094 <minIndex>
   10138:	00950533          	add	a0,a0,s1
   1013c:	00251513          	sll	a0,a0,0x2
   10140:	19050793          	add	a5,a0,400
   10144:	00278533          	add	a0,a5,sp
   10148:	e7452783          	lw	a5,-396(a0)
   1014c:	00042703          	lw	a4,0(s0)
   10150:	e6e52a23          	sw	a4,-396(a0)
   10154:	00f42023          	sw	a5,0(s0)
   10158:	00148493          	add	s1,s1,1
   1015c:	00440413          	add	s0,s0,4
   10160:	fd2496e3          	bne	s1,s2,1012c <main+0x4c>
   10164:	00412503          	lw	a0,4(sp)
   10168:	1ac12083          	lw	ra,428(sp)
   1016c:	1a812403          	lw	s0,424(sp)
   10170:	1a412483          	lw	s1,420(sp)
   10174:	1a012903          	lw	s2,416(sp)
   10178:	19c12983          	lw	s3,412(sp)
   1017c:	1b010113          	add	sp,sp,432
   10180:	00008067          	ret

00010184 <_start>:
   10184:	ff010113          	add	sp,sp,-16
   10188:	00112623          	sw	ra,12(sp)
   1018c:	f55ff0ef          	jal	100e0 <main>
   10190:	00a00893          	li	a7,10
   10194:	00000073          	ecall
   10198:	00c12083          	lw	ra,12(sp)
   1019c:	01010113          	add	sp,sp,16
   101a0:	00008067          	ret
