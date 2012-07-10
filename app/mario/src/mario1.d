
mario:     file format elf32-i386


Disassembly of section .text:

01000000 <start>:
 1000000:	bf 00 40 02 01       	mov    $0x1024000,%edi
 1000005:	b9 cc 8a 05 01       	mov    $0x1058acc,%ecx
 100000a:	81 e9 00 40 02 01    	sub    $0x1024000,%ecx
 1000010:	b8 00 00 00 00       	mov    $0x0,%eax
 1000015:	fc                   	cld    
 1000016:	f3 aa                	rep stos %al,%es:(%edi)
 1000018:	e8 0b 78 00 00       	call   1007828 <libc_init>
 100001d:	e8 21 00 00 00       	call   1000043 <call_ctors>
 1000022:	6a 00                	push   $0x0
 1000024:	6a 00                	push   $0x0
 1000026:	e8 dc 4f 00 00       	call   1005007 <main>
 100002b:	83 c4 08             	add    $0x8,%esp
 100002e:	50                   	push   %eax
 100002f:	6a 00                	push   $0x0
 1000031:	e8 a2 00 00 00       	call   10000d8 <__cxa_finalize>
 1000036:	83 c4 04             	add    $0x4,%esp
 1000039:	58                   	pop    %eax
 100003a:	89 c3                	mov    %eax,%ebx
 100003c:	b8 09 00 00 00       	mov    $0x9,%eax
 1000041:	cd 80                	int    $0x80

01000043 <call_ctors>:
 1000043:	53                   	push   %ebx
 1000044:	bb 00 90 00 01       	mov    $0x1009000,%ebx
 1000049:	eb 05                	jmp    1000050 <call_ctors+0xd>
 100004b:	ff 13                	call   *(%ebx)
 100004d:	83 c3 04             	add    $0x4,%ebx
 1000050:	81 fb 04 90 00 01    	cmp    $0x1009004,%ebx
 1000056:	72 f3                	jb     100004b <call_ctors+0x8>
 1000058:	5b                   	pop    %ebx
 1000059:	c3                   	ret    

0100005a <errno>:
 100005a:	00 00                	add    %al,(%eax)
 100005c:	00 00                	add    %al,(%eax)
	...

01000060 <__cxa_atexit>:
 1000060:	55                   	push   %ebp
 1000061:	89 e5                	mov    %esp,%ebp
 1000063:	a1 20 43 02 01       	mov    0x1024320,%eax
 1000068:	83 f8 3f             	cmp    $0x3f,%eax
 100006b:	76 07                	jbe    1000074 <__cxa_atexit+0x14>
 100006d:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 1000072:	eb 62                	jmp    10000d6 <__cxa_atexit+0x76>
 1000074:	8b 15 20 43 02 01    	mov    0x1024320,%edx
 100007a:	89 d0                	mov    %edx,%eax
 100007c:	01 c0                	add    %eax,%eax
 100007e:	01 d0                	add    %edx,%eax
 1000080:	c1 e0 02             	shl    $0x2,%eax
 1000083:	8d 90 20 40 02 01    	lea    0x1024020(%eax),%edx
 1000089:	8b 45 08             	mov    0x8(%ebp),%eax
 100008c:	89 02                	mov    %eax,(%edx)
 100008e:	8b 15 20 43 02 01    	mov    0x1024320,%edx
 1000094:	89 d0                	mov    %edx,%eax
 1000096:	01 c0                	add    %eax,%eax
 1000098:	01 d0                	add    %edx,%eax
 100009a:	c1 e0 02             	shl    $0x2,%eax
 100009d:	8d 90 20 40 02 01    	lea    0x1024020(%eax),%edx
 10000a3:	8b 45 0c             	mov    0xc(%ebp),%eax
 10000a6:	89 42 04             	mov    %eax,0x4(%edx)
 10000a9:	8b 15 20 43 02 01    	mov    0x1024320,%edx
 10000af:	89 d0                	mov    %edx,%eax
 10000b1:	01 c0                	add    %eax,%eax
 10000b3:	01 d0                	add    %edx,%eax
 10000b5:	c1 e0 02             	shl    $0x2,%eax
 10000b8:	8d 90 20 40 02 01    	lea    0x1024020(%eax),%edx
 10000be:	8b 45 10             	mov    0x10(%ebp),%eax
 10000c1:	89 42 08             	mov    %eax,0x8(%edx)
 10000c4:	a1 20 43 02 01       	mov    0x1024320,%eax
 10000c9:	83 c0 01             	add    $0x1,%eax
 10000cc:	a3 20 43 02 01       	mov    %eax,0x1024320
 10000d1:	b8 00 00 00 00       	mov    $0x0,%eax
 10000d6:	5d                   	pop    %ebp
 10000d7:	c3                   	ret    

010000d8 <__cxa_finalize>:
 10000d8:	55                   	push   %ebp
 10000d9:	89 e5                	mov    %esp,%ebp
 10000db:	83 ec 28             	sub    $0x28,%esp
 10000de:	a1 20 43 02 01       	mov    0x1024320,%eax
 10000e3:	89 45 f4             	mov    %eax,-0xc(%ebp)
 10000e6:	83 7d 08 00          	cmpl   $0x0,0x8(%ebp)
 10000ea:	74 45                	je     1000131 <__cxa_finalize+0x59>
 10000ec:	eb 4e                	jmp    100013c <__cxa_finalize+0x64>
 10000ee:	a1 20 43 02 01       	mov    0x1024320,%eax
 10000f3:	83 e8 01             	sub    $0x1,%eax
 10000f6:	a3 20 43 02 01       	mov    %eax,0x1024320
 10000fb:	8b 15 20 43 02 01    	mov    0x1024320,%edx
 1000101:	89 d0                	mov    %edx,%eax
 1000103:	01 c0                	add    %eax,%eax
 1000105:	01 d0                	add    %edx,%eax
 1000107:	c1 e0 02             	shl    $0x2,%eax
 100010a:	05 20 40 02 01       	add    $0x1024020,%eax
 100010f:	8b 08                	mov    (%eax),%ecx
 1000111:	8b 15 20 43 02 01    	mov    0x1024320,%edx
 1000117:	89 d0                	mov    %edx,%eax
 1000119:	01 c0                	add    %eax,%eax
 100011b:	01 d0                	add    %edx,%eax
 100011d:	c1 e0 02             	shl    $0x2,%eax
 1000120:	05 20 40 02 01       	add    $0x1024020,%eax
 1000125:	8b 40 04             	mov    0x4(%eax),%eax
 1000128:	89 04 24             	mov    %eax,(%esp)
 100012b:	ff d1                	call   *%ecx
 100012d:	83 6d f4 01          	subl   $0x1,-0xc(%ebp)
 1000131:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 1000135:	0f 95 c0             	setne  %al
 1000138:	84 c0                	test   %al,%al
 100013a:	75 b2                	jne    10000ee <__cxa_finalize+0x16>
 100013c:	c9                   	leave  
 100013d:	c3                   	ret    

0100013e <__cxa_pure_virtual>:
 100013e:	55                   	push   %ebp
 100013f:	89 e5                	mov    %esp,%ebp
 1000141:	5d                   	pop    %ebp
 1000142:	c3                   	ret    

01000143 <_Znwj>:
 1000143:	55                   	push   %ebp
 1000144:	89 e5                	mov    %esp,%ebp
 1000146:	83 ec 28             	sub    $0x28,%esp
 1000149:	8b 45 08             	mov    0x8(%ebp),%eax
 100014c:	89 04 24             	mov    %eax,(%esp)
 100014f:	e8 dc 86 00 00       	call   1008830 <malloc>
 1000154:	89 45 f4             	mov    %eax,-0xc(%ebp)
 1000157:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100015a:	c9                   	leave  
 100015b:	c3                   	ret    

0100015c <_ZdlPv>:
 100015c:	55                   	push   %ebp
 100015d:	89 e5                	mov    %esp,%ebp
 100015f:	83 ec 18             	sub    $0x18,%esp
 1000162:	8b 45 08             	mov    0x8(%ebp),%eax
 1000165:	89 04 24             	mov    %eax,(%esp)
 1000168:	e8 b9 87 00 00       	call   1008926 <free>
 100016d:	c9                   	leave  
 100016e:	c3                   	ret    

0100016f <_Znaj>:
 100016f:	55                   	push   %ebp
 1000170:	89 e5                	mov    %esp,%ebp
 1000172:	83 ec 28             	sub    $0x28,%esp
 1000175:	8b 45 08             	mov    0x8(%ebp),%eax
 1000178:	89 04 24             	mov    %eax,(%esp)
 100017b:	e8 b0 86 00 00       	call   1008830 <malloc>
 1000180:	89 45 f4             	mov    %eax,-0xc(%ebp)
 1000183:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1000186:	c9                   	leave  
 1000187:	c3                   	ret    

01000188 <_ZdaPv>:
 1000188:	55                   	push   %ebp
 1000189:	89 e5                	mov    %esp,%ebp
 100018b:	83 ec 18             	sub    $0x18,%esp
 100018e:	8b 45 08             	mov    0x8(%ebp),%eax
 1000191:	89 04 24             	mov    %eax,(%esp)
 1000194:	e8 8d 87 00 00       	call   1008926 <free>
 1000199:	c9                   	leave  
 100019a:	c3                   	ret    
	...

0100019c <draw_init>:
 100019c:	83 ec 1c             	sub    $0x1c,%esp
 100019f:	c7 04 24 40 43 02 01 	movl   $0x1024340,(%esp)
 10001a6:	e8 74 73 00 00       	call   100751f <get_graph_info>
 10001ab:	a1 48 43 02 01       	mov    0x1024348,%eax
 10001b0:	83 f8 10             	cmp    $0x10,%eax
 10001b3:	74 13                	je     10001c8 <draw_init+0x2c>
 10001b5:	c7 04 24 04 90 00 01 	movl   $0x1009004,(%esp)
 10001bc:	e8 7b 76 00 00       	call   100783c <printf>
 10001c1:	b8 01 00 00 00       	mov    $0x1,%eax
 10001c6:	eb 25                	jmp    10001ed <draw_init+0x51>
 10001c8:	c7 44 24 04 60 43 02 	movl   $0x1024360,0x4(%esp)
 10001cf:	01 
 10001d0:	c7 04 24 0f 90 00 01 	movl   $0x100900f,(%esp)
 10001d7:	e8 06 74 00 00       	call   10075e2 <get_module>
 10001dc:	c7 04 24 04 00 00 00 	movl   $0x4,(%esp)
 10001e3:	e8 78 73 00 00       	call   1007560 <tty_switch>
 10001e8:	b8 00 00 00 00       	mov    $0x0,%eax
 10001ed:	83 c4 1c             	add    $0x1c,%esp
 10001f0:	c3                   	ret    

010001f1 <draw_set_canvas>:
 10001f1:	83 7c 24 08 00       	cmpl   $0x0,0x8(%esp)
 10001f6:	74 0c                	je     1000204 <draw_set_canvas+0x13>
 10001f8:	8b 44 24 04          	mov    0x4(%esp),%eax
 10001fc:	8b 54 24 08          	mov    0x8(%esp),%edx
 1000200:	89 10                	mov    %edx,(%eax)
 1000202:	eb 0c                	jmp    1000210 <draw_set_canvas+0x1f>
 1000204:	8b 15 4c 43 02 01    	mov    0x102434c,%edx
 100020a:	8b 44 24 04          	mov    0x4(%esp),%eax
 100020e:	89 10                	mov    %edx,(%eax)
 1000210:	8b 15 40 43 02 01    	mov    0x1024340,%edx
 1000216:	8b 44 24 04          	mov    0x4(%esp),%eax
 100021a:	89 50 04             	mov    %edx,0x4(%eax)
 100021d:	8b 15 44 43 02 01    	mov    0x1024344,%edx
 1000223:	8b 44 24 04          	mov    0x4(%esp),%eax
 1000227:	89 50 08             	mov    %edx,0x8(%eax)
 100022a:	8b 15 48 43 02 01    	mov    0x1024348,%edx
 1000230:	8b 44 24 04          	mov    0x4(%esp),%eax
 1000234:	89 50 0c             	mov    %edx,0xc(%eax)
 1000237:	b8 00 00 00 00       	mov    $0x0,%eax
 100023c:	c3                   	ret    

0100023d <draw_set_point>:
 100023d:	83 ec 04             	sub    $0x4,%esp
 1000240:	8b 44 24 14          	mov    0x14(%esp),%eax
 1000244:	66 89 04 24          	mov    %ax,(%esp)
 1000248:	8b 44 24 08          	mov    0x8(%esp),%eax
 100024c:	8b 40 04             	mov    0x4(%eax),%eax
 100024f:	3b 44 24 0c          	cmp    0xc(%esp),%eax
 1000253:	76 30                	jbe    1000285 <draw_set_point+0x48>
 1000255:	8b 44 24 08          	mov    0x8(%esp),%eax
 1000259:	8b 40 08             	mov    0x8(%eax),%eax
 100025c:	3b 44 24 10          	cmp    0x10(%esp),%eax
 1000260:	76 26                	jbe    1000288 <draw_set_point+0x4b>
 1000262:	8b 44 24 08          	mov    0x8(%esp),%eax
 1000266:	8b 10                	mov    (%eax),%edx
 1000268:	8b 44 24 08          	mov    0x8(%esp),%eax
 100026c:	8b 40 04             	mov    0x4(%eax),%eax
 100026f:	0f af 44 24 10       	imul   0x10(%esp),%eax
 1000274:	03 44 24 0c          	add    0xc(%esp),%eax
 1000278:	01 c0                	add    %eax,%eax
 100027a:	01 c2                	add    %eax,%edx
 100027c:	0f b7 04 24          	movzwl (%esp),%eax
 1000280:	66 89 02             	mov    %ax,(%edx)
 1000283:	eb 04                	jmp    1000289 <draw_set_point+0x4c>
 1000285:	90                   	nop
 1000286:	eb 01                	jmp    1000289 <draw_set_point+0x4c>
 1000288:	90                   	nop
 1000289:	83 c4 04             	add    $0x4,%esp
 100028c:	c3                   	ret    

0100028d <draw_get_point>:
 100028d:	8b 44 24 04          	mov    0x4(%esp),%eax
 1000291:	8b 40 04             	mov    0x4(%eax),%eax
 1000294:	3b 44 24 08          	cmp    0x8(%esp),%eax
 1000298:	77 07                	ja     10002a1 <draw_get_point+0x14>
 100029a:	b8 00 00 00 00       	mov    $0x0,%eax
 100029f:	eb 31                	jmp    10002d2 <draw_get_point+0x45>
 10002a1:	8b 44 24 04          	mov    0x4(%esp),%eax
 10002a5:	8b 40 08             	mov    0x8(%eax),%eax
 10002a8:	3b 44 24 0c          	cmp    0xc(%esp),%eax
 10002ac:	77 07                	ja     10002b5 <draw_get_point+0x28>
 10002ae:	b8 00 00 00 00       	mov    $0x0,%eax
 10002b3:	eb 1d                	jmp    10002d2 <draw_get_point+0x45>
 10002b5:	8b 44 24 04          	mov    0x4(%esp),%eax
 10002b9:	8b 10                	mov    (%eax),%edx
 10002bb:	8b 44 24 04          	mov    0x4(%esp),%eax
 10002bf:	8b 40 04             	mov    0x4(%eax),%eax
 10002c2:	0f af 44 24 0c       	imul   0xc(%esp),%eax
 10002c7:	03 44 24 08          	add    0x8(%esp),%eax
 10002cb:	01 c0                	add    %eax,%eax
 10002cd:	01 d0                	add    %edx,%eax
 10002cf:	0f b7 00             	movzwl (%eax),%eax
 10002d2:	c3                   	ret    

010002d3 <draw_fill_rect>:
 10002d3:	57                   	push   %edi
 10002d4:	53                   	push   %ebx
 10002d5:	83 ec 14             	sub    $0x14,%esp
 10002d8:	8b 44 24 34          	mov    0x34(%esp),%eax
 10002dc:	66 89 04 24          	mov    %ax,(%esp)
 10002e0:	8b 44 24 20          	mov    0x20(%esp),%eax
 10002e4:	8b 40 04             	mov    0x4(%eax),%eax
 10002e7:	3b 44 24 24          	cmp    0x24(%esp),%eax
 10002eb:	0f 86 b7 00 00 00    	jbe    10003a8 <draw_fill_rect+0xd5>
 10002f1:	8b 44 24 20          	mov    0x20(%esp),%eax
 10002f5:	8b 40 08             	mov    0x8(%eax),%eax
 10002f8:	3b 44 24 28          	cmp    0x28(%esp),%eax
 10002fc:	0f 86 a9 00 00 00    	jbe    10003ab <draw_fill_rect+0xd8>
 1000302:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000306:	8b 40 04             	mov    0x4(%eax),%eax
 1000309:	3b 44 24 2c          	cmp    0x2c(%esp),%eax
 100030d:	0f 86 9b 00 00 00    	jbe    10003ae <draw_fill_rect+0xdb>
 1000313:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000317:	8b 40 08             	mov    0x8(%eax),%eax
 100031a:	3b 44 24 30          	cmp    0x30(%esp),%eax
 100031e:	0f 86 8d 00 00 00    	jbe    10003b1 <draw_fill_rect+0xde>
 1000324:	8b 44 24 24          	mov    0x24(%esp),%eax
 1000328:	3b 44 24 2c          	cmp    0x2c(%esp),%eax
 100032c:	0f 87 82 00 00 00    	ja     10003b4 <draw_fill_rect+0xe1>
 1000332:	8b 44 24 28          	mov    0x28(%esp),%eax
 1000336:	3b 44 24 30          	cmp    0x30(%esp),%eax
 100033a:	77 78                	ja     10003b4 <draw_fill_rect+0xe1>
 100033c:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000340:	8b 10                	mov    (%eax),%edx
 1000342:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000346:	8b 40 04             	mov    0x4(%eax),%eax
 1000349:	0f af 44 24 28       	imul   0x28(%esp),%eax
 100034e:	03 44 24 24          	add    0x24(%esp),%eax
 1000352:	01 c0                	add    %eax,%eax
 1000354:	01 d0                	add    %edx,%eax
 1000356:	89 44 24 0c          	mov    %eax,0xc(%esp)
 100035a:	8b 44 24 24          	mov    0x24(%esp),%eax
 100035e:	8b 54 24 2c          	mov    0x2c(%esp),%edx
 1000362:	89 d1                	mov    %edx,%ecx
 1000364:	29 c1                	sub    %eax,%ecx
 1000366:	89 c8                	mov    %ecx,%eax
 1000368:	89 44 24 08          	mov    %eax,0x8(%esp)
 100036c:	fc                   	cld    
 100036d:	8b 44 24 28          	mov    0x28(%esp),%eax
 1000371:	89 44 24 10          	mov    %eax,0x10(%esp)
 1000375:	eb 25                	jmp    100039c <draw_fill_rect+0xc9>
 1000377:	8b 54 24 08          	mov    0x8(%esp),%edx
 100037b:	0f b7 04 24          	movzwl (%esp),%eax
 100037f:	8b 5c 24 0c          	mov    0xc(%esp),%ebx
 1000383:	89 d1                	mov    %edx,%ecx
 1000385:	89 df                	mov    %ebx,%edi
 1000387:	f3 66 ab             	rep stos %ax,%es:(%edi)
 100038a:	8b 44 24 20          	mov    0x20(%esp),%eax
 100038e:	8b 40 04             	mov    0x4(%eax),%eax
 1000391:	01 c0                	add    %eax,%eax
 1000393:	01 44 24 0c          	add    %eax,0xc(%esp)
 1000397:	83 44 24 10 01       	addl   $0x1,0x10(%esp)
 100039c:	8b 44 24 10          	mov    0x10(%esp),%eax
 10003a0:	3b 44 24 30          	cmp    0x30(%esp),%eax
 10003a4:	76 d1                	jbe    1000377 <draw_fill_rect+0xa4>
 10003a6:	eb 0d                	jmp    10003b5 <draw_fill_rect+0xe2>
 10003a8:	90                   	nop
 10003a9:	eb 0a                	jmp    10003b5 <draw_fill_rect+0xe2>
 10003ab:	90                   	nop
 10003ac:	eb 07                	jmp    10003b5 <draw_fill_rect+0xe2>
 10003ae:	90                   	nop
 10003af:	eb 04                	jmp    10003b5 <draw_fill_rect+0xe2>
 10003b1:	90                   	nop
 10003b2:	eb 01                	jmp    10003b5 <draw_fill_rect+0xe2>
 10003b4:	90                   	nop
 10003b5:	83 c4 14             	add    $0x14,%esp
 10003b8:	5b                   	pop    %ebx
 10003b9:	5f                   	pop    %edi
 10003ba:	c3                   	ret    

010003bb <draw_clear_screen>:
 10003bb:	57                   	push   %edi
 10003bc:	53                   	push   %ebx
 10003bd:	83 ec 04             	sub    $0x4,%esp
 10003c0:	8b 44 24 14          	mov    0x14(%esp),%eax
 10003c4:	66 89 04 24          	mov    %ax,(%esp)
 10003c8:	8b 44 24 10          	mov    0x10(%esp),%eax
 10003cc:	8b 50 04             	mov    0x4(%eax),%edx
 10003cf:	8b 44 24 10          	mov    0x10(%esp),%eax
 10003d3:	8b 40 08             	mov    0x8(%eax),%eax
 10003d6:	0f af c2             	imul   %edx,%eax
 10003d9:	89 c1                	mov    %eax,%ecx
 10003db:	d1 f9                	sar    %ecx
 10003dd:	0f b7 04 24          	movzwl (%esp),%eax
 10003e1:	89 c2                	mov    %eax,%edx
 10003e3:	c1 e2 10             	shl    $0x10,%edx
 10003e6:	0f b7 04 24          	movzwl (%esp),%eax
 10003ea:	89 d3                	mov    %edx,%ebx
 10003ec:	09 c3                	or     %eax,%ebx
 10003ee:	8b 44 24 10          	mov    0x10(%esp),%eax
 10003f2:	8b 10                	mov    (%eax),%edx
 10003f4:	89 d8                	mov    %ebx,%eax
 10003f6:	89 d7                	mov    %edx,%edi
 10003f8:	fc                   	cld    
 10003f9:	f3 ab                	rep stos %eax,%es:(%edi)
 10003fb:	83 c4 04             	add    $0x4,%esp
 10003fe:	5b                   	pop    %ebx
 10003ff:	5f                   	pop    %edi
 1000400:	c3                   	ret    

01000401 <draw_copy>:
 1000401:	57                   	push   %edi
 1000402:	56                   	push   %esi
 1000403:	53                   	push   %ebx
 1000404:	83 ec 10             	sub    $0x10,%esp
 1000407:	8b 44 24 20          	mov    0x20(%esp),%eax
 100040b:	8b 40 04             	mov    0x4(%eax),%eax
 100040e:	3b 44 24 28          	cmp    0x28(%esp),%eax
 1000412:	0f 86 47 01 00 00    	jbe    100055f <draw_copy+0x15e>
 1000418:	8b 44 24 20          	mov    0x20(%esp),%eax
 100041c:	8b 40 08             	mov    0x8(%eax),%eax
 100041f:	3b 44 24 2c          	cmp    0x2c(%esp),%eax
 1000423:	0f 86 39 01 00 00    	jbe    1000562 <draw_copy+0x161>
 1000429:	8b 44 24 24          	mov    0x24(%esp),%eax
 100042d:	8b 40 04             	mov    0x4(%eax),%eax
 1000430:	3b 44 24 28          	cmp    0x28(%esp),%eax
 1000434:	0f 86 2b 01 00 00    	jbe    1000565 <draw_copy+0x164>
 100043a:	8b 44 24 24          	mov    0x24(%esp),%eax
 100043e:	8b 40 08             	mov    0x8(%eax),%eax
 1000441:	3b 44 24 2c          	cmp    0x2c(%esp),%eax
 1000445:	0f 86 1d 01 00 00    	jbe    1000568 <draw_copy+0x167>
 100044b:	8b 44 24 30          	mov    0x30(%esp),%eax
 100044f:	8b 54 24 28          	mov    0x28(%esp),%edx
 1000453:	01 c2                	add    %eax,%edx
 1000455:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000459:	8b 40 04             	mov    0x4(%eax),%eax
 100045c:	39 c2                	cmp    %eax,%edx
 100045e:	72 0f                	jb     100046f <draw_copy+0x6e>
 1000460:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000464:	8b 40 04             	mov    0x4(%eax),%eax
 1000467:	2b 44 24 28          	sub    0x28(%esp),%eax
 100046b:	89 44 24 30          	mov    %eax,0x30(%esp)
 100046f:	8b 44 24 30          	mov    0x30(%esp),%eax
 1000473:	8b 54 24 28          	mov    0x28(%esp),%edx
 1000477:	01 c2                	add    %eax,%edx
 1000479:	8b 44 24 24          	mov    0x24(%esp),%eax
 100047d:	8b 40 04             	mov    0x4(%eax),%eax
 1000480:	39 c2                	cmp    %eax,%edx
 1000482:	72 0f                	jb     1000493 <draw_copy+0x92>
 1000484:	8b 44 24 24          	mov    0x24(%esp),%eax
 1000488:	8b 40 04             	mov    0x4(%eax),%eax
 100048b:	2b 44 24 28          	sub    0x28(%esp),%eax
 100048f:	89 44 24 30          	mov    %eax,0x30(%esp)
 1000493:	8b 44 24 34          	mov    0x34(%esp),%eax
 1000497:	8b 54 24 2c          	mov    0x2c(%esp),%edx
 100049b:	01 c2                	add    %eax,%edx
 100049d:	8b 44 24 20          	mov    0x20(%esp),%eax
 10004a1:	8b 40 08             	mov    0x8(%eax),%eax
 10004a4:	39 c2                	cmp    %eax,%edx
 10004a6:	72 0f                	jb     10004b7 <draw_copy+0xb6>
 10004a8:	8b 44 24 20          	mov    0x20(%esp),%eax
 10004ac:	8b 40 08             	mov    0x8(%eax),%eax
 10004af:	2b 44 24 2c          	sub    0x2c(%esp),%eax
 10004b3:	89 44 24 34          	mov    %eax,0x34(%esp)
 10004b7:	8b 44 24 34          	mov    0x34(%esp),%eax
 10004bb:	8b 54 24 2c          	mov    0x2c(%esp),%edx
 10004bf:	01 c2                	add    %eax,%edx
 10004c1:	8b 44 24 24          	mov    0x24(%esp),%eax
 10004c5:	8b 40 08             	mov    0x8(%eax),%eax
 10004c8:	39 c2                	cmp    %eax,%edx
 10004ca:	72 0f                	jb     10004db <draw_copy+0xda>
 10004cc:	8b 44 24 24          	mov    0x24(%esp),%eax
 10004d0:	8b 40 08             	mov    0x8(%eax),%eax
 10004d3:	2b 44 24 2c          	sub    0x2c(%esp),%eax
 10004d7:	89 44 24 34          	mov    %eax,0x34(%esp)
 10004db:	8b 44 24 20          	mov    0x20(%esp),%eax
 10004df:	8b 40 04             	mov    0x4(%eax),%eax
 10004e2:	0f af 44 24 2c       	imul   0x2c(%esp),%eax
 10004e7:	03 44 24 28          	add    0x28(%esp),%eax
 10004eb:	89 44 24 08          	mov    %eax,0x8(%esp)
 10004ef:	8b 44 24 24          	mov    0x24(%esp),%eax
 10004f3:	8b 40 04             	mov    0x4(%eax),%eax
 10004f6:	0f af 44 24 2c       	imul   0x2c(%esp),%eax
 10004fb:	03 44 24 28          	add    0x28(%esp),%eax
 10004ff:	89 44 24 04          	mov    %eax,0x4(%esp)
 1000503:	fc                   	cld    
 1000504:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 100050b:	00 
 100050c:	eb 45                	jmp    1000553 <draw_copy+0x152>
 100050e:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000512:	8b 00                	mov    (%eax),%eax
 1000514:	8b 54 24 08          	mov    0x8(%esp),%edx
 1000518:	01 d2                	add    %edx,%edx
 100051a:	01 c2                	add    %eax,%edx
 100051c:	8b 44 24 24          	mov    0x24(%esp),%eax
 1000520:	8b 00                	mov    (%eax),%eax
 1000522:	8b 4c 24 04          	mov    0x4(%esp),%ecx
 1000526:	01 c9                	add    %ecx,%ecx
 1000528:	8d 1c 08             	lea    (%eax,%ecx,1),%ebx
 100052b:	8b 44 24 30          	mov    0x30(%esp),%eax
 100052f:	89 c1                	mov    %eax,%ecx
 1000531:	89 d6                	mov    %edx,%esi
 1000533:	89 df                	mov    %ebx,%edi
 1000535:	f3 66 a5             	rep movsw %ds:(%esi),%es:(%edi)
 1000538:	8b 44 24 20          	mov    0x20(%esp),%eax
 100053c:	8b 40 04             	mov    0x4(%eax),%eax
 100053f:	01 44 24 08          	add    %eax,0x8(%esp)
 1000543:	8b 44 24 24          	mov    0x24(%esp),%eax
 1000547:	8b 40 04             	mov    0x4(%eax),%eax
 100054a:	01 44 24 04          	add    %eax,0x4(%esp)
 100054e:	83 44 24 0c 01       	addl   $0x1,0xc(%esp)
 1000553:	8b 44 24 0c          	mov    0xc(%esp),%eax
 1000557:	3b 44 24 34          	cmp    0x34(%esp),%eax
 100055b:	72 b1                	jb     100050e <draw_copy+0x10d>
 100055d:	eb 0a                	jmp    1000569 <draw_copy+0x168>
 100055f:	90                   	nop
 1000560:	eb 07                	jmp    1000569 <draw_copy+0x168>
 1000562:	90                   	nop
 1000563:	eb 04                	jmp    1000569 <draw_copy+0x168>
 1000565:	90                   	nop
 1000566:	eb 01                	jmp    1000569 <draw_copy+0x168>
 1000568:	90                   	nop
 1000569:	83 c4 10             	add    $0x10,%esp
 100056c:	5b                   	pop    %ebx
 100056d:	5e                   	pop    %esi
 100056e:	5f                   	pop    %edi
 100056f:	c3                   	ret    

01000570 <draw_window>:
 1000570:	57                   	push   %edi
 1000571:	56                   	push   %esi
 1000572:	53                   	push   %ebx
 1000573:	83 ec 10             	sub    $0x10,%esp
 1000576:	8b 44 24 24          	mov    0x24(%esp),%eax
 100057a:	8b 40 04             	mov    0x4(%eax),%eax
 100057d:	3b 44 24 28          	cmp    0x28(%esp),%eax
 1000581:	0f 86 25 01 00 00    	jbe    10006ac <draw_window+0x13c>
 1000587:	8b 44 24 24          	mov    0x24(%esp),%eax
 100058b:	8b 40 08             	mov    0x8(%eax),%eax
 100058e:	3b 44 24 2c          	cmp    0x2c(%esp),%eax
 1000592:	0f 86 17 01 00 00    	jbe    10006af <draw_window+0x13f>
 1000598:	8b 44 24 20          	mov    0x20(%esp),%eax
 100059c:	8b 40 04             	mov    0x4(%eax),%eax
 100059f:	3b 44 24 30          	cmp    0x30(%esp),%eax
 10005a3:	77 0b                	ja     10005b0 <draw_window+0x40>
 10005a5:	8b 44 24 20          	mov    0x20(%esp),%eax
 10005a9:	8b 40 04             	mov    0x4(%eax),%eax
 10005ac:	89 44 24 30          	mov    %eax,0x30(%esp)
 10005b0:	8b 44 24 20          	mov    0x20(%esp),%eax
 10005b4:	8b 40 08             	mov    0x8(%eax),%eax
 10005b7:	3b 44 24 34          	cmp    0x34(%esp),%eax
 10005bb:	77 0b                	ja     10005c8 <draw_window+0x58>
 10005bd:	8b 44 24 20          	mov    0x20(%esp),%eax
 10005c1:	8b 40 08             	mov    0x8(%eax),%eax
 10005c4:	89 44 24 34          	mov    %eax,0x34(%esp)
 10005c8:	8b 44 24 30          	mov    0x30(%esp),%eax
 10005cc:	8b 54 24 28          	mov    0x28(%esp),%edx
 10005d0:	01 c2                	add    %eax,%edx
 10005d2:	8b 44 24 24          	mov    0x24(%esp),%eax
 10005d6:	8b 40 04             	mov    0x4(%eax),%eax
 10005d9:	39 c2                	cmp    %eax,%edx
 10005db:	72 0f                	jb     10005ec <draw_window+0x7c>
 10005dd:	8b 44 24 24          	mov    0x24(%esp),%eax
 10005e1:	8b 40 04             	mov    0x4(%eax),%eax
 10005e4:	2b 44 24 28          	sub    0x28(%esp),%eax
 10005e8:	89 44 24 30          	mov    %eax,0x30(%esp)
 10005ec:	8b 44 24 34          	mov    0x34(%esp),%eax
 10005f0:	8b 54 24 2c          	mov    0x2c(%esp),%edx
 10005f4:	01 c2                	add    %eax,%edx
 10005f6:	8b 44 24 20          	mov    0x20(%esp),%eax
 10005fa:	8b 40 08             	mov    0x8(%eax),%eax
 10005fd:	39 c2                	cmp    %eax,%edx
 10005ff:	72 0f                	jb     1000610 <draw_window+0xa0>
 1000601:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000605:	8b 40 08             	mov    0x8(%eax),%eax
 1000608:	2b 44 24 2c          	sub    0x2c(%esp),%eax
 100060c:	89 44 24 34          	mov    %eax,0x34(%esp)
 1000610:	8b 44 24 34          	mov    0x34(%esp),%eax
 1000614:	8b 54 24 2c          	mov    0x2c(%esp),%edx
 1000618:	01 c2                	add    %eax,%edx
 100061a:	8b 44 24 24          	mov    0x24(%esp),%eax
 100061e:	8b 40 08             	mov    0x8(%eax),%eax
 1000621:	39 c2                	cmp    %eax,%edx
 1000623:	72 0f                	jb     1000634 <draw_window+0xc4>
 1000625:	8b 44 24 24          	mov    0x24(%esp),%eax
 1000629:	8b 40 08             	mov    0x8(%eax),%eax
 100062c:	2b 44 24 2c          	sub    0x2c(%esp),%eax
 1000630:	89 44 24 34          	mov    %eax,0x34(%esp)
 1000634:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 100063b:	00 
 100063c:	8b 44 24 24          	mov    0x24(%esp),%eax
 1000640:	8b 40 04             	mov    0x4(%eax),%eax
 1000643:	0f af 44 24 2c       	imul   0x2c(%esp),%eax
 1000648:	03 44 24 28          	add    0x28(%esp),%eax
 100064c:	89 44 24 04          	mov    %eax,0x4(%esp)
 1000650:	fc                   	cld    
 1000651:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 1000658:	00 
 1000659:	eb 45                	jmp    10006a0 <draw_window+0x130>
 100065b:	8b 44 24 20          	mov    0x20(%esp),%eax
 100065f:	8b 00                	mov    (%eax),%eax
 1000661:	8b 54 24 08          	mov    0x8(%esp),%edx
 1000665:	01 d2                	add    %edx,%edx
 1000667:	01 c2                	add    %eax,%edx
 1000669:	8b 44 24 24          	mov    0x24(%esp),%eax
 100066d:	8b 00                	mov    (%eax),%eax
 100066f:	8b 4c 24 04          	mov    0x4(%esp),%ecx
 1000673:	01 c9                	add    %ecx,%ecx
 1000675:	8d 1c 08             	lea    (%eax,%ecx,1),%ebx
 1000678:	8b 44 24 30          	mov    0x30(%esp),%eax
 100067c:	89 c1                	mov    %eax,%ecx
 100067e:	89 d6                	mov    %edx,%esi
 1000680:	89 df                	mov    %ebx,%edi
 1000682:	f3 66 a5             	rep movsw %ds:(%esi),%es:(%edi)
 1000685:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000689:	8b 40 04             	mov    0x4(%eax),%eax
 100068c:	01 44 24 08          	add    %eax,0x8(%esp)
 1000690:	8b 44 24 24          	mov    0x24(%esp),%eax
 1000694:	8b 40 04             	mov    0x4(%eax),%eax
 1000697:	01 44 24 04          	add    %eax,0x4(%esp)
 100069b:	83 44 24 0c 01       	addl   $0x1,0xc(%esp)
 10006a0:	8b 44 24 0c          	mov    0xc(%esp),%eax
 10006a4:	3b 44 24 34          	cmp    0x34(%esp),%eax
 10006a8:	72 b1                	jb     100065b <draw_window+0xeb>
 10006aa:	eb 04                	jmp    10006b0 <draw_window+0x140>
 10006ac:	90                   	nop
 10006ad:	eb 01                	jmp    10006b0 <draw_window+0x140>
 10006af:	90                   	nop
 10006b0:	83 c4 10             	add    $0x10,%esp
 10006b3:	5b                   	pop    %ebx
 10006b4:	5e                   	pop    %esi
 10006b5:	5f                   	pop    %edi
 10006b6:	c3                   	ret    

010006b7 <draw_cursor_mask>:
 10006b7:	83 ec 24             	sub    $0x24,%esp
 10006ba:	8b 44 24 38          	mov    0x38(%esp),%eax
 10006be:	66 89 04 24          	mov    %ax,(%esp)
 10006c2:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 10006c6:	8b 40 04             	mov    0x4(%eax),%eax
 10006c9:	3b 44 24 30          	cmp    0x30(%esp),%eax
 10006cd:	0f 86 17 01 00 00    	jbe    10007ea <draw_cursor_mask+0x133>
 10006d3:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 10006d7:	8b 40 08             	mov    0x8(%eax),%eax
 10006da:	3b 44 24 34          	cmp    0x34(%esp),%eax
 10006de:	0f 86 09 01 00 00    	jbe    10007ed <draw_cursor_mask+0x136>
 10006e4:	8b 44 24 28          	mov    0x28(%esp),%eax
 10006e8:	8b 00                	mov    (%eax),%eax
 10006ea:	89 44 24 10          	mov    %eax,0x10(%esp)
 10006ee:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 10006f2:	8b 00                	mov    (%eax),%eax
 10006f4:	89 44 24 0c          	mov    %eax,0xc(%esp)
 10006f8:	8b 44 24 28          	mov    0x28(%esp),%eax
 10006fc:	8b 40 04             	mov    0x4(%eax),%eax
 10006ff:	89 44 24 18          	mov    %eax,0x18(%esp)
 1000703:	8b 44 24 28          	mov    0x28(%esp),%eax
 1000707:	8b 40 08             	mov    0x8(%eax),%eax
 100070a:	89 44 24 14          	mov    %eax,0x14(%esp)
 100070e:	8b 44 24 18          	mov    0x18(%esp),%eax
 1000712:	89 c2                	mov    %eax,%edx
 1000714:	03 54 24 30          	add    0x30(%esp),%edx
 1000718:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 100071c:	8b 40 04             	mov    0x4(%eax),%eax
 100071f:	39 c2                	cmp    %eax,%edx
 1000721:	72 0f                	jb     1000732 <draw_cursor_mask+0x7b>
 1000723:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 1000727:	8b 40 04             	mov    0x4(%eax),%eax
 100072a:	2b 44 24 30          	sub    0x30(%esp),%eax
 100072e:	89 44 24 18          	mov    %eax,0x18(%esp)
 1000732:	8b 44 24 14          	mov    0x14(%esp),%eax
 1000736:	89 c2                	mov    %eax,%edx
 1000738:	03 54 24 34          	add    0x34(%esp),%edx
 100073c:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 1000740:	8b 40 08             	mov    0x8(%eax),%eax
 1000743:	39 c2                	cmp    %eax,%edx
 1000745:	72 0f                	jb     1000756 <draw_cursor_mask+0x9f>
 1000747:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 100074b:	8b 40 08             	mov    0x8(%eax),%eax
 100074e:	2b 44 24 34          	sub    0x34(%esp),%eax
 1000752:	89 44 24 14          	mov    %eax,0x14(%esp)
 1000756:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 100075a:	8b 40 04             	mov    0x4(%eax),%eax
 100075d:	0f af 44 24 34       	imul   0x34(%esp),%eax
 1000762:	03 44 24 30          	add    0x30(%esp),%eax
 1000766:	01 c0                	add    %eax,%eax
 1000768:	01 44 24 0c          	add    %eax,0xc(%esp)
 100076c:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
 1000773:	00 
 1000774:	eb 68                	jmp    10007de <draw_cursor_mask+0x127>
 1000776:	c7 44 24 20 00 00 00 	movl   $0x0,0x20(%esp)
 100077d:	00 
 100077e:	eb 35                	jmp    10007b5 <draw_cursor_mask+0xfe>
 1000780:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000784:	01 c0                	add    %eax,%eax
 1000786:	03 44 24 10          	add    0x10(%esp),%eax
 100078a:	0f b7 00             	movzwl (%eax),%eax
 100078d:	66 3b 04 24          	cmp    (%esp),%ax
 1000791:	74 1c                	je     10007af <draw_cursor_mask+0xf8>
 1000793:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000797:	01 c0                	add    %eax,%eax
 1000799:	03 44 24 0c          	add    0xc(%esp),%eax
 100079d:	8b 54 24 20          	mov    0x20(%esp),%edx
 10007a1:	01 d2                	add    %edx,%edx
 10007a3:	03 54 24 10          	add    0x10(%esp),%edx
 10007a7:	0f b7 12             	movzwl (%edx),%edx
 10007aa:	66 89 10             	mov    %dx,(%eax)
 10007ad:	eb 01                	jmp    10007b0 <draw_cursor_mask+0xf9>
 10007af:	90                   	nop
 10007b0:	83 44 24 20 01       	addl   $0x1,0x20(%esp)
 10007b5:	8b 44 24 20          	mov    0x20(%esp),%eax
 10007b9:	3b 44 24 18          	cmp    0x18(%esp),%eax
 10007bd:	7c c1                	jl     1000780 <draw_cursor_mask+0xc9>
 10007bf:	8b 44 24 28          	mov    0x28(%esp),%eax
 10007c3:	8b 40 04             	mov    0x4(%eax),%eax
 10007c6:	01 c0                	add    %eax,%eax
 10007c8:	01 44 24 10          	add    %eax,0x10(%esp)
 10007cc:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 10007d0:	8b 40 04             	mov    0x4(%eax),%eax
 10007d3:	01 c0                	add    %eax,%eax
 10007d5:	01 44 24 0c          	add    %eax,0xc(%esp)
 10007d9:	83 44 24 1c 01       	addl   $0x1,0x1c(%esp)
 10007de:	8b 44 24 1c          	mov    0x1c(%esp),%eax
 10007e2:	3b 44 24 14          	cmp    0x14(%esp),%eax
 10007e6:	7c 8e                	jl     1000776 <draw_cursor_mask+0xbf>
 10007e8:	eb 04                	jmp    10007ee <draw_cursor_mask+0x137>
 10007ea:	90                   	nop
 10007eb:	eb 01                	jmp    10007ee <draw_cursor_mask+0x137>
 10007ed:	90                   	nop
 10007ee:	83 c4 24             	add    $0x24,%esp
 10007f1:	c3                   	ret    

010007f2 <draw_x_line>:
 10007f2:	57                   	push   %edi
 10007f3:	53                   	push   %ebx
 10007f4:	83 ec 04             	sub    $0x4,%esp
 10007f7:	8b 44 24 20          	mov    0x20(%esp),%eax
 10007fb:	66 89 04 24          	mov    %ax,(%esp)
 10007ff:	8b 44 24 18          	mov    0x18(%esp),%eax
 1000803:	3b 44 24 1c          	cmp    0x1c(%esp),%eax
 1000807:	77 33                	ja     100083c <draw_x_line+0x4a>
 1000809:	8b 44 24 18          	mov    0x18(%esp),%eax
 100080d:	8b 54 24 1c          	mov    0x1c(%esp),%edx
 1000811:	29 c2                	sub    %eax,%edx
 1000813:	8b 44 24 10          	mov    0x10(%esp),%eax
 1000817:	8b 08                	mov    (%eax),%ecx
 1000819:	8b 44 24 10          	mov    0x10(%esp),%eax
 100081d:	8b 40 04             	mov    0x4(%eax),%eax
 1000820:	0f af 44 24 14       	imul   0x14(%esp),%eax
 1000825:	03 44 24 18          	add    0x18(%esp),%eax
 1000829:	01 c0                	add    %eax,%eax
 100082b:	8d 1c 01             	lea    (%ecx,%eax,1),%ebx
 100082e:	0f b7 04 24          	movzwl (%esp),%eax
 1000832:	89 d1                	mov    %edx,%ecx
 1000834:	89 df                	mov    %ebx,%edi
 1000836:	fc                   	cld    
 1000837:	f3 66 ab             	rep stos %ax,%es:(%edi)
 100083a:	eb 01                	jmp    100083d <draw_x_line+0x4b>
 100083c:	90                   	nop
 100083d:	83 c4 04             	add    $0x4,%esp
 1000840:	5b                   	pop    %ebx
 1000841:	5f                   	pop    %edi
 1000842:	c3                   	ret    

01000843 <draw_y_line>:
 1000843:	83 ec 24             	sub    $0x24,%esp
 1000846:	8b 44 24 38          	mov    0x38(%esp),%eax
 100084a:	66 89 44 24 10       	mov    %ax,0x10(%esp)
 100084f:	8b 44 24 30          	mov    0x30(%esp),%eax
 1000853:	89 44 24 20          	mov    %eax,0x20(%esp)
 1000857:	eb 2a                	jmp    1000883 <draw_y_line+0x40>
 1000859:	0f b7 54 24 10       	movzwl 0x10(%esp),%edx
 100085e:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000862:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1000866:	89 44 24 08          	mov    %eax,0x8(%esp)
 100086a:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 100086e:	89 44 24 04          	mov    %eax,0x4(%esp)
 1000872:	8b 44 24 28          	mov    0x28(%esp),%eax
 1000876:	89 04 24             	mov    %eax,(%esp)
 1000879:	e8 bf f9 ff ff       	call   100023d <draw_set_point>
 100087e:	83 44 24 20 01       	addl   $0x1,0x20(%esp)
 1000883:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000887:	3b 44 24 34          	cmp    0x34(%esp),%eax
 100088b:	76 cc                	jbe    1000859 <draw_y_line+0x16>
 100088d:	83 c4 24             	add    $0x24,%esp
 1000890:	c3                   	ret    

01000891 <draw_rect>:
 1000891:	83 ec 1c             	sub    $0x1c,%esp
 1000894:	8b 44 24 34          	mov    0x34(%esp),%eax
 1000898:	66 89 44 24 18       	mov    %ax,0x18(%esp)
 100089d:	0f b7 44 24 18       	movzwl 0x18(%esp),%eax
 10008a2:	89 44 24 10          	mov    %eax,0x10(%esp)
 10008a6:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 10008aa:	89 44 24 0c          	mov    %eax,0xc(%esp)
 10008ae:	8b 44 24 24          	mov    0x24(%esp),%eax
 10008b2:	89 44 24 08          	mov    %eax,0x8(%esp)
 10008b6:	8b 44 24 28          	mov    0x28(%esp),%eax
 10008ba:	89 44 24 04          	mov    %eax,0x4(%esp)
 10008be:	8b 44 24 20          	mov    0x20(%esp),%eax
 10008c2:	89 04 24             	mov    %eax,(%esp)
 10008c5:	e8 28 ff ff ff       	call   10007f2 <draw_x_line>
 10008ca:	0f b7 44 24 18       	movzwl 0x18(%esp),%eax
 10008cf:	89 44 24 10          	mov    %eax,0x10(%esp)
 10008d3:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 10008d7:	89 44 24 0c          	mov    %eax,0xc(%esp)
 10008db:	8b 44 24 24          	mov    0x24(%esp),%eax
 10008df:	89 44 24 08          	mov    %eax,0x8(%esp)
 10008e3:	8b 44 24 30          	mov    0x30(%esp),%eax
 10008e7:	89 44 24 04          	mov    %eax,0x4(%esp)
 10008eb:	8b 44 24 20          	mov    0x20(%esp),%eax
 10008ef:	89 04 24             	mov    %eax,(%esp)
 10008f2:	e8 fb fe ff ff       	call   10007f2 <draw_x_line>
 10008f7:	0f b7 44 24 18       	movzwl 0x18(%esp),%eax
 10008fc:	89 44 24 10          	mov    %eax,0x10(%esp)
 1000900:	8b 44 24 30          	mov    0x30(%esp),%eax
 1000904:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1000908:	8b 44 24 28          	mov    0x28(%esp),%eax
 100090c:	89 44 24 08          	mov    %eax,0x8(%esp)
 1000910:	8b 44 24 24          	mov    0x24(%esp),%eax
 1000914:	89 44 24 04          	mov    %eax,0x4(%esp)
 1000918:	8b 44 24 20          	mov    0x20(%esp),%eax
 100091c:	89 04 24             	mov    %eax,(%esp)
 100091f:	e8 1f ff ff ff       	call   1000843 <draw_y_line>
 1000924:	0f b7 44 24 18       	movzwl 0x18(%esp),%eax
 1000929:	89 44 24 10          	mov    %eax,0x10(%esp)
 100092d:	8b 44 24 30          	mov    0x30(%esp),%eax
 1000931:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1000935:	8b 44 24 28          	mov    0x28(%esp),%eax
 1000939:	89 44 24 08          	mov    %eax,0x8(%esp)
 100093d:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 1000941:	89 44 24 04          	mov    %eax,0x4(%esp)
 1000945:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000949:	89 04 24             	mov    %eax,(%esp)
 100094c:	e8 f2 fe ff ff       	call   1000843 <draw_y_line>
 1000951:	83 7c 24 38 00       	cmpl   $0x0,0x38(%esp)
 1000956:	74 35                	je     100098d <draw_rect+0xfc>
 1000958:	0f b7 44 24 18       	movzwl 0x18(%esp),%eax
 100095d:	89 44 24 14          	mov    %eax,0x14(%esp)
 1000961:	8b 44 24 30          	mov    0x30(%esp),%eax
 1000965:	89 44 24 10          	mov    %eax,0x10(%esp)
 1000969:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 100096d:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1000971:	8b 44 24 28          	mov    0x28(%esp),%eax
 1000975:	89 44 24 08          	mov    %eax,0x8(%esp)
 1000979:	8b 44 24 24          	mov    0x24(%esp),%eax
 100097d:	89 44 24 04          	mov    %eax,0x4(%esp)
 1000981:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000985:	89 04 24             	mov    %eax,(%esp)
 1000988:	e8 46 f9 ff ff       	call   10002d3 <draw_fill_rect>
 100098d:	83 c4 1c             	add    $0x1c,%esp
 1000990:	c3                   	ret    

01000991 <draw_string>:
 1000991:	83 ec 3c             	sub    $0x3c,%esp
 1000994:	8b 44 24 50          	mov    0x50(%esp),%eax
 1000998:	66 89 44 24 2c       	mov    %ax,0x2c(%esp)
 100099d:	eb 3d                	jmp    10009dc <draw_string+0x4b>
 100099f:	0f b7 54 24 2c       	movzwl 0x2c(%esp),%edx
 10009a4:	8b 44 24 4c          	mov    0x4c(%esp),%eax
 10009a8:	0f b6 00             	movzbl (%eax),%eax
 10009ab:	0f be c0             	movsbl %al,%eax
 10009ae:	89 54 24 10          	mov    %edx,0x10(%esp)
 10009b2:	89 44 24 0c          	mov    %eax,0xc(%esp)
 10009b6:	8b 44 24 48          	mov    0x48(%esp),%eax
 10009ba:	89 44 24 08          	mov    %eax,0x8(%esp)
 10009be:	8b 44 24 44          	mov    0x44(%esp),%eax
 10009c2:	89 44 24 04          	mov    %eax,0x4(%esp)
 10009c6:	8b 44 24 40          	mov    0x40(%esp),%eax
 10009ca:	89 04 24             	mov    %eax,(%esp)
 10009cd:	e8 1d 00 00 00       	call   10009ef <draw_ascii>
 10009d2:	83 44 24 44 08       	addl   $0x8,0x44(%esp)
 10009d7:	83 44 24 4c 01       	addl   $0x1,0x4c(%esp)
 10009dc:	8b 44 24 4c          	mov    0x4c(%esp),%eax
 10009e0:	0f b6 00             	movzbl (%eax),%eax
 10009e3:	84 c0                	test   %al,%al
 10009e5:	75 b8                	jne    100099f <draw_string+0xe>
 10009e7:	8b 44 24 44          	mov    0x44(%esp),%eax
 10009eb:	83 c4 3c             	add    $0x3c,%esp
 10009ee:	c3                   	ret    

010009ef <draw_ascii>:
 10009ef:	53                   	push   %ebx
 10009f0:	83 ec 14             	sub    $0x14,%esp
 10009f3:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 10009f7:	66 89 04 24          	mov    %ax,(%esp)
 10009fb:	8b 44 24 28          	mov    0x28(%esp),%eax
 10009ff:	c1 e0 04             	shl    $0x4,%eax
 1000a02:	05 60 43 02 01       	add    $0x1024360,%eax
 1000a07:	89 44 24 10          	mov    %eax,0x10(%esp)
 1000a0b:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 1000a12:	00 
 1000a13:	e9 b2 00 00 00       	jmp    1000aca <draw_ascii+0xdb>
 1000a18:	8b 44 24 10          	mov    0x10(%esp),%eax
 1000a1c:	0f b6 00             	movzbl (%eax),%eax
 1000a1f:	88 44 24 0f          	mov    %al,0xf(%esp)
 1000a23:	83 44 24 10 01       	addl   $0x1,0x10(%esp)
 1000a28:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 1000a2f:	00 
 1000a30:	e9 85 00 00 00       	jmp    1000aba <draw_ascii+0xcb>
 1000a35:	0f be 44 24 0f       	movsbl 0xf(%esp),%eax
 1000a3a:	83 e0 01             	and    $0x1,%eax
 1000a3d:	84 c0                	test   %al,%al
 1000a3f:	74 3a                	je     1000a7b <draw_ascii+0x8c>
 1000a41:	8b 44 24 1c          	mov    0x1c(%esp),%eax
 1000a45:	8b 10                	mov    (%eax),%edx
 1000a47:	8b 44 24 04          	mov    0x4(%esp),%eax
 1000a4b:	89 c1                	mov    %eax,%ecx
 1000a4d:	03 4c 24 24          	add    0x24(%esp),%ecx
 1000a51:	8b 44 24 1c          	mov    0x1c(%esp),%eax
 1000a55:	8b 40 04             	mov    0x4(%eax),%eax
 1000a58:	0f af c1             	imul   %ecx,%eax
 1000a5b:	89 c1                	mov    %eax,%ecx
 1000a5d:	03 4c 24 20          	add    0x20(%esp),%ecx
 1000a61:	8b 44 24 08          	mov    0x8(%esp),%eax
 1000a65:	89 cb                	mov    %ecx,%ebx
 1000a67:	29 c3                	sub    %eax,%ebx
 1000a69:	89 d8                	mov    %ebx,%eax
 1000a6b:	83 c0 08             	add    $0x8,%eax
 1000a6e:	01 c0                	add    %eax,%eax
 1000a70:	01 c2                	add    %eax,%edx
 1000a72:	0f b7 04 24          	movzwl (%esp),%eax
 1000a76:	66 89 02             	mov    %ax,(%edx)
 1000a79:	eb 36                	jmp    1000ab1 <draw_ascii+0xc2>
 1000a7b:	8b 44 24 1c          	mov    0x1c(%esp),%eax
 1000a7f:	8b 10                	mov    (%eax),%edx
 1000a81:	8b 44 24 04          	mov    0x4(%esp),%eax
 1000a85:	89 c1                	mov    %eax,%ecx
 1000a87:	03 4c 24 24          	add    0x24(%esp),%ecx
 1000a8b:	8b 44 24 1c          	mov    0x1c(%esp),%eax
 1000a8f:	8b 40 04             	mov    0x4(%eax),%eax
 1000a92:	0f af c1             	imul   %ecx,%eax
 1000a95:	89 c1                	mov    %eax,%ecx
 1000a97:	03 4c 24 20          	add    0x20(%esp),%ecx
 1000a9b:	8b 44 24 08          	mov    0x8(%esp),%eax
 1000a9f:	89 cb                	mov    %ecx,%ebx
 1000aa1:	29 c3                	sub    %eax,%ebx
 1000aa3:	89 d8                	mov    %ebx,%eax
 1000aa5:	83 c0 08             	add    $0x8,%eax
 1000aa8:	01 c0                	add    %eax,%eax
 1000aaa:	01 d0                	add    %edx,%eax
 1000aac:	66 c7 00 ff ff       	movw   $0xffff,(%eax)
 1000ab1:	d0 7c 24 0f          	sarb   0xf(%esp)
 1000ab5:	83 44 24 08 01       	addl   $0x1,0x8(%esp)
 1000aba:	83 7c 24 08 07       	cmpl   $0x7,0x8(%esp)
 1000abf:	0f 8e 70 ff ff ff    	jle    1000a35 <draw_ascii+0x46>
 1000ac5:	83 44 24 04 01       	addl   $0x1,0x4(%esp)
 1000aca:	83 7c 24 04 0f       	cmpl   $0xf,0x4(%esp)
 1000acf:	0f 8e 43 ff ff ff    	jle    1000a18 <draw_ascii+0x29>
 1000ad5:	83 c4 14             	add    $0x14,%esp
 1000ad8:	5b                   	pop    %ebx
 1000ad9:	c3                   	ret    

01000ada <draw_bmp16>:
 1000ada:	83 ec 34             	sub    $0x34,%esp
 1000add:	8b 44 24 48          	mov    0x48(%esp),%eax
 1000ae1:	66 89 44 24 10       	mov    %ax,0x10(%esp)
 1000ae6:	8b 44 24 44          	mov    0x44(%esp),%eax
 1000aea:	89 44 24 24          	mov    %eax,0x24(%esp)
 1000aee:	8b 44 24 24          	mov    0x24(%esp),%eax
 1000af2:	8b 40 12             	mov    0x12(%eax),%eax
 1000af5:	89 44 24 20          	mov    %eax,0x20(%esp)
 1000af9:	8b 44 24 24          	mov    0x24(%esp),%eax
 1000afd:	8b 40 16             	mov    0x16(%eax),%eax
 1000b00:	89 44 24 1c          	mov    %eax,0x1c(%esp)
 1000b04:	8b 44 24 24          	mov    0x24(%esp),%eax
 1000b08:	8b 50 0a             	mov    0xa(%eax),%edx
 1000b0b:	8b 44 24 44          	mov    0x44(%esp),%eax
 1000b0f:	01 d0                	add    %edx,%eax
 1000b11:	89 44 24 28          	mov    %eax,0x28(%esp)
 1000b15:	8b 44 24 20          	mov    0x20(%esp),%eax
 1000b19:	8d 14 00             	lea    (%eax,%eax,1),%edx
 1000b1c:	89 d0                	mov    %edx,%eax
 1000b1e:	c1 f8 1f             	sar    $0x1f,%eax
 1000b21:	c1 e8 1e             	shr    $0x1e,%eax
 1000b24:	01 c2                	add    %eax,%edx
 1000b26:	83 e2 03             	and    $0x3,%edx
 1000b29:	89 d1                	mov    %edx,%ecx
 1000b2b:	29 c1                	sub    %eax,%ecx
 1000b2d:	89 c8                	mov    %ecx,%eax
 1000b2f:	89 c2                	mov    %eax,%edx
 1000b31:	c1 ea 1f             	shr    $0x1f,%edx
 1000b34:	01 d0                	add    %edx,%eax
 1000b36:	d1 f8                	sar    %eax
 1000b38:	89 44 24 18          	mov    %eax,0x18(%esp)
 1000b3c:	8b 44 24 1c          	mov    0x1c(%esp),%eax
 1000b40:	83 e8 01             	sub    $0x1,%eax
 1000b43:	89 44 24 30          	mov    %eax,0x30(%esp)
 1000b47:	e9 96 00 00 00       	jmp    1000be2 <draw_bmp16+0x108>
 1000b4c:	c7 44 24 2c 00 00 00 	movl   $0x0,0x2c(%esp)
 1000b53:	00 
 1000b54:	eb 73                	jmp    1000bc9 <draw_bmp16+0xef>
 1000b56:	8b 44 24 28          	mov    0x28(%esp),%eax
 1000b5a:	0f b7 00             	movzwl (%eax),%eax
 1000b5d:	66 c1 e8 05          	shr    $0x5,%ax
 1000b61:	0f b7 c0             	movzwl %ax,%eax
 1000b64:	c1 e0 06             	shl    $0x6,%eax
 1000b67:	89 c2                	mov    %eax,%edx
 1000b69:	8b 44 24 28          	mov    0x28(%esp),%eax
 1000b6d:	0f b7 00             	movzwl (%eax),%eax
 1000b70:	83 e0 1f             	and    $0x1f,%eax
 1000b73:	09 d0                	or     %edx,%eax
 1000b75:	83 c8 20             	or     $0x20,%eax
 1000b78:	66 89 44 24 16       	mov    %ax,0x16(%esp)
 1000b7d:	83 7c 24 4c 00       	cmpl   $0x0,0x4c(%esp)
 1000b82:	74 0c                	je     1000b90 <draw_bmp16+0xb6>
 1000b84:	0f b7 44 24 16       	movzwl 0x16(%esp),%eax
 1000b89:	66 3b 44 24 10       	cmp    0x10(%esp),%ax
 1000b8e:	74 2f                	je     1000bbf <draw_bmp16+0xe5>
 1000b90:	0f b7 4c 24 16       	movzwl 0x16(%esp),%ecx
 1000b95:	8b 44 24 30          	mov    0x30(%esp),%eax
 1000b99:	89 c2                	mov    %eax,%edx
 1000b9b:	03 54 24 40          	add    0x40(%esp),%edx
 1000b9f:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 1000ba3:	03 44 24 3c          	add    0x3c(%esp),%eax
 1000ba7:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 1000bab:	89 54 24 08          	mov    %edx,0x8(%esp)
 1000baf:	89 44 24 04          	mov    %eax,0x4(%esp)
 1000bb3:	8b 44 24 38          	mov    0x38(%esp),%eax
 1000bb7:	89 04 24             	mov    %eax,(%esp)
 1000bba:	e8 7e f6 ff ff       	call   100023d <draw_set_point>
 1000bbf:	83 44 24 28 02       	addl   $0x2,0x28(%esp)
 1000bc4:	83 44 24 2c 01       	addl   $0x1,0x2c(%esp)
 1000bc9:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 1000bcd:	3b 44 24 20          	cmp    0x20(%esp),%eax
 1000bd1:	7c 83                	jl     1000b56 <draw_bmp16+0x7c>
 1000bd3:	8b 44 24 18          	mov    0x18(%esp),%eax
 1000bd7:	01 c0                	add    %eax,%eax
 1000bd9:	01 44 24 28          	add    %eax,0x28(%esp)
 1000bdd:	83 6c 24 30 01       	subl   $0x1,0x30(%esp)
 1000be2:	83 7c 24 30 00       	cmpl   $0x0,0x30(%esp)
 1000be7:	0f 89 5f ff ff ff    	jns    1000b4c <draw_bmp16+0x72>
 1000bed:	83 c4 34             	add    $0x34,%esp
 1000bf0:	c3                   	ret    

01000bf1 <draw_bmp>:
 1000bf1:	83 ec 4c             	sub    $0x4c,%esp
 1000bf4:	8b 44 24 60          	mov    0x60(%esp),%eax
 1000bf8:	66 89 44 24 2c       	mov    %ax,0x2c(%esp)
 1000bfd:	8b 44 24 5c          	mov    0x5c(%esp),%eax
 1000c01:	89 44 24 3c          	mov    %eax,0x3c(%esp)
 1000c05:	8b 44 24 3c          	mov    0x3c(%esp),%eax
 1000c09:	0f b7 40 1c          	movzwl 0x1c(%eax),%eax
 1000c0d:	66 83 f8 18          	cmp    $0x18,%ax
 1000c11:	75 37                	jne    1000c4a <draw_bmp+0x59>
 1000c13:	0f b7 44 24 2c       	movzwl 0x2c(%esp),%eax
 1000c18:	8b 54 24 64          	mov    0x64(%esp),%edx
 1000c1c:	89 54 24 14          	mov    %edx,0x14(%esp)
 1000c20:	89 44 24 10          	mov    %eax,0x10(%esp)
 1000c24:	8b 44 24 5c          	mov    0x5c(%esp),%eax
 1000c28:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1000c2c:	8b 44 24 58          	mov    0x58(%esp),%eax
 1000c30:	89 44 24 08          	mov    %eax,0x8(%esp)
 1000c34:	8b 44 24 54          	mov    0x54(%esp),%eax
 1000c38:	89 44 24 04          	mov    %eax,0x4(%esp)
 1000c3c:	8b 44 24 50          	mov    0x50(%esp),%eax
 1000c40:	89 04 24             	mov    %eax,(%esp)
 1000c43:	e8 3b 00 00 00       	call   1000c83 <draw_bmp24>
 1000c48:	eb 35                	jmp    1000c7f <draw_bmp+0x8e>
 1000c4a:	0f b7 44 24 2c       	movzwl 0x2c(%esp),%eax
 1000c4f:	8b 54 24 64          	mov    0x64(%esp),%edx
 1000c53:	89 54 24 14          	mov    %edx,0x14(%esp)
 1000c57:	89 44 24 10          	mov    %eax,0x10(%esp)
 1000c5b:	8b 44 24 5c          	mov    0x5c(%esp),%eax
 1000c5f:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1000c63:	8b 44 24 58          	mov    0x58(%esp),%eax
 1000c67:	89 44 24 08          	mov    %eax,0x8(%esp)
 1000c6b:	8b 44 24 54          	mov    0x54(%esp),%eax
 1000c6f:	89 44 24 04          	mov    %eax,0x4(%esp)
 1000c73:	8b 44 24 50          	mov    0x50(%esp),%eax
 1000c77:	89 04 24             	mov    %eax,(%esp)
 1000c7a:	e8 5b fe ff ff       	call   1000ada <draw_bmp16>
 1000c7f:	83 c4 4c             	add    $0x4c,%esp
 1000c82:	c3                   	ret    

01000c83 <draw_bmp24>:
 1000c83:	83 ec 34             	sub    $0x34,%esp
 1000c86:	8b 44 24 48          	mov    0x48(%esp),%eax
 1000c8a:	66 89 44 24 10       	mov    %ax,0x10(%esp)
 1000c8f:	8b 44 24 44          	mov    0x44(%esp),%eax
 1000c93:	89 44 24 24          	mov    %eax,0x24(%esp)
 1000c97:	8b 44 24 24          	mov    0x24(%esp),%eax
 1000c9b:	8b 40 12             	mov    0x12(%eax),%eax
 1000c9e:	89 44 24 20          	mov    %eax,0x20(%esp)
 1000ca2:	8b 44 24 24          	mov    0x24(%esp),%eax
 1000ca6:	8b 40 16             	mov    0x16(%eax),%eax
 1000ca9:	89 44 24 1c          	mov    %eax,0x1c(%esp)
 1000cad:	8b 44 24 24          	mov    0x24(%esp),%eax
 1000cb1:	8b 50 0a             	mov    0xa(%eax),%edx
 1000cb4:	8b 44 24 44          	mov    0x44(%esp),%eax
 1000cb8:	01 d0                	add    %edx,%eax
 1000cba:	89 44 24 28          	mov    %eax,0x28(%esp)
 1000cbe:	8b 54 24 20          	mov    0x20(%esp),%edx
 1000cc2:	89 d0                	mov    %edx,%eax
 1000cc4:	01 c0                	add    %eax,%eax
 1000cc6:	01 c2                	add    %eax,%edx
 1000cc8:	89 d0                	mov    %edx,%eax
 1000cca:	c1 f8 1f             	sar    $0x1f,%eax
 1000ccd:	c1 e8 1e             	shr    $0x1e,%eax
 1000cd0:	01 c2                	add    %eax,%edx
 1000cd2:	83 e2 03             	and    $0x3,%edx
 1000cd5:	89 d1                	mov    %edx,%ecx
 1000cd7:	29 c1                	sub    %eax,%ecx
 1000cd9:	89 c8                	mov    %ecx,%eax
 1000cdb:	89 44 24 18          	mov    %eax,0x18(%esp)
 1000cdf:	8b 44 24 1c          	mov    0x1c(%esp),%eax
 1000ce3:	83 e8 01             	sub    $0x1,%eax
 1000ce6:	89 44 24 30          	mov    %eax,0x30(%esp)
 1000cea:	e9 ba 00 00 00       	jmp    1000da9 <draw_bmp24+0x126>
 1000cef:	c7 44 24 2c 00 00 00 	movl   $0x0,0x2c(%esp)
 1000cf6:	00 
 1000cf7:	e9 8c 00 00 00       	jmp    1000d88 <draw_bmp24+0x105>
 1000cfc:	8b 44 24 28          	mov    0x28(%esp),%eax
 1000d00:	0f b6 40 02          	movzbl 0x2(%eax),%eax
 1000d04:	c0 e8 03             	shr    $0x3,%al
 1000d07:	0f b6 c0             	movzbl %al,%eax
 1000d0a:	c1 e0 0b             	shl    $0xb,%eax
 1000d0d:	89 c2                	mov    %eax,%edx
 1000d0f:	8b 44 24 28          	mov    0x28(%esp),%eax
 1000d13:	0f b6 40 01          	movzbl 0x1(%eax),%eax
 1000d17:	c0 e8 02             	shr    $0x2,%al
 1000d1a:	0f b6 c0             	movzbl %al,%eax
 1000d1d:	83 e0 3f             	and    $0x3f,%eax
 1000d20:	c1 e0 05             	shl    $0x5,%eax
 1000d23:	01 c2                	add    %eax,%edx
 1000d25:	8b 44 24 28          	mov    0x28(%esp),%eax
 1000d29:	0f b6 00             	movzbl (%eax),%eax
 1000d2c:	c0 e8 03             	shr    $0x3,%al
 1000d2f:	0f b6 c0             	movzbl %al,%eax
 1000d32:	83 e0 1f             	and    $0x1f,%eax
 1000d35:	01 d0                	add    %edx,%eax
 1000d37:	66 89 44 24 16       	mov    %ax,0x16(%esp)
 1000d3c:	83 7c 24 4c 00       	cmpl   $0x0,0x4c(%esp)
 1000d41:	74 0c                	je     1000d4f <draw_bmp24+0xcc>
 1000d43:	0f b7 44 24 16       	movzwl 0x16(%esp),%eax
 1000d48:	66 3b 44 24 10       	cmp    0x10(%esp),%ax
 1000d4d:	74 2f                	je     1000d7e <draw_bmp24+0xfb>
 1000d4f:	0f b7 4c 24 16       	movzwl 0x16(%esp),%ecx
 1000d54:	8b 44 24 30          	mov    0x30(%esp),%eax
 1000d58:	89 c2                	mov    %eax,%edx
 1000d5a:	03 54 24 40          	add    0x40(%esp),%edx
 1000d5e:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 1000d62:	03 44 24 3c          	add    0x3c(%esp),%eax
 1000d66:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 1000d6a:	89 54 24 08          	mov    %edx,0x8(%esp)
 1000d6e:	89 44 24 04          	mov    %eax,0x4(%esp)
 1000d72:	8b 44 24 38          	mov    0x38(%esp),%eax
 1000d76:	89 04 24             	mov    %eax,(%esp)
 1000d79:	e8 bf f4 ff ff       	call   100023d <draw_set_point>
 1000d7e:	83 44 24 28 03       	addl   $0x3,0x28(%esp)
 1000d83:	83 44 24 2c 01       	addl   $0x1,0x2c(%esp)
 1000d88:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 1000d8c:	3b 44 24 20          	cmp    0x20(%esp),%eax
 1000d90:	0f 8c 66 ff ff ff    	jl     1000cfc <draw_bmp24+0x79>
 1000d96:	8b 54 24 28          	mov    0x28(%esp),%edx
 1000d9a:	8b 44 24 18          	mov    0x18(%esp),%eax
 1000d9e:	01 d0                	add    %edx,%eax
 1000da0:	89 44 24 28          	mov    %eax,0x28(%esp)
 1000da4:	83 6c 24 30 01       	subl   $0x1,0x30(%esp)
 1000da9:	83 7c 24 30 00       	cmpl   $0x0,0x30(%esp)
 1000dae:	0f 89 3b ff ff ff    	jns    1000cef <draw_bmp24+0x6c>
 1000db4:	83 c4 34             	add    $0x34,%esp
 1000db7:	c3                   	ret    

01000db8 <_ZN12CBeetleDemonC1EP5CGameii>:
 1000db8:	55                   	push   %ebp
 1000db9:	89 e5                	mov    %esp,%ebp
 1000dbb:	83 ec 28             	sub    $0x28,%esp
 1000dbe:	8b 45 08             	mov    0x8(%ebp),%eax
 1000dc1:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
 1000dc8:	00 
 1000dc9:	c7 44 24 18 10 00 00 	movl   $0x10,0x18(%esp)
 1000dd0:	00 
 1000dd1:	c7 44 24 14 10 00 00 	movl   $0x10,0x14(%esp)
 1000dd8:	00 
 1000dd9:	8b 55 14             	mov    0x14(%ebp),%edx
 1000ddc:	89 54 24 10          	mov    %edx,0x10(%esp)
 1000de0:	8b 55 10             	mov    0x10(%ebp),%edx
 1000de3:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1000de7:	c7 44 24 08 03 00 00 	movl   $0x3,0x8(%esp)
 1000dee:	00 
 1000def:	8b 55 0c             	mov    0xc(%ebp),%edx
 1000df2:	89 54 24 04          	mov    %edx,0x4(%esp)
 1000df6:	89 04 24             	mov    %eax,(%esp)
 1000df9:	e8 92 50 00 00       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 1000dfe:	8b 45 08             	mov    0x8(%ebp),%eax
 1000e01:	c7 00 20 90 00 01    	movl   $0x1009020,(%eax)
 1000e07:	8b 45 08             	mov    0x8(%ebp),%eax
 1000e0a:	c7 40 2c 00 00 00 00 	movl   $0x0,0x2c(%eax)
 1000e11:	8b 45 08             	mov    0x8(%ebp),%eax
 1000e14:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 1000e1b:	8b 45 08             	mov    0x8(%ebp),%eax
 1000e1e:	c7 40 24 fd ff ff ff 	movl   $0xfffffffd,0x24(%eax)
 1000e25:	8b 45 08             	mov    0x8(%ebp),%eax
 1000e28:	c6 40 34 00          	movb   $0x0,0x34(%eax)
 1000e2c:	c9                   	leave  
 1000e2d:	c3                   	ret    

01000e2e <_ZN12CBeetleDemon8GetImageEPbS0_>:
 1000e2e:	55                   	push   %ebp
 1000e2f:	89 e5                	mov    %esp,%ebp
 1000e31:	8b 45 10             	mov    0x10(%ebp),%eax
 1000e34:	c6 00 00             	movb   $0x0,(%eax)
 1000e37:	8b 45 08             	mov    0x8(%ebp),%eax
 1000e3a:	0f b6 50 34          	movzbl 0x34(%eax),%edx
 1000e3e:	8b 45 0c             	mov    0xc(%ebp),%eax
 1000e41:	88 10                	mov    %dl,(%eax)
 1000e43:	8b 45 08             	mov    0x8(%ebp),%eax
 1000e46:	8b 40 2c             	mov    0x2c(%eax),%eax
 1000e49:	c1 e0 0a             	shl    $0xa,%eax
 1000e4c:	05 00 62 01 01       	add    $0x1016200,%eax
 1000e51:	5d                   	pop    %ebp
 1000e52:	c3                   	ret    
 1000e53:	90                   	nop

01000e54 <_ZN12CBeetleDemon5ClockEv>:
 1000e54:	55                   	push   %ebp
 1000e55:	89 e5                	mov    %esp,%ebp
 1000e57:	53                   	push   %ebx
 1000e58:	83 ec 24             	sub    $0x24,%esp
 1000e5b:	8b 45 08             	mov    0x8(%ebp),%eax
 1000e5e:	8b 40 2c             	mov    0x2c(%eax),%eax
 1000e61:	83 f8 02             	cmp    $0x2,%eax
 1000e64:	75 5a                	jne    1000ec0 <_ZN12CBeetleDemon5ClockEv+0x6c>
 1000e66:	8b 45 08             	mov    0x8(%ebp),%eax
 1000e69:	8b 40 08             	mov    0x8(%eax),%eax
 1000e6c:	83 f8 01             	cmp    $0x1,%eax
 1000e6f:	0f 85 83 00 00 00    	jne    1000ef8 <_ZN12CBeetleDemon5ClockEv+0xa4>
 1000e75:	8b 45 08             	mov    0x8(%ebp),%eax
 1000e78:	8b 40 24             	mov    0x24(%eax),%eax
 1000e7b:	85 c0                	test   %eax,%eax
 1000e7d:	75 79                	jne    1000ef8 <_ZN12CBeetleDemon5ClockEv+0xa4>
 1000e7f:	8b 45 08             	mov    0x8(%ebp),%eax
 1000e82:	8b 40 30             	mov    0x30(%eax),%eax
 1000e85:	8d 50 01             	lea    0x1(%eax),%edx
 1000e88:	8b 45 08             	mov    0x8(%ebp),%eax
 1000e8b:	89 50 30             	mov    %edx,0x30(%eax)
 1000e8e:	8b 45 08             	mov    0x8(%ebp),%eax
 1000e91:	8b 40 30             	mov    0x30(%eax),%eax
 1000e94:	83 f8 63             	cmp    $0x63,%eax
 1000e97:	7e 5f                	jle    1000ef8 <_ZN12CBeetleDemon5ClockEv+0xa4>
 1000e99:	8b 45 08             	mov    0x8(%ebp),%eax
 1000e9c:	c7 40 2c 00 00 00 00 	movl   $0x0,0x2c(%eax)
 1000ea3:	8b 45 08             	mov    0x8(%ebp),%eax
 1000ea6:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 1000ead:	8b 45 08             	mov    0x8(%ebp),%eax
 1000eb0:	c7 40 24 fe ff ff ff 	movl   $0xfffffffe,0x24(%eax)
 1000eb7:	8b 45 08             	mov    0x8(%ebp),%eax
 1000eba:	c6 40 34 00          	movb   $0x0,0x34(%eax)
 1000ebe:	eb 38                	jmp    1000ef8 <_ZN12CBeetleDemon5ClockEv+0xa4>
 1000ec0:	8b 45 08             	mov    0x8(%ebp),%eax
 1000ec3:	8b 40 30             	mov    0x30(%eax),%eax
 1000ec6:	8d 50 01             	lea    0x1(%eax),%edx
 1000ec9:	8b 45 08             	mov    0x8(%ebp),%eax
 1000ecc:	89 50 30             	mov    %edx,0x30(%eax)
 1000ecf:	8b 45 08             	mov    0x8(%ebp),%eax
 1000ed2:	8b 40 30             	mov    0x30(%eax),%eax
 1000ed5:	83 f8 04             	cmp    $0x4,%eax
 1000ed8:	7e 1e                	jle    1000ef8 <_ZN12CBeetleDemon5ClockEv+0xa4>
 1000eda:	8b 45 08             	mov    0x8(%ebp),%eax
 1000edd:	8b 40 2c             	mov    0x2c(%eax),%eax
 1000ee0:	85 c0                	test   %eax,%eax
 1000ee2:	0f 94 c0             	sete   %al
 1000ee5:	0f b6 d0             	movzbl %al,%edx
 1000ee8:	8b 45 08             	mov    0x8(%ebp),%eax
 1000eeb:	89 50 2c             	mov    %edx,0x2c(%eax)
 1000eee:	8b 45 08             	mov    0x8(%ebp),%eax
 1000ef1:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 1000ef8:	8b 45 08             	mov    0x8(%ebp),%eax
 1000efb:	8b 40 28             	mov    0x28(%eax),%eax
 1000efe:	8d 50 02             	lea    0x2(%eax),%edx
 1000f01:	8b 45 08             	mov    0x8(%ebp),%eax
 1000f04:	89 50 28             	mov    %edx,0x28(%eax)
 1000f07:	8b 45 08             	mov    0x8(%ebp),%eax
 1000f0a:	8b 40 28             	mov    0x28(%eax),%eax
 1000f0d:	83 f8 14             	cmp    $0x14,%eax
 1000f10:	7e 0a                	jle    1000f1c <_ZN12CBeetleDemon5ClockEv+0xc8>
 1000f12:	8b 45 08             	mov    0x8(%ebp),%eax
 1000f15:	c7 40 28 14 00 00 00 	movl   $0x14,0x28(%eax)
 1000f1c:	8b 45 08             	mov    0x8(%ebp),%eax
 1000f1f:	8b 40 24             	mov    0x24(%eax),%eax
 1000f22:	85 c0                	test   %eax,%eax
 1000f24:	75 0e                	jne    1000f34 <_ZN12CBeetleDemon5ClockEv+0xe0>
 1000f26:	8b 45 08             	mov    0x8(%ebp),%eax
 1000f29:	8b 40 28             	mov    0x28(%eax),%eax
 1000f2c:	85 c0                	test   %eax,%eax
 1000f2e:	0f 84 8d 00 00 00    	je     1000fc1 <_ZN12CBeetleDemon5ClockEv+0x16d>
 1000f34:	8b 45 08             	mov    0x8(%ebp),%eax
 1000f37:	8b 58 28             	mov    0x28(%eax),%ebx
 1000f3a:	8b 45 08             	mov    0x8(%ebp),%eax
 1000f3d:	8b 48 24             	mov    0x24(%eax),%ecx
 1000f40:	8b 55 08             	mov    0x8(%ebp),%edx
 1000f43:	8b 45 08             	mov    0x8(%ebp),%eax
 1000f46:	8b 40 20             	mov    0x20(%eax),%eax
 1000f49:	89 5c 24 0c          	mov    %ebx,0xc(%esp)
 1000f4d:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 1000f51:	89 54 24 04          	mov    %edx,0x4(%esp)
 1000f55:	89 04 24             	mov    %eax,(%esp)
 1000f58:	e8 cd 24 00 00       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 1000f5d:	89 45 f4             	mov    %eax,-0xc(%ebp)
 1000f60:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1000f63:	83 e0 01             	and    $0x1,%eax
 1000f66:	84 c0                	test   %al,%al
 1000f68:	74 43                	je     1000fad <_ZN12CBeetleDemon5ClockEv+0x159>
 1000f6a:	8b 45 08             	mov    0x8(%ebp),%eax
 1000f6d:	8b 40 2c             	mov    0x2c(%eax),%eax
 1000f70:	83 f8 02             	cmp    $0x2,%eax
 1000f73:	75 16                	jne    1000f8b <_ZN12CBeetleDemon5ClockEv+0x137>
 1000f75:	8b 45 08             	mov    0x8(%ebp),%eax
 1000f78:	8b 40 20             	mov    0x20(%eax),%eax
 1000f7b:	c7 44 24 04 02 00 00 	movl   $0x2,0x4(%esp)
 1000f82:	00 
 1000f83:	89 04 24             	mov    %eax,(%esp)
 1000f86:	e8 7d 32 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1000f8b:	8b 45 08             	mov    0x8(%ebp),%eax
 1000f8e:	8b 40 24             	mov    0x24(%eax),%eax
 1000f91:	89 c2                	mov    %eax,%edx
 1000f93:	f7 da                	neg    %edx
 1000f95:	8b 45 08             	mov    0x8(%ebp),%eax
 1000f98:	89 50 24             	mov    %edx,0x24(%eax)
 1000f9b:	8b 45 08             	mov    0x8(%ebp),%eax
 1000f9e:	0f b6 40 34          	movzbl 0x34(%eax),%eax
 1000fa2:	89 c2                	mov    %eax,%edx
 1000fa4:	83 f2 01             	xor    $0x1,%edx
 1000fa7:	8b 45 08             	mov    0x8(%ebp),%eax
 1000faa:	88 50 34             	mov    %dl,0x34(%eax)
 1000fad:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1000fb0:	83 e0 02             	and    $0x2,%eax
 1000fb3:	85 c0                	test   %eax,%eax
 1000fb5:	74 0a                	je     1000fc1 <_ZN12CBeetleDemon5ClockEv+0x16d>
 1000fb7:	8b 45 08             	mov    0x8(%ebp),%eax
 1000fba:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%eax)
 1000fc1:	83 c4 24             	add    $0x24,%esp
 1000fc4:	5b                   	pop    %ebx
 1000fc5:	5d                   	pop    %ebp
 1000fc6:	c3                   	ret    
 1000fc7:	90                   	nop

01000fc8 <_ZN12CBeetleDemon6AttackEP7CObjecti>:
 1000fc8:	55                   	push   %ebp
 1000fc9:	89 e5                	mov    %esp,%ebp
 1000fcb:	83 ec 18             	sub    $0x18,%esp
 1000fce:	8b 45 08             	mov    0x8(%ebp),%eax
 1000fd1:	8b 40 08             	mov    0x8(%eax),%eax
 1000fd4:	83 f8 01             	cmp    $0x1,%eax
 1000fd7:	0f 85 2f 01 00 00    	jne    100110c <_ZN12CBeetleDemon6AttackEP7CObjecti+0x144>
 1000fdd:	8b 45 10             	mov    0x10(%ebp),%eax
 1000fe0:	83 f8 01             	cmp    $0x1,%eax
 1000fe3:	74 0a                	je     1000fef <_ZN12CBeetleDemon6AttackEP7CObjecti+0x27>
 1000fe5:	83 f8 02             	cmp    $0x2,%eax
 1000fe8:	74 61                	je     100104b <_ZN12CBeetleDemon6AttackEP7CObjecti+0x83>
 1000fea:	e9 cb 00 00 00       	jmp    10010ba <_ZN12CBeetleDemon6AttackEP7CObjecti+0xf2>
 1000fef:	8b 45 0c             	mov    0xc(%ebp),%eax
 1000ff2:	8b 40 04             	mov    0x4(%eax),%eax
 1000ff5:	83 f8 04             	cmp    $0x4,%eax
 1000ff8:	0f 84 11 01 00 00    	je     100110f <_ZN12CBeetleDemon6AttackEP7CObjecti+0x147>
 1000ffe:	8b 45 08             	mov    0x8(%ebp),%eax
 1001001:	8b 40 20             	mov    0x20(%eax),%eax
 1001004:	c7 44 24 04 09 00 00 	movl   $0x9,0x4(%esp)
 100100b:	00 
 100100c:	89 04 24             	mov    %eax,(%esp)
 100100f:	e8 f4 31 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1001014:	8b 45 08             	mov    0x8(%ebp),%eax
 1001017:	c7 40 2c 02 00 00 00 	movl   $0x2,0x2c(%eax)
 100101e:	8b 45 08             	mov    0x8(%ebp),%eax
 1001021:	c7 40 08 02 00 00 00 	movl   $0x2,0x8(%eax)
 1001028:	8b 45 08             	mov    0x8(%ebp),%eax
 100102b:	c7 40 28 f6 ff ff ff 	movl   $0xfffffff6,0x28(%eax)
 1001032:	8b 45 08             	mov    0x8(%ebp),%eax
 1001035:	c7 40 24 02 00 00 00 	movl   $0x2,0x24(%eax)
 100103c:	8b 45 08             	mov    0x8(%ebp),%eax
 100103f:	c7 40 1c 01 00 00 00 	movl   $0x1,0x1c(%eax)
 1001046:	e9 c8 00 00 00       	jmp    1001113 <_ZN12CBeetleDemon6AttackEP7CObjecti+0x14b>
 100104b:	8b 45 08             	mov    0x8(%ebp),%eax
 100104e:	8b 40 2c             	mov    0x2c(%eax),%eax
 1001051:	83 f8 02             	cmp    $0x2,%eax
 1001054:	75 1d                	jne    1001073 <_ZN12CBeetleDemon6AttackEP7CObjecti+0xab>
 1001056:	8b 45 08             	mov    0x8(%ebp),%eax
 1001059:	8b 40 2c             	mov    0x2c(%eax),%eax
 100105c:	83 f8 02             	cmp    $0x2,%eax
 100105f:	0f 85 ad 00 00 00    	jne    1001112 <_ZN12CBeetleDemon6AttackEP7CObjecti+0x14a>
 1001065:	8b 45 08             	mov    0x8(%ebp),%eax
 1001068:	8b 40 24             	mov    0x24(%eax),%eax
 100106b:	85 c0                	test   %eax,%eax
 100106d:	0f 84 9f 00 00 00    	je     1001112 <_ZN12CBeetleDemon6AttackEP7CObjecti+0x14a>
 1001073:	8b 45 08             	mov    0x8(%ebp),%eax
 1001076:	8b 40 20             	mov    0x20(%eax),%eax
 1001079:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 1001080:	00 
 1001081:	89 04 24             	mov    %eax,(%esp)
 1001084:	e8 7f 31 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1001089:	8b 45 08             	mov    0x8(%ebp),%eax
 100108c:	c7 40 2c 02 00 00 00 	movl   $0x2,0x2c(%eax)
 1001093:	8b 45 08             	mov    0x8(%ebp),%eax
 1001096:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%eax)
 100109d:	8b 45 08             	mov    0x8(%ebp),%eax
 10010a0:	c7 40 24 00 00 00 00 	movl   $0x0,0x24(%eax)
 10010a7:	8b 45 08             	mov    0x8(%ebp),%eax
 10010aa:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 10010b1:	8b 45 08             	mov    0x8(%ebp),%eax
 10010b4:	c6 40 35 00          	movb   $0x0,0x35(%eax)
 10010b8:	eb 58                	jmp    1001112 <_ZN12CBeetleDemon6AttackEP7CObjecti+0x14a>
 10010ba:	8b 45 0c             	mov    0xc(%ebp),%eax
 10010bd:	8b 40 04             	mov    0x4(%eax),%eax
 10010c0:	83 f8 02             	cmp    $0x2,%eax
 10010c3:	75 4e                	jne    1001113 <_ZN12CBeetleDemon6AttackEP7CObjecti+0x14b>
 10010c5:	8b 45 08             	mov    0x8(%ebp),%eax
 10010c8:	8b 40 20             	mov    0x20(%eax),%eax
 10010cb:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 10010d2:	00 
 10010d3:	89 04 24             	mov    %eax,(%esp)
 10010d6:	e8 2d 31 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 10010db:	8b 45 08             	mov    0x8(%ebp),%eax
 10010de:	c7 40 2c 02 00 00 00 	movl   $0x2,0x2c(%eax)
 10010e5:	8b 45 08             	mov    0x8(%ebp),%eax
 10010e8:	c7 40 28 fc ff ff ff 	movl   $0xfffffffc,0x28(%eax)
 10010ef:	8b 45 08             	mov    0x8(%ebp),%eax
 10010f2:	c7 40 24 00 00 00 00 	movl   $0x0,0x24(%eax)
 10010f9:	8b 45 08             	mov    0x8(%ebp),%eax
 10010fc:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 1001103:	8b 45 08             	mov    0x8(%ebp),%eax
 1001106:	c6 40 35 01          	movb   $0x1,0x35(%eax)
 100110a:	eb 07                	jmp    1001113 <_ZN12CBeetleDemon6AttackEP7CObjecti+0x14b>
 100110c:	90                   	nop
 100110d:	eb 04                	jmp    1001113 <_ZN12CBeetleDemon6AttackEP7CObjecti+0x14b>
 100110f:	90                   	nop
 1001110:	eb 01                	jmp    1001113 <_ZN12CBeetleDemon6AttackEP7CObjecti+0x14b>
 1001112:	90                   	nop
 1001113:	c9                   	leave  
 1001114:	c3                   	ret    
 1001115:	90                   	nop

01001116 <_ZN12CBeetleDemon4BumpEP7CObjectib>:
 1001116:	55                   	push   %ebp
 1001117:	89 e5                	mov    %esp,%ebp
 1001119:	83 ec 28             	sub    $0x28,%esp
 100111c:	8b 45 14             	mov    0x14(%ebp),%eax
 100111f:	88 45 f4             	mov    %al,-0xc(%ebp)
 1001122:	8b 45 08             	mov    0x8(%ebp),%eax
 1001125:	8b 40 08             	mov    0x8(%eax),%eax
 1001128:	83 f8 01             	cmp    $0x1,%eax
 100112b:	0f 85 14 01 00 00    	jne    1001245 <_ZN12CBeetleDemon4BumpEP7CObjectib+0x12f>
 1001131:	8b 45 08             	mov    0x8(%ebp),%eax
 1001134:	8b 40 2c             	mov    0x2c(%eax),%eax
 1001137:	83 f8 02             	cmp    $0x2,%eax
 100113a:	0f 85 cb 00 00 00    	jne    100120b <_ZN12CBeetleDemon4BumpEP7CObjectib+0xf5>
 1001140:	8b 45 08             	mov    0x8(%ebp),%eax
 1001143:	8b 40 24             	mov    0x24(%eax),%eax
 1001146:	85 c0                	test   %eax,%eax
 1001148:	75 6d                	jne    10011b7 <_ZN12CBeetleDemon4BumpEP7CObjectib+0xa1>
 100114a:	8b 45 0c             	mov    0xc(%ebp),%eax
 100114d:	8b 40 04             	mov    0x4(%eax),%eax
 1001150:	83 f8 01             	cmp    $0x1,%eax
 1001153:	0f 85 ed 00 00 00    	jne    1001246 <_ZN12CBeetleDemon4BumpEP7CObjectib+0x130>
 1001159:	8b 45 08             	mov    0x8(%ebp),%eax
 100115c:	0f b6 40 35          	movzbl 0x35(%eax),%eax
 1001160:	84 c0                	test   %al,%al
 1001162:	74 47                	je     10011ab <_ZN12CBeetleDemon4BumpEP7CObjectib+0x95>
 1001164:	8b 45 08             	mov    0x8(%ebp),%eax
 1001167:	8b 40 20             	mov    0x20(%eax),%eax
 100116a:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 1001171:	00 
 1001172:	89 04 24             	mov    %eax,(%esp)
 1001175:	e8 8e 30 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 100117a:	8b 45 0c             	mov    0xc(%ebp),%eax
 100117d:	8b 50 0c             	mov    0xc(%eax),%edx
 1001180:	8b 45 08             	mov    0x8(%ebp),%eax
 1001183:	8b 40 0c             	mov    0xc(%eax),%eax
 1001186:	83 c0 08             	add    $0x8,%eax
 1001189:	39 c2                	cmp    %eax,%edx
 100118b:	7e 0f                	jle    100119c <_ZN12CBeetleDemon4BumpEP7CObjectib+0x86>
 100118d:	8b 45 08             	mov    0x8(%ebp),%eax
 1001190:	c7 40 24 f6 ff ff ff 	movl   $0xfffffff6,0x24(%eax)
 1001197:	e9 aa 00 00 00       	jmp    1001246 <_ZN12CBeetleDemon4BumpEP7CObjectib+0x130>
 100119c:	8b 45 08             	mov    0x8(%ebp),%eax
 100119f:	c7 40 24 0a 00 00 00 	movl   $0xa,0x24(%eax)
 10011a6:	e9 9b 00 00 00       	jmp    1001246 <_ZN12CBeetleDemon4BumpEP7CObjectib+0x130>
 10011ab:	8b 45 08             	mov    0x8(%ebp),%eax
 10011ae:	c6 40 35 01          	movb   $0x1,0x35(%eax)
 10011b2:	e9 8f 00 00 00       	jmp    1001246 <_ZN12CBeetleDemon4BumpEP7CObjectib+0x130>
 10011b7:	8b 45 08             	mov    0x8(%ebp),%eax
 10011ba:	8b 40 08             	mov    0x8(%eax),%eax
 10011bd:	83 f8 01             	cmp    $0x1,%eax
 10011c0:	0f 85 80 00 00 00    	jne    1001246 <_ZN12CBeetleDemon4BumpEP7CObjectib+0x130>
 10011c6:	83 7d 10 03          	cmpl   $0x3,0x10(%ebp)
 10011ca:	74 06                	je     10011d2 <_ZN12CBeetleDemon4BumpEP7CObjectib+0xbc>
 10011cc:	83 7d 10 01          	cmpl   $0x1,0x10(%ebp)
 10011d0:	75 74                	jne    1001246 <_ZN12CBeetleDemon4BumpEP7CObjectib+0x130>
 10011d2:	8b 45 0c             	mov    0xc(%ebp),%eax
 10011d5:	8b 40 04             	mov    0x4(%eax),%eax
 10011d8:	83 f8 01             	cmp    $0x1,%eax
 10011db:	74 0b                	je     10011e8 <_ZN12CBeetleDemon4BumpEP7CObjectib+0xd2>
 10011dd:	8b 45 0c             	mov    0xc(%ebp),%eax
 10011e0:	8b 40 04             	mov    0x4(%eax),%eax
 10011e3:	83 f8 03             	cmp    $0x3,%eax
 10011e6:	75 5e                	jne    1001246 <_ZN12CBeetleDemon4BumpEP7CObjectib+0x130>
 10011e8:	8b 45 0c             	mov    0xc(%ebp),%eax
 10011eb:	8b 00                	mov    (%eax),%eax
 10011ed:	83 c0 10             	add    $0x10,%eax
 10011f0:	8b 10                	mov    (%eax),%edx
 10011f2:	8b 45 08             	mov    0x8(%ebp),%eax
 10011f5:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 10011fc:	00 
 10011fd:	89 44 24 04          	mov    %eax,0x4(%esp)
 1001201:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001204:	89 04 24             	mov    %eax,(%esp)
 1001207:	ff d2                	call   *%edx
 1001209:	eb 3b                	jmp    1001246 <_ZN12CBeetleDemon4BumpEP7CObjectib+0x130>
 100120b:	8b 45 0c             	mov    0xc(%ebp),%eax
 100120e:	8b 40 04             	mov    0x4(%eax),%eax
 1001211:	83 f8 01             	cmp    $0x1,%eax
 1001214:	75 30                	jne    1001246 <_ZN12CBeetleDemon4BumpEP7CObjectib+0x130>
 1001216:	83 7d 10 03          	cmpl   $0x3,0x10(%ebp)
 100121a:	74 06                	je     1001222 <_ZN12CBeetleDemon4BumpEP7CObjectib+0x10c>
 100121c:	83 7d 10 01          	cmpl   $0x1,0x10(%ebp)
 1001220:	75 24                	jne    1001246 <_ZN12CBeetleDemon4BumpEP7CObjectib+0x130>
 1001222:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001225:	8b 00                	mov    (%eax),%eax
 1001227:	83 c0 10             	add    $0x10,%eax
 100122a:	8b 10                	mov    (%eax),%edx
 100122c:	8b 45 08             	mov    0x8(%ebp),%eax
 100122f:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 1001236:	00 
 1001237:	89 44 24 04          	mov    %eax,0x4(%esp)
 100123b:	8b 45 0c             	mov    0xc(%ebp),%eax
 100123e:	89 04 24             	mov    %eax,(%esp)
 1001241:	ff d2                	call   *%edx
 1001243:	eb 01                	jmp    1001246 <_ZN12CBeetleDemon4BumpEP7CObjectib+0x130>
 1001245:	90                   	nop
 1001246:	c9                   	leave  
 1001247:	c3                   	ret    

01001248 <_ZN12CBeetleDemon5BlockEP7CObject>:
 1001248:	55                   	push   %ebp
 1001249:	89 e5                	mov    %esp,%ebp
 100124b:	8b 45 08             	mov    0x8(%ebp),%eax
 100124e:	8b 40 08             	mov    0x8(%eax),%eax
 1001251:	83 f8 01             	cmp    $0x1,%eax
 1001254:	74 07                	je     100125d <_ZN12CBeetleDemon5BlockEP7CObject+0x15>
 1001256:	b8 00 00 00 00       	mov    $0x0,%eax
 100125b:	eb 5d                	jmp    10012ba <_ZN12CBeetleDemon5BlockEP7CObject+0x72>
 100125d:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
 1001261:	74 52                	je     10012b5 <_ZN12CBeetleDemon5BlockEP7CObject+0x6d>
 1001263:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001266:	8b 40 04             	mov    0x4(%eax),%eax
 1001269:	83 f8 05             	cmp    $0x5,%eax
 100126c:	75 07                	jne    1001275 <_ZN12CBeetleDemon5BlockEP7CObject+0x2d>
 100126e:	b8 00 00 00 00       	mov    $0x0,%eax
 1001273:	eb 45                	jmp    10012ba <_ZN12CBeetleDemon5BlockEP7CObject+0x72>
 1001275:	8b 45 08             	mov    0x8(%ebp),%eax
 1001278:	8b 40 2c             	mov    0x2c(%eax),%eax
 100127b:	83 f8 02             	cmp    $0x2,%eax
 100127e:	75 1c                	jne    100129c <_ZN12CBeetleDemon5BlockEP7CObject+0x54>
 1001280:	8b 45 08             	mov    0x8(%ebp),%eax
 1001283:	8b 40 24             	mov    0x24(%eax),%eax
 1001286:	85 c0                	test   %eax,%eax
 1001288:	74 12                	je     100129c <_ZN12CBeetleDemon5BlockEP7CObject+0x54>
 100128a:	8b 45 0c             	mov    0xc(%ebp),%eax
 100128d:	8b 40 04             	mov    0x4(%eax),%eax
 1001290:	83 f8 03             	cmp    $0x3,%eax
 1001293:	75 07                	jne    100129c <_ZN12CBeetleDemon5BlockEP7CObject+0x54>
 1001295:	b8 00 00 00 00       	mov    $0x0,%eax
 100129a:	eb 1e                	jmp    10012ba <_ZN12CBeetleDemon5BlockEP7CObject+0x72>
 100129c:	8b 45 0c             	mov    0xc(%ebp),%eax
 100129f:	8b 40 04             	mov    0x4(%eax),%eax
 10012a2:	83 f8 04             	cmp    $0x4,%eax
 10012a5:	75 07                	jne    10012ae <_ZN12CBeetleDemon5BlockEP7CObject+0x66>
 10012a7:	b8 00 00 00 00       	mov    $0x0,%eax
 10012ac:	eb 0c                	jmp    10012ba <_ZN12CBeetleDemon5BlockEP7CObject+0x72>
 10012ae:	b8 01 00 00 00       	mov    $0x1,%eax
 10012b3:	eb 05                	jmp    10012ba <_ZN12CBeetleDemon5BlockEP7CObject+0x72>
 10012b5:	b8 00 00 00 00       	mov    $0x0,%eax
 10012ba:	5d                   	pop    %ebp
 10012bb:	c3                   	ret    

010012bc <_ZN6CBrickC1EP5CGameiii>:
 10012bc:	55                   	push   %ebp
 10012bd:	89 e5                	mov    %esp,%ebp
 10012bf:	83 ec 28             	sub    $0x28,%esp
 10012c2:	8b 45 08             	mov    0x8(%ebp),%eax
 10012c5:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
 10012cc:	00 
 10012cd:	c7 44 24 18 10 00 00 	movl   $0x10,0x18(%esp)
 10012d4:	00 
 10012d5:	c7 44 24 14 10 00 00 	movl   $0x10,0x14(%esp)
 10012dc:	00 
 10012dd:	8b 55 14             	mov    0x14(%ebp),%edx
 10012e0:	89 54 24 10          	mov    %edx,0x10(%esp)
 10012e4:	8b 55 10             	mov    0x10(%ebp),%edx
 10012e7:	89 54 24 0c          	mov    %edx,0xc(%esp)
 10012eb:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 10012f2:	00 
 10012f3:	8b 55 0c             	mov    0xc(%ebp),%edx
 10012f6:	89 54 24 04          	mov    %edx,0x4(%esp)
 10012fa:	89 04 24             	mov    %eax,(%esp)
 10012fd:	e8 8e 4b 00 00       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 1001302:	8b 45 08             	mov    0x8(%ebp),%eax
 1001305:	c7 00 40 90 00 01    	movl   $0x1009040,(%eax)
 100130b:	8b 45 08             	mov    0x8(%ebp),%eax
 100130e:	8b 55 14             	mov    0x14(%ebp),%edx
 1001311:	89 50 2c             	mov    %edx,0x2c(%eax)
 1001314:	8b 45 18             	mov    0x18(%ebp),%eax
 1001317:	83 f8 02             	cmp    $0x2,%eax
 100131a:	74 16                	je     1001332 <_ZN6CBrickC1EP5CGameiii+0x76>
 100131c:	83 f8 03             	cmp    $0x3,%eax
 100131f:	74 1d                	je     100133e <_ZN6CBrickC1EP5CGameiii+0x82>
 1001321:	83 f8 01             	cmp    $0x1,%eax
 1001324:	75 24                	jne    100134a <_ZN6CBrickC1EP5CGameiii+0x8e>
 1001326:	8b 45 08             	mov    0x8(%ebp),%eax
 1001329:	c7 40 34 ff ff ff ff 	movl   $0xffffffff,0x34(%eax)
 1001330:	eb 22                	jmp    1001354 <_ZN6CBrickC1EP5CGameiii+0x98>
 1001332:	8b 45 08             	mov    0x8(%ebp),%eax
 1001335:	c7 40 34 0a 00 00 00 	movl   $0xa,0x34(%eax)
 100133c:	eb 16                	jmp    1001354 <_ZN6CBrickC1EP5CGameiii+0x98>
 100133e:	8b 45 08             	mov    0x8(%ebp),%eax
 1001341:	c7 40 34 fe ff ff ff 	movl   $0xfffffffe,0x34(%eax)
 1001348:	eb 0a                	jmp    1001354 <_ZN6CBrickC1EP5CGameiii+0x98>
 100134a:	8b 45 08             	mov    0x8(%ebp),%eax
 100134d:	c7 40 34 00 00 00 00 	movl   $0x0,0x34(%eax)
 1001354:	c9                   	leave  
 1001355:	c3                   	ret    

01001356 <_ZN6CBrick8GetImageEPbS0_>:
 1001356:	55                   	push   %ebp
 1001357:	89 e5                	mov    %esp,%ebp
 1001359:	8b 45 10             	mov    0x10(%ebp),%eax
 100135c:	c6 00 00             	movb   $0x0,(%eax)
 100135f:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001362:	c6 00 00             	movb   $0x0,(%eax)
 1001365:	b8 00 18 01 01       	mov    $0x1011800,%eax
 100136a:	5d                   	pop    %ebp
 100136b:	c3                   	ret    

0100136c <_ZN6CBrick6AttackEP7CObjecti>:
 100136c:	55                   	push   %ebp
 100136d:	89 e5                	mov    %esp,%ebp
 100136f:	53                   	push   %ebx
 1001370:	83 ec 34             	sub    $0x34,%esp
 1001373:	8b 45 08             	mov    0x8(%ebp),%eax
 1001376:	8b 40 34             	mov    0x34(%eax),%eax
 1001379:	89 45 f4             	mov    %eax,-0xc(%ebp)
 100137c:	8b 45 08             	mov    0x8(%ebp),%eax
 100137f:	8b 40 34             	mov    0x34(%eax),%eax
 1001382:	83 f8 ff             	cmp    $0xffffffff,%eax
 1001385:	74 16                	je     100139d <_ZN6CBrick6AttackEP7CObjecti+0x31>
 1001387:	85 c0                	test   %eax,%eax
 1001389:	0f 84 77 01 00 00    	je     1001506 <_ZN6CBrick6AttackEP7CObjecti+0x19a>
 100138f:	83 f8 fe             	cmp    $0xfffffffe,%eax
 1001392:	0f 84 b1 00 00 00    	je     1001449 <_ZN6CBrick6AttackEP7CObjecti+0xdd>
 1001398:	e9 fe 00 00 00       	jmp    100149b <_ZN6CBrick6AttackEP7CObjecti+0x12f>
 100139d:	8b 45 0c             	mov    0xc(%ebp),%eax
 10013a0:	89 04 24             	mov    %eax,(%esp)
 10013a3:	e8 a6 49 00 00       	call   1005d4e <_ZN6CMario5IsBigEv>
 10013a8:	84 c0                	test   %al,%al
 10013aa:	74 48                	je     10013f4 <_ZN6CBrick6AttackEP7CObjecti+0x88>
 10013ac:	c7 04 24 34 00 00 00 	movl   $0x34,(%esp)
 10013b3:	e8 8b ed ff ff       	call   1000143 <_Znwj>
 10013b8:	89 c3                	mov    %eax,%ebx
 10013ba:	8b 45 08             	mov    0x8(%ebp),%eax
 10013bd:	8b 48 10             	mov    0x10(%eax),%ecx
 10013c0:	8b 45 08             	mov    0x8(%ebp),%eax
 10013c3:	8b 50 0c             	mov    0xc(%eax),%edx
 10013c6:	8b 45 08             	mov    0x8(%ebp),%eax
 10013c9:	8b 40 20             	mov    0x20(%eax),%eax
 10013cc:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 10013d0:	89 54 24 08          	mov    %edx,0x8(%esp)
 10013d4:	89 44 24 04          	mov    %eax,0x4(%esp)
 10013d8:	89 1c 24             	mov    %ebx,(%esp)
 10013db:	e8 1c 0d 00 00       	call   10020fc <_ZN7CFlowerC1EP5CGameii>
 10013e0:	8b 45 08             	mov    0x8(%ebp),%eax
 10013e3:	8b 40 20             	mov    0x20(%eax),%eax
 10013e6:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 10013ea:	89 04 24             	mov    %eax,(%esp)
 10013ed:	e8 ee 2d 00 00       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 10013f2:	eb 46                	jmp    100143a <_ZN6CBrick6AttackEP7CObjecti+0xce>
 10013f4:	c7 04 24 30 00 00 00 	movl   $0x30,(%esp)
 10013fb:	e8 43 ed ff ff       	call   1000143 <_Znwj>
 1001400:	89 c3                	mov    %eax,%ebx
 1001402:	8b 45 08             	mov    0x8(%ebp),%eax
 1001405:	8b 48 10             	mov    0x10(%eax),%ecx
 1001408:	8b 45 08             	mov    0x8(%ebp),%eax
 100140b:	8b 50 0c             	mov    0xc(%eax),%edx
 100140e:	8b 45 08             	mov    0x8(%ebp),%eax
 1001411:	8b 40 20             	mov    0x20(%eax),%eax
 1001414:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 1001418:	89 54 24 08          	mov    %edx,0x8(%esp)
 100141c:	89 44 24 04          	mov    %eax,0x4(%esp)
 1001420:	89 1c 24             	mov    %ebx,(%esp)
 1001423:	e8 60 11 00 00       	call   1002588 <_ZN7CFungusC1EP5CGameii>
 1001428:	8b 45 08             	mov    0x8(%ebp),%eax
 100142b:	8b 40 20             	mov    0x20(%eax),%eax
 100142e:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1001432:	89 04 24             	mov    %eax,(%esp)
 1001435:	e8 a6 2d 00 00       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 100143a:	8b 45 08             	mov    0x8(%ebp),%eax
 100143d:	c7 40 34 00 00 00 00 	movl   $0x0,0x34(%eax)
 1001444:	e9 be 00 00 00       	jmp    1001507 <_ZN6CBrick6AttackEP7CObjecti+0x19b>
 1001449:	c7 04 24 34 00 00 00 	movl   $0x34,(%esp)
 1001450:	e8 ee ec ff ff       	call   1000143 <_Znwj>
 1001455:	89 c3                	mov    %eax,%ebx
 1001457:	8b 45 08             	mov    0x8(%ebp),%eax
 100145a:	8b 48 10             	mov    0x10(%eax),%ecx
 100145d:	8b 45 08             	mov    0x8(%ebp),%eax
 1001460:	8b 50 0c             	mov    0xc(%eax),%edx
 1001463:	8b 45 08             	mov    0x8(%ebp),%eax
 1001466:	8b 40 20             	mov    0x20(%eax),%eax
 1001469:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 100146d:	89 54 24 08          	mov    %edx,0x8(%esp)
 1001471:	89 44 24 04          	mov    %eax,0x4(%esp)
 1001475:	89 1c 24             	mov    %ebx,(%esp)
 1001478:	e8 a7 51 00 00       	call   1006624 <_ZN5CStarC1EP5CGameii>
 100147d:	8b 45 08             	mov    0x8(%ebp),%eax
 1001480:	8b 40 20             	mov    0x20(%eax),%eax
 1001483:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1001487:	89 04 24             	mov    %eax,(%esp)
 100148a:	e8 51 2d 00 00       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 100148f:	8b 45 08             	mov    0x8(%ebp),%eax
 1001492:	c7 40 34 00 00 00 00 	movl   $0x0,0x34(%eax)
 1001499:	eb 6c                	jmp    1001507 <_ZN6CBrick6AttackEP7CObjecti+0x19b>
 100149b:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 10014a2:	e8 9c ec ff ff       	call   1000143 <_Znwj>
 10014a7:	89 c3                	mov    %eax,%ebx
 10014a9:	8b 45 08             	mov    0x8(%ebp),%eax
 10014ac:	8b 40 10             	mov    0x10(%eax),%eax
 10014af:	8d 48 f0             	lea    -0x10(%eax),%ecx
 10014b2:	8b 45 08             	mov    0x8(%ebp),%eax
 10014b5:	8b 50 0c             	mov    0xc(%eax),%edx
 10014b8:	8b 45 08             	mov    0x8(%ebp),%eax
 10014bb:	8b 40 20             	mov    0x20(%eax),%eax
 10014be:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 10014c2:	89 54 24 08          	mov    %edx,0x8(%esp)
 10014c6:	89 44 24 04          	mov    %eax,0x4(%esp)
 10014ca:	89 1c 24             	mov    %ebx,(%esp)
 10014cd:	e8 06 08 00 00       	call   1001cd8 <_ZN5CCoinC1EP5CGameii>
 10014d2:	89 5d f0             	mov    %ebx,-0x10(%ebp)
 10014d5:	8b 45 08             	mov    0x8(%ebp),%eax
 10014d8:	8b 40 20             	mov    0x20(%eax),%eax
 10014db:	8b 55 f0             	mov    -0x10(%ebp),%edx
 10014de:	89 54 24 04          	mov    %edx,0x4(%esp)
 10014e2:	89 04 24             	mov    %eax,(%esp)
 10014e5:	e8 f6 2c 00 00       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 10014ea:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10014ed:	89 04 24             	mov    %eax,(%esp)
 10014f0:	e8 97 09 00 00       	call   1001e8c <_ZN5CCoin7ThrowUpEv>
 10014f5:	8b 45 08             	mov    0x8(%ebp),%eax
 10014f8:	8b 40 34             	mov    0x34(%eax),%eax
 10014fb:	8d 50 ff             	lea    -0x1(%eax),%edx
 10014fe:	8b 45 08             	mov    0x8(%ebp),%eax
 1001501:	89 50 34             	mov    %edx,0x34(%eax)
 1001504:	eb 01                	jmp    1001507 <_ZN6CBrick6AttackEP7CObjecti+0x19b>
 1001506:	90                   	nop
 1001507:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 100150b:	74 78                	je     1001585 <_ZN6CBrick6AttackEP7CObjecti+0x219>
 100150d:	8b 45 08             	mov    0x8(%ebp),%eax
 1001510:	8b 40 34             	mov    0x34(%eax),%eax
 1001513:	85 c0                	test   %eax,%eax
 1001515:	75 6e                	jne    1001585 <_ZN6CBrick6AttackEP7CObjecti+0x219>
 1001517:	8b 45 08             	mov    0x8(%ebp),%eax
 100151a:	c7 40 08 03 00 00 00 	movl   $0x3,0x8(%eax)
 1001521:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 1001528:	e8 16 ec ff ff       	call   1000143 <_Znwj>
 100152d:	89 c3                	mov    %eax,%ebx
 100152f:	8b 45 08             	mov    0x8(%ebp),%eax
 1001532:	8b 48 10             	mov    0x10(%eax),%ecx
 1001535:	8b 45 08             	mov    0x8(%ebp),%eax
 1001538:	8b 50 0c             	mov    0xc(%eax),%edx
 100153b:	8b 45 08             	mov    0x8(%ebp),%eax
 100153e:	8b 40 20             	mov    0x20(%eax),%eax
 1001541:	c7 44 24 10 00 00 00 	movl   $0x0,0x10(%esp)
 1001548:	00 
 1001549:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 100154d:	89 54 24 08          	mov    %edx,0x8(%esp)
 1001551:	89 44 24 04          	mov    %eax,0x4(%esp)
 1001555:	89 1c 24             	mov    %ebx,(%esp)
 1001558:	e8 c7 4a 00 00       	call   1006024 <_ZN9CQuestionC1EP5CGameiii>
 100155d:	89 5d ec             	mov    %ebx,-0x14(%ebp)
 1001560:	8b 45 08             	mov    0x8(%ebp),%eax
 1001563:	8b 40 20             	mov    0x20(%eax),%eax
 1001566:	8b 55 ec             	mov    -0x14(%ebp),%edx
 1001569:	89 54 24 04          	mov    %edx,0x4(%esp)
 100156d:	89 04 24             	mov    %eax,(%esp)
 1001570:	e8 6b 2c 00 00       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 1001575:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1001578:	89 04 24             	mov    %eax,(%esp)
 100157b:	e8 6e 4b 00 00       	call   10060ee <_ZN9CQuestion6MoveUpEv>
 1001580:	e9 d0 01 00 00       	jmp    1001755 <_ZN6CBrick6AttackEP7CObjecti+0x3e9>
 1001585:	8b 55 08             	mov    0x8(%ebp),%edx
 1001588:	8b 45 08             	mov    0x8(%ebp),%eax
 100158b:	8b 40 20             	mov    0x20(%eax),%eax
 100158e:	c7 44 24 0c fc ff ff 	movl   $0xfffffffc,0xc(%esp)
 1001595:	ff 
 1001596:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 100159d:	00 
 100159e:	89 54 24 04          	mov    %edx,0x4(%esp)
 10015a2:	89 04 24             	mov    %eax,(%esp)
 10015a5:	e8 80 1e 00 00       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 10015aa:	8b 45 08             	mov    0x8(%ebp),%eax
 10015ad:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 10015b4:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 10015b8:	0f 85 97 01 00 00    	jne    1001755 <_ZN6CBrick6AttackEP7CObjecti+0x3e9>
 10015be:	8b 45 0c             	mov    0xc(%ebp),%eax
 10015c1:	89 04 24             	mov    %eax,(%esp)
 10015c4:	e8 85 47 00 00       	call   1005d4e <_ZN6CMario5IsBigEv>
 10015c9:	84 c0                	test   %al,%al
 10015cb:	0f 84 84 01 00 00    	je     1001755 <_ZN6CBrick6AttackEP7CObjecti+0x3e9>
 10015d1:	8b 45 08             	mov    0x8(%ebp),%eax
 10015d4:	8b 40 20             	mov    0x20(%eax),%eax
 10015d7:	c7 44 24 04 0a 00 00 	movl   $0xa,0x4(%esp)
 10015de:	00 
 10015df:	89 04 24             	mov    %eax,(%esp)
 10015e2:	e8 21 2c 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 10015e7:	8b 45 08             	mov    0x8(%ebp),%eax
 10015ea:	c7 40 08 03 00 00 00 	movl   $0x3,0x8(%eax)
 10015f1:	c7 04 24 2c 00 00 00 	movl   $0x2c,(%esp)
 10015f8:	e8 46 eb ff ff       	call   1000143 <_Znwj>
 10015fd:	89 c3                	mov    %eax,%ebx
 10015ff:	8b 45 08             	mov    0x8(%ebp),%eax
 1001602:	8b 48 10             	mov    0x10(%eax),%ecx
 1001605:	8b 45 08             	mov    0x8(%ebp),%eax
 1001608:	8b 50 0c             	mov    0xc(%eax),%edx
 100160b:	8b 45 08             	mov    0x8(%ebp),%eax
 100160e:	8b 40 20             	mov    0x20(%eax),%eax
 1001611:	c7 44 24 14 f0 ff ff 	movl   $0xfffffff0,0x14(%esp)
 1001618:	ff 
 1001619:	c7 44 24 10 fd ff ff 	movl   $0xfffffffd,0x10(%esp)
 1001620:	ff 
 1001621:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 1001625:	89 54 24 08          	mov    %edx,0x8(%esp)
 1001629:	89 44 24 04          	mov    %eax,0x4(%esp)
 100162d:	89 1c 24             	mov    %ebx,(%esp)
 1001630:	e8 eb 01 00 00       	call   1001820 <_ZN12CBrokenBrickC1EP5CGameiiii>
 1001635:	8b 45 08             	mov    0x8(%ebp),%eax
 1001638:	8b 40 20             	mov    0x20(%eax),%eax
 100163b:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 100163f:	89 04 24             	mov    %eax,(%esp)
 1001642:	e8 99 2b 00 00       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 1001647:	c7 04 24 2c 00 00 00 	movl   $0x2c,(%esp)
 100164e:	e8 f0 ea ff ff       	call   1000143 <_Znwj>
 1001653:	89 c3                	mov    %eax,%ebx
 1001655:	8b 45 08             	mov    0x8(%ebp),%eax
 1001658:	8b 50 10             	mov    0x10(%eax),%edx
 100165b:	8b 45 08             	mov    0x8(%ebp),%eax
 100165e:	8b 40 0c             	mov    0xc(%eax),%eax
 1001661:	8d 48 08             	lea    0x8(%eax),%ecx
 1001664:	8b 45 08             	mov    0x8(%ebp),%eax
 1001667:	8b 40 20             	mov    0x20(%eax),%eax
 100166a:	c7 44 24 14 f0 ff ff 	movl   $0xfffffff0,0x14(%esp)
 1001671:	ff 
 1001672:	c7 44 24 10 03 00 00 	movl   $0x3,0x10(%esp)
 1001679:	00 
 100167a:	89 54 24 0c          	mov    %edx,0xc(%esp)
 100167e:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 1001682:	89 44 24 04          	mov    %eax,0x4(%esp)
 1001686:	89 1c 24             	mov    %ebx,(%esp)
 1001689:	e8 92 01 00 00       	call   1001820 <_ZN12CBrokenBrickC1EP5CGameiiii>
 100168e:	8b 45 08             	mov    0x8(%ebp),%eax
 1001691:	8b 40 20             	mov    0x20(%eax),%eax
 1001694:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1001698:	89 04 24             	mov    %eax,(%esp)
 100169b:	e8 40 2b 00 00       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 10016a0:	c7 04 24 2c 00 00 00 	movl   $0x2c,(%esp)
 10016a7:	e8 97 ea ff ff       	call   1000143 <_Znwj>
 10016ac:	89 c3                	mov    %eax,%ebx
 10016ae:	8b 45 08             	mov    0x8(%ebp),%eax
 10016b1:	8b 40 10             	mov    0x10(%eax),%eax
 10016b4:	8d 48 08             	lea    0x8(%eax),%ecx
 10016b7:	8b 45 08             	mov    0x8(%ebp),%eax
 10016ba:	8b 50 0c             	mov    0xc(%eax),%edx
 10016bd:	8b 45 08             	mov    0x8(%ebp),%eax
 10016c0:	8b 40 20             	mov    0x20(%eax),%eax
 10016c3:	c7 44 24 14 f6 ff ff 	movl   $0xfffffff6,0x14(%esp)
 10016ca:	ff 
 10016cb:	c7 44 24 10 fd ff ff 	movl   $0xfffffffd,0x10(%esp)
 10016d2:	ff 
 10016d3:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 10016d7:	89 54 24 08          	mov    %edx,0x8(%esp)
 10016db:	89 44 24 04          	mov    %eax,0x4(%esp)
 10016df:	89 1c 24             	mov    %ebx,(%esp)
 10016e2:	e8 39 01 00 00       	call   1001820 <_ZN12CBrokenBrickC1EP5CGameiiii>
 10016e7:	8b 45 08             	mov    0x8(%ebp),%eax
 10016ea:	8b 40 20             	mov    0x20(%eax),%eax
 10016ed:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 10016f1:	89 04 24             	mov    %eax,(%esp)
 10016f4:	e8 e7 2a 00 00       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 10016f9:	c7 04 24 2c 00 00 00 	movl   $0x2c,(%esp)
 1001700:	e8 3e ea ff ff       	call   1000143 <_Znwj>
 1001705:	89 c3                	mov    %eax,%ebx
 1001707:	8b 45 08             	mov    0x8(%ebp),%eax
 100170a:	8b 40 10             	mov    0x10(%eax),%eax
 100170d:	8d 48 08             	lea    0x8(%eax),%ecx
 1001710:	8b 45 08             	mov    0x8(%ebp),%eax
 1001713:	8b 40 0c             	mov    0xc(%eax),%eax
 1001716:	8d 50 08             	lea    0x8(%eax),%edx
 1001719:	8b 45 08             	mov    0x8(%ebp),%eax
 100171c:	8b 40 20             	mov    0x20(%eax),%eax
 100171f:	c7 44 24 14 f6 ff ff 	movl   $0xfffffff6,0x14(%esp)
 1001726:	ff 
 1001727:	c7 44 24 10 03 00 00 	movl   $0x3,0x10(%esp)
 100172e:	00 
 100172f:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 1001733:	89 54 24 08          	mov    %edx,0x8(%esp)
 1001737:	89 44 24 04          	mov    %eax,0x4(%esp)
 100173b:	89 1c 24             	mov    %ebx,(%esp)
 100173e:	e8 dd 00 00 00       	call   1001820 <_ZN12CBrokenBrickC1EP5CGameiiii>
 1001743:	8b 45 08             	mov    0x8(%ebp),%eax
 1001746:	8b 40 20             	mov    0x20(%eax),%eax
 1001749:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 100174d:	89 04 24             	mov    %eax,(%esp)
 1001750:	e8 8b 2a 00 00       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 1001755:	83 c4 34             	add    $0x34,%esp
 1001758:	5b                   	pop    %ebx
 1001759:	5d                   	pop    %ebp
 100175a:	c3                   	ret    
 100175b:	90                   	nop

0100175c <_ZN6CBrick4BumpEP7CObjectib>:
 100175c:	55                   	push   %ebp
 100175d:	89 e5                	mov    %esp,%ebp
 100175f:	83 ec 28             	sub    $0x28,%esp
 1001762:	8b 45 14             	mov    0x14(%ebp),%eax
 1001765:	88 45 f4             	mov    %al,-0xc(%ebp)
 1001768:	0f b6 45 f4          	movzbl -0xc(%ebp),%eax
 100176c:	83 f0 01             	xor    $0x1,%eax
 100176f:	84 c0                	test   %al,%al
 1001771:	75 39                	jne    10017ac <_ZN6CBrick4BumpEP7CObjectib+0x50>
 1001773:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001776:	8b 40 04             	mov    0x4(%eax),%eax
 1001779:	83 f8 03             	cmp    $0x3,%eax
 100177c:	75 2f                	jne    10017ad <_ZN6CBrick4BumpEP7CObjectib+0x51>
 100177e:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001781:	8b 40 08             	mov    0x8(%eax),%eax
 1001784:	83 f8 01             	cmp    $0x1,%eax
 1001787:	75 24                	jne    10017ad <_ZN6CBrick4BumpEP7CObjectib+0x51>
 1001789:	8b 45 0c             	mov    0xc(%ebp),%eax
 100178c:	8b 00                	mov    (%eax),%eax
 100178e:	83 c0 10             	add    $0x10,%eax
 1001791:	8b 10                	mov    (%eax),%edx
 1001793:	8b 45 08             	mov    0x8(%ebp),%eax
 1001796:	c7 44 24 08 03 00 00 	movl   $0x3,0x8(%esp)
 100179d:	00 
 100179e:	89 44 24 04          	mov    %eax,0x4(%esp)
 10017a2:	8b 45 0c             	mov    0xc(%ebp),%eax
 10017a5:	89 04 24             	mov    %eax,(%esp)
 10017a8:	ff d2                	call   *%edx
 10017aa:	eb 01                	jmp    10017ad <_ZN6CBrick4BumpEP7CObjectib+0x51>
 10017ac:	90                   	nop
 10017ad:	c9                   	leave  
 10017ae:	c3                   	ret    
 10017af:	90                   	nop

010017b0 <_ZN6CBrick5BlockEP7CObject>:
 10017b0:	55                   	push   %ebp
 10017b1:	89 e5                	mov    %esp,%ebp
 10017b3:	b8 00 00 00 00       	mov    $0x0,%eax
 10017b8:	5d                   	pop    %ebp
 10017b9:	c3                   	ret    

010017ba <_ZN6CBrick5ClockEv>:
 10017ba:	55                   	push   %ebp
 10017bb:	89 e5                	mov    %esp,%ebp
 10017bd:	83 ec 18             	sub    $0x18,%esp
 10017c0:	8b 45 08             	mov    0x8(%ebp),%eax
 10017c3:	8b 50 10             	mov    0x10(%eax),%edx
 10017c6:	8b 45 08             	mov    0x8(%ebp),%eax
 10017c9:	8b 40 2c             	mov    0x2c(%eax),%eax
 10017cc:	39 c2                	cmp    %eax,%edx
 10017ce:	74 4d                	je     100181d <_ZN6CBrick5ClockEv+0x63>
 10017d0:	8b 45 08             	mov    0x8(%ebp),%eax
 10017d3:	8b 40 30             	mov    0x30(%eax),%eax
 10017d6:	8d 50 01             	lea    0x1(%eax),%edx
 10017d9:	8b 45 08             	mov    0x8(%ebp),%eax
 10017dc:	89 50 30             	mov    %edx,0x30(%eax)
 10017df:	8b 45 08             	mov    0x8(%ebp),%eax
 10017e2:	8b 40 30             	mov    0x30(%eax),%eax
 10017e5:	83 f8 03             	cmp    $0x3,%eax
 10017e8:	75 34                	jne    100181e <_ZN6CBrick5ClockEv+0x64>
 10017ea:	8b 45 08             	mov    0x8(%ebp),%eax
 10017ed:	8b 50 2c             	mov    0x2c(%eax),%edx
 10017f0:	8b 45 08             	mov    0x8(%ebp),%eax
 10017f3:	8b 40 10             	mov    0x10(%eax),%eax
 10017f6:	89 d1                	mov    %edx,%ecx
 10017f8:	29 c1                	sub    %eax,%ecx
 10017fa:	8b 55 08             	mov    0x8(%ebp),%edx
 10017fd:	8b 45 08             	mov    0x8(%ebp),%eax
 1001800:	8b 40 20             	mov    0x20(%eax),%eax
 1001803:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 1001807:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 100180e:	00 
 100180f:	89 54 24 04          	mov    %edx,0x4(%esp)
 1001813:	89 04 24             	mov    %eax,(%esp)
 1001816:	e8 0f 1c 00 00       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 100181b:	eb 01                	jmp    100181e <_ZN6CBrick5ClockEv+0x64>
 100181d:	90                   	nop
 100181e:	c9                   	leave  
 100181f:	c3                   	ret    

01001820 <_ZN12CBrokenBrickC1EP5CGameiiii>:
 1001820:	55                   	push   %ebp
 1001821:	89 e5                	mov    %esp,%ebp
 1001823:	83 ec 28             	sub    $0x28,%esp
 1001826:	8b 45 08             	mov    0x8(%ebp),%eax
 1001829:	c7 44 24 1c 01 00 00 	movl   $0x1,0x1c(%esp)
 1001830:	00 
 1001831:	c7 44 24 18 08 00 00 	movl   $0x8,0x18(%esp)
 1001838:	00 
 1001839:	c7 44 24 14 08 00 00 	movl   $0x8,0x14(%esp)
 1001840:	00 
 1001841:	8b 55 14             	mov    0x14(%ebp),%edx
 1001844:	89 54 24 10          	mov    %edx,0x10(%esp)
 1001848:	8b 55 10             	mov    0x10(%ebp),%edx
 100184b:	89 54 24 0c          	mov    %edx,0xc(%esp)
 100184f:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 1001856:	00 
 1001857:	8b 55 0c             	mov    0xc(%ebp),%edx
 100185a:	89 54 24 04          	mov    %edx,0x4(%esp)
 100185e:	89 04 24             	mov    %eax,(%esp)
 1001861:	e8 2a 46 00 00       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 1001866:	8b 45 08             	mov    0x8(%ebp),%eax
 1001869:	c7 00 60 90 00 01    	movl   $0x1009060,(%eax)
 100186f:	8b 45 08             	mov    0x8(%ebp),%eax
 1001872:	8b 55 18             	mov    0x18(%ebp),%edx
 1001875:	89 50 24             	mov    %edx,0x24(%eax)
 1001878:	8b 45 08             	mov    0x8(%ebp),%eax
 100187b:	8b 55 1c             	mov    0x1c(%ebp),%edx
 100187e:	89 50 28             	mov    %edx,0x28(%eax)
 1001881:	8b 45 08             	mov    0x8(%ebp),%eax
 1001884:	c7 40 08 02 00 00 00 	movl   $0x2,0x8(%eax)
 100188b:	c9                   	leave  
 100188c:	c3                   	ret    
 100188d:	90                   	nop

0100188e <_ZN12CBrokenBrick8GetImageEPbS0_>:
 100188e:	55                   	push   %ebp
 100188f:	89 e5                	mov    %esp,%ebp
 1001891:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001894:	c6 00 00             	movb   $0x0,(%eax)
 1001897:	8b 45 10             	mov    0x10(%ebp),%eax
 100189a:	c6 00 00             	movb   $0x0,(%eax)
 100189d:	b8 00 9e 01 01       	mov    $0x1019e00,%eax
 10018a2:	5d                   	pop    %ebp
 10018a3:	c3                   	ret    

010018a4 <_ZN12CBrokenBrick5ClockEv>:
 10018a4:	55                   	push   %ebp
 10018a5:	89 e5                	mov    %esp,%ebp
 10018a7:	53                   	push   %ebx
 10018a8:	83 ec 14             	sub    $0x14,%esp
 10018ab:	8b 45 08             	mov    0x8(%ebp),%eax
 10018ae:	8b 40 28             	mov    0x28(%eax),%eax
 10018b1:	8d 50 02             	lea    0x2(%eax),%edx
 10018b4:	8b 45 08             	mov    0x8(%ebp),%eax
 10018b7:	89 50 28             	mov    %edx,0x28(%eax)
 10018ba:	8b 45 08             	mov    0x8(%ebp),%eax
 10018bd:	8b 40 28             	mov    0x28(%eax),%eax
 10018c0:	83 f8 14             	cmp    $0x14,%eax
 10018c3:	7e 0a                	jle    10018cf <_ZN12CBrokenBrick5ClockEv+0x2b>
 10018c5:	8b 45 08             	mov    0x8(%ebp),%eax
 10018c8:	c7 40 28 14 00 00 00 	movl   $0x14,0x28(%eax)
 10018cf:	8b 45 08             	mov    0x8(%ebp),%eax
 10018d2:	8b 40 24             	mov    0x24(%eax),%eax
 10018d5:	85 c0                	test   %eax,%eax
 10018d7:	75 0a                	jne    10018e3 <_ZN12CBrokenBrick5ClockEv+0x3f>
 10018d9:	8b 45 08             	mov    0x8(%ebp),%eax
 10018dc:	8b 40 28             	mov    0x28(%eax),%eax
 10018df:	85 c0                	test   %eax,%eax
 10018e1:	74 29                	je     100190c <_ZN12CBrokenBrick5ClockEv+0x68>
 10018e3:	8b 45 08             	mov    0x8(%ebp),%eax
 10018e6:	8b 58 28             	mov    0x28(%eax),%ebx
 10018e9:	8b 45 08             	mov    0x8(%ebp),%eax
 10018ec:	8b 48 24             	mov    0x24(%eax),%ecx
 10018ef:	8b 55 08             	mov    0x8(%ebp),%edx
 10018f2:	8b 45 08             	mov    0x8(%ebp),%eax
 10018f5:	8b 40 20             	mov    0x20(%eax),%eax
 10018f8:	89 5c 24 0c          	mov    %ebx,0xc(%esp)
 10018fc:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 1001900:	89 54 24 04          	mov    %edx,0x4(%esp)
 1001904:	89 04 24             	mov    %eax,(%esp)
 1001907:	e8 1e 1b 00 00       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 100190c:	83 c4 14             	add    $0x14,%esp
 100190f:	5b                   	pop    %ebx
 1001910:	5d                   	pop    %ebp
 1001911:	c3                   	ret    
	...

01001914 <_ZN7CBulletC1EP5CGameiii>:
 1001914:	55                   	push   %ebp
 1001915:	89 e5                	mov    %esp,%ebp
 1001917:	83 ec 28             	sub    $0x28,%esp
 100191a:	8b 45 08             	mov    0x8(%ebp),%eax
 100191d:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
 1001924:	00 
 1001925:	c7 44 24 18 08 00 00 	movl   $0x8,0x18(%esp)
 100192c:	00 
 100192d:	c7 44 24 14 08 00 00 	movl   $0x8,0x14(%esp)
 1001934:	00 
 1001935:	8b 55 14             	mov    0x14(%ebp),%edx
 1001938:	89 54 24 10          	mov    %edx,0x10(%esp)
 100193c:	8b 55 10             	mov    0x10(%ebp),%edx
 100193f:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1001943:	c7 44 24 08 04 00 00 	movl   $0x4,0x8(%esp)
 100194a:	00 
 100194b:	8b 55 0c             	mov    0xc(%ebp),%edx
 100194e:	89 54 24 04          	mov    %edx,0x4(%esp)
 1001952:	89 04 24             	mov    %eax,(%esp)
 1001955:	e8 36 45 00 00       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 100195a:	8b 45 08             	mov    0x8(%ebp),%eax
 100195d:	c7 00 80 90 00 01    	movl   $0x1009080,(%eax)
 1001963:	83 7d 18 00          	cmpl   $0x0,0x18(%ebp)
 1001967:	74 0c                	je     1001975 <_ZN7CBulletC1EP5CGameiii+0x61>
 1001969:	8b 45 08             	mov    0x8(%ebp),%eax
 100196c:	c7 40 24 f6 ff ff ff 	movl   $0xfffffff6,0x24(%eax)
 1001973:	eb 0a                	jmp    100197f <_ZN7CBulletC1EP5CGameiii+0x6b>
 1001975:	8b 45 08             	mov    0x8(%ebp),%eax
 1001978:	c7 40 24 0a 00 00 00 	movl   $0xa,0x24(%eax)
 100197f:	8b 45 08             	mov    0x8(%ebp),%eax
 1001982:	c7 40 2c 00 00 00 00 	movl   $0x0,0x2c(%eax)
 1001989:	c9                   	leave  
 100198a:	c3                   	ret    
 100198b:	90                   	nop

0100198c <_ZN7CBullet8GetImageEPbS0_>:
 100198c:	55                   	push   %ebp
 100198d:	89 e5                	mov    %esp,%ebp
 100198f:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001992:	c6 00 00             	movb   $0x0,(%eax)
 1001995:	8b 45 10             	mov    0x10(%ebp),%eax
 1001998:	c6 00 00             	movb   $0x0,(%eax)
 100199b:	8b 45 08             	mov    0x8(%ebp),%eax
 100199e:	8b 40 2c             	mov    0x2c(%eax),%eax
 10019a1:	c1 e0 08             	shl    $0x8,%eax
 10019a4:	05 00 9a 01 01       	add    $0x1019a00,%eax
 10019a9:	5d                   	pop    %ebp
 10019aa:	c3                   	ret    
 10019ab:	90                   	nop

010019ac <_ZN7CBullet5ClockEv>:
 10019ac:	55                   	push   %ebp
 10019ad:	89 e5                	mov    %esp,%ebp
 10019af:	53                   	push   %ebx
 10019b0:	83 ec 24             	sub    $0x24,%esp
 10019b3:	8b 45 08             	mov    0x8(%ebp),%eax
 10019b6:	8b 40 2c             	mov    0x2c(%eax),%eax
 10019b9:	8d 50 01             	lea    0x1(%eax),%edx
 10019bc:	8b 45 08             	mov    0x8(%ebp),%eax
 10019bf:	89 50 2c             	mov    %edx,0x2c(%eax)
 10019c2:	8b 45 08             	mov    0x8(%ebp),%eax
 10019c5:	8b 40 2c             	mov    0x2c(%eax),%eax
 10019c8:	83 f8 04             	cmp    $0x4,%eax
 10019cb:	75 0a                	jne    10019d7 <_ZN7CBullet5ClockEv+0x2b>
 10019cd:	8b 45 08             	mov    0x8(%ebp),%eax
 10019d0:	c7 40 2c 00 00 00 00 	movl   $0x0,0x2c(%eax)
 10019d7:	8b 45 08             	mov    0x8(%ebp),%eax
 10019da:	8b 40 28             	mov    0x28(%eax),%eax
 10019dd:	8d 50 02             	lea    0x2(%eax),%edx
 10019e0:	8b 45 08             	mov    0x8(%ebp),%eax
 10019e3:	89 50 28             	mov    %edx,0x28(%eax)
 10019e6:	8b 45 08             	mov    0x8(%ebp),%eax
 10019e9:	8b 40 28             	mov    0x28(%eax),%eax
 10019ec:	83 f8 14             	cmp    $0x14,%eax
 10019ef:	7e 0a                	jle    10019fb <_ZN7CBullet5ClockEv+0x4f>
 10019f1:	8b 45 08             	mov    0x8(%ebp),%eax
 10019f4:	c7 40 28 14 00 00 00 	movl   $0x14,0x28(%eax)
 10019fb:	8b 45 08             	mov    0x8(%ebp),%eax
 10019fe:	8b 58 28             	mov    0x28(%eax),%ebx
 1001a01:	8b 45 08             	mov    0x8(%ebp),%eax
 1001a04:	8b 48 24             	mov    0x24(%eax),%ecx
 1001a07:	8b 55 08             	mov    0x8(%ebp),%edx
 1001a0a:	8b 45 08             	mov    0x8(%ebp),%eax
 1001a0d:	8b 40 20             	mov    0x20(%eax),%eax
 1001a10:	89 5c 24 0c          	mov    %ebx,0xc(%esp)
 1001a14:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 1001a18:	89 54 24 04          	mov    %edx,0x4(%esp)
 1001a1c:	89 04 24             	mov    %eax,(%esp)
 1001a1f:	e8 06 1a 00 00       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 1001a24:	89 45 f4             	mov    %eax,-0xc(%ebp)
 1001a27:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1001a2a:	83 e0 01             	and    $0x1,%eax
 1001a2d:	84 c0                	test   %al,%al
 1001a2f:	74 0a                	je     1001a3b <_ZN7CBullet5ClockEv+0x8f>
 1001a31:	8b 45 08             	mov    0x8(%ebp),%eax
 1001a34:	c7 40 08 03 00 00 00 	movl   $0x3,0x8(%eax)
 1001a3b:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1001a3e:	83 e0 02             	and    $0x2,%eax
 1001a41:	85 c0                	test   %eax,%eax
 1001a43:	74 20                	je     1001a65 <_ZN7CBullet5ClockEv+0xb9>
 1001a45:	8b 45 08             	mov    0x8(%ebp),%eax
 1001a48:	8b 40 28             	mov    0x28(%eax),%eax
 1001a4b:	85 c0                	test   %eax,%eax
 1001a4d:	7e 0c                	jle    1001a5b <_ZN7CBullet5ClockEv+0xaf>
 1001a4f:	8b 45 08             	mov    0x8(%ebp),%eax
 1001a52:	c7 40 28 f8 ff ff ff 	movl   $0xfffffff8,0x28(%eax)
 1001a59:	eb 0a                	jmp    1001a65 <_ZN7CBullet5ClockEv+0xb9>
 1001a5b:	8b 45 08             	mov    0x8(%ebp),%eax
 1001a5e:	c7 40 08 03 00 00 00 	movl   $0x3,0x8(%eax)
 1001a65:	83 c4 24             	add    $0x24,%esp
 1001a68:	5b                   	pop    %ebx
 1001a69:	5d                   	pop    %ebp
 1001a6a:	c3                   	ret    
 1001a6b:	90                   	nop

01001a6c <_ZN7CBullet4BumpEP7CObjectib>:
 1001a6c:	55                   	push   %ebp
 1001a6d:	89 e5                	mov    %esp,%ebp
 1001a6f:	83 ec 28             	sub    $0x28,%esp
 1001a72:	8b 45 14             	mov    0x14(%ebp),%eax
 1001a75:	88 45 f4             	mov    %al,-0xc(%ebp)
 1001a78:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001a7b:	8b 40 04             	mov    0x4(%eax),%eax
 1001a7e:	83 f8 03             	cmp    $0x3,%eax
 1001a81:	75 36                	jne    1001ab9 <_ZN7CBullet4BumpEP7CObjectib+0x4d>
 1001a83:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001a86:	8b 40 08             	mov    0x8(%eax),%eax
 1001a89:	83 f8 01             	cmp    $0x1,%eax
 1001a8c:	75 2b                	jne    1001ab9 <_ZN7CBullet4BumpEP7CObjectib+0x4d>
 1001a8e:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001a91:	8b 00                	mov    (%eax),%eax
 1001a93:	83 c0 10             	add    $0x10,%eax
 1001a96:	8b 10                	mov    (%eax),%edx
 1001a98:	8b 45 08             	mov    0x8(%ebp),%eax
 1001a9b:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 1001aa2:	00 
 1001aa3:	89 44 24 04          	mov    %eax,0x4(%esp)
 1001aa7:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001aaa:	89 04 24             	mov    %eax,(%esp)
 1001aad:	ff d2                	call   *%edx
 1001aaf:	8b 45 08             	mov    0x8(%ebp),%eax
 1001ab2:	c7 40 08 03 00 00 00 	movl   $0x3,0x8(%eax)
 1001ab9:	c9                   	leave  
 1001aba:	c3                   	ret    
	...

01001abc <_ZN10CClipDemonC1EP5CGameii>:
 1001abc:	55                   	push   %ebp
 1001abd:	89 e5                	mov    %esp,%ebp
 1001abf:	83 ec 28             	sub    $0x28,%esp
 1001ac2:	8b 45 14             	mov    0x14(%ebp),%eax
 1001ac5:	8d 48 08             	lea    0x8(%eax),%ecx
 1001ac8:	8b 45 10             	mov    0x10(%ebp),%eax
 1001acb:	8d 50 08             	lea    0x8(%eax),%edx
 1001ace:	8b 45 08             	mov    0x8(%ebp),%eax
 1001ad1:	c7 44 24 1c ff ff ff 	movl   $0xffffffff,0x1c(%esp)
 1001ad8:	ff 
 1001ad9:	c7 44 24 18 18 00 00 	movl   $0x18,0x18(%esp)
 1001ae0:	00 
 1001ae1:	c7 44 24 14 10 00 00 	movl   $0x10,0x14(%esp)
 1001ae8:	00 
 1001ae9:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 1001aed:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1001af1:	c7 44 24 08 03 00 00 	movl   $0x3,0x8(%esp)
 1001af8:	00 
 1001af9:	8b 55 0c             	mov    0xc(%ebp),%edx
 1001afc:	89 54 24 04          	mov    %edx,0x4(%esp)
 1001b00:	89 04 24             	mov    %eax,(%esp)
 1001b03:	e8 88 43 00 00       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 1001b08:	8b 45 08             	mov    0x8(%ebp),%eax
 1001b0b:	c7 00 a0 90 00 01    	movl   $0x10090a0,(%eax)
 1001b11:	8b 45 08             	mov    0x8(%ebp),%eax
 1001b14:	c7 40 2c 00 00 00 00 	movl   $0x0,0x2c(%eax)
 1001b1b:	8b 45 08             	mov    0x8(%ebp),%eax
 1001b1e:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 1001b25:	8b 45 08             	mov    0x8(%ebp),%eax
 1001b28:	c7 40 34 00 00 00 00 	movl   $0x0,0x34(%eax)
 1001b2f:	8b 45 14             	mov    0x14(%ebp),%eax
 1001b32:	8d 50 08             	lea    0x8(%eax),%edx
 1001b35:	8b 45 08             	mov    0x8(%ebp),%eax
 1001b38:	89 50 38             	mov    %edx,0x38(%eax)
 1001b3b:	c9                   	leave  
 1001b3c:	c3                   	ret    
 1001b3d:	90                   	nop

01001b3e <_ZN10CClipDemon8GetImageEPbS0_>:
 1001b3e:	55                   	push   %ebp
 1001b3f:	89 e5                	mov    %esp,%ebp
 1001b41:	8b 45 10             	mov    0x10(%ebp),%eax
 1001b44:	c6 00 00             	movb   $0x0,(%eax)
 1001b47:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001b4a:	c6 00 00             	movb   $0x0,(%eax)
 1001b4d:	8b 45 08             	mov    0x8(%ebp),%eax
 1001b50:	8b 50 2c             	mov    0x2c(%eax),%edx
 1001b53:	89 d0                	mov    %edx,%eax
 1001b55:	01 c0                	add    %eax,%eax
 1001b57:	01 d0                	add    %edx,%eax
 1001b59:	c1 e0 09             	shl    $0x9,%eax
 1001b5c:	05 00 56 01 01       	add    $0x1015600,%eax
 1001b61:	5d                   	pop    %ebp
 1001b62:	c3                   	ret    
 1001b63:	90                   	nop

01001b64 <_ZN10CClipDemon5ClockEv>:
 1001b64:	55                   	push   %ebp
 1001b65:	89 e5                	mov    %esp,%ebp
 1001b67:	53                   	push   %ebx
 1001b68:	83 ec 14             	sub    $0x14,%esp
 1001b6b:	8b 45 08             	mov    0x8(%ebp),%eax
 1001b6e:	8b 40 30             	mov    0x30(%eax),%eax
 1001b71:	8d 50 01             	lea    0x1(%eax),%edx
 1001b74:	8b 45 08             	mov    0x8(%ebp),%eax
 1001b77:	89 50 30             	mov    %edx,0x30(%eax)
 1001b7a:	8b 45 08             	mov    0x8(%ebp),%eax
 1001b7d:	8b 40 30             	mov    0x30(%eax),%eax
 1001b80:	83 f8 04             	cmp    $0x4,%eax
 1001b83:	7e 1e                	jle    1001ba3 <_ZN10CClipDemon5ClockEv+0x3f>
 1001b85:	8b 45 08             	mov    0x8(%ebp),%eax
 1001b88:	8b 40 2c             	mov    0x2c(%eax),%eax
 1001b8b:	85 c0                	test   %eax,%eax
 1001b8d:	0f 94 c0             	sete   %al
 1001b90:	0f b6 d0             	movzbl %al,%edx
 1001b93:	8b 45 08             	mov    0x8(%ebp),%eax
 1001b96:	89 50 2c             	mov    %edx,0x2c(%eax)
 1001b99:	8b 45 08             	mov    0x8(%ebp),%eax
 1001b9c:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 1001ba3:	8b 45 08             	mov    0x8(%ebp),%eax
 1001ba6:	8b 40 34             	mov    0x34(%eax),%eax
 1001ba9:	8d 50 01             	lea    0x1(%eax),%edx
 1001bac:	8b 45 08             	mov    0x8(%ebp),%eax
 1001baf:	89 50 34             	mov    %edx,0x34(%eax)
 1001bb2:	8b 45 08             	mov    0x8(%ebp),%eax
 1001bb5:	8b 40 28             	mov    0x28(%eax),%eax
 1001bb8:	85 c0                	test   %eax,%eax
 1001bba:	74 62                	je     1001c1e <_ZN10CClipDemon5ClockEv+0xba>
 1001bbc:	8b 45 08             	mov    0x8(%ebp),%eax
 1001bbf:	8b 58 28             	mov    0x28(%eax),%ebx
 1001bc2:	8b 45 08             	mov    0x8(%ebp),%eax
 1001bc5:	8b 48 24             	mov    0x24(%eax),%ecx
 1001bc8:	8b 55 08             	mov    0x8(%ebp),%edx
 1001bcb:	8b 45 08             	mov    0x8(%ebp),%eax
 1001bce:	8b 40 20             	mov    0x20(%eax),%eax
 1001bd1:	89 5c 24 0c          	mov    %ebx,0xc(%esp)
 1001bd5:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 1001bd9:	89 54 24 04          	mov    %edx,0x4(%esp)
 1001bdd:	89 04 24             	mov    %eax,(%esp)
 1001be0:	e8 45 18 00 00       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 1001be5:	8b 45 08             	mov    0x8(%ebp),%eax
 1001be8:	8b 50 10             	mov    0x10(%eax),%edx
 1001beb:	8b 45 08             	mov    0x8(%ebp),%eax
 1001bee:	8b 40 38             	mov    0x38(%eax),%eax
 1001bf1:	39 c2                	cmp    %eax,%edx
 1001bf3:	74 13                	je     1001c08 <_ZN10CClipDemon5ClockEv+0xa4>
 1001bf5:	8b 45 08             	mov    0x8(%ebp),%eax
 1001bf8:	8b 50 10             	mov    0x10(%eax),%edx
 1001bfb:	8b 45 08             	mov    0x8(%ebp),%eax
 1001bfe:	8b 40 38             	mov    0x38(%eax),%eax
 1001c01:	83 c0 19             	add    $0x19,%eax
 1001c04:	39 c2                	cmp    %eax,%edx
 1001c06:	75 51                	jne    1001c59 <_ZN10CClipDemon5ClockEv+0xf5>
 1001c08:	8b 45 08             	mov    0x8(%ebp),%eax
 1001c0b:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%eax)
 1001c12:	8b 45 08             	mov    0x8(%ebp),%eax
 1001c15:	c7 40 34 00 00 00 00 	movl   $0x0,0x34(%eax)
 1001c1c:	eb 3b                	jmp    1001c59 <_ZN10CClipDemon5ClockEv+0xf5>
 1001c1e:	8b 45 08             	mov    0x8(%ebp),%eax
 1001c21:	8b 40 34             	mov    0x34(%eax),%eax
 1001c24:	83 f8 1e             	cmp    $0x1e,%eax
 1001c27:	75 30                	jne    1001c59 <_ZN10CClipDemon5ClockEv+0xf5>
 1001c29:	8b 45 08             	mov    0x8(%ebp),%eax
 1001c2c:	8b 50 10             	mov    0x10(%eax),%edx
 1001c2f:	8b 45 08             	mov    0x8(%ebp),%eax
 1001c32:	8b 40 38             	mov    0x38(%eax),%eax
 1001c35:	39 c2                	cmp    %eax,%edx
 1001c37:	75 0c                	jne    1001c45 <_ZN10CClipDemon5ClockEv+0xe1>
 1001c39:	8b 45 08             	mov    0x8(%ebp),%eax
 1001c3c:	c7 40 28 01 00 00 00 	movl   $0x1,0x28(%eax)
 1001c43:	eb 0a                	jmp    1001c4f <_ZN10CClipDemon5ClockEv+0xeb>
 1001c45:	8b 45 08             	mov    0x8(%ebp),%eax
 1001c48:	c7 40 28 ff ff ff ff 	movl   $0xffffffff,0x28(%eax)
 1001c4f:	8b 45 08             	mov    0x8(%ebp),%eax
 1001c52:	c7 40 34 00 00 00 00 	movl   $0x0,0x34(%eax)
 1001c59:	83 c4 14             	add    $0x14,%esp
 1001c5c:	5b                   	pop    %ebx
 1001c5d:	5d                   	pop    %ebp
 1001c5e:	c3                   	ret    
 1001c5f:	90                   	nop

01001c60 <_ZN10CClipDemon5BlockEP7CObject>:
 1001c60:	55                   	push   %ebp
 1001c61:	89 e5                	mov    %esp,%ebp
 1001c63:	b8 00 00 00 00       	mov    $0x0,%eax
 1001c68:	5d                   	pop    %ebp
 1001c69:	c3                   	ret    

01001c6a <_ZN10CClipDemon6AttackEP7CObjecti>:
 1001c6a:	55                   	push   %ebp
 1001c6b:	89 e5                	mov    %esp,%ebp
 1001c6d:	83 ec 18             	sub    $0x18,%esp
 1001c70:	8b 45 10             	mov    0x10(%ebp),%eax
 1001c73:	83 f8 01             	cmp    $0x1,%eax
 1001c76:	75 21                	jne    1001c99 <_ZN10CClipDemon6AttackEP7CObjecti+0x2f>
 1001c78:	8b 45 08             	mov    0x8(%ebp),%eax
 1001c7b:	8b 40 20             	mov    0x20(%eax),%eax
 1001c7e:	c7 44 24 04 09 00 00 	movl   $0x9,0x4(%esp)
 1001c85:	00 
 1001c86:	89 04 24             	mov    %eax,(%esp)
 1001c89:	e8 7a 25 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1001c8e:	8b 45 08             	mov    0x8(%ebp),%eax
 1001c91:	c7 40 08 03 00 00 00 	movl   $0x3,0x8(%eax)
 1001c98:	90                   	nop
 1001c99:	c9                   	leave  
 1001c9a:	c3                   	ret    
 1001c9b:	90                   	nop

01001c9c <_ZN10CClipDemon4BumpEP7CObjectib>:
 1001c9c:	55                   	push   %ebp
 1001c9d:	89 e5                	mov    %esp,%ebp
 1001c9f:	83 ec 28             	sub    $0x28,%esp
 1001ca2:	8b 45 14             	mov    0x14(%ebp),%eax
 1001ca5:	88 45 f4             	mov    %al,-0xc(%ebp)
 1001ca8:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001cab:	8b 40 04             	mov    0x4(%eax),%eax
 1001cae:	83 f8 01             	cmp    $0x1,%eax
 1001cb1:	75 21                	jne    1001cd4 <_ZN10CClipDemon4BumpEP7CObjectib+0x38>
 1001cb3:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001cb6:	8b 00                	mov    (%eax),%eax
 1001cb8:	83 c0 10             	add    $0x10,%eax
 1001cbb:	8b 10                	mov    (%eax),%edx
 1001cbd:	8b 45 08             	mov    0x8(%ebp),%eax
 1001cc0:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 1001cc7:	00 
 1001cc8:	89 44 24 04          	mov    %eax,0x4(%esp)
 1001ccc:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001ccf:	89 04 24             	mov    %eax,(%esp)
 1001cd2:	ff d2                	call   *%edx
 1001cd4:	c9                   	leave  
 1001cd5:	c3                   	ret    
	...

01001cd8 <_ZN5CCoinC1EP5CGameii>:
 1001cd8:	55                   	push   %ebp
 1001cd9:	89 e5                	mov    %esp,%ebp
 1001cdb:	83 ec 28             	sub    $0x28,%esp
 1001cde:	8b 45 08             	mov    0x8(%ebp),%eax
 1001ce1:	c7 44 24 1c 01 00 00 	movl   $0x1,0x1c(%esp)
 1001ce8:	00 
 1001ce9:	c7 44 24 18 10 00 00 	movl   $0x10,0x18(%esp)
 1001cf0:	00 
 1001cf1:	c7 44 24 14 10 00 00 	movl   $0x10,0x14(%esp)
 1001cf8:	00 
 1001cf9:	8b 55 14             	mov    0x14(%ebp),%edx
 1001cfc:	89 54 24 10          	mov    %edx,0x10(%esp)
 1001d00:	8b 55 10             	mov    0x10(%ebp),%edx
 1001d03:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1001d07:	c7 44 24 08 05 00 00 	movl   $0x5,0x8(%esp)
 1001d0e:	00 
 1001d0f:	8b 55 0c             	mov    0xc(%ebp),%edx
 1001d12:	89 54 24 04          	mov    %edx,0x4(%esp)
 1001d16:	89 04 24             	mov    %eax,(%esp)
 1001d19:	e8 72 41 00 00       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 1001d1e:	8b 45 08             	mov    0x8(%ebp),%eax
 1001d21:	c7 00 c0 90 00 01    	movl   $0x10090c0,(%eax)
 1001d27:	8b 45 08             	mov    0x8(%ebp),%eax
 1001d2a:	8b 55 14             	mov    0x14(%ebp),%edx
 1001d2d:	89 50 2c             	mov    %edx,0x2c(%eax)
 1001d30:	8b 45 08             	mov    0x8(%ebp),%eax
 1001d33:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 1001d3a:	c9                   	leave  
 1001d3b:	c3                   	ret    

01001d3c <_ZN5CCoin8GetImageEPbS0_>:
 1001d3c:	55                   	push   %ebp
 1001d3d:	89 e5                	mov    %esp,%ebp
 1001d3f:	8b 45 10             	mov    0x10(%ebp),%eax
 1001d42:	c6 00 00             	movb   $0x0,(%eax)
 1001d45:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001d48:	c6 00 00             	movb   $0x0,(%eax)
 1001d4b:	8b 45 08             	mov    0x8(%ebp),%eax
 1001d4e:	8b 40 30             	mov    0x30(%eax),%eax
 1001d51:	85 c0                	test   %eax,%eax
 1001d53:	74 10                	je     1001d65 <_ZN5CCoin8GetImageEPbS0_+0x29>
 1001d55:	8b 45 08             	mov    0x8(%ebp),%eax
 1001d58:	8b 40 30             	mov    0x30(%eax),%eax
 1001d5b:	c1 e0 0a             	shl    $0xa,%eax
 1001d5e:	05 00 7a 01 01       	add    $0x1017a00,%eax
 1001d63:	eb 0d                	jmp    1001d72 <_ZN5CCoin8GetImageEPbS0_+0x36>
 1001d65:	a1 60 53 02 01       	mov    0x1025360,%eax
 1001d6a:	c1 e0 0a             	shl    $0xa,%eax
 1001d6d:	05 00 7a 01 01       	add    $0x1017a00,%eax
 1001d72:	5d                   	pop    %ebp
 1001d73:	c3                   	ret    

01001d74 <_ZN5CCoin6AttackEP7CObjecti>:
 1001d74:	55                   	push   %ebp
 1001d75:	89 e5                	mov    %esp,%ebp
 1001d77:	83 ec 18             	sub    $0x18,%esp
 1001d7a:	8b 45 08             	mov    0x8(%ebp),%eax
 1001d7d:	8b 40 08             	mov    0x8(%eax),%eax
 1001d80:	83 f8 02             	cmp    $0x2,%eax
 1001d83:	74 22                	je     1001da7 <_ZN5CCoin6AttackEP7CObjecti+0x33>
 1001d85:	8b 45 08             	mov    0x8(%ebp),%eax
 1001d88:	8b 40 20             	mov    0x20(%eax),%eax
 1001d8b:	c7 44 24 04 04 00 00 	movl   $0x4,0x4(%esp)
 1001d92:	00 
 1001d93:	89 04 24             	mov    %eax,(%esp)
 1001d96:	e8 6d 24 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1001d9b:	8b 45 08             	mov    0x8(%ebp),%eax
 1001d9e:	c7 40 08 03 00 00 00 	movl   $0x3,0x8(%eax)
 1001da5:	eb 01                	jmp    1001da8 <_ZN5CCoin6AttackEP7CObjecti+0x34>
 1001da7:	90                   	nop
 1001da8:	c9                   	leave  
 1001da9:	c3                   	ret    

01001daa <_ZN5CCoin5BlockEP7CObject>:
 1001daa:	55                   	push   %ebp
 1001dab:	89 e5                	mov    %esp,%ebp
 1001dad:	b8 00 00 00 00       	mov    $0x0,%eax
 1001db2:	5d                   	pop    %ebp
 1001db3:	c3                   	ret    

01001db4 <_ZN5CCoin5ClockEv>:
 1001db4:	55                   	push   %ebp
 1001db5:	89 e5                	mov    %esp,%ebp
 1001db7:	83 ec 18             	sub    $0x18,%esp
 1001dba:	8b 45 08             	mov    0x8(%ebp),%eax
 1001dbd:	8b 40 30             	mov    0x30(%eax),%eax
 1001dc0:	83 f8 04             	cmp    $0x4,%eax
 1001dc3:	74 1d                	je     1001de2 <_ZN5CCoin5ClockEv+0x2e>
 1001dc5:	83 f8 05             	cmp    $0x5,%eax
 1001dc8:	74 3b                	je     1001e05 <_ZN5CCoin5ClockEv+0x51>
 1001dca:	83 f8 03             	cmp    $0x3,%eax
 1001dcd:	75 49                	jne    1001e18 <_ZN5CCoin5ClockEv+0x64>
 1001dcf:	8b 45 08             	mov    0x8(%ebp),%eax
 1001dd2:	c7 40 30 04 00 00 00 	movl   $0x4,0x30(%eax)
 1001dd9:	8b 45 08             	mov    0x8(%ebp),%eax
 1001ddc:	c6 40 34 01          	movb   $0x1,0x34(%eax)
 1001de0:	eb 38                	jmp    1001e1a <_ZN5CCoin5ClockEv+0x66>
 1001de2:	8b 45 08             	mov    0x8(%ebp),%eax
 1001de5:	0f b6 40 34          	movzbl 0x34(%eax),%eax
 1001de9:	84 c0                	test   %al,%al
 1001deb:	74 0c                	je     1001df9 <_ZN5CCoin5ClockEv+0x45>
 1001ded:	8b 45 08             	mov    0x8(%ebp),%eax
 1001df0:	c7 40 30 05 00 00 00 	movl   $0x5,0x30(%eax)
 1001df7:	eb 21                	jmp    1001e1a <_ZN5CCoin5ClockEv+0x66>
 1001df9:	8b 45 08             	mov    0x8(%ebp),%eax
 1001dfc:	c7 40 30 03 00 00 00 	movl   $0x3,0x30(%eax)
 1001e03:	eb 15                	jmp    1001e1a <_ZN5CCoin5ClockEv+0x66>
 1001e05:	8b 45 08             	mov    0x8(%ebp),%eax
 1001e08:	c7 40 30 04 00 00 00 	movl   $0x4,0x30(%eax)
 1001e0f:	8b 45 08             	mov    0x8(%ebp),%eax
 1001e12:	c6 40 34 00          	movb   $0x0,0x34(%eax)
 1001e16:	eb 02                	jmp    1001e1a <_ZN5CCoin5ClockEv+0x66>
 1001e18:	eb 6f                	jmp    1001e89 <_ZN5CCoin5ClockEv+0xd5>
 1001e1a:	8b 45 08             	mov    0x8(%ebp),%eax
 1001e1d:	8b 40 28             	mov    0x28(%eax),%eax
 1001e20:	8d 50 01             	lea    0x1(%eax),%edx
 1001e23:	8b 45 08             	mov    0x8(%ebp),%eax
 1001e26:	89 50 28             	mov    %edx,0x28(%eax)
 1001e29:	8b 45 08             	mov    0x8(%ebp),%eax
 1001e2c:	8b 40 28             	mov    0x28(%eax),%eax
 1001e2f:	83 f8 0a             	cmp    $0xa,%eax
 1001e32:	7e 0a                	jle    1001e3e <_ZN5CCoin5ClockEv+0x8a>
 1001e34:	8b 45 08             	mov    0x8(%ebp),%eax
 1001e37:	c7 40 28 0a 00 00 00 	movl   $0xa,0x28(%eax)
 1001e3e:	8b 45 08             	mov    0x8(%ebp),%eax
 1001e41:	8b 40 28             	mov    0x28(%eax),%eax
 1001e44:	85 c0                	test   %eax,%eax
 1001e46:	74 27                	je     1001e6f <_ZN5CCoin5ClockEv+0xbb>
 1001e48:	8b 45 08             	mov    0x8(%ebp),%eax
 1001e4b:	8b 48 28             	mov    0x28(%eax),%ecx
 1001e4e:	8b 55 08             	mov    0x8(%ebp),%edx
 1001e51:	8b 45 08             	mov    0x8(%ebp),%eax
 1001e54:	8b 40 20             	mov    0x20(%eax),%eax
 1001e57:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 1001e5b:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 1001e62:	00 
 1001e63:	89 54 24 04          	mov    %edx,0x4(%esp)
 1001e67:	89 04 24             	mov    %eax,(%esp)
 1001e6a:	e8 bb 15 00 00       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 1001e6f:	8b 45 08             	mov    0x8(%ebp),%eax
 1001e72:	8b 50 10             	mov    0x10(%eax),%edx
 1001e75:	8b 45 08             	mov    0x8(%ebp),%eax
 1001e78:	8b 40 2c             	mov    0x2c(%eax),%eax
 1001e7b:	39 c2                	cmp    %eax,%edx
 1001e7d:	7e 0a                	jle    1001e89 <_ZN5CCoin5ClockEv+0xd5>
 1001e7f:	8b 45 08             	mov    0x8(%ebp),%eax
 1001e82:	c7 40 08 03 00 00 00 	movl   $0x3,0x8(%eax)
 1001e89:	c9                   	leave  
 1001e8a:	c3                   	ret    
 1001e8b:	90                   	nop

01001e8c <_ZN5CCoin7ThrowUpEv>:
 1001e8c:	55                   	push   %ebp
 1001e8d:	89 e5                	mov    %esp,%ebp
 1001e8f:	83 ec 18             	sub    $0x18,%esp
 1001e92:	8b 45 08             	mov    0x8(%ebp),%eax
 1001e95:	8b 40 20             	mov    0x20(%eax),%eax
 1001e98:	c7 44 24 04 04 00 00 	movl   $0x4,0x4(%esp)
 1001e9f:	00 
 1001ea0:	89 04 24             	mov    %eax,(%esp)
 1001ea3:	e8 60 23 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1001ea8:	8b 45 08             	mov    0x8(%ebp),%eax
 1001eab:	c7 40 28 f7 ff ff ff 	movl   $0xfffffff7,0x28(%eax)
 1001eb2:	8b 45 08             	mov    0x8(%ebp),%eax
 1001eb5:	c7 40 30 03 00 00 00 	movl   $0x3,0x30(%eax)
 1001ebc:	8b 45 08             	mov    0x8(%ebp),%eax
 1001ebf:	c7 40 08 02 00 00 00 	movl   $0x2,0x8(%eax)
 1001ec6:	c9                   	leave  
 1001ec7:	c3                   	ret    

01001ec8 <_ZN8CControl5ClockEv>:
 1001ec8:	55                   	push   %ebp
 1001ec9:	89 e5                	mov    %esp,%ebp
 1001ecb:	83 ec 18             	sub    $0x18,%esp
 1001ece:	8b 45 08             	mov    0x8(%ebp),%eax
 1001ed1:	8b 40 04             	mov    0x4(%eax),%eax
 1001ed4:	89 04 24             	mov    %eax,(%esp)
 1001ed7:	e8 ec 11 00 00       	call   10030c8 <_ZN5CGame5ClockEv>
 1001edc:	8b 45 08             	mov    0x8(%ebp),%eax
 1001edf:	8b 00                	mov    (%eax),%eax
 1001ee1:	89 04 24             	mov    %eax,(%esp)
 1001ee4:	e8 db 28 00 00       	call   10047c4 <_ZN9CGraphMan6UpdateEv>
 1001ee9:	c9                   	leave  
 1001eea:	c3                   	ret    
 1001eeb:	90                   	nop

01001eec <_ZN8CControl8SetGraphEP9CGraphMan>:
 1001eec:	55                   	push   %ebp
 1001eed:	89 e5                	mov    %esp,%ebp
 1001eef:	8b 45 08             	mov    0x8(%ebp),%eax
 1001ef2:	8b 55 0c             	mov    0xc(%ebp),%edx
 1001ef5:	89 10                	mov    %edx,(%eax)
 1001ef7:	5d                   	pop    %ebp
 1001ef8:	c3                   	ret    
 1001ef9:	90                   	nop

01001efa <_ZN8CControl10KeyChangedEi>:
 1001efa:	55                   	push   %ebp
 1001efb:	89 e5                	mov    %esp,%ebp
 1001efd:	83 ec 28             	sub    $0x28,%esp
 1001f00:	8b 45 08             	mov    0x8(%ebp),%eax
 1001f03:	8b 40 08             	mov    0x8(%eax),%eax
 1001f06:	83 e0 40             	and    $0x40,%eax
 1001f09:	85 c0                	test   %eax,%eax
 1001f0b:	75 24                	jne    1001f31 <_ZN8CControl10KeyChangedEi+0x37>
 1001f0d:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001f10:	83 e0 40             	and    $0x40,%eax
 1001f13:	85 c0                	test   %eax,%eax
 1001f15:	74 1a                	je     1001f31 <_ZN8CControl10KeyChangedEi+0x37>
 1001f17:	8b 45 08             	mov    0x8(%ebp),%eax
 1001f1a:	8b 40 04             	mov    0x4(%eax),%eax
 1001f1d:	89 04 24             	mov    %eax,(%esp)
 1001f20:	e8 5f 0c 00 00       	call   1002b84 <_ZN5CGame5StartEv>
 1001f25:	c7 04 24 d4 90 00 01 	movl   $0x10090d4,(%esp)
 1001f2c:	e8 0b 59 00 00       	call   100783c <printf>
 1001f31:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001f34:	83 e0 0f             	and    $0xf,%eax
 1001f37:	85 c0                	test   %eax,%eax
 1001f39:	75 30                	jne    1001f6b <_ZN8CControl10KeyChangedEi+0x71>
 1001f3b:	8b 45 08             	mov    0x8(%ebp),%eax
 1001f3e:	8b 40 08             	mov    0x8(%eax),%eax
 1001f41:	83 e0 0f             	and    $0xf,%eax
 1001f44:	85 c0                	test   %eax,%eax
 1001f46:	74 23                	je     1001f6b <_ZN8CControl10KeyChangedEi+0x71>
 1001f48:	8b 45 08             	mov    0x8(%ebp),%eax
 1001f4b:	8b 40 04             	mov    0x4(%eax),%eax
 1001f4e:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 1001f55:	00 
 1001f56:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 1001f5d:	00 
 1001f5e:	89 04 24             	mov    %eax,(%esp)
 1001f61:	e8 4a 14 00 00       	call   10033b0 <_ZN5CGame4MoveEib>
 1001f66:	e9 1a 01 00 00       	jmp    1002085 <_ZN8CControl10KeyChangedEi+0x18b>
 1001f6b:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001f6e:	83 e0 20             	and    $0x20,%eax
 1001f71:	85 c0                	test   %eax,%eax
 1001f73:	0f 95 c0             	setne  %al
 1001f76:	88 45 f7             	mov    %al,-0x9(%ebp)
 1001f79:	8b 45 08             	mov    0x8(%ebp),%eax
 1001f7c:	8b 40 08             	mov    0x8(%eax),%eax
 1001f7f:	33 45 0c             	xor    0xc(%ebp),%eax
 1001f82:	83 e0 20             	and    $0x20,%eax
 1001f85:	85 c0                	test   %eax,%eax
 1001f87:	0f 95 c0             	setne  %al
 1001f8a:	88 45 f6             	mov    %al,-0xa(%ebp)
 1001f8d:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001f90:	83 e0 01             	and    $0x1,%eax
 1001f93:	84 c0                	test   %al,%al
 1001f95:	74 39                	je     1001fd0 <_ZN8CControl10KeyChangedEi+0xd6>
 1001f97:	8b 45 08             	mov    0x8(%ebp),%eax
 1001f9a:	8b 40 08             	mov    0x8(%eax),%eax
 1001f9d:	83 e0 01             	and    $0x1,%eax
 1001fa0:	83 f0 01             	xor    $0x1,%eax
 1001fa3:	84 c0                	test   %al,%al
 1001fa5:	75 06                	jne    1001fad <_ZN8CControl10KeyChangedEi+0xb3>
 1001fa7:	80 7d f6 00          	cmpb   $0x0,-0xa(%ebp)
 1001fab:	74 23                	je     1001fd0 <_ZN8CControl10KeyChangedEi+0xd6>
 1001fad:	0f b6 55 f7          	movzbl -0x9(%ebp),%edx
 1001fb1:	8b 45 08             	mov    0x8(%ebp),%eax
 1001fb4:	8b 40 04             	mov    0x4(%eax),%eax
 1001fb7:	89 54 24 08          	mov    %edx,0x8(%esp)
 1001fbb:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 1001fc2:	00 
 1001fc3:	89 04 24             	mov    %eax,(%esp)
 1001fc6:	e8 e5 13 00 00       	call   10033b0 <_ZN5CGame4MoveEib>
 1001fcb:	e9 b5 00 00 00       	jmp    1002085 <_ZN8CControl10KeyChangedEi+0x18b>
 1001fd0:	8b 45 0c             	mov    0xc(%ebp),%eax
 1001fd3:	83 e0 02             	and    $0x2,%eax
 1001fd6:	85 c0                	test   %eax,%eax
 1001fd8:	74 33                	je     100200d <_ZN8CControl10KeyChangedEi+0x113>
 1001fda:	8b 45 08             	mov    0x8(%ebp),%eax
 1001fdd:	8b 40 08             	mov    0x8(%eax),%eax
 1001fe0:	83 e0 02             	and    $0x2,%eax
 1001fe3:	85 c0                	test   %eax,%eax
 1001fe5:	74 06                	je     1001fed <_ZN8CControl10KeyChangedEi+0xf3>
 1001fe7:	80 7d f6 00          	cmpb   $0x0,-0xa(%ebp)
 1001feb:	74 20                	je     100200d <_ZN8CControl10KeyChangedEi+0x113>
 1001fed:	0f b6 55 f7          	movzbl -0x9(%ebp),%edx
 1001ff1:	8b 45 08             	mov    0x8(%ebp),%eax
 1001ff4:	8b 40 04             	mov    0x4(%eax),%eax
 1001ff7:	89 54 24 08          	mov    %edx,0x8(%esp)
 1001ffb:	c7 44 24 04 02 00 00 	movl   $0x2,0x4(%esp)
 1002002:	00 
 1002003:	89 04 24             	mov    %eax,(%esp)
 1002006:	e8 a5 13 00 00       	call   10033b0 <_ZN5CGame4MoveEib>
 100200b:	eb 78                	jmp    1002085 <_ZN8CControl10KeyChangedEi+0x18b>
 100200d:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002010:	83 e0 04             	and    $0x4,%eax
 1002013:	85 c0                	test   %eax,%eax
 1002015:	74 33                	je     100204a <_ZN8CControl10KeyChangedEi+0x150>
 1002017:	8b 45 08             	mov    0x8(%ebp),%eax
 100201a:	8b 40 08             	mov    0x8(%eax),%eax
 100201d:	83 e0 04             	and    $0x4,%eax
 1002020:	85 c0                	test   %eax,%eax
 1002022:	74 06                	je     100202a <_ZN8CControl10KeyChangedEi+0x130>
 1002024:	80 7d f6 00          	cmpb   $0x0,-0xa(%ebp)
 1002028:	74 20                	je     100204a <_ZN8CControl10KeyChangedEi+0x150>
 100202a:	0f b6 55 f7          	movzbl -0x9(%ebp),%edx
 100202e:	8b 45 08             	mov    0x8(%ebp),%eax
 1002031:	8b 40 04             	mov    0x4(%eax),%eax
 1002034:	89 54 24 08          	mov    %edx,0x8(%esp)
 1002038:	c7 44 24 04 03 00 00 	movl   $0x3,0x4(%esp)
 100203f:	00 
 1002040:	89 04 24             	mov    %eax,(%esp)
 1002043:	e8 68 13 00 00       	call   10033b0 <_ZN5CGame4MoveEib>
 1002048:	eb 3b                	jmp    1002085 <_ZN8CControl10KeyChangedEi+0x18b>
 100204a:	8b 45 0c             	mov    0xc(%ebp),%eax
 100204d:	83 e0 08             	and    $0x8,%eax
 1002050:	85 c0                	test   %eax,%eax
 1002052:	74 31                	je     1002085 <_ZN8CControl10KeyChangedEi+0x18b>
 1002054:	8b 45 08             	mov    0x8(%ebp),%eax
 1002057:	8b 40 08             	mov    0x8(%eax),%eax
 100205a:	83 e0 08             	and    $0x8,%eax
 100205d:	85 c0                	test   %eax,%eax
 100205f:	74 06                	je     1002067 <_ZN8CControl10KeyChangedEi+0x16d>
 1002061:	80 7d f6 00          	cmpb   $0x0,-0xa(%ebp)
 1002065:	74 1e                	je     1002085 <_ZN8CControl10KeyChangedEi+0x18b>
 1002067:	0f b6 55 f7          	movzbl -0x9(%ebp),%edx
 100206b:	8b 45 08             	mov    0x8(%ebp),%eax
 100206e:	8b 40 04             	mov    0x4(%eax),%eax
 1002071:	89 54 24 08          	mov    %edx,0x8(%esp)
 1002075:	c7 44 24 04 04 00 00 	movl   $0x4,0x4(%esp)
 100207c:	00 
 100207d:	89 04 24             	mov    %eax,(%esp)
 1002080:	e8 2b 13 00 00       	call   10033b0 <_ZN5CGame4MoveEib>
 1002085:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002088:	83 e0 10             	and    $0x10,%eax
 100208b:	85 c0                	test   %eax,%eax
 100208d:	74 0e                	je     100209d <_ZN8CControl10KeyChangedEi+0x1a3>
 100208f:	8b 45 08             	mov    0x8(%ebp),%eax
 1002092:	8b 40 04             	mov    0x4(%eax),%eax
 1002095:	89 04 24             	mov    %eax,(%esp)
 1002098:	e8 49 13 00 00       	call   10033e6 <_ZN5CGame4JumpEv>
 100209d:	8b 45 08             	mov    0x8(%ebp),%eax
 10020a0:	8b 40 08             	mov    0x8(%eax),%eax
 10020a3:	83 e0 20             	and    $0x20,%eax
 10020a6:	85 c0                	test   %eax,%eax
 10020a8:	75 18                	jne    10020c2 <_ZN8CControl10KeyChangedEi+0x1c8>
 10020aa:	8b 45 0c             	mov    0xc(%ebp),%eax
 10020ad:	83 e0 20             	and    $0x20,%eax
 10020b0:	85 c0                	test   %eax,%eax
 10020b2:	74 0e                	je     10020c2 <_ZN8CControl10KeyChangedEi+0x1c8>
 10020b4:	8b 45 08             	mov    0x8(%ebp),%eax
 10020b7:	8b 40 04             	mov    0x4(%eax),%eax
 10020ba:	89 04 24             	mov    %eax,(%esp)
 10020bd:	e8 46 13 00 00       	call   1003408 <_ZN5CGame4FireEv>
 10020c2:	8b 45 08             	mov    0x8(%ebp),%eax
 10020c5:	8b 55 0c             	mov    0xc(%ebp),%edx
 10020c8:	89 50 08             	mov    %edx,0x8(%eax)
 10020cb:	c9                   	leave  
 10020cc:	c3                   	ret    
 10020cd:	90                   	nop

010020ce <_ZN8CControl7SetGameEP5CGame>:
 10020ce:	55                   	push   %ebp
 10020cf:	89 e5                	mov    %esp,%ebp
 10020d1:	8b 45 08             	mov    0x8(%ebp),%eax
 10020d4:	8b 55 0c             	mov    0xc(%ebp),%edx
 10020d7:	89 50 04             	mov    %edx,0x4(%eax)
 10020da:	5d                   	pop    %ebp
 10020db:	c3                   	ret    

010020dc <_ZN8CControlC1Ev>:
 10020dc:	55                   	push   %ebp
 10020dd:	89 e5                	mov    %esp,%ebp
 10020df:	83 ec 18             	sub    $0x18,%esp
 10020e2:	8b 45 08             	mov    0x8(%ebp),%eax
 10020e5:	c7 40 08 00 00 00 00 	movl   $0x0,0x8(%eax)
 10020ec:	c7 04 24 dc 90 00 01 	movl   $0x10090dc,(%esp)
 10020f3:	e8 44 57 00 00       	call   100783c <printf>
 10020f8:	c9                   	leave  
 10020f9:	c3                   	ret    
	...

010020fc <_ZN7CFlowerC1EP5CGameii>:
 10020fc:	55                   	push   %ebp
 10020fd:	89 e5                	mov    %esp,%ebp
 10020ff:	83 ec 28             	sub    $0x28,%esp
 1002102:	8b 45 08             	mov    0x8(%ebp),%eax
 1002105:	c7 44 24 1c ff ff ff 	movl   $0xffffffff,0x1c(%esp)
 100210c:	ff 
 100210d:	c7 44 24 18 10 00 00 	movl   $0x10,0x18(%esp)
 1002114:	00 
 1002115:	c7 44 24 14 10 00 00 	movl   $0x10,0x14(%esp)
 100211c:	00 
 100211d:	8b 55 14             	mov    0x14(%ebp),%edx
 1002120:	89 54 24 10          	mov    %edx,0x10(%esp)
 1002124:	8b 55 10             	mov    0x10(%ebp),%edx
 1002127:	89 54 24 0c          	mov    %edx,0xc(%esp)
 100212b:	c7 44 24 08 05 00 00 	movl   $0x5,0x8(%esp)
 1002132:	00 
 1002133:	8b 55 0c             	mov    0xc(%ebp),%edx
 1002136:	89 54 24 04          	mov    %edx,0x4(%esp)
 100213a:	89 04 24             	mov    %eax,(%esp)
 100213d:	e8 4e 3d 00 00       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 1002142:	8b 45 08             	mov    0x8(%ebp),%eax
 1002145:	c7 00 f8 90 00 01    	movl   $0x10090f8,(%eax)
 100214b:	8b 45 08             	mov    0x8(%ebp),%eax
 100214e:	8b 40 20             	mov    0x20(%eax),%eax
 1002151:	c7 44 24 04 07 00 00 	movl   $0x7,0x4(%esp)
 1002158:	00 
 1002159:	89 04 24             	mov    %eax,(%esp)
 100215c:	e8 a7 20 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1002161:	8b 45 08             	mov    0x8(%ebp),%eax
 1002164:	8b 55 14             	mov    0x14(%ebp),%edx
 1002167:	89 50 2c             	mov    %edx,0x2c(%eax)
 100216a:	8b 45 08             	mov    0x8(%ebp),%eax
 100216d:	c7 40 28 ff ff ff ff 	movl   $0xffffffff,0x28(%eax)
 1002174:	8b 45 08             	mov    0x8(%ebp),%eax
 1002177:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 100217e:	c9                   	leave  
 100217f:	c3                   	ret    

01002180 <_ZN7CFlower8GetImageEPbS0_>:
 1002180:	55                   	push   %ebp
 1002181:	89 e5                	mov    %esp,%ebp
 1002183:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002186:	c6 00 00             	movb   $0x0,(%eax)
 1002189:	8b 45 10             	mov    0x10(%ebp),%eax
 100218c:	c6 00 00             	movb   $0x0,(%eax)
 100218f:	8b 45 08             	mov    0x8(%ebp),%eax
 1002192:	8b 40 30             	mov    0x30(%eax),%eax
 1002195:	c1 e0 0a             	shl    $0xa,%eax
 1002198:	05 00 92 01 01       	add    $0x1019200,%eax
 100219d:	5d                   	pop    %ebp
 100219e:	c3                   	ret    
 100219f:	90                   	nop

010021a0 <_ZN7CFlower5ClockEv>:
 10021a0:	55                   	push   %ebp
 10021a1:	89 e5                	mov    %esp,%ebp
 10021a3:	83 ec 18             	sub    $0x18,%esp
 10021a6:	8b 45 08             	mov    0x8(%ebp),%eax
 10021a9:	8b 40 30             	mov    0x30(%eax),%eax
 10021ac:	85 c0                	test   %eax,%eax
 10021ae:	0f 94 c0             	sete   %al
 10021b1:	0f b6 d0             	movzbl %al,%edx
 10021b4:	8b 45 08             	mov    0x8(%ebp),%eax
 10021b7:	89 50 30             	mov    %edx,0x30(%eax)
 10021ba:	8b 45 08             	mov    0x8(%ebp),%eax
 10021bd:	8b 40 2c             	mov    0x2c(%eax),%eax
 10021c0:	85 c0                	test   %eax,%eax
 10021c2:	74 2b                	je     10021ef <_ZN7CFlower5ClockEv+0x4f>
 10021c4:	8b 45 08             	mov    0x8(%ebp),%eax
 10021c7:	8b 50 2c             	mov    0x2c(%eax),%edx
 10021ca:	8b 45 08             	mov    0x8(%ebp),%eax
 10021cd:	8b 40 10             	mov    0x10(%eax),%eax
 10021d0:	89 d1                	mov    %edx,%ecx
 10021d2:	29 c1                	sub    %eax,%ecx
 10021d4:	89 c8                	mov    %ecx,%eax
 10021d6:	83 f8 10             	cmp    $0x10,%eax
 10021d9:	75 14                	jne    10021ef <_ZN7CFlower5ClockEv+0x4f>
 10021db:	8b 45 08             	mov    0x8(%ebp),%eax
 10021de:	c7 40 2c 00 00 00 00 	movl   $0x0,0x2c(%eax)
 10021e5:	8b 45 08             	mov    0x8(%ebp),%eax
 10021e8:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%eax)
 10021ef:	8b 45 08             	mov    0x8(%ebp),%eax
 10021f2:	8b 40 28             	mov    0x28(%eax),%eax
 10021f5:	85 c0                	test   %eax,%eax
 10021f7:	74 27                	je     1002220 <_ZN7CFlower5ClockEv+0x80>
 10021f9:	8b 45 08             	mov    0x8(%ebp),%eax
 10021fc:	8b 48 28             	mov    0x28(%eax),%ecx
 10021ff:	8b 55 08             	mov    0x8(%ebp),%edx
 1002202:	8b 45 08             	mov    0x8(%ebp),%eax
 1002205:	8b 40 20             	mov    0x20(%eax),%eax
 1002208:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 100220c:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 1002213:	00 
 1002214:	89 54 24 04          	mov    %edx,0x4(%esp)
 1002218:	89 04 24             	mov    %eax,(%esp)
 100221b:	e8 0a 12 00 00       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 1002220:	c9                   	leave  
 1002221:	c3                   	ret    

01002222 <_ZN7CFlower6AttackEP7CObjecti>:
 1002222:	55                   	push   %ebp
 1002223:	89 e5                	mov    %esp,%ebp
 1002225:	83 ec 18             	sub    $0x18,%esp
 1002228:	8b 45 08             	mov    0x8(%ebp),%eax
 100222b:	8b 40 20             	mov    0x20(%eax),%eax
 100222e:	c7 44 24 04 06 00 00 	movl   $0x6,0x4(%esp)
 1002235:	00 
 1002236:	89 04 24             	mov    %eax,(%esp)
 1002239:	e8 ca 1f 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 100223e:	8b 45 08             	mov    0x8(%ebp),%eax
 1002241:	c7 40 08 03 00 00 00 	movl   $0x3,0x8(%eax)
 1002248:	8b 45 0c             	mov    0xc(%ebp),%eax
 100224b:	89 04 24             	mov    %eax,(%esp)
 100224e:	e8 0d 3b 00 00       	call   1005d60 <_ZN6CMario8AddPowerEv>
 1002253:	c9                   	leave  
 1002254:	c3                   	ret    
 1002255:	90                   	nop

01002256 <_ZN7CFlower5BlockEP7CObject>:
 1002256:	55                   	push   %ebp
 1002257:	89 e5                	mov    %esp,%ebp
 1002259:	b8 00 00 00 00       	mov    $0x0,%eax
 100225e:	5d                   	pop    %ebp
 100225f:	c3                   	ret    

01002260 <_ZN17CFlyTortoiseDemonC1EP5CGameii>:
 1002260:	55                   	push   %ebp
 1002261:	89 e5                	mov    %esp,%ebp
 1002263:	83 ec 28             	sub    $0x28,%esp
 1002266:	8b 45 14             	mov    0x14(%ebp),%eax
 1002269:	8d 50 08             	lea    0x8(%eax),%edx
 100226c:	8b 45 08             	mov    0x8(%ebp),%eax
 100226f:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
 1002276:	00 
 1002277:	c7 44 24 18 18 00 00 	movl   $0x18,0x18(%esp)
 100227e:	00 
 100227f:	c7 44 24 14 10 00 00 	movl   $0x10,0x14(%esp)
 1002286:	00 
 1002287:	89 54 24 10          	mov    %edx,0x10(%esp)
 100228b:	8b 55 10             	mov    0x10(%ebp),%edx
 100228e:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1002292:	c7 44 24 08 03 00 00 	movl   $0x3,0x8(%esp)
 1002299:	00 
 100229a:	8b 55 0c             	mov    0xc(%ebp),%edx
 100229d:	89 54 24 04          	mov    %edx,0x4(%esp)
 10022a1:	89 04 24             	mov    %eax,(%esp)
 10022a4:	e8 e7 3b 00 00       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 10022a9:	8b 45 08             	mov    0x8(%ebp),%eax
 10022ac:	c7 00 18 91 00 01    	movl   $0x1009118,(%eax)
 10022b2:	8b 45 08             	mov    0x8(%ebp),%eax
 10022b5:	c7 40 2c 00 00 00 00 	movl   $0x0,0x2c(%eax)
 10022bc:	8b 45 08             	mov    0x8(%ebp),%eax
 10022bf:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 10022c6:	8b 45 08             	mov    0x8(%ebp),%eax
 10022c9:	c7 40 24 fe ff ff ff 	movl   $0xfffffffe,0x24(%eax)
 10022d0:	8b 45 08             	mov    0x8(%ebp),%eax
 10022d3:	c6 40 34 00          	movb   $0x0,0x34(%eax)
 10022d7:	c9                   	leave  
 10022d8:	c3                   	ret    
 10022d9:	90                   	nop

010022da <_ZN17CFlyTortoiseDemon8GetImageEPbS0_>:
 10022da:	55                   	push   %ebp
 10022db:	89 e5                	mov    %esp,%ebp
 10022dd:	8b 45 10             	mov    0x10(%ebp),%eax
 10022e0:	c6 00 00             	movb   $0x0,(%eax)
 10022e3:	8b 45 08             	mov    0x8(%ebp),%eax
 10022e6:	0f b6 50 34          	movzbl 0x34(%eax),%edx
 10022ea:	8b 45 0c             	mov    0xc(%ebp),%eax
 10022ed:	88 10                	mov    %dl,(%eax)
 10022ef:	8b 45 08             	mov    0x8(%ebp),%eax
 10022f2:	8b 50 2c             	mov    0x2c(%eax),%edx
 10022f5:	89 d0                	mov    %edx,%eax
 10022f7:	01 c0                	add    %eax,%eax
 10022f9:	01 d0                	add    %edx,%eax
 10022fb:	c1 e0 09             	shl    $0x9,%eax
 10022fe:	05 00 4a 01 01       	add    $0x1014a00,%eax
 1002303:	5d                   	pop    %ebp
 1002304:	c3                   	ret    
 1002305:	90                   	nop

01002306 <_ZN17CFlyTortoiseDemon5ClockEv>:
 1002306:	55                   	push   %ebp
 1002307:	89 e5                	mov    %esp,%ebp
 1002309:	53                   	push   %ebx
 100230a:	83 ec 24             	sub    $0x24,%esp
 100230d:	8b 45 08             	mov    0x8(%ebp),%eax
 1002310:	8b 40 30             	mov    0x30(%eax),%eax
 1002313:	8d 50 01             	lea    0x1(%eax),%edx
 1002316:	8b 45 08             	mov    0x8(%ebp),%eax
 1002319:	89 50 30             	mov    %edx,0x30(%eax)
 100231c:	8b 45 08             	mov    0x8(%ebp),%eax
 100231f:	8b 40 30             	mov    0x30(%eax),%eax
 1002322:	83 f8 04             	cmp    $0x4,%eax
 1002325:	7e 1e                	jle    1002345 <_ZN17CFlyTortoiseDemon5ClockEv+0x3f>
 1002327:	8b 45 08             	mov    0x8(%ebp),%eax
 100232a:	8b 40 2c             	mov    0x2c(%eax),%eax
 100232d:	85 c0                	test   %eax,%eax
 100232f:	0f 94 c0             	sete   %al
 1002332:	0f b6 d0             	movzbl %al,%edx
 1002335:	8b 45 08             	mov    0x8(%ebp),%eax
 1002338:	89 50 2c             	mov    %edx,0x2c(%eax)
 100233b:	8b 45 08             	mov    0x8(%ebp),%eax
 100233e:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 1002345:	8b 45 08             	mov    0x8(%ebp),%eax
 1002348:	8b 40 28             	mov    0x28(%eax),%eax
 100234b:	8d 50 01             	lea    0x1(%eax),%edx
 100234e:	8b 45 08             	mov    0x8(%ebp),%eax
 1002351:	89 50 28             	mov    %edx,0x28(%eax)
 1002354:	8b 45 08             	mov    0x8(%ebp),%eax
 1002357:	8b 40 28             	mov    0x28(%eax),%eax
 100235a:	83 f8 0a             	cmp    $0xa,%eax
 100235d:	7e 0a                	jle    1002369 <_ZN17CFlyTortoiseDemon5ClockEv+0x63>
 100235f:	8b 45 08             	mov    0x8(%ebp),%eax
 1002362:	c7 40 28 0a 00 00 00 	movl   $0xa,0x28(%eax)
 1002369:	8b 45 08             	mov    0x8(%ebp),%eax
 100236c:	8b 40 24             	mov    0x24(%eax),%eax
 100236f:	85 c0                	test   %eax,%eax
 1002371:	75 0e                	jne    1002381 <_ZN17CFlyTortoiseDemon5ClockEv+0x7b>
 1002373:	8b 45 08             	mov    0x8(%ebp),%eax
 1002376:	8b 40 28             	mov    0x28(%eax),%eax
 1002379:	85 c0                	test   %eax,%eax
 100237b:	0f 84 82 00 00 00    	je     1002403 <_ZN17CFlyTortoiseDemon5ClockEv+0xfd>
 1002381:	8b 45 08             	mov    0x8(%ebp),%eax
 1002384:	8b 58 28             	mov    0x28(%eax),%ebx
 1002387:	8b 45 08             	mov    0x8(%ebp),%eax
 100238a:	8b 48 24             	mov    0x24(%eax),%ecx
 100238d:	8b 55 08             	mov    0x8(%ebp),%edx
 1002390:	8b 45 08             	mov    0x8(%ebp),%eax
 1002393:	8b 40 20             	mov    0x20(%eax),%eax
 1002396:	89 5c 24 0c          	mov    %ebx,0xc(%esp)
 100239a:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 100239e:	89 54 24 04          	mov    %edx,0x4(%esp)
 10023a2:	89 04 24             	mov    %eax,(%esp)
 10023a5:	e8 80 10 00 00       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 10023aa:	89 45 f4             	mov    %eax,-0xc(%ebp)
 10023ad:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10023b0:	83 e0 01             	and    $0x1,%eax
 10023b3:	84 c0                	test   %al,%al
 10023b5:	74 22                	je     10023d9 <_ZN17CFlyTortoiseDemon5ClockEv+0xd3>
 10023b7:	8b 45 08             	mov    0x8(%ebp),%eax
 10023ba:	8b 40 24             	mov    0x24(%eax),%eax
 10023bd:	89 c2                	mov    %eax,%edx
 10023bf:	f7 da                	neg    %edx
 10023c1:	8b 45 08             	mov    0x8(%ebp),%eax
 10023c4:	89 50 24             	mov    %edx,0x24(%eax)
 10023c7:	8b 45 08             	mov    0x8(%ebp),%eax
 10023ca:	0f b6 40 34          	movzbl 0x34(%eax),%eax
 10023ce:	89 c2                	mov    %eax,%edx
 10023d0:	83 f2 01             	xor    $0x1,%edx
 10023d3:	8b 45 08             	mov    0x8(%ebp),%eax
 10023d6:	88 50 34             	mov    %dl,0x34(%eax)
 10023d9:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10023dc:	83 e0 02             	and    $0x2,%eax
 10023df:	85 c0                	test   %eax,%eax
 10023e1:	74 20                	je     1002403 <_ZN17CFlyTortoiseDemon5ClockEv+0xfd>
 10023e3:	8b 45 08             	mov    0x8(%ebp),%eax
 10023e6:	8b 40 28             	mov    0x28(%eax),%eax
 10023e9:	85 c0                	test   %eax,%eax
 10023eb:	7e 0c                	jle    10023f9 <_ZN17CFlyTortoiseDemon5ClockEv+0xf3>
 10023ed:	8b 45 08             	mov    0x8(%ebp),%eax
 10023f0:	c7 40 28 f6 ff ff ff 	movl   $0xfffffff6,0x28(%eax)
 10023f7:	eb 0a                	jmp    1002403 <_ZN17CFlyTortoiseDemon5ClockEv+0xfd>
 10023f9:	8b 45 08             	mov    0x8(%ebp),%eax
 10023fc:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%eax)
 1002403:	83 c4 24             	add    $0x24,%esp
 1002406:	5b                   	pop    %ebx
 1002407:	5d                   	pop    %ebp
 1002408:	c3                   	ret    
 1002409:	90                   	nop

0100240a <_ZN17CFlyTortoiseDemon6AttackEP7CObjecti>:
 100240a:	55                   	push   %ebp
 100240b:	89 e5                	mov    %esp,%ebp
 100240d:	53                   	push   %ebx
 100240e:	83 ec 24             	sub    $0x24,%esp
 1002411:	8b 45 08             	mov    0x8(%ebp),%eax
 1002414:	8b 40 08             	mov    0x8(%eax),%eax
 1002417:	83 f8 01             	cmp    $0x1,%eax
 100241a:	0f 85 0d 01 00 00    	jne    100252d <_ZN17CFlyTortoiseDemon6AttackEP7CObjecti+0x123>
 1002420:	8b 45 10             	mov    0x10(%ebp),%eax
 1002423:	83 f8 01             	cmp    $0x1,%eax
 1002426:	74 0e                	je     1002436 <_ZN17CFlyTortoiseDemon6AttackEP7CObjecti+0x2c>
 1002428:	83 f8 02             	cmp    $0x2,%eax
 100242b:	0f 84 93 00 00 00    	je     10024c4 <_ZN17CFlyTortoiseDemon6AttackEP7CObjecti+0xba>
 1002431:	e9 f8 00 00 00       	jmp    100252e <_ZN17CFlyTortoiseDemon6AttackEP7CObjecti+0x124>
 1002436:	8b 45 08             	mov    0x8(%ebp),%eax
 1002439:	8b 40 20             	mov    0x20(%eax),%eax
 100243c:	c7 44 24 04 09 00 00 	movl   $0x9,0x4(%esp)
 1002443:	00 
 1002444:	89 04 24             	mov    %eax,(%esp)
 1002447:	e8 bc 1d 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 100244c:	8b 45 08             	mov    0x8(%ebp),%eax
 100244f:	c7 40 08 03 00 00 00 	movl   $0x3,0x8(%eax)
 1002456:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 100245d:	e8 e1 dc ff ff       	call   1000143 <_Znwj>
 1002462:	89 c3                	mov    %eax,%ebx
 1002464:	8b 45 08             	mov    0x8(%ebp),%eax
 1002467:	8b 48 10             	mov    0x10(%eax),%ecx
 100246a:	8b 45 08             	mov    0x8(%ebp),%eax
 100246d:	8b 50 0c             	mov    0xc(%eax),%edx
 1002470:	8b 45 08             	mov    0x8(%ebp),%eax
 1002473:	8b 40 20             	mov    0x20(%eax),%eax
 1002476:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 100247a:	89 54 24 08          	mov    %edx,0x8(%esp)
 100247e:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002482:	89 1c 24             	mov    %ebx,(%esp)
 1002485:	e8 1a 44 00 00       	call   10068a4 <_ZN14CTortoiseDemonC1EP5CGameii>
 100248a:	89 5d f4             	mov    %ebx,-0xc(%ebp)
 100248d:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1002490:	8b 00                	mov    (%eax),%eax
 1002492:	83 c0 10             	add    $0x10,%eax
 1002495:	8b 10                	mov    (%eax),%edx
 1002497:	8b 45 10             	mov    0x10(%ebp),%eax
 100249a:	89 44 24 08          	mov    %eax,0x8(%esp)
 100249e:	8b 45 0c             	mov    0xc(%ebp),%eax
 10024a1:	89 44 24 04          	mov    %eax,0x4(%esp)
 10024a5:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10024a8:	89 04 24             	mov    %eax,(%esp)
 10024ab:	ff d2                	call   *%edx
 10024ad:	8b 45 08             	mov    0x8(%ebp),%eax
 10024b0:	8b 40 20             	mov    0x20(%eax),%eax
 10024b3:	8b 55 f4             	mov    -0xc(%ebp),%edx
 10024b6:	89 54 24 04          	mov    %edx,0x4(%esp)
 10024ba:	89 04 24             	mov    %eax,(%esp)
 10024bd:	e8 1e 1d 00 00       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 10024c2:	eb 6a                	jmp    100252e <_ZN17CFlyTortoiseDemon6AttackEP7CObjecti+0x124>
 10024c4:	8b 45 08             	mov    0x8(%ebp),%eax
 10024c7:	8b 40 20             	mov    0x20(%eax),%eax
 10024ca:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 10024d1:	00 
 10024d2:	89 04 24             	mov    %eax,(%esp)
 10024d5:	e8 2e 1d 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 10024da:	8b 45 08             	mov    0x8(%ebp),%eax
 10024dd:	c7 40 08 03 00 00 00 	movl   $0x3,0x8(%eax)
 10024e4:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 10024eb:	e8 53 dc ff ff       	call   1000143 <_Znwj>
 10024f0:	89 c3                	mov    %eax,%ebx
 10024f2:	8b 45 08             	mov    0x8(%ebp),%eax
 10024f5:	8b 48 10             	mov    0x10(%eax),%ecx
 10024f8:	8b 45 08             	mov    0x8(%ebp),%eax
 10024fb:	8b 50 0c             	mov    0xc(%eax),%edx
 10024fe:	8b 45 08             	mov    0x8(%ebp),%eax
 1002501:	8b 40 20             	mov    0x20(%eax),%eax
 1002504:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 1002508:	89 54 24 08          	mov    %edx,0x8(%esp)
 100250c:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002510:	89 1c 24             	mov    %ebx,(%esp)
 1002513:	e8 8c 43 00 00       	call   10068a4 <_ZN14CTortoiseDemonC1EP5CGameii>
 1002518:	8b 45 08             	mov    0x8(%ebp),%eax
 100251b:	8b 40 20             	mov    0x20(%eax),%eax
 100251e:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1002522:	89 04 24             	mov    %eax,(%esp)
 1002525:	e8 b6 1c 00 00       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 100252a:	90                   	nop
 100252b:	eb 01                	jmp    100252e <_ZN17CFlyTortoiseDemon6AttackEP7CObjecti+0x124>
 100252d:	90                   	nop
 100252e:	83 c4 24             	add    $0x24,%esp
 1002531:	5b                   	pop    %ebx
 1002532:	5d                   	pop    %ebp
 1002533:	c3                   	ret    

01002534 <_ZN17CFlyTortoiseDemon4BumpEP7CObjectib>:
 1002534:	55                   	push   %ebp
 1002535:	89 e5                	mov    %esp,%ebp
 1002537:	83 ec 28             	sub    $0x28,%esp
 100253a:	8b 45 14             	mov    0x14(%ebp),%eax
 100253d:	88 45 f4             	mov    %al,-0xc(%ebp)
 1002540:	8b 45 08             	mov    0x8(%ebp),%eax
 1002543:	8b 40 08             	mov    0x8(%eax),%eax
 1002546:	83 f8 01             	cmp    $0x1,%eax
 1002549:	75 3a                	jne    1002585 <_ZN17CFlyTortoiseDemon4BumpEP7CObjectib+0x51>
 100254b:	8b 45 0c             	mov    0xc(%ebp),%eax
 100254e:	8b 40 04             	mov    0x4(%eax),%eax
 1002551:	83 f8 01             	cmp    $0x1,%eax
 1002554:	75 30                	jne    1002586 <_ZN17CFlyTortoiseDemon4BumpEP7CObjectib+0x52>
 1002556:	83 7d 10 03          	cmpl   $0x3,0x10(%ebp)
 100255a:	74 06                	je     1002562 <_ZN17CFlyTortoiseDemon4BumpEP7CObjectib+0x2e>
 100255c:	83 7d 10 01          	cmpl   $0x1,0x10(%ebp)
 1002560:	75 24                	jne    1002586 <_ZN17CFlyTortoiseDemon4BumpEP7CObjectib+0x52>
 1002562:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002565:	8b 00                	mov    (%eax),%eax
 1002567:	83 c0 10             	add    $0x10,%eax
 100256a:	8b 10                	mov    (%eax),%edx
 100256c:	8b 45 08             	mov    0x8(%ebp),%eax
 100256f:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 1002576:	00 
 1002577:	89 44 24 04          	mov    %eax,0x4(%esp)
 100257b:	8b 45 0c             	mov    0xc(%ebp),%eax
 100257e:	89 04 24             	mov    %eax,(%esp)
 1002581:	ff d2                	call   *%edx
 1002583:	eb 01                	jmp    1002586 <_ZN17CFlyTortoiseDemon4BumpEP7CObjectib+0x52>
 1002585:	90                   	nop
 1002586:	c9                   	leave  
 1002587:	c3                   	ret    

01002588 <_ZN7CFungusC1EP5CGameii>:
 1002588:	55                   	push   %ebp
 1002589:	89 e5                	mov    %esp,%ebp
 100258b:	83 ec 28             	sub    $0x28,%esp
 100258e:	8b 45 08             	mov    0x8(%ebp),%eax
 1002591:	c7 44 24 1c ff ff ff 	movl   $0xffffffff,0x1c(%esp)
 1002598:	ff 
 1002599:	c7 44 24 18 10 00 00 	movl   $0x10,0x18(%esp)
 10025a0:	00 
 10025a1:	c7 44 24 14 10 00 00 	movl   $0x10,0x14(%esp)
 10025a8:	00 
 10025a9:	8b 55 14             	mov    0x14(%ebp),%edx
 10025ac:	89 54 24 10          	mov    %edx,0x10(%esp)
 10025b0:	8b 55 10             	mov    0x10(%ebp),%edx
 10025b3:	89 54 24 0c          	mov    %edx,0xc(%esp)
 10025b7:	c7 44 24 08 05 00 00 	movl   $0x5,0x8(%esp)
 10025be:	00 
 10025bf:	8b 55 0c             	mov    0xc(%ebp),%edx
 10025c2:	89 54 24 04          	mov    %edx,0x4(%esp)
 10025c6:	89 04 24             	mov    %eax,(%esp)
 10025c9:	e8 c2 38 00 00       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 10025ce:	8b 45 08             	mov    0x8(%ebp),%eax
 10025d1:	c7 00 38 91 00 01    	movl   $0x1009138,(%eax)
 10025d7:	8b 45 08             	mov    0x8(%ebp),%eax
 10025da:	8b 40 20             	mov    0x20(%eax),%eax
 10025dd:	c7 44 24 04 07 00 00 	movl   $0x7,0x4(%esp)
 10025e4:	00 
 10025e5:	89 04 24             	mov    %eax,(%esp)
 10025e8:	e8 1b 1c 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 10025ed:	8b 45 08             	mov    0x8(%ebp),%eax
 10025f0:	8b 55 14             	mov    0x14(%ebp),%edx
 10025f3:	89 50 2c             	mov    %edx,0x2c(%eax)
 10025f6:	8b 45 08             	mov    0x8(%ebp),%eax
 10025f9:	c7 40 28 ff ff ff ff 	movl   $0xffffffff,0x28(%eax)
 1002600:	c9                   	leave  
 1002601:	c3                   	ret    

01002602 <_ZN7CFungus8GetImageEPbS0_>:
 1002602:	55                   	push   %ebp
 1002603:	89 e5                	mov    %esp,%ebp
 1002605:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002608:	c6 00 00             	movb   $0x0,(%eax)
 100260b:	8b 45 10             	mov    0x10(%ebp),%eax
 100260e:	c6 00 00             	movb   $0x0,(%eax)
 1002611:	b8 00 6e 01 01       	mov    $0x1016e00,%eax
 1002616:	5d                   	pop    %ebp
 1002617:	c3                   	ret    

01002618 <_ZN7CFungus5ClockEv>:
 1002618:	55                   	push   %ebp
 1002619:	89 e5                	mov    %esp,%ebp
 100261b:	53                   	push   %ebx
 100261c:	83 ec 24             	sub    $0x24,%esp
 100261f:	8b 45 08             	mov    0x8(%ebp),%eax
 1002622:	8b 40 2c             	mov    0x2c(%eax),%eax
 1002625:	85 c0                	test   %eax,%eax
 1002627:	74 37                	je     1002660 <_ZN7CFungus5ClockEv+0x48>
 1002629:	8b 45 08             	mov    0x8(%ebp),%eax
 100262c:	8b 50 2c             	mov    0x2c(%eax),%edx
 100262f:	8b 45 08             	mov    0x8(%ebp),%eax
 1002632:	8b 40 10             	mov    0x10(%eax),%eax
 1002635:	89 d1                	mov    %edx,%ecx
 1002637:	29 c1                	sub    %eax,%ecx
 1002639:	89 c8                	mov    %ecx,%eax
 100263b:	83 f8 10             	cmp    $0x10,%eax
 100263e:	75 44                	jne    1002684 <_ZN7CFungus5ClockEv+0x6c>
 1002640:	8b 45 08             	mov    0x8(%ebp),%eax
 1002643:	c7 40 2c 00 00 00 00 	movl   $0x0,0x2c(%eax)
 100264a:	8b 45 08             	mov    0x8(%ebp),%eax
 100264d:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%eax)
 1002654:	8b 45 08             	mov    0x8(%ebp),%eax
 1002657:	c7 40 24 03 00 00 00 	movl   $0x3,0x24(%eax)
 100265e:	eb 24                	jmp    1002684 <_ZN7CFungus5ClockEv+0x6c>
 1002660:	8b 45 08             	mov    0x8(%ebp),%eax
 1002663:	8b 40 28             	mov    0x28(%eax),%eax
 1002666:	8d 50 02             	lea    0x2(%eax),%edx
 1002669:	8b 45 08             	mov    0x8(%ebp),%eax
 100266c:	89 50 28             	mov    %edx,0x28(%eax)
 100266f:	8b 45 08             	mov    0x8(%ebp),%eax
 1002672:	8b 40 28             	mov    0x28(%eax),%eax
 1002675:	83 f8 14             	cmp    $0x14,%eax
 1002678:	7e 0a                	jle    1002684 <_ZN7CFungus5ClockEv+0x6c>
 100267a:	8b 45 08             	mov    0x8(%ebp),%eax
 100267d:	c7 40 28 14 00 00 00 	movl   $0x14,0x28(%eax)
 1002684:	8b 45 08             	mov    0x8(%ebp),%eax
 1002687:	8b 40 24             	mov    0x24(%eax),%eax
 100268a:	85 c0                	test   %eax,%eax
 100268c:	75 0a                	jne    1002698 <_ZN7CFungus5ClockEv+0x80>
 100268e:	8b 45 08             	mov    0x8(%ebp),%eax
 1002691:	8b 40 28             	mov    0x28(%eax),%eax
 1002694:	85 c0                	test   %eax,%eax
 1002696:	74 5a                	je     10026f2 <_ZN7CFungus5ClockEv+0xda>
 1002698:	8b 45 08             	mov    0x8(%ebp),%eax
 100269b:	8b 58 28             	mov    0x28(%eax),%ebx
 100269e:	8b 45 08             	mov    0x8(%ebp),%eax
 10026a1:	8b 48 24             	mov    0x24(%eax),%ecx
 10026a4:	8b 55 08             	mov    0x8(%ebp),%edx
 10026a7:	8b 45 08             	mov    0x8(%ebp),%eax
 10026aa:	8b 40 20             	mov    0x20(%eax),%eax
 10026ad:	89 5c 24 0c          	mov    %ebx,0xc(%esp)
 10026b1:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 10026b5:	89 54 24 04          	mov    %edx,0x4(%esp)
 10026b9:	89 04 24             	mov    %eax,(%esp)
 10026bc:	e8 69 0d 00 00       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 10026c1:	89 45 f4             	mov    %eax,-0xc(%ebp)
 10026c4:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10026c7:	83 e0 01             	and    $0x1,%eax
 10026ca:	84 c0                	test   %al,%al
 10026cc:	74 10                	je     10026de <_ZN7CFungus5ClockEv+0xc6>
 10026ce:	8b 45 08             	mov    0x8(%ebp),%eax
 10026d1:	8b 40 24             	mov    0x24(%eax),%eax
 10026d4:	89 c2                	mov    %eax,%edx
 10026d6:	f7 da                	neg    %edx
 10026d8:	8b 45 08             	mov    0x8(%ebp),%eax
 10026db:	89 50 24             	mov    %edx,0x24(%eax)
 10026de:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10026e1:	83 e0 02             	and    $0x2,%eax
 10026e4:	85 c0                	test   %eax,%eax
 10026e6:	74 0a                	je     10026f2 <_ZN7CFungus5ClockEv+0xda>
 10026e8:	8b 45 08             	mov    0x8(%ebp),%eax
 10026eb:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%eax)
 10026f2:	83 c4 24             	add    $0x24,%esp
 10026f5:	5b                   	pop    %ebx
 10026f6:	5d                   	pop    %ebp
 10026f7:	c3                   	ret    

010026f8 <_ZN7CFungus6AttackEP7CObjecti>:
 10026f8:	55                   	push   %ebp
 10026f9:	89 e5                	mov    %esp,%ebp
 10026fb:	83 ec 18             	sub    $0x18,%esp
 10026fe:	8b 45 08             	mov    0x8(%ebp),%eax
 1002701:	8b 40 20             	mov    0x20(%eax),%eax
 1002704:	c7 44 24 04 06 00 00 	movl   $0x6,0x4(%esp)
 100270b:	00 
 100270c:	89 04 24             	mov    %eax,(%esp)
 100270f:	e8 f4 1a 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1002714:	8b 45 08             	mov    0x8(%ebp),%eax
 1002717:	c7 40 08 03 00 00 00 	movl   $0x3,0x8(%eax)
 100271e:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002721:	89 04 24             	mov    %eax,(%esp)
 1002724:	e8 37 36 00 00       	call   1005d60 <_ZN6CMario8AddPowerEv>
 1002729:	c9                   	leave  
 100272a:	c3                   	ret    
 100272b:	90                   	nop

0100272c <_ZN7CFungus5BlockEP7CObject>:
 100272c:	55                   	push   %ebp
 100272d:	89 e5                	mov    %esp,%ebp
 100272f:	8b 45 08             	mov    0x8(%ebp),%eax
 1002732:	8b 40 2c             	mov    0x2c(%eax),%eax
 1002735:	85 c0                	test   %eax,%eax
 1002737:	74 07                	je     1002740 <_ZN7CFungus5BlockEP7CObject+0x14>
 1002739:	b8 00 00 00 00       	mov    $0x0,%eax
 100273e:	eb 1d                	jmp    100275d <_ZN7CFungus5BlockEP7CObject+0x31>
 1002740:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
 1002744:	74 12                	je     1002758 <_ZN7CFungus5BlockEP7CObject+0x2c>
 1002746:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002749:	8b 40 04             	mov    0x4(%eax),%eax
 100274c:	83 f8 02             	cmp    $0x2,%eax
 100274f:	75 07                	jne    1002758 <_ZN7CFungus5BlockEP7CObject+0x2c>
 1002751:	b8 01 00 00 00       	mov    $0x1,%eax
 1002756:	eb 05                	jmp    100275d <_ZN7CFungus5BlockEP7CObject+0x31>
 1002758:	b8 00 00 00 00       	mov    $0x0,%eax
 100275d:	5d                   	pop    %ebp
 100275e:	c3                   	ret    
	...

01002760 <_ZN12CFungusDemonC1EP5CGameii>:
 1002760:	55                   	push   %ebp
 1002761:	89 e5                	mov    %esp,%ebp
 1002763:	83 ec 28             	sub    $0x28,%esp
 1002766:	8b 45 08             	mov    0x8(%ebp),%eax
 1002769:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
 1002770:	00 
 1002771:	c7 44 24 18 10 00 00 	movl   $0x10,0x18(%esp)
 1002778:	00 
 1002779:	c7 44 24 14 10 00 00 	movl   $0x10,0x14(%esp)
 1002780:	00 
 1002781:	8b 55 14             	mov    0x14(%ebp),%edx
 1002784:	89 54 24 10          	mov    %edx,0x10(%esp)
 1002788:	8b 55 10             	mov    0x10(%ebp),%edx
 100278b:	89 54 24 0c          	mov    %edx,0xc(%esp)
 100278f:	c7 44 24 08 03 00 00 	movl   $0x3,0x8(%esp)
 1002796:	00 
 1002797:	8b 55 0c             	mov    0xc(%ebp),%edx
 100279a:	89 54 24 04          	mov    %edx,0x4(%esp)
 100279e:	89 04 24             	mov    %eax,(%esp)
 10027a1:	e8 ea 36 00 00       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 10027a6:	8b 45 08             	mov    0x8(%ebp),%eax
 10027a9:	c7 00 58 91 00 01    	movl   $0x1009158,(%eax)
 10027af:	8b 45 08             	mov    0x8(%ebp),%eax
 10027b2:	c7 40 2c 00 00 00 00 	movl   $0x0,0x2c(%eax)
 10027b9:	8b 45 08             	mov    0x8(%ebp),%eax
 10027bc:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 10027c3:	8b 45 08             	mov    0x8(%ebp),%eax
 10027c6:	c7 40 24 fe ff ff ff 	movl   $0xfffffffe,0x24(%eax)
 10027cd:	c9                   	leave  
 10027ce:	c3                   	ret    
 10027cf:	90                   	nop

010027d0 <_ZN12CFungusDemon8GetImageEPbS0_>:
 10027d0:	55                   	push   %ebp
 10027d1:	89 e5                	mov    %esp,%ebp
 10027d3:	8b 45 0c             	mov    0xc(%ebp),%eax
 10027d6:	c6 00 00             	movb   $0x0,(%eax)
 10027d9:	8b 45 08             	mov    0x8(%ebp),%eax
 10027dc:	8b 40 08             	mov    0x8(%eax),%eax
 10027df:	83 f8 02             	cmp    $0x2,%eax
 10027e2:	75 12                	jne    10027f6 <_ZN12CFungusDemon8GetImageEPbS0_+0x26>
 10027e4:	8b 45 08             	mov    0x8(%ebp),%eax
 10027e7:	8b 40 2c             	mov    0x2c(%eax),%eax
 10027ea:	85 c0                	test   %eax,%eax
 10027ec:	75 08                	jne    10027f6 <_ZN12CFungusDemon8GetImageEPbS0_+0x26>
 10027ee:	8b 45 10             	mov    0x10(%ebp),%eax
 10027f1:	c6 00 01             	movb   $0x1,(%eax)
 10027f4:	eb 06                	jmp    10027fc <_ZN12CFungusDemon8GetImageEPbS0_+0x2c>
 10027f6:	8b 45 10             	mov    0x10(%ebp),%eax
 10027f9:	c6 00 00             	movb   $0x0,(%eax)
 10027fc:	8b 45 08             	mov    0x8(%ebp),%eax
 10027ff:	8b 40 2c             	mov    0x2c(%eax),%eax
 1002802:	c1 e0 0a             	shl    $0xa,%eax
 1002805:	05 00 2c 01 01       	add    $0x1012c00,%eax
 100280a:	5d                   	pop    %ebp
 100280b:	c3                   	ret    

0100280c <_ZN12CFungusDemon5ClockEv>:
 100280c:	55                   	push   %ebp
 100280d:	89 e5                	mov    %esp,%ebp
 100280f:	53                   	push   %ebx
 1002810:	83 ec 24             	sub    $0x24,%esp
 1002813:	8b 45 08             	mov    0x8(%ebp),%eax
 1002816:	8b 40 08             	mov    0x8(%eax),%eax
 1002819:	83 f8 01             	cmp    $0x1,%eax
 100281c:	75 38                	jne    1002856 <_ZN12CFungusDemon5ClockEv+0x4a>
 100281e:	8b 45 08             	mov    0x8(%ebp),%eax
 1002821:	8b 40 30             	mov    0x30(%eax),%eax
 1002824:	8d 50 01             	lea    0x1(%eax),%edx
 1002827:	8b 45 08             	mov    0x8(%ebp),%eax
 100282a:	89 50 30             	mov    %edx,0x30(%eax)
 100282d:	8b 45 08             	mov    0x8(%ebp),%eax
 1002830:	8b 40 30             	mov    0x30(%eax),%eax
 1002833:	83 f8 04             	cmp    $0x4,%eax
 1002836:	7e 1e                	jle    1002856 <_ZN12CFungusDemon5ClockEv+0x4a>
 1002838:	8b 45 08             	mov    0x8(%ebp),%eax
 100283b:	8b 40 2c             	mov    0x2c(%eax),%eax
 100283e:	85 c0                	test   %eax,%eax
 1002840:	0f 94 c0             	sete   %al
 1002843:	0f b6 d0             	movzbl %al,%edx
 1002846:	8b 45 08             	mov    0x8(%ebp),%eax
 1002849:	89 50 2c             	mov    %edx,0x2c(%eax)
 100284c:	8b 45 08             	mov    0x8(%ebp),%eax
 100284f:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 1002856:	8b 45 08             	mov    0x8(%ebp),%eax
 1002859:	8b 40 08             	mov    0x8(%eax),%eax
 100285c:	83 f8 02             	cmp    $0x2,%eax
 100285f:	75 31                	jne    1002892 <_ZN12CFungusDemon5ClockEv+0x86>
 1002861:	8b 45 08             	mov    0x8(%ebp),%eax
 1002864:	8b 40 2c             	mov    0x2c(%eax),%eax
 1002867:	83 f8 02             	cmp    $0x2,%eax
 100286a:	75 26                	jne    1002892 <_ZN12CFungusDemon5ClockEv+0x86>
 100286c:	8b 45 08             	mov    0x8(%ebp),%eax
 100286f:	8b 40 30             	mov    0x30(%eax),%eax
 1002872:	8d 50 01             	lea    0x1(%eax),%edx
 1002875:	8b 45 08             	mov    0x8(%ebp),%eax
 1002878:	89 50 30             	mov    %edx,0x30(%eax)
 100287b:	8b 45 08             	mov    0x8(%ebp),%eax
 100287e:	8b 40 30             	mov    0x30(%eax),%eax
 1002881:	83 f8 0a             	cmp    $0xa,%eax
 1002884:	75 30                	jne    10028b6 <_ZN12CFungusDemon5ClockEv+0xaa>
 1002886:	8b 45 08             	mov    0x8(%ebp),%eax
 1002889:	c7 40 08 03 00 00 00 	movl   $0x3,0x8(%eax)
 1002890:	eb 24                	jmp    10028b6 <_ZN12CFungusDemon5ClockEv+0xaa>
 1002892:	8b 45 08             	mov    0x8(%ebp),%eax
 1002895:	8b 40 28             	mov    0x28(%eax),%eax
 1002898:	8d 50 02             	lea    0x2(%eax),%edx
 100289b:	8b 45 08             	mov    0x8(%ebp),%eax
 100289e:	89 50 28             	mov    %edx,0x28(%eax)
 10028a1:	8b 45 08             	mov    0x8(%ebp),%eax
 10028a4:	8b 40 28             	mov    0x28(%eax),%eax
 10028a7:	83 f8 14             	cmp    $0x14,%eax
 10028aa:	7e 0a                	jle    10028b6 <_ZN12CFungusDemon5ClockEv+0xaa>
 10028ac:	8b 45 08             	mov    0x8(%ebp),%eax
 10028af:	c7 40 28 14 00 00 00 	movl   $0x14,0x28(%eax)
 10028b6:	8b 45 08             	mov    0x8(%ebp),%eax
 10028b9:	8b 40 24             	mov    0x24(%eax),%eax
 10028bc:	85 c0                	test   %eax,%eax
 10028be:	75 0a                	jne    10028ca <_ZN12CFungusDemon5ClockEv+0xbe>
 10028c0:	8b 45 08             	mov    0x8(%ebp),%eax
 10028c3:	8b 40 28             	mov    0x28(%eax),%eax
 10028c6:	85 c0                	test   %eax,%eax
 10028c8:	74 5a                	je     1002924 <_ZN12CFungusDemon5ClockEv+0x118>
 10028ca:	8b 45 08             	mov    0x8(%ebp),%eax
 10028cd:	8b 58 28             	mov    0x28(%eax),%ebx
 10028d0:	8b 45 08             	mov    0x8(%ebp),%eax
 10028d3:	8b 48 24             	mov    0x24(%eax),%ecx
 10028d6:	8b 55 08             	mov    0x8(%ebp),%edx
 10028d9:	8b 45 08             	mov    0x8(%ebp),%eax
 10028dc:	8b 40 20             	mov    0x20(%eax),%eax
 10028df:	89 5c 24 0c          	mov    %ebx,0xc(%esp)
 10028e3:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 10028e7:	89 54 24 04          	mov    %edx,0x4(%esp)
 10028eb:	89 04 24             	mov    %eax,(%esp)
 10028ee:	e8 37 0b 00 00       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 10028f3:	89 45 f4             	mov    %eax,-0xc(%ebp)
 10028f6:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10028f9:	83 e0 01             	and    $0x1,%eax
 10028fc:	84 c0                	test   %al,%al
 10028fe:	74 10                	je     1002910 <_ZN12CFungusDemon5ClockEv+0x104>
 1002900:	8b 45 08             	mov    0x8(%ebp),%eax
 1002903:	8b 40 24             	mov    0x24(%eax),%eax
 1002906:	89 c2                	mov    %eax,%edx
 1002908:	f7 da                	neg    %edx
 100290a:	8b 45 08             	mov    0x8(%ebp),%eax
 100290d:	89 50 24             	mov    %edx,0x24(%eax)
 1002910:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1002913:	83 e0 02             	and    $0x2,%eax
 1002916:	85 c0                	test   %eax,%eax
 1002918:	74 0a                	je     1002924 <_ZN12CFungusDemon5ClockEv+0x118>
 100291a:	8b 45 08             	mov    0x8(%ebp),%eax
 100291d:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%eax)
 1002924:	83 c4 24             	add    $0x24,%esp
 1002927:	5b                   	pop    %ebx
 1002928:	5d                   	pop    %ebp
 1002929:	c3                   	ret    

0100292a <_ZN12CFungusDemon6AttackEP7CObjecti>:
 100292a:	55                   	push   %ebp
 100292b:	89 e5                	mov    %esp,%ebp
 100292d:	83 ec 18             	sub    $0x18,%esp
 1002930:	8b 45 08             	mov    0x8(%ebp),%eax
 1002933:	8b 40 08             	mov    0x8(%eax),%eax
 1002936:	83 f8 01             	cmp    $0x1,%eax
 1002939:	0f 85 f4 00 00 00    	jne    1002a33 <_ZN12CFungusDemon6AttackEP7CObjecti+0x109>
 100293f:	8b 45 10             	mov    0x10(%ebp),%eax
 1002942:	83 f8 01             	cmp    $0x1,%eax
 1002945:	74 0a                	je     1002951 <_ZN12CFungusDemon6AttackEP7CObjecti+0x27>
 1002947:	83 f8 02             	cmp    $0x2,%eax
 100294a:	74 48                	je     1002994 <_ZN12CFungusDemon6AttackEP7CObjecti+0x6a>
 100294c:	e9 8d 00 00 00       	jmp    10029de <_ZN12CFungusDemon6AttackEP7CObjecti+0xb4>
 1002951:	8b 45 08             	mov    0x8(%ebp),%eax
 1002954:	8b 40 20             	mov    0x20(%eax),%eax
 1002957:	c7 44 24 04 09 00 00 	movl   $0x9,0x4(%esp)
 100295e:	00 
 100295f:	89 04 24             	mov    %eax,(%esp)
 1002962:	e8 a1 18 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1002967:	8b 45 08             	mov    0x8(%ebp),%eax
 100296a:	c7 40 2c 00 00 00 00 	movl   $0x0,0x2c(%eax)
 1002971:	8b 45 08             	mov    0x8(%ebp),%eax
 1002974:	c7 40 08 02 00 00 00 	movl   $0x2,0x8(%eax)
 100297b:	8b 45 08             	mov    0x8(%ebp),%eax
 100297e:	c7 40 28 f6 ff ff ff 	movl   $0xfffffff6,0x28(%eax)
 1002985:	8b 45 08             	mov    0x8(%ebp),%eax
 1002988:	c7 40 24 02 00 00 00 	movl   $0x2,0x24(%eax)
 100298f:	e9 93 00 00 00       	jmp    1002a27 <_ZN12CFungusDemon6AttackEP7CObjecti+0xfd>
 1002994:	8b 45 08             	mov    0x8(%ebp),%eax
 1002997:	8b 40 20             	mov    0x20(%eax),%eax
 100299a:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 10029a1:	00 
 10029a2:	89 04 24             	mov    %eax,(%esp)
 10029a5:	e8 5e 18 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 10029aa:	8b 45 08             	mov    0x8(%ebp),%eax
 10029ad:	c7 40 2c 02 00 00 00 	movl   $0x2,0x2c(%eax)
 10029b4:	8b 45 08             	mov    0x8(%ebp),%eax
 10029b7:	c7 40 08 02 00 00 00 	movl   $0x2,0x8(%eax)
 10029be:	8b 45 08             	mov    0x8(%ebp),%eax
 10029c1:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%eax)
 10029c8:	8b 45 08             	mov    0x8(%ebp),%eax
 10029cb:	c7 40 24 00 00 00 00 	movl   $0x0,0x24(%eax)
 10029d2:	8b 45 08             	mov    0x8(%ebp),%eax
 10029d5:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 10029dc:	eb 49                	jmp    1002a27 <_ZN12CFungusDemon6AttackEP7CObjecti+0xfd>
 10029de:	8b 45 0c             	mov    0xc(%ebp),%eax
 10029e1:	8b 40 04             	mov    0x4(%eax),%eax
 10029e4:	83 f8 02             	cmp    $0x2,%eax
 10029e7:	75 3e                	jne    1002a27 <_ZN12CFungusDemon6AttackEP7CObjecti+0xfd>
 10029e9:	8b 45 08             	mov    0x8(%ebp),%eax
 10029ec:	8b 40 20             	mov    0x20(%eax),%eax
 10029ef:	c7 44 24 04 09 00 00 	movl   $0x9,0x4(%esp)
 10029f6:	00 
 10029f7:	89 04 24             	mov    %eax,(%esp)
 10029fa:	e8 09 18 00 00       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 10029ff:	8b 45 08             	mov    0x8(%ebp),%eax
 1002a02:	c7 40 2c 00 00 00 00 	movl   $0x0,0x2c(%eax)
 1002a09:	8b 45 08             	mov    0x8(%ebp),%eax
 1002a0c:	c7 40 08 02 00 00 00 	movl   $0x2,0x8(%eax)
 1002a13:	8b 45 08             	mov    0x8(%ebp),%eax
 1002a16:	c7 40 28 f6 ff ff ff 	movl   $0xfffffff6,0x28(%eax)
 1002a1d:	8b 45 08             	mov    0x8(%ebp),%eax
 1002a20:	c7 40 24 02 00 00 00 	movl   $0x2,0x24(%eax)
 1002a27:	8b 45 08             	mov    0x8(%ebp),%eax
 1002a2a:	c7 40 1c 01 00 00 00 	movl   $0x1,0x1c(%eax)
 1002a31:	eb 01                	jmp    1002a34 <_ZN12CFungusDemon6AttackEP7CObjecti+0x10a>
 1002a33:	90                   	nop
 1002a34:	c9                   	leave  
 1002a35:	c3                   	ret    

01002a36 <_ZN12CFungusDemon4BumpEP7CObjectib>:
 1002a36:	55                   	push   %ebp
 1002a37:	89 e5                	mov    %esp,%ebp
 1002a39:	83 ec 28             	sub    $0x28,%esp
 1002a3c:	8b 45 14             	mov    0x14(%ebp),%eax
 1002a3f:	88 45 f4             	mov    %al,-0xc(%ebp)
 1002a42:	8b 45 08             	mov    0x8(%ebp),%eax
 1002a45:	8b 40 08             	mov    0x8(%eax),%eax
 1002a48:	83 f8 01             	cmp    $0x1,%eax
 1002a4b:	75 3a                	jne    1002a87 <_ZN12CFungusDemon4BumpEP7CObjectib+0x51>
 1002a4d:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002a50:	8b 40 04             	mov    0x4(%eax),%eax
 1002a53:	83 f8 01             	cmp    $0x1,%eax
 1002a56:	75 30                	jne    1002a88 <_ZN12CFungusDemon4BumpEP7CObjectib+0x52>
 1002a58:	83 7d 10 03          	cmpl   $0x3,0x10(%ebp)
 1002a5c:	74 06                	je     1002a64 <_ZN12CFungusDemon4BumpEP7CObjectib+0x2e>
 1002a5e:	83 7d 10 01          	cmpl   $0x1,0x10(%ebp)
 1002a62:	75 24                	jne    1002a88 <_ZN12CFungusDemon4BumpEP7CObjectib+0x52>
 1002a64:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002a67:	8b 00                	mov    (%eax),%eax
 1002a69:	83 c0 10             	add    $0x10,%eax
 1002a6c:	8b 10                	mov    (%eax),%edx
 1002a6e:	8b 45 08             	mov    0x8(%ebp),%eax
 1002a71:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 1002a78:	00 
 1002a79:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002a7d:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002a80:	89 04 24             	mov    %eax,(%esp)
 1002a83:	ff d2                	call   *%edx
 1002a85:	eb 01                	jmp    1002a88 <_ZN12CFungusDemon4BumpEP7CObjectib+0x52>
 1002a87:	90                   	nop
 1002a88:	c9                   	leave  
 1002a89:	c3                   	ret    
	...

01002a8c <_ZN5CGameC1Ev>:
 1002a8c:	55                   	push   %ebp
 1002a8d:	89 e5                	mov    %esp,%ebp
 1002a8f:	83 ec 18             	sub    $0x18,%esp
 1002a92:	8b 45 08             	mov    0x8(%ebp),%eax
 1002a95:	c7 00 00 00 00 00    	movl   $0x0,(%eax)
 1002a9b:	8b 45 08             	mov    0x8(%ebp),%eax
 1002a9e:	c7 80 58 9c 00 00 00 	movl   $0x0,0x9c58(%eax)
 1002aa5:	00 00 00 
 1002aa8:	8b 45 08             	mov    0x8(%ebp),%eax
 1002aab:	c7 40 18 00 00 00 00 	movl   $0x0,0x18(%eax)
 1002ab2:	c7 04 24 6c 91 00 01 	movl   $0x100916c,(%esp)
 1002ab9:	e8 7e 4d 00 00       	call   100783c <printf>
 1002abe:	c9                   	leave  
 1002abf:	c3                   	ret    

01002ac0 <_ZN5CGame12GetAllObjectEv>:
 1002ac0:	55                   	push   %ebp
 1002ac1:	89 e5                	mov    %esp,%ebp
 1002ac3:	8b 45 08             	mov    0x8(%ebp),%eax
 1002ac6:	8b 00                	mov    (%eax),%eax
 1002ac8:	85 c0                	test   %eax,%eax
 1002aca:	75 07                	jne    1002ad3 <_ZN5CGame12GetAllObjectEv+0x13>
 1002acc:	b8 00 00 00 00       	mov    $0x0,%eax
 1002ad1:	eb 06                	jmp    1002ad9 <_ZN5CGame12GetAllObjectEv+0x19>
 1002ad3:	8b 45 08             	mov    0x8(%ebp),%eax
 1002ad6:	83 c0 18             	add    $0x18,%eax
 1002ad9:	5d                   	pop    %ebp
 1002ada:	c3                   	ret    
 1002adb:	90                   	nop

01002adc <_ZN5CGame15m_Object_insertEP7CObject>:
 1002adc:	55                   	push   %ebp
 1002add:	89 e5                	mov    %esp,%ebp
 1002adf:	53                   	push   %ebx
 1002ae0:	8b 45 08             	mov    0x8(%ebp),%eax
 1002ae3:	8b 80 58 9c 00 00    	mov    0x9c58(%eax),%eax
 1002ae9:	8b 55 08             	mov    0x8(%ebp),%edx
 1002aec:	8d 48 04             	lea    0x4(%eax),%ecx
 1002aef:	8b 5d 0c             	mov    0xc(%ebp),%ebx
 1002af2:	89 5c 8a 08          	mov    %ebx,0x8(%edx,%ecx,4)
 1002af6:	8d 50 01             	lea    0x1(%eax),%edx
 1002af9:	8b 45 08             	mov    0x8(%ebp),%eax
 1002afc:	89 90 58 9c 00 00    	mov    %edx,0x9c58(%eax)
 1002b02:	5b                   	pop    %ebx
 1002b03:	5d                   	pop    %ebp
 1002b04:	c3                   	ret    
 1002b05:	90                   	nop

01002b06 <_ZN5CGame14m_Object_eraseEPP7CObject>:
 1002b06:	55                   	push   %ebp
 1002b07:	89 e5                	mov    %esp,%ebp
 1002b09:	83 ec 10             	sub    $0x10,%esp
 1002b0c:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002b0f:	89 45 fc             	mov    %eax,-0x4(%ebp)
 1002b12:	eb 0f                	jmp    1002b23 <_ZN5CGame14m_Object_eraseEPP7CObject+0x1d>
 1002b14:	8b 45 fc             	mov    -0x4(%ebp),%eax
 1002b17:	8b 50 04             	mov    0x4(%eax),%edx
 1002b1a:	8b 45 fc             	mov    -0x4(%ebp),%eax
 1002b1d:	89 10                	mov    %edx,(%eax)
 1002b1f:	83 45 fc 04          	addl   $0x4,-0x4(%ebp)
 1002b23:	8b 45 fc             	mov    -0x4(%ebp),%eax
 1002b26:	8b 00                	mov    (%eax),%eax
 1002b28:	85 c0                	test   %eax,%eax
 1002b2a:	0f 95 c0             	setne  %al
 1002b2d:	84 c0                	test   %al,%al
 1002b2f:	75 e3                	jne    1002b14 <_ZN5CGame14m_Object_eraseEPP7CObject+0xe>
 1002b31:	8b 45 08             	mov    0x8(%ebp),%eax
 1002b34:	8b 80 58 9c 00 00    	mov    0x9c58(%eax),%eax
 1002b3a:	8d 50 ff             	lea    -0x1(%eax),%edx
 1002b3d:	8b 45 08             	mov    0x8(%ebp),%eax
 1002b40:	89 90 58 9c 00 00    	mov    %edx,0x9c58(%eax)
 1002b46:	c9                   	leave  
 1002b47:	c3                   	ret    

01002b48 <_ZN5CGame14m_Object_clearEv>:
 1002b48:	55                   	push   %ebp
 1002b49:	89 e5                	mov    %esp,%ebp
 1002b4b:	83 ec 10             	sub    $0x10,%esp
 1002b4e:	8b 45 08             	mov    0x8(%ebp),%eax
 1002b51:	83 c0 18             	add    $0x18,%eax
 1002b54:	89 45 fc             	mov    %eax,-0x4(%ebp)
 1002b57:	eb 0d                	jmp    1002b66 <_ZN5CGame14m_Object_clearEv+0x1e>
 1002b59:	8b 45 fc             	mov    -0x4(%ebp),%eax
 1002b5c:	c7 00 00 00 00 00    	movl   $0x0,(%eax)
 1002b62:	83 45 fc 04          	addl   $0x4,-0x4(%ebp)
 1002b66:	8b 45 fc             	mov    -0x4(%ebp),%eax
 1002b69:	8b 00                	mov    (%eax),%eax
 1002b6b:	85 c0                	test   %eax,%eax
 1002b6d:	0f 95 c0             	setne  %al
 1002b70:	84 c0                	test   %al,%al
 1002b72:	75 e5                	jne    1002b59 <_ZN5CGame14m_Object_clearEv+0x11>
 1002b74:	8b 45 08             	mov    0x8(%ebp),%eax
 1002b77:	c7 80 58 9c 00 00 00 	movl   $0x0,0x9c58(%eax)
 1002b7e:	00 00 00 
 1002b81:	c9                   	leave  
 1002b82:	c3                   	ret    
 1002b83:	90                   	nop

01002b84 <_ZN5CGame5StartEv>:
 1002b84:	55                   	push   %ebp
 1002b85:	89 e5                	mov    %esp,%ebp
 1002b87:	53                   	push   %ebx
 1002b88:	83 ec 34             	sub    $0x34,%esp
 1002b8b:	8b 45 08             	mov    0x8(%ebp),%eax
 1002b8e:	8b 00                	mov    (%eax),%eax
 1002b90:	85 c0                	test   %eax,%eax
 1002b92:	0f 85 a4 00 00 00    	jne    1002c3c <_ZN5CGame5StartEv+0xb8>
 1002b98:	8b 45 08             	mov    0x8(%ebp),%eax
 1002b9b:	83 c0 18             	add    $0x18,%eax
 1002b9e:	89 45 f4             	mov    %eax,-0xc(%ebp)
 1002ba1:	eb 11                	jmp    1002bb4 <_ZN5CGame5StartEv+0x30>
 1002ba3:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1002ba6:	8b 00                	mov    (%eax),%eax
 1002ba8:	89 04 24             	mov    %eax,(%esp)
 1002bab:	e8 ac d5 ff ff       	call   100015c <_ZdlPv>
 1002bb0:	83 45 f4 04          	addl   $0x4,-0xc(%ebp)
 1002bb4:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1002bb7:	8b 00                	mov    (%eax),%eax
 1002bb9:	85 c0                	test   %eax,%eax
 1002bbb:	0f 95 c0             	setne  %al
 1002bbe:	84 c0                	test   %al,%al
 1002bc0:	75 e1                	jne    1002ba3 <_ZN5CGame5StartEv+0x1f>
 1002bc2:	8b 45 08             	mov    0x8(%ebp),%eax
 1002bc5:	89 04 24             	mov    %eax,(%esp)
 1002bc8:	e8 7b ff ff ff       	call   1002b48 <_ZN5CGame14m_Object_clearEv>
 1002bcd:	c7 04 24 4c 00 00 00 	movl   $0x4c,(%esp)
 1002bd4:	e8 6a d5 ff ff       	call   1000143 <_Znwj>
 1002bd9:	89 c3                	mov    %eax,%ebx
 1002bdb:	c7 44 24 10 01 00 00 	movl   $0x1,0x10(%esp)
 1002be2:	00 
 1002be3:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 1002bea:	00 
 1002beb:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 1002bf2:	00 
 1002bf3:	8b 45 08             	mov    0x8(%ebp),%eax
 1002bf6:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002bfa:	89 1c 24             	mov    %ebx,(%esp)
 1002bfd:	e8 16 26 00 00       	call   1005218 <_ZN6CMarioC1EP5CGameiii>
 1002c02:	8b 45 08             	mov    0x8(%ebp),%eax
 1002c05:	89 18                	mov    %ebx,(%eax)
 1002c07:	8b 45 08             	mov    0x8(%ebp),%eax
 1002c0a:	8b 00                	mov    (%eax),%eax
 1002c0c:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002c10:	8b 45 08             	mov    0x8(%ebp),%eax
 1002c13:	89 04 24             	mov    %eax,(%esp)
 1002c16:	e8 c1 fe ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1002c1b:	8b 45 08             	mov    0x8(%ebp),%eax
 1002c1e:	c7 40 04 00 00 00 00 	movl   $0x0,0x4(%eax)
 1002c25:	8b 45 08             	mov    0x8(%ebp),%eax
 1002c28:	c7 40 08 24 9f 01 01 	movl   $0x1019f24,0x8(%eax)
 1002c2f:	8b 45 08             	mov    0x8(%ebp),%eax
 1002c32:	89 04 24             	mov    %eax,(%esp)
 1002c35:	e8 48 13 00 00       	call   1003f82 <_ZN5CGame11LoadMapDataEv>
 1002c3a:	eb 01                	jmp    1002c3d <_ZN5CGame5StartEv+0xb9>
 1002c3c:	90                   	nop
 1002c3d:	83 c4 34             	add    $0x34,%esp
 1002c40:	5b                   	pop    %ebx
 1002c41:	5d                   	pop    %ebp
 1002c42:	c3                   	ret    
 1002c43:	90                   	nop

01002c44 <_ZN5CGame12InsertObjectEiii>:
 1002c44:	55                   	push   %ebp
 1002c45:	89 e5                	mov    %esp,%ebp
 1002c47:	53                   	push   %ebx
 1002c48:	83 ec 24             	sub    $0x24,%esp
 1002c4b:	83 7d 14 11          	cmpl   $0x11,0x14(%ebp)
 1002c4f:	0f 87 6c 04 00 00    	ja     10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 1002c55:	8b 45 14             	mov    0x14(%ebp),%eax
 1002c58:	c1 e0 02             	shl    $0x2,%eax
 1002c5b:	05 78 91 00 01       	add    $0x1009178,%eax
 1002c60:	8b 00                	mov    (%eax),%eax
 1002c62:	ff e0                	jmp    *%eax
 1002c64:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 1002c6b:	e8 d3 d4 ff ff       	call   1000143 <_Znwj>
 1002c70:	89 c3                	mov    %eax,%ebx
 1002c72:	c7 44 24 10 00 00 00 	movl   $0x0,0x10(%esp)
 1002c79:	00 
 1002c7a:	8b 45 10             	mov    0x10(%ebp),%eax
 1002c7d:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1002c81:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002c84:	89 44 24 08          	mov    %eax,0x8(%esp)
 1002c88:	8b 45 08             	mov    0x8(%ebp),%eax
 1002c8b:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002c8f:	89 1c 24             	mov    %ebx,(%esp)
 1002c92:	e8 25 e6 ff ff       	call   10012bc <_ZN6CBrickC1EP5CGameiii>
 1002c97:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1002c9b:	8b 45 08             	mov    0x8(%ebp),%eax
 1002c9e:	89 04 24             	mov    %eax,(%esp)
 1002ca1:	e8 36 fe ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1002ca6:	e9 16 04 00 00       	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 1002cab:	c7 04 24 2c 00 00 00 	movl   $0x2c,(%esp)
 1002cb2:	e8 8c d4 ff ff       	call   1000143 <_Znwj>
 1002cb7:	89 c3                	mov    %eax,%ebx
 1002cb9:	8b 45 10             	mov    0x10(%ebp),%eax
 1002cbc:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1002cc0:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002cc3:	89 44 24 08          	mov    %eax,0x8(%esp)
 1002cc7:	8b 45 08             	mov    0x8(%ebp),%eax
 1002cca:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002cce:	89 1c 24             	mov    %ebx,(%esp)
 1002cd1:	e8 66 3b 00 00       	call   100683c <_ZN6CStoneC1EP5CGameii>
 1002cd6:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1002cda:	8b 45 08             	mov    0x8(%ebp),%eax
 1002cdd:	89 04 24             	mov    %eax,(%esp)
 1002ce0:	e8 f7 fd ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1002ce5:	e9 d7 03 00 00       	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 1002cea:	c7 04 24 2c 00 00 00 	movl   $0x2c,(%esp)
 1002cf1:	e8 4d d4 ff ff       	call   1000143 <_Znwj>
 1002cf6:	89 c3                	mov    %eax,%ebx
 1002cf8:	8b 45 10             	mov    0x10(%ebp),%eax
 1002cfb:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1002cff:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002d02:	89 44 24 08          	mov    %eax,0x8(%esp)
 1002d06:	8b 45 08             	mov    0x8(%ebp),%eax
 1002d09:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002d0d:	89 1c 24             	mov    %ebx,(%esp)
 1002d10:	e8 3f 32 00 00       	call   1005f54 <_ZN9CPipeBodyC1EP5CGameii>
 1002d15:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1002d19:	8b 45 08             	mov    0x8(%ebp),%eax
 1002d1c:	89 04 24             	mov    %eax,(%esp)
 1002d1f:	e8 b8 fd ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1002d24:	e9 98 03 00 00       	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 1002d29:	c7 04 24 2c 00 00 00 	movl   $0x2c,(%esp)
 1002d30:	e8 0e d4 ff ff       	call   1000143 <_Znwj>
 1002d35:	89 c3                	mov    %eax,%ebx
 1002d37:	8b 45 10             	mov    0x10(%ebp),%eax
 1002d3a:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1002d3e:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002d41:	89 44 24 08          	mov    %eax,0x8(%esp)
 1002d45:	8b 45 08             	mov    0x8(%ebp),%eax
 1002d48:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002d4c:	89 1c 24             	mov    %ebx,(%esp)
 1002d4f:	e8 68 32 00 00       	call   1005fbc <_ZN8CPipeTopC1EP5CGameii>
 1002d54:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1002d58:	8b 45 08             	mov    0x8(%ebp),%eax
 1002d5b:	89 04 24             	mov    %eax,(%esp)
 1002d5e:	e8 79 fd ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1002d63:	e9 59 03 00 00       	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 1002d68:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 1002d6f:	e8 cf d3 ff ff       	call   1000143 <_Znwj>
 1002d74:	89 c3                	mov    %eax,%ebx
 1002d76:	c7 44 24 10 03 00 00 	movl   $0x3,0x10(%esp)
 1002d7d:	00 
 1002d7e:	8b 45 10             	mov    0x10(%ebp),%eax
 1002d81:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1002d85:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002d88:	89 44 24 08          	mov    %eax,0x8(%esp)
 1002d8c:	8b 45 08             	mov    0x8(%ebp),%eax
 1002d8f:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002d93:	89 1c 24             	mov    %ebx,(%esp)
 1002d96:	e8 89 32 00 00       	call   1006024 <_ZN9CQuestionC1EP5CGameiii>
 1002d9b:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1002d9f:	8b 45 08             	mov    0x8(%ebp),%eax
 1002da2:	89 04 24             	mov    %eax,(%esp)
 1002da5:	e8 32 fd ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1002daa:	e9 12 03 00 00       	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 1002daf:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 1002db6:	e8 88 d3 ff ff       	call   1000143 <_Znwj>
 1002dbb:	89 c3                	mov    %eax,%ebx
 1002dbd:	c7 44 24 10 01 00 00 	movl   $0x1,0x10(%esp)
 1002dc4:	00 
 1002dc5:	8b 45 10             	mov    0x10(%ebp),%eax
 1002dc8:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1002dcc:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002dcf:	89 44 24 08          	mov    %eax,0x8(%esp)
 1002dd3:	8b 45 08             	mov    0x8(%ebp),%eax
 1002dd6:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002dda:	89 1c 24             	mov    %ebx,(%esp)
 1002ddd:	e8 42 32 00 00       	call   1006024 <_ZN9CQuestionC1EP5CGameiii>
 1002de2:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1002de6:	8b 45 08             	mov    0x8(%ebp),%eax
 1002de9:	89 04 24             	mov    %eax,(%esp)
 1002dec:	e8 eb fc ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1002df1:	e9 cb 02 00 00       	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 1002df6:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 1002dfd:	e8 41 d3 ff ff       	call   1000143 <_Znwj>
 1002e02:	89 c3                	mov    %eax,%ebx
 1002e04:	c7 44 24 10 02 00 00 	movl   $0x2,0x10(%esp)
 1002e0b:	00 
 1002e0c:	8b 45 10             	mov    0x10(%ebp),%eax
 1002e0f:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1002e13:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002e16:	89 44 24 08          	mov    %eax,0x8(%esp)
 1002e1a:	8b 45 08             	mov    0x8(%ebp),%eax
 1002e1d:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002e21:	89 1c 24             	mov    %ebx,(%esp)
 1002e24:	e8 fb 31 00 00       	call   1006024 <_ZN9CQuestionC1EP5CGameiii>
 1002e29:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1002e2d:	8b 45 08             	mov    0x8(%ebp),%eax
 1002e30:	89 04 24             	mov    %eax,(%esp)
 1002e33:	e8 a4 fc ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1002e38:	e9 84 02 00 00       	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 1002e3d:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 1002e44:	e8 fa d2 ff ff       	call   1000143 <_Znwj>
 1002e49:	89 c3                	mov    %eax,%ebx
 1002e4b:	c7 44 24 10 01 00 00 	movl   $0x1,0x10(%esp)
 1002e52:	00 
 1002e53:	8b 45 10             	mov    0x10(%ebp),%eax
 1002e56:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1002e5a:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002e5d:	89 44 24 08          	mov    %eax,0x8(%esp)
 1002e61:	8b 45 08             	mov    0x8(%ebp),%eax
 1002e64:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002e68:	89 1c 24             	mov    %ebx,(%esp)
 1002e6b:	e8 4c e4 ff ff       	call   10012bc <_ZN6CBrickC1EP5CGameiii>
 1002e70:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1002e74:	8b 45 08             	mov    0x8(%ebp),%eax
 1002e77:	89 04 24             	mov    %eax,(%esp)
 1002e7a:	e8 5d fc ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1002e7f:	e9 3d 02 00 00       	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 1002e84:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 1002e8b:	e8 b3 d2 ff ff       	call   1000143 <_Znwj>
 1002e90:	89 c3                	mov    %eax,%ebx
 1002e92:	c7 44 24 10 03 00 00 	movl   $0x3,0x10(%esp)
 1002e99:	00 
 1002e9a:	8b 45 10             	mov    0x10(%ebp),%eax
 1002e9d:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1002ea1:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002ea4:	89 44 24 08          	mov    %eax,0x8(%esp)
 1002ea8:	8b 45 08             	mov    0x8(%ebp),%eax
 1002eab:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002eaf:	89 1c 24             	mov    %ebx,(%esp)
 1002eb2:	e8 05 e4 ff ff       	call   10012bc <_ZN6CBrickC1EP5CGameiii>
 1002eb7:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1002ebb:	8b 45 08             	mov    0x8(%ebp),%eax
 1002ebe:	89 04 24             	mov    %eax,(%esp)
 1002ec1:	e8 16 fc ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1002ec6:	e9 f6 01 00 00       	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 1002ecb:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 1002ed2:	e8 6c d2 ff ff       	call   1000143 <_Znwj>
 1002ed7:	89 c3                	mov    %eax,%ebx
 1002ed9:	c7 44 24 10 02 00 00 	movl   $0x2,0x10(%esp)
 1002ee0:	00 
 1002ee1:	8b 45 10             	mov    0x10(%ebp),%eax
 1002ee4:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1002ee8:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002eeb:	89 44 24 08          	mov    %eax,0x8(%esp)
 1002eef:	8b 45 08             	mov    0x8(%ebp),%eax
 1002ef2:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002ef6:	89 1c 24             	mov    %ebx,(%esp)
 1002ef9:	e8 be e3 ff ff       	call   10012bc <_ZN6CBrickC1EP5CGameiii>
 1002efe:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1002f02:	8b 45 08             	mov    0x8(%ebp),%eax
 1002f05:	89 04 24             	mov    %eax,(%esp)
 1002f08:	e8 cf fb ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1002f0d:	e9 af 01 00 00       	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 1002f12:	c7 04 24 34 00 00 00 	movl   $0x34,(%esp)
 1002f19:	e8 25 d2 ff ff       	call   1000143 <_Znwj>
 1002f1e:	89 c3                	mov    %eax,%ebx
 1002f20:	8b 45 10             	mov    0x10(%ebp),%eax
 1002f23:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1002f27:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002f2a:	89 44 24 08          	mov    %eax,0x8(%esp)
 1002f2e:	8b 45 08             	mov    0x8(%ebp),%eax
 1002f31:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002f35:	89 1c 24             	mov    %ebx,(%esp)
 1002f38:	e8 23 f8 ff ff       	call   1002760 <_ZN12CFungusDemonC1EP5CGameii>
 1002f3d:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1002f41:	8b 45 08             	mov    0x8(%ebp),%eax
 1002f44:	89 04 24             	mov    %eax,(%esp)
 1002f47:	e8 90 fb ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1002f4c:	e9 70 01 00 00       	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 1002f51:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 1002f58:	e8 e6 d1 ff ff       	call   1000143 <_Znwj>
 1002f5d:	89 c3                	mov    %eax,%ebx
 1002f5f:	8b 45 10             	mov    0x10(%ebp),%eax
 1002f62:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1002f66:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002f69:	89 44 24 08          	mov    %eax,0x8(%esp)
 1002f6d:	8b 45 08             	mov    0x8(%ebp),%eax
 1002f70:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002f74:	89 1c 24             	mov    %ebx,(%esp)
 1002f77:	e8 28 39 00 00       	call   10068a4 <_ZN14CTortoiseDemonC1EP5CGameii>
 1002f7c:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1002f80:	8b 45 08             	mov    0x8(%ebp),%eax
 1002f83:	89 04 24             	mov    %eax,(%esp)
 1002f86:	e8 51 fb ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1002f8b:	e9 31 01 00 00       	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 1002f90:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 1002f97:	e8 a7 d1 ff ff       	call   1000143 <_Znwj>
 1002f9c:	89 c3                	mov    %eax,%ebx
 1002f9e:	8b 45 10             	mov    0x10(%ebp),%eax
 1002fa1:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1002fa5:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002fa8:	89 44 24 08          	mov    %eax,0x8(%esp)
 1002fac:	8b 45 08             	mov    0x8(%ebp),%eax
 1002faf:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002fb3:	89 1c 24             	mov    %ebx,(%esp)
 1002fb6:	e8 a5 f2 ff ff       	call   1002260 <_ZN17CFlyTortoiseDemonC1EP5CGameii>
 1002fbb:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1002fbf:	8b 45 08             	mov    0x8(%ebp),%eax
 1002fc2:	89 04 24             	mov    %eax,(%esp)
 1002fc5:	e8 12 fb ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1002fca:	e9 f2 00 00 00       	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 1002fcf:	c7 04 24 3c 00 00 00 	movl   $0x3c,(%esp)
 1002fd6:	e8 68 d1 ff ff       	call   1000143 <_Znwj>
 1002fdb:	89 c3                	mov    %eax,%ebx
 1002fdd:	8b 45 10             	mov    0x10(%ebp),%eax
 1002fe0:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1002fe4:	8b 45 0c             	mov    0xc(%ebp),%eax
 1002fe7:	89 44 24 08          	mov    %eax,0x8(%esp)
 1002feb:	8b 45 08             	mov    0x8(%ebp),%eax
 1002fee:	89 44 24 04          	mov    %eax,0x4(%esp)
 1002ff2:	89 1c 24             	mov    %ebx,(%esp)
 1002ff5:	e8 c2 ea ff ff       	call   1001abc <_ZN10CClipDemonC1EP5CGameii>
 1002ffa:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1002ffe:	8b 45 08             	mov    0x8(%ebp),%eax
 1003001:	89 04 24             	mov    %eax,(%esp)
 1003004:	e8 d3 fa ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1003009:	e9 b3 00 00 00       	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 100300e:	c7 04 24 2c 00 00 00 	movl   $0x2c,(%esp)
 1003015:	e8 29 d1 ff ff       	call   1000143 <_Znwj>
 100301a:	89 c3                	mov    %eax,%ebx
 100301c:	8b 45 10             	mov    0x10(%ebp),%eax
 100301f:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1003023:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003026:	89 44 24 08          	mov    %eax,0x8(%esp)
 100302a:	8b 45 08             	mov    0x8(%ebp),%eax
 100302d:	89 44 24 04          	mov    %eax,0x4(%esp)
 1003031:	89 1c 24             	mov    %ebx,(%esp)
 1003034:	e8 43 1b 00 00       	call   1004b7c <_ZN7CGroundC1EP5CGameii>
 1003039:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 100303d:	8b 45 08             	mov    0x8(%ebp),%eax
 1003040:	89 04 24             	mov    %eax,(%esp)
 1003043:	e8 94 fa ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1003048:	eb 77                	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 100304a:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 1003051:	e8 ed d0 ff ff       	call   1000143 <_Znwj>
 1003056:	89 c3                	mov    %eax,%ebx
 1003058:	8b 45 10             	mov    0x10(%ebp),%eax
 100305b:	89 44 24 0c          	mov    %eax,0xc(%esp)
 100305f:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003062:	89 44 24 08          	mov    %eax,0x8(%esp)
 1003066:	8b 45 08             	mov    0x8(%ebp),%eax
 1003069:	89 44 24 04          	mov    %eax,0x4(%esp)
 100306d:	89 1c 24             	mov    %ebx,(%esp)
 1003070:	e8 63 ec ff ff       	call   1001cd8 <_ZN5CCoinC1EP5CGameii>
 1003075:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1003079:	8b 45 08             	mov    0x8(%ebp),%eax
 100307c:	89 04 24             	mov    %eax,(%esp)
 100307f:	e8 58 fa ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 1003084:	eb 3b                	jmp    10030c1 <_ZN5CGame12InsertObjectEiii+0x47d>
 1003086:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 100308d:	e8 b1 d0 ff ff       	call   1000143 <_Znwj>
 1003092:	89 c3                	mov    %eax,%ebx
 1003094:	8b 45 10             	mov    0x10(%ebp),%eax
 1003097:	89 44 24 0c          	mov    %eax,0xc(%esp)
 100309b:	8b 45 0c             	mov    0xc(%ebp),%eax
 100309e:	89 44 24 08          	mov    %eax,0x8(%esp)
 10030a2:	8b 45 08             	mov    0x8(%ebp),%eax
 10030a5:	89 44 24 04          	mov    %eax,0x4(%esp)
 10030a9:	89 1c 24             	mov    %ebx,(%esp)
 10030ac:	e8 07 dd ff ff       	call   1000db8 <_ZN12CBeetleDemonC1EP5CGameii>
 10030b1:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 10030b5:	8b 45 08             	mov    0x8(%ebp),%eax
 10030b8:	89 04 24             	mov    %eax,(%esp)
 10030bb:	e8 1c fa ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 10030c0:	90                   	nop
 10030c1:	83 c4 24             	add    $0x24,%esp
 10030c4:	5b                   	pop    %ebx
 10030c5:	5d                   	pop    %ebp
 10030c6:	c3                   	ret    
 10030c7:	90                   	nop

010030c8 <_ZN5CGame5ClockEv>:
 10030c8:	55                   	push   %ebp
 10030c9:	89 e5                	mov    %esp,%ebp
 10030cb:	53                   	push   %ebx
 10030cc:	83 ec 24             	sub    $0x24,%esp
 10030cf:	a1 00 5d 02 01       	mov    0x1025d00,%eax
 10030d4:	83 c0 01             	add    $0x1,%eax
 10030d7:	a3 00 5d 02 01       	mov    %eax,0x1025d00
 10030dc:	a1 60 53 02 01       	mov    0x1025360,%eax
 10030e1:	85 c0                	test   %eax,%eax
 10030e3:	74 07                	je     10030ec <_ZN5CGame5ClockEv+0x24>
 10030e5:	83 f8 01             	cmp    $0x1,%eax
 10030e8:	74 2c                	je     1003116 <_ZN5CGame5ClockEv+0x4e>
 10030ea:	eb 52                	jmp    100313e <_ZN5CGame5ClockEv+0x76>
 10030ec:	a1 00 5d 02 01       	mov    0x1025d00,%eax
 10030f1:	83 f8 09             	cmp    $0x9,%eax
 10030f4:	7e 72                	jle    1003168 <_ZN5CGame5ClockEv+0xa0>
 10030f6:	c7 05 60 53 02 01 01 	movl   $0x1,0x1025360
 10030fd:	00 00 00 
 1003100:	c7 05 04 5d 02 01 01 	movl   $0x1,0x1025d04
 1003107:	00 00 00 
 100310a:	c7 05 00 5d 02 01 00 	movl   $0x0,0x1025d00
 1003111:	00 00 00 
 1003114:	eb 52                	jmp    1003168 <_ZN5CGame5ClockEv+0xa0>
 1003116:	a1 00 5d 02 01       	mov    0x1025d00,%eax
 100311b:	83 f8 01             	cmp    $0x1,%eax
 100311e:	7e 4b                	jle    100316b <_ZN5CGame5ClockEv+0xa3>
 1003120:	8b 15 60 53 02 01    	mov    0x1025360,%edx
 1003126:	a1 04 5d 02 01       	mov    0x1025d04,%eax
 100312b:	01 d0                	add    %edx,%eax
 100312d:	a3 60 53 02 01       	mov    %eax,0x1025360
 1003132:	c7 05 00 5d 02 01 00 	movl   $0x0,0x1025d00
 1003139:	00 00 00 
 100313c:	eb 2d                	jmp    100316b <_ZN5CGame5ClockEv+0xa3>
 100313e:	a1 00 5d 02 01       	mov    0x1025d00,%eax
 1003143:	83 f8 02             	cmp    $0x2,%eax
 1003146:	7e 24                	jle    100316c <_ZN5CGame5ClockEv+0xa4>
 1003148:	c7 05 60 53 02 01 01 	movl   $0x1,0x1025360
 100314f:	00 00 00 
 1003152:	c7 05 04 5d 02 01 ff 	movl   $0xffffffff,0x1025d04
 1003159:	ff ff ff 
 100315c:	c7 05 00 5d 02 01 00 	movl   $0x0,0x1025d00
 1003163:	00 00 00 
 1003166:	eb 04                	jmp    100316c <_ZN5CGame5ClockEv+0xa4>
 1003168:	90                   	nop
 1003169:	eb 01                	jmp    100316c <_ZN5CGame5ClockEv+0xa4>
 100316b:	90                   	nop
 100316c:	8b 45 08             	mov    0x8(%ebp),%eax
 100316f:	83 c0 18             	add    $0x18,%eax
 1003172:	89 45 f4             	mov    %eax,-0xc(%ebp)
 1003175:	e9 d7 00 00 00       	jmp    1003251 <_ZN5CGame5ClockEv+0x189>
 100317a:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100317d:	8b 00                	mov    (%eax),%eax
 100317f:	8b 40 08             	mov    0x8(%eax),%eax
 1003182:	83 f8 03             	cmp    $0x3,%eax
 1003185:	74 35                	je     10031bc <_ZN5CGame5ClockEv+0xf4>
 1003187:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100318a:	8b 00                	mov    (%eax),%eax
 100318c:	8b 40 0c             	mov    0xc(%eax),%eax
 100318f:	3d 40 01 00 00       	cmp    $0x140,%eax
 1003194:	7f 26                	jg     10031bc <_ZN5CGame5ClockEv+0xf4>
 1003196:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1003199:	8b 00                	mov    (%eax),%eax
 100319b:	8b 50 0c             	mov    0xc(%eax),%edx
 100319e:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10031a1:	8b 00                	mov    (%eax),%eax
 10031a3:	8b 40 14             	mov    0x14(%eax),%eax
 10031a6:	01 d0                	add    %edx,%eax
 10031a8:	83 f8 e0             	cmp    $0xffffffe0,%eax
 10031ab:	7c 0f                	jl     10031bc <_ZN5CGame5ClockEv+0xf4>
 10031ad:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10031b0:	8b 00                	mov    (%eax),%eax
 10031b2:	8b 40 10             	mov    0x10(%eax),%eax
 10031b5:	3d 00 01 00 00       	cmp    $0x100,%eax
 10031ba:	7e 7b                	jle    1003237 <_ZN5CGame5ClockEv+0x16f>
 10031bc:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10031bf:	8b 10                	mov    (%eax),%edx
 10031c1:	8b 45 08             	mov    0x8(%ebp),%eax
 10031c4:	8b 00                	mov    (%eax),%eax
 10031c6:	39 c2                	cmp    %eax,%edx
 10031c8:	75 42                	jne    100320c <_ZN5CGame5ClockEv+0x144>
 10031ca:	8b 45 08             	mov    0x8(%ebp),%eax
 10031cd:	8b 00                	mov    (%eax),%eax
 10031cf:	8b 40 08             	mov    0x8(%eax),%eax
 10031d2:	83 f8 01             	cmp    $0x1,%eax
 10031d5:	75 2c                	jne    1003203 <_ZN5CGame5ClockEv+0x13b>
 10031d7:	8b 45 08             	mov    0x8(%ebp),%eax
 10031da:	8b 40 14             	mov    0x14(%eax),%eax
 10031dd:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 10031e4:	00 
 10031e5:	89 04 24             	mov    %eax,(%esp)
 10031e8:	e8 9b 31 00 00       	call   1006388 <_ZN9CSoundMan13PlayBackMusicEi>
 10031ed:	8b 45 08             	mov    0x8(%ebp),%eax
 10031f0:	8b 40 14             	mov    0x14(%eax),%eax
 10031f3:	c7 44 24 04 05 00 00 	movl   $0x5,0x4(%esp)
 10031fa:	00 
 10031fb:	89 04 24             	mov    %eax,(%esp)
 10031fe:	e8 fd 31 00 00       	call   1006400 <_ZN9CSoundMan9PlaySoundENS_8SOUNDNUME>
 1003203:	8b 45 08             	mov    0x8(%ebp),%eax
 1003206:	c7 00 00 00 00 00    	movl   $0x0,(%eax)
 100320c:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100320f:	89 45 f0             	mov    %eax,-0x10(%ebp)
 1003212:	83 45 f4 04          	addl   $0x4,-0xc(%ebp)
 1003216:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1003219:	8b 00                	mov    (%eax),%eax
 100321b:	89 04 24             	mov    %eax,(%esp)
 100321e:	e8 39 cf ff ff       	call   100015c <_ZdlPv>
 1003223:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1003226:	89 44 24 04          	mov    %eax,0x4(%esp)
 100322a:	8b 45 08             	mov    0x8(%ebp),%eax
 100322d:	89 04 24             	mov    %eax,(%esp)
 1003230:	e8 d1 f8 ff ff       	call   1002b06 <_ZN5CGame14m_Object_eraseEPP7CObject>
 1003235:	eb 1a                	jmp    1003251 <_ZN5CGame5ClockEv+0x189>
 1003237:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100323a:	8b 00                	mov    (%eax),%eax
 100323c:	8b 00                	mov    (%eax),%eax
 100323e:	83 c0 04             	add    $0x4,%eax
 1003241:	8b 10                	mov    (%eax),%edx
 1003243:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1003246:	8b 00                	mov    (%eax),%eax
 1003248:	89 04 24             	mov    %eax,(%esp)
 100324b:	ff d2                	call   *%edx
 100324d:	83 45 f4 04          	addl   $0x4,-0xc(%ebp)
 1003251:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1003254:	8b 00                	mov    (%eax),%eax
 1003256:	85 c0                	test   %eax,%eax
 1003258:	0f 95 c0             	setne  %al
 100325b:	84 c0                	test   %al,%al
 100325d:	0f 85 17 ff ff ff    	jne    100317a <_ZN5CGame5ClockEv+0xb2>
 1003263:	8b 45 08             	mov    0x8(%ebp),%eax
 1003266:	8b 00                	mov    (%eax),%eax
 1003268:	85 c0                	test   %eax,%eax
 100326a:	0f 84 38 01 00 00    	je     10033a8 <_ZN5CGame5ClockEv+0x2e0>
 1003270:	8b 45 08             	mov    0x8(%ebp),%eax
 1003273:	8b 00                	mov    (%eax),%eax
 1003275:	8b 50 0c             	mov    0xc(%eax),%edx
 1003278:	8b 45 08             	mov    0x8(%ebp),%eax
 100327b:	8b 00                	mov    (%eax),%eax
 100327d:	8b 40 14             	mov    0x14(%eax),%eax
 1003280:	b9 20 01 00 00       	mov    $0x120,%ecx
 1003285:	89 cb                	mov    %ecx,%ebx
 1003287:	29 c3                	sub    %eax,%ebx
 1003289:	89 d8                	mov    %ebx,%eax
 100328b:	d1 f8                	sar    %eax
 100328d:	89 d1                	mov    %edx,%ecx
 100328f:	29 c1                	sub    %eax,%ecx
 1003291:	89 c8                	mov    %ecx,%eax
 1003293:	89 45 ec             	mov    %eax,-0x14(%ebp)
 1003296:	83 7d ec 00          	cmpl   $0x0,-0x14(%ebp)
 100329a:	7e 12                	jle    10032ae <_ZN5CGame5ClockEv+0x1e6>
 100329c:	8b 45 ec             	mov    -0x14(%ebp),%eax
 100329f:	89 44 24 04          	mov    %eax,0x4(%esp)
 10032a3:	8b 45 08             	mov    0x8(%ebp),%eax
 10032a6:	89 04 24             	mov    %eax,(%esp)
 10032a9:	e8 bc 0d 00 00       	call   100406a <_ZN5CGame7MoveMapEi>
 10032ae:	8b 45 08             	mov    0x8(%ebp),%eax
 10032b1:	8b 00                	mov    (%eax),%eax
 10032b3:	8b 50 0c             	mov    0xc(%eax),%edx
 10032b6:	8b 45 08             	mov    0x8(%ebp),%eax
 10032b9:	8b 00                	mov    (%eax),%eax
 10032bb:	8b 40 14             	mov    0x14(%eax),%eax
 10032be:	b9 20 01 00 00       	mov    $0x120,%ecx
 10032c3:	89 cb                	mov    %ecx,%ebx
 10032c5:	29 c3                	sub    %eax,%ebx
 10032c7:	89 d8                	mov    %ebx,%eax
 10032c9:	39 c2                	cmp    %eax,%edx
 10032cb:	0f 85 d8 00 00 00    	jne    10033a9 <_ZN5CGame5ClockEv+0x2e1>
 10032d1:	8b 45 08             	mov    0x8(%ebp),%eax
 10032d4:	83 c0 18             	add    $0x18,%eax
 10032d7:	89 45 f4             	mov    %eax,-0xc(%ebp)
 10032da:	eb 3a                	jmp    1003316 <_ZN5CGame5ClockEv+0x24e>
 10032dc:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10032df:	89 45 f0             	mov    %eax,-0x10(%ebp)
 10032e2:	83 45 f4 04          	addl   $0x4,-0xc(%ebp)
 10032e6:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10032e9:	8b 10                	mov    (%eax),%edx
 10032eb:	8b 45 08             	mov    0x8(%ebp),%eax
 10032ee:	8b 00                	mov    (%eax),%eax
 10032f0:	39 c2                	cmp    %eax,%edx
 10032f2:	74 21                	je     1003315 <_ZN5CGame5ClockEv+0x24d>
 10032f4:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10032f7:	8b 00                	mov    (%eax),%eax
 10032f9:	89 04 24             	mov    %eax,(%esp)
 10032fc:	e8 5b ce ff ff       	call   100015c <_ZdlPv>
 1003301:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1003304:	89 44 24 04          	mov    %eax,0x4(%esp)
 1003308:	8b 45 08             	mov    0x8(%ebp),%eax
 100330b:	89 04 24             	mov    %eax,(%esp)
 100330e:	e8 f3 f7 ff ff       	call   1002b06 <_ZN5CGame14m_Object_eraseEPP7CObject>
 1003313:	eb 01                	jmp    1003316 <_ZN5CGame5ClockEv+0x24e>
 1003315:	90                   	nop
 1003316:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1003319:	8b 00                	mov    (%eax),%eax
 100331b:	85 c0                	test   %eax,%eax
 100331d:	0f 95 c0             	setne  %al
 1003320:	84 c0                	test   %al,%al
 1003322:	75 b8                	jne    10032dc <_ZN5CGame5ClockEv+0x214>
 1003324:	8b 45 08             	mov    0x8(%ebp),%eax
 1003327:	8b 40 04             	mov    0x4(%eax),%eax
 100332a:	8d 50 01             	lea    0x1(%eax),%edx
 100332d:	8b 45 08             	mov    0x8(%ebp),%eax
 1003330:	89 50 04             	mov    %edx,0x4(%eax)
 1003333:	8b 15 20 9f 01 01    	mov    0x1019f20,%edx
 1003339:	8b 45 08             	mov    0x8(%ebp),%eax
 100333c:	8b 40 04             	mov    0x4(%eax),%eax
 100333f:	39 c2                	cmp    %eax,%edx
 1003341:	75 39                	jne    100337c <_ZN5CGame5ClockEv+0x2b4>
 1003343:	8b 45 08             	mov    0x8(%ebp),%eax
 1003346:	8b 40 14             	mov    0x14(%eax),%eax
 1003349:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 1003350:	00 
 1003351:	89 04 24             	mov    %eax,(%esp)
 1003354:	e8 2f 30 00 00       	call   1006388 <_ZN9CSoundMan13PlayBackMusicEi>
 1003359:	8b 45 08             	mov    0x8(%ebp),%eax
 100335c:	89 04 24             	mov    %eax,(%esp)
 100335f:	e8 e4 f7 ff ff       	call   1002b48 <_ZN5CGame14m_Object_clearEv>
 1003364:	8b 45 08             	mov    0x8(%ebp),%eax
 1003367:	8b 00                	mov    (%eax),%eax
 1003369:	89 04 24             	mov    %eax,(%esp)
 100336c:	e8 eb cd ff ff       	call   100015c <_ZdlPv>
 1003371:	8b 45 08             	mov    0x8(%ebp),%eax
 1003374:	c7 00 00 00 00 00    	movl   $0x0,(%eax)
 100337a:	eb 2d                	jmp    10033a9 <_ZN5CGame5ClockEv+0x2e1>
 100337c:	8b 45 08             	mov    0x8(%ebp),%eax
 100337f:	8b 50 08             	mov    0x8(%eax),%edx
 1003382:	8b 45 08             	mov    0x8(%ebp),%eax
 1003385:	8b 40 08             	mov    0x8(%eax),%eax
 1003388:	83 c0 08             	add    $0x8,%eax
 100338b:	8b 00                	mov    (%eax),%eax
 100338d:	c1 e0 06             	shl    $0x6,%eax
 1003390:	83 c0 0c             	add    $0xc,%eax
 1003393:	01 c2                	add    %eax,%edx
 1003395:	8b 45 08             	mov    0x8(%ebp),%eax
 1003398:	89 50 08             	mov    %edx,0x8(%eax)
 100339b:	8b 45 08             	mov    0x8(%ebp),%eax
 100339e:	89 04 24             	mov    %eax,(%esp)
 10033a1:	e8 dc 0b 00 00       	call   1003f82 <_ZN5CGame11LoadMapDataEv>
 10033a6:	eb 01                	jmp    10033a9 <_ZN5CGame5ClockEv+0x2e1>
 10033a8:	90                   	nop
 10033a9:	83 c4 24             	add    $0x24,%esp
 10033ac:	5b                   	pop    %ebx
 10033ad:	5d                   	pop    %ebp
 10033ae:	c3                   	ret    
 10033af:	90                   	nop

010033b0 <_ZN5CGame4MoveEib>:
 10033b0:	55                   	push   %ebp
 10033b1:	89 e5                	mov    %esp,%ebp
 10033b3:	83 ec 28             	sub    $0x28,%esp
 10033b6:	8b 45 10             	mov    0x10(%ebp),%eax
 10033b9:	88 45 f4             	mov    %al,-0xc(%ebp)
 10033bc:	8b 45 08             	mov    0x8(%ebp),%eax
 10033bf:	8b 00                	mov    (%eax),%eax
 10033c1:	85 c0                	test   %eax,%eax
 10033c3:	74 1e                	je     10033e3 <_ZN5CGame4MoveEib+0x33>
 10033c5:	0f b6 55 f4          	movzbl -0xc(%ebp),%edx
 10033c9:	8b 45 08             	mov    0x8(%ebp),%eax
 10033cc:	8b 00                	mov    (%eax),%eax
 10033ce:	89 54 24 08          	mov    %edx,0x8(%esp)
 10033d2:	8b 55 0c             	mov    0xc(%ebp),%edx
 10033d5:	89 54 24 04          	mov    %edx,0x4(%esp)
 10033d9:	89 04 24             	mov    %eax,(%esp)
 10033dc:	e8 43 23 00 00       	call   1005724 <_ZN6CMario4MoveEib>
 10033e1:	eb 01                	jmp    10033e4 <_ZN5CGame4MoveEib+0x34>
 10033e3:	90                   	nop
 10033e4:	c9                   	leave  
 10033e5:	c3                   	ret    

010033e6 <_ZN5CGame4JumpEv>:
 10033e6:	55                   	push   %ebp
 10033e7:	89 e5                	mov    %esp,%ebp
 10033e9:	83 ec 18             	sub    $0x18,%esp
 10033ec:	8b 45 08             	mov    0x8(%ebp),%eax
 10033ef:	8b 00                	mov    (%eax),%eax
 10033f1:	85 c0                	test   %eax,%eax
 10033f3:	74 0f                	je     1003404 <_ZN5CGame4JumpEv+0x1e>
 10033f5:	8b 45 08             	mov    0x8(%ebp),%eax
 10033f8:	8b 00                	mov    (%eax),%eax
 10033fa:	89 04 24             	mov    %eax,(%esp)
 10033fd:	e8 bc 22 00 00       	call   10056be <_ZN6CMario4JumpEv>
 1003402:	eb 01                	jmp    1003405 <_ZN5CGame4JumpEv+0x1f>
 1003404:	90                   	nop
 1003405:	c9                   	leave  
 1003406:	c3                   	ret    
 1003407:	90                   	nop

01003408 <_ZN5CGame4FireEv>:
 1003408:	55                   	push   %ebp
 1003409:	89 e5                	mov    %esp,%ebp
 100340b:	83 ec 18             	sub    $0x18,%esp
 100340e:	8b 45 08             	mov    0x8(%ebp),%eax
 1003411:	8b 00                	mov    (%eax),%eax
 1003413:	85 c0                	test   %eax,%eax
 1003415:	74 0f                	je     1003426 <_ZN5CGame4FireEv+0x1e>
 1003417:	8b 45 08             	mov    0x8(%ebp),%eax
 100341a:	8b 00                	mov    (%eax),%eax
 100341c:	89 04 24             	mov    %eax,(%esp)
 100341f:	e8 56 23 00 00       	call   100577a <_ZN6CMario4FireEv>
 1003424:	eb 01                	jmp    1003427 <_ZN5CGame4FireEv+0x1f>
 1003426:	90                   	nop
 1003427:	c9                   	leave  
 1003428:	c3                   	ret    
 1003429:	90                   	nop

0100342a <_ZN5CGame4MoveEP7CObjectii>:3524
 100342a:	55                   	push   %ebp
 100342b:	89 e5                	mov    %esp,%ebp
 100342d:	53                   	push   %ebx
 100342e:	81 ec c4 00 00 00    	sub    $0xc4,%esp
 1003434:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp) retval = 0
 100343b:	8b 45 0c             	mov    0xc(%ebp),%eax
 100343e:	8b 40 0c             	mov    0xc(%eax),%eax
 1003441:	03 45 10             	add    0x10(%ebp),%eax
 1003444:	89 45 dc             	mov    %eax,-0x24(%ebp)
 1003447:	8b 45 0c             	mov    0xc(%ebp),%eax
 100344a:	8b 40 10             	mov    0x10(%eax),%eax
 100344d:	03 45 14             	add    0x14(%ebp),%eax
 1003450:	89 45 d8             	mov    %eax,-0x28(%ebp)	OrDestXY
 1003453:	83 7d 14 00          	cmpl   $0x0,0x14(%ebp)  Vert>0
 1003457:	7e 06                	jle    100345f <_ZN5CGame4MoveEP7CObjectii+0x35>
 1003459:	c6 45 9f 00          	movb   $0x0,-0x61(%ebp)
 100345d:	eb 04                	jmp    1003463 <_ZN5CGame4MoveEP7CObjectii+0x39>
 100345f:	c6 45 9f 01          	movb   $0x1,-0x61(%ebp)
 1003463:	83 7d 10 00          	cmpl   $0x0,0x10(%ebp)	Horz>0
 1003467:	7e 06                	jle    100346f <_ZN5CGame4MoveEP7CObjectii+0x45>
 1003469:	c6 45 9e 00          	movb   $0x0,-0x62(%ebp)
 100346d:	eb 04                	jmp    1003473 <_ZN5CGame4MoveEP7CObjectii+0x49>
 100346f:	c6 45 9e 01          	movb   $0x1,-0x62(%ebp)
 1003473:	8d 45 9e             	lea    -0x62(%ebp),%eax
 1003476:	89 44 24 04          	mov    %eax,0x4(%esp)
 100347a:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 1003481:	e8 e6 0e 00 00       	call   100436c <_ZN16bipriority_queue4initEP16BLOCKINFOCompare>
 1003486:	83 7d 14 00          	cmpl   $0x0,0x14(%ebp)	Vert<0
 100348a:	0f 89 64 01 00 00    	jns    10035f4 <_ZN5CGame4MoveEP7CObjectii+0x1ca>
 1003490:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003493:	8b 40 10             	mov    0x10(%eax),%eax
 1003496:	89 45 d4             	mov    %eax,-0x2c(%ebp)	strt=
 1003499:	8b 45 14             	mov    0x14(%ebp),%eax
 100349c:	8b 55 d4             	mov    -0x2c(%ebp),%edx
 100349f:	01 d0                	add    %edx,%eax
 10034a1:	89 45 d0             	mov    %eax,-0x30(%ebp)	end=
 10034a4:	8b 45 08             	mov    0x8(%ebp),%eax
 10034a7:	83 c0 18             	add    $0x18,%eax
 10034aa:	89 45 f0             	mov    %eax,-0x10(%ebp)	it=m_Object
 10034ad:	e9 2b 01 00 00       	jmp    10035dd <_ZN5CGame4MoveEP7CObjectii+0x1b3>
 10034b2:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10034b5:	8b 00                	mov    (%eax),%eax
 10034b7:	3b 45 0c             	cmp    0xc(%ebp),%eax
 10034ba:	0f 84 18 01 00 00    	je     10035d8 <_ZN5CGame4MoveEP7CObjectii+0x1ae> continue
 10034c0:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10034c3:	8b 00                	mov    (%eax),%eax
 10034c5:	8b 50 10             	mov    0x10(%eax),%edx
 10034c8:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10034cb:	8b 00                	mov    (%eax),%eax
 10034cd:	8b 40 18             	mov    0x18(%eax),%eax
 10034d0:	01 d0                	add    %edx,%eax
 10034d2:	89 45 cc             	mov    %eax,-0x34(%ebp)	ypos=
 10034d5:	8b 45 cc             	mov    -0x34(%ebp),%eax
 10034d8:	3b 45 d0             	cmp    -0x30(%ebp),%eax
 10034db:	0f 8e f8 00 00 00    	jle    10035d9 <_ZN5CGame4MoveEP7CObjectii+0x1af> if ypos>end
 10034e1:	8b 45 cc             	mov    -0x34(%ebp),%eax
 10034e4:	3b 45 d4             	cmp    -0x2c(%ebp),%eax
 10034e7:	0f 8f ec 00 00 00    	jg     10035d9 <_ZN5CGame4MoveEP7CObjectii+0x1af> if ypos<=start
 10034ed:	8b 45 0c             	mov    0xc(%ebp),%eax
 10034f0:	8b 48 0c             	mov    0xc(%eax),%ecx
 10034f3:	8b 45 d4             	mov    -0x2c(%ebp),%eax
 10034f6:	8b 55 cc             	mov    -0x34(%ebp),%edx
 10034f9:	89 d3                	mov    %edx,%ebx
 10034fb:	29 c3                	sub    %eax,%ebx
 10034fd:	89 d8                	mov    %ebx,%eax
 10034ff:	0f af 45 10          	imul   0x10(%ebp),%eax
 1003503:	89 c2                	mov    %eax,%edx	|
 1003505:	c1 fa 1f             	sar    $0x1f,%edx	|->¶ÔeaxÏòedx·ûºÅÀ©Õ¹!!
 1003508:	f7 7d 14             	idivl  0x14(%ebp)
 100350b:	01 c8                	add    %ecx,%eax
 100350d:	89 45 c8             	mov    %eax,-0x38(%ebp)	x1=
 1003510:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003513:	8b 40 14             	mov    0x14(%eax),%eax
 1003516:	03 45 c8             	add    -0x38(%ebp),%eax
 1003519:	89 45 c4             	mov    %eax,-0x3c(%ebp)	x2=
 100351c:	8b 45 f0             	mov    -0x10(%ebp),%eax
 100351f:	8b 00                	mov    (%eax),%eax	eax=*it
 1003521:	8b 40 0c             	mov    0xc(%eax),%eax	eax=(*it)->XPos
 1003524:	3b 45 c4             	cmp    -0x3c(%ebp),%eax
 1003527:	7d 52                	jge    100357b <_ZN5CGame4MoveEP7CObjectii+0x151>
 1003529:	8b 45 f0             	mov    -0x10(%ebp),%eax
 100352c:	8b 00                	mov    (%eax),%eax
 100352e:	8b 50 0c             	mov    0xc(%eax),%edx
 1003531:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1003534:	8b 00                	mov    (%eax),%eax
 1003536:	8b 40 14             	mov    0x14(%eax),%eax
 1003539:	01 d0                	add    %edx,%eax
 100353b:	3b 45 c8             	cmp    -0x38(%ebp),%eax
 100353e:	7e 3b                	jle    100357b <_ZN5CGame4MoveEP7CObjectii+0x151> second if
 1003540:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1003543:	8b 00                	mov    (%eax),%eax
 1003545:	89 45 84             	mov    %eax,-0x7c(%ebp)
 1003548:	c7 45 90 02 00 00 00 	movl   $0x2,-0x70(%ebp)
 100354f:	c7 45 94 02 00 00 00 	movl   $0x2,-0x6c(%ebp)
 1003556:	c6 45 98 00          	movb   $0x0,-0x68(%ebp)
 100355a:	8b 45 c8             	mov    -0x38(%ebp),%eax
 100355d:	89 45 88             	mov    %eax,-0x78(%ebp)
 1003560:	8b 45 cc             	mov    -0x34(%ebp),%eax
 1003563:	89 45 8c             	mov    %eax,-0x74(%ebp)
 1003566:	8d 45 84             	lea    -0x7c(%ebp),%eax
 1003569:	89 44 24 04          	mov    %eax,0x4(%esp)
 100356d:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 1003574:	e8 07 10 00 00       	call   1004580 <_ZN16bipriority_queue4pushER9BLOCKINFO>
 1003579:	eb 5e                	jmp    10035d9 <_ZN5CGame4MoveEP7CObjectii+0x1af>
 100357b:	83 7d 10 00          	cmpl   $0x0,0x10(%ebp)
 100357f:	7e 0d                	jle    100358e <_ZN5CGame4MoveEP7CObjectii+0x164>
 1003581:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1003584:	8b 00                	mov    (%eax),%eax
 1003586:	8b 40 0c             	mov    0xc(%eax),%eax
 1003589:	3b 45 c4             	cmp    -0x3c(%ebp),%eax
 100358c:	74 1d                	je     10035ab <_ZN5CGame4MoveEP7CObjectii+0x181>
 100358e:	83 7d 10 00          	cmpl   $0x0,0x10(%ebp)
 1003592:	79 45                	jns    10035d9 <_ZN5CGame4MoveEP7CObjectii+0x1af>
 1003594:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1003597:	8b 00                	mov    (%eax),%eax
 1003599:	8b 50 0c             	mov    0xc(%eax),%edx
 100359c:	8b 45 f0             	mov    -0x10(%ebp),%eax
 100359f:	8b 00                	mov    (%eax),%eax
 10035a1:	8b 40 14             	mov    0x14(%eax),%eax
 10035a4:	01 d0                	add    %edx,%eax
 10035a6:	3b 45 c8             	cmp    -0x38(%ebp),%eax
 10035a9:	75 2e                	jne    10035d9 <_ZN5CGame4MoveEP7CObjectii+0x1af>
 10035ab:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10035ae:	8b 00                	mov    (%eax),%eax
 10035b0:	89 45 84             	mov    %eax,-0x7c(%ebp)
 10035b3:	c6 45 98 01          	movb   $0x1,-0x68(%ebp)
 10035b7:	8b 45 c8             	mov    -0x38(%ebp),%eax
 10035ba:	89 45 88             	mov    %eax,-0x78(%ebp)
 10035bd:	8b 45 cc             	mov    -0x34(%ebp),%eax
 10035c0:	89 45 8c             	mov    %eax,-0x74(%ebp)
 10035c3:	8d 45 84             	lea    -0x7c(%ebp),%eax
 10035c6:	89 44 24 04          	mov    %eax,0x4(%esp)
 10035ca:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 10035d1:	e8 aa 0f 00 00       	call   1004580 <_ZN16bipriority_queue4pushER9BLOCKINFO>
 10035d6:	eb 01                	jmp    10035d9 <_ZN5CGame4MoveEP7CObjectii+0x1af>
 10035d8:	90                   	nop
 10035d9:	83 45 f0 04          	addl   $0x4,-0x10(%ebp)	it++
 10035dd:	8b 45 f0             	mov    -0x10(%ebp),%eax	//cond: *it
 10035e0:	8b 00                	mov    (%eax),%eax
 10035e2:	85 c0                	test   %eax,%eax
 10035e4:	0f 95 c0             	setne  %al
 10035e7:	84 c0                	test   %al,%al
 10035e9:	0f 85 c3 fe ff ff    	jne    10034b2 <_ZN5CGame4MoveEP7CObjectii+0x88>
 10035ef:	e9 7f 01 00 00       	jmp    1003773 <_ZN5CGame4MoveEP7CObjectii+0x349>
 10035f4:	83 7d 14 00          	cmpl   $0x0,0x14(%ebp)
 10035f8:	0f 8e 75 01 00 00    	jle    1003773 <_ZN5CGame4MoveEP7CObjectii+0x349>
 10035fe:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003601:	8b 50 10             	mov    0x10(%eax),%edx
 1003604:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003607:	8b 40 18             	mov    0x18(%eax),%eax
 100360a:	01 d0                	add    %edx,%eax
 100360c:	89 45 d4             	mov    %eax,-0x2c(%ebp)
 100360f:	8b 45 14             	mov    0x14(%ebp),%eax
 1003612:	8b 55 d4             	mov    -0x2c(%ebp),%edx
 1003615:	01 d0                	add    %edx,%eax
 1003617:	89 45 d0             	mov    %eax,-0x30(%ebp)
 100361a:	8b 45 08             	mov    0x8(%ebp),%eax
 100361d:	83 c0 18             	add    $0x18,%eax
 1003620:	89 45 ec             	mov    %eax,-0x14(%ebp)
 1003623:	e9 39 01 00 00       	jmp    1003761 <_ZN5CGame4MoveEP7CObjectii+0x337>
 1003628:	8b 45 ec             	mov    -0x14(%ebp),%eax
 100362b:	8b 00                	mov    (%eax),%eax
 100362d:	3b 45 0c             	cmp    0xc(%ebp),%eax
 1003630:	0f 84 26 01 00 00    	je     100375c <_ZN5CGame4MoveEP7CObjectii+0x332>
 1003636:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1003639:	8b 00                	mov    (%eax),%eax
 100363b:	8b 40 10             	mov    0x10(%eax),%eax
 100363e:	89 45 c0             	mov    %eax,-0x40(%ebp)
 1003641:	8b 45 c0             	mov    -0x40(%ebp),%eax
 1003644:	3b 45 d4             	cmp    -0x2c(%ebp),%eax
 1003647:	0f 8c 10 01 00 00    	jl     100375d <_ZN5CGame4MoveEP7CObjectii+0x333>
 100364d:	8b 45 c0             	mov    -0x40(%ebp),%eax
 1003650:	3b 45 d0             	cmp    -0x30(%ebp),%eax
 1003653:	0f 8d 04 01 00 00    	jge    100375d <_ZN5CGame4MoveEP7CObjectii+0x333>
 1003659:	8b 45 0c             	mov    0xc(%ebp),%eax
 100365c:	8b 48 0c             	mov    0xc(%eax),%ecx
 100365f:	8b 45 d4             	mov    -0x2c(%ebp),%eax
 1003662:	8b 55 c0             	mov    -0x40(%ebp),%edx
 1003665:	89 d3                	mov    %edx,%ebx
 1003667:	29 c3                	sub    %eax,%ebx
 1003669:	89 d8                	mov    %ebx,%eax
 100366b:	0f af 45 10          	imul   0x10(%ebp),%eax
 100366f:	89 c2                	mov    %eax,%edx
 1003671:	c1 fa 1f             	sar    $0x1f,%edx
 1003674:	f7 7d 14             	idivl  0x14(%ebp)
 1003677:	01 c8                	add    %ecx,%eax
 1003679:	89 45 bc             	mov    %eax,-0x44(%ebp)
 100367c:	8b 45 0c             	mov    0xc(%ebp),%eax
 100367f:	8b 40 14             	mov    0x14(%eax),%eax
 1003682:	03 45 bc             	add    -0x44(%ebp),%eax
 1003685:	89 45 b8             	mov    %eax,-0x48(%ebp)
 1003688:	8b 45 ec             	mov    -0x14(%ebp),%eax
 100368b:	8b 00                	mov    (%eax),%eax
 100368d:	8b 40 0c             	mov    0xc(%eax),%eax
 1003690:	3b 45 b8             	cmp    -0x48(%ebp),%eax
 1003693:	7d 5e                	jge    10036f3 <_ZN5CGame4MoveEP7CObjectii+0x2c9>
 1003695:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1003698:	8b 00                	mov    (%eax),%eax
 100369a:	8b 50 0c             	mov    0xc(%eax),%edx
 100369d:	8b 45 ec             	mov    -0x14(%ebp),%eax
 10036a0:	8b 00                	mov    (%eax),%eax
 10036a2:	8b 40 14             	mov    0x14(%eax),%eax
 10036a5:	01 d0                	add    %edx,%eax
 10036a7:	3b 45 bc             	cmp    -0x44(%ebp),%eax
 10036aa:	7e 47                	jle    10036f3 <_ZN5CGame4MoveEP7CObjectii+0x2c9>
 10036ac:	8b 45 ec             	mov    -0x14(%ebp),%eax
 10036af:	8b 00                	mov    (%eax),%eax
 10036b1:	89 45 84             	mov    %eax,-0x7c(%ebp)
 10036b4:	c7 45 90 02 00 00 00 	movl   $0x2,-0x70(%ebp)
 10036bb:	c7 45 94 01 00 00 00 	movl   $0x1,-0x6c(%ebp)
 10036c2:	c6 45 98 00          	movb   $0x0,-0x68(%ebp)
 10036c6:	8b 45 bc             	mov    -0x44(%ebp),%eax
 10036c9:	89 45 88             	mov    %eax,-0x78(%ebp)
 10036cc:	8b 45 0c             	mov    0xc(%ebp),%eax
 10036cf:	8b 40 18             	mov    0x18(%eax),%eax
 10036d2:	8b 55 c0             	mov    -0x40(%ebp),%edx
 10036d5:	89 d1                	mov    %edx,%ecx
 10036d7:	29 c1                	sub    %eax,%ecx
 10036d9:	89 c8                	mov    %ecx,%eax
 10036db:	89 45 8c             	mov    %eax,-0x74(%ebp)
 10036de:	8d 45 84             	lea    -0x7c(%ebp),%eax
 10036e1:	89 44 24 04          	mov    %eax,0x4(%esp)
 10036e5:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 10036ec:	e8 8f 0e 00 00       	call   1004580 <_ZN16bipriority_queue4pushER9BLOCKINFO>
 10036f1:	eb 6a                	jmp    100375d <_ZN5CGame4MoveEP7CObjectii+0x333>
 10036f3:	83 7d 10 00          	cmpl   $0x0,0x10(%ebp)
 10036f7:	7e 0d                	jle    1003706 <_ZN5CGame4MoveEP7CObjectii+0x2dc>
 10036f9:	8b 45 ec             	mov    -0x14(%ebp),%eax
 10036fc:	8b 00                	mov    (%eax),%eax
 10036fe:	8b 40 0c             	mov    0xc(%eax),%eax
 1003701:	3b 45 b8             	cmp    -0x48(%ebp),%eax
 1003704:	74 1d                	je     1003723 <_ZN5CGame4MoveEP7CObjectii+0x2f9>
 1003706:	83 7d 10 00          	cmpl   $0x0,0x10(%ebp)
 100370a:	79 51                	jns    100375d <_ZN5CGame4MoveEP7CObjectii+0x333>
 100370c:	8b 45 ec             	mov    -0x14(%ebp),%eax
 100370f:	8b 00                	mov    (%eax),%eax
 1003711:	8b 50 0c             	mov    0xc(%eax),%edx
 1003714:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1003717:	8b 00                	mov    (%eax),%eax
 1003719:	8b 40 14             	mov    0x14(%eax),%eax
 100371c:	01 d0                	add    %edx,%eax
 100371e:	3b 45 bc             	cmp    -0x44(%ebp),%eax
 1003721:	75 3a                	jne    100375d <_ZN5CGame4MoveEP7CObjectii+0x333>
 1003723:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1003726:	8b 00                	mov    (%eax),%eax
 1003728:	89 45 84             	mov    %eax,-0x7c(%ebp)
 100372b:	c6 45 98 01          	movb   $0x1,-0x68(%ebp)
 100372f:	8b 45 bc             	mov    -0x44(%ebp),%eax
 1003732:	89 45 88             	mov    %eax,-0x78(%ebp)
 1003735:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003738:	8b 40 18             	mov    0x18(%eax),%eax
 100373b:	8b 55 c0             	mov    -0x40(%ebp),%edx
 100373e:	89 d3                	mov    %edx,%ebx
 1003740:	29 c3                	sub    %eax,%ebx
 1003742:	89 d8                	mov    %ebx,%eax
 1003744:	89 45 8c             	mov    %eax,-0x74(%ebp)
 1003747:	8d 45 84             	lea    -0x7c(%ebp),%eax
 100374a:	89 44 24 04          	mov    %eax,0x4(%esp)
 100374e:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 1003755:	e8 26 0e 00 00       	call   1004580 <_ZN16bipriority_queue4pushER9BLOCKINFO>
 100375a:	eb 01                	jmp    100375d <_ZN5CGame4MoveEP7CObjectii+0x333>
 100375c:	90                   	nop
 100375d:	83 45 ec 04          	addl   $0x4,-0x14(%ebp)
 1003761:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1003764:	8b 00                	mov    (%eax),%eax
 1003766:	85 c0                	test   %eax,%eax
 1003768:	0f 95 c0             	setne  %al
 100376b:	84 c0                	test   %al,%al
 100376d:	0f 85 b5 fe ff ff    	jne    1003628 <_ZN5CGame4MoveEP7CObjectii+0x1fe>
 1003773:	83 7d 10 00          	cmpl   $0x0,0x10(%ebp)
 1003777:	0f 89 b6 01 00 00    	jns    1003933 <_ZN5CGame4MoveEP7CObjectii+0x509>
 100377d:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003780:	8b 40 0c             	mov    0xc(%eax),%eax
 1003783:	89 45 d4             	mov    %eax,-0x2c(%ebp)
 1003786:	8b 45 10             	mov    0x10(%ebp),%eax
 1003789:	8b 55 d4             	mov    -0x2c(%ebp),%edx
 100378c:	01 d0                	add    %edx,%eax
 100378e:	89 45 d0             	mov    %eax,-0x30(%ebp)
 1003791:	8b 45 08             	mov    0x8(%ebp),%eax
 1003794:	83 c0 18             	add    $0x18,%eax
 1003797:	89 45 e8             	mov    %eax,-0x18(%ebp)
 100379a:	e9 2b 01 00 00       	jmp    10038ca <_ZN5CGame4MoveEP7CObjectii+0x4a0>
 100379f:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10037a2:	8b 00                	mov    (%eax),%eax
 10037a4:	3b 45 0c             	cmp    0xc(%ebp),%eax
 10037a7:	0f 84 18 01 00 00    	je     10038c5 <_ZN5CGame4MoveEP7CObjectii+0x49b>
 10037ad:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10037b0:	8b 00                	mov    (%eax),%eax
 10037b2:	8b 50 0c             	mov    0xc(%eax),%edx
 10037b5:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10037b8:	8b 00                	mov    (%eax),%eax
 10037ba:	8b 40 14             	mov    0x14(%eax),%eax
 10037bd:	01 d0                	add    %edx,%eax
 10037bf:	89 45 b4             	mov    %eax,-0x4c(%ebp)
 10037c2:	8b 45 b4             	mov    -0x4c(%ebp),%eax
 10037c5:	3b 45 d0             	cmp    -0x30(%ebp),%eax
 10037c8:	0f 8e f8 00 00 00    	jle    10038c6 <_ZN5CGame4MoveEP7CObjectii+0x49c>
 10037ce:	8b 45 b4             	mov    -0x4c(%ebp),%eax
 10037d1:	3b 45 d4             	cmp    -0x2c(%ebp),%eax
 10037d4:	0f 8f ec 00 00 00    	jg     10038c6 <_ZN5CGame4MoveEP7CObjectii+0x49c>
 10037da:	8b 45 0c             	mov    0xc(%ebp),%eax
 10037dd:	8b 48 10             	mov    0x10(%eax),%ecx
 10037e0:	8b 45 d4             	mov    -0x2c(%ebp),%eax
 10037e3:	8b 55 b4             	mov    -0x4c(%ebp),%edx
 10037e6:	89 d3                	mov    %edx,%ebx
 10037e8:	29 c3                	sub    %eax,%ebx
 10037ea:	89 d8                	mov    %ebx,%eax
 10037ec:	0f af 45 14          	imul   0x14(%ebp),%eax
 10037f0:	89 c2                	mov    %eax,%edx
 10037f2:	c1 fa 1f             	sar    $0x1f,%edx
 10037f5:	f7 7d 10             	idivl  0x10(%ebp)
 10037f8:	01 c8                	add    %ecx,%eax
 10037fa:	89 45 b0             	mov    %eax,-0x50(%ebp)
 10037fd:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003800:	8b 40 18             	mov    0x18(%eax),%eax
 1003803:	03 45 b0             	add    -0x50(%ebp),%eax
 1003806:	89 45 ac             	mov    %eax,-0x54(%ebp)
 1003809:	8b 45 e8             	mov    -0x18(%ebp),%eax
 100380c:	8b 00                	mov    (%eax),%eax
 100380e:	8b 40 10             	mov    0x10(%eax),%eax
 1003811:	3b 45 ac             	cmp    -0x54(%ebp),%eax
 1003814:	7d 52                	jge    1003868 <_ZN5CGame4MoveEP7CObjectii+0x43e>
 1003816:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1003819:	8b 00                	mov    (%eax),%eax
 100381b:	8b 50 10             	mov    0x10(%eax),%edx
 100381e:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1003821:	8b 00                	mov    (%eax),%eax
 1003823:	8b 40 18             	mov    0x18(%eax),%eax
 1003826:	01 d0                	add    %edx,%eax
 1003828:	3b 45 b0             	cmp    -0x50(%ebp),%eax
 100382b:	7e 3b                	jle    1003868 <_ZN5CGame4MoveEP7CObjectii+0x43e>
 100382d:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1003830:	8b 00                	mov    (%eax),%eax
 1003832:	89 45 84             	mov    %eax,-0x7c(%ebp)
 1003835:	c7 45 90 01 00 00 00 	movl   $0x1,-0x70(%ebp)
 100383c:	c7 45 94 03 00 00 00 	movl   $0x3,-0x6c(%ebp)
 1003843:	c6 45 98 00          	movb   $0x0,-0x68(%ebp)
 1003847:	8b 45 b4             	mov    -0x4c(%ebp),%eax
 100384a:	89 45 88             	mov    %eax,-0x78(%ebp)
 100384d:	8b 45 b0             	mov    -0x50(%ebp),%eax
 1003850:	89 45 8c             	mov    %eax,-0x74(%ebp)
 1003853:	8d 45 84             	lea    -0x7c(%ebp),%eax
 1003856:	89 44 24 04          	mov    %eax,0x4(%esp)
 100385a:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 1003861:	e8 1a 0d 00 00       	call   1004580 <_ZN16bipriority_queue4pushER9BLOCKINFO>
 1003866:	eb 5e                	jmp    10038c6 <_ZN5CGame4MoveEP7CObjectii+0x49c>
 1003868:	83 7d 14 00          	cmpl   $0x0,0x14(%ebp)
 100386c:	7e 0d                	jle    100387b <_ZN5CGame4MoveEP7CObjectii+0x451>
 100386e:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1003871:	8b 00                	mov    (%eax),%eax
 1003873:	8b 40 10             	mov    0x10(%eax),%eax
 1003876:	3b 45 ac             	cmp    -0x54(%ebp),%eax
 1003879:	74 1d                	je     1003898 <_ZN5CGame4MoveEP7CObjectii+0x46e>
 100387b:	83 7d 14 00          	cmpl   $0x0,0x14(%ebp)
 100387f:	79 45                	jns    10038c6 <_ZN5CGame4MoveEP7CObjectii+0x49c>
 1003881:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1003884:	8b 00                	mov    (%eax),%eax
 1003886:	8b 50 10             	mov    0x10(%eax),%edx
 1003889:	8b 45 e8             	mov    -0x18(%ebp),%eax
 100388c:	8b 00                	mov    (%eax),%eax
 100388e:	8b 40 18             	mov    0x18(%eax),%eax
 1003891:	01 d0                	add    %edx,%eax
 1003893:	3b 45 b0             	cmp    -0x50(%ebp),%eax
 1003896:	75 2e                	jne    10038c6 <_ZN5CGame4MoveEP7CObjectii+0x49c>
 1003898:	8b 45 e8             	mov    -0x18(%ebp),%eax
 100389b:	8b 00                	mov    (%eax),%eax
 100389d:	89 45 84             	mov    %eax,-0x7c(%ebp)
 10038a0:	c6 45 98 00          	movb   $0x0,-0x68(%ebp)
 10038a4:	8b 45 b4             	mov    -0x4c(%ebp),%eax
 10038a7:	89 45 88             	mov    %eax,-0x78(%ebp)
 10038aa:	8b 45 b0             	mov    -0x50(%ebp),%eax
 10038ad:	89 45 8c             	mov    %eax,-0x74(%ebp)
 10038b0:	8d 45 84             	lea    -0x7c(%ebp),%eax
 10038b3:	89 44 24 04          	mov    %eax,0x4(%esp)
 10038b7:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 10038be:	e8 bd 0c 00 00       	call   1004580 <_ZN16bipriority_queue4pushER9BLOCKINFO>
 10038c3:	eb 01                	jmp    10038c6 <_ZN5CGame4MoveEP7CObjectii+0x49c>
 10038c5:	90                   	nop
 10038c6:	83 45 e8 04          	addl   $0x4,-0x18(%ebp)
 10038ca:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10038cd:	8b 00                	mov    (%eax),%eax
 10038cf:	85 c0                	test   %eax,%eax
 10038d1:	0f 95 c0             	setne  %al
 10038d4:	84 c0                	test   %al,%al
 10038d6:	0f 85 c3 fe ff ff    	jne    100379f <_ZN5CGame4MoveEP7CObjectii+0x375>
 10038dc:	83 7d d0 00          	cmpl   $0x0,-0x30(%ebp)
 10038e0:	0f 89 34 02 00 00    	jns    1003b1a <_ZN5CGame4MoveEP7CObjectii+0x6f0>
 10038e6:	c7 45 84 00 00 00 00 	movl   $0x0,-0x7c(%ebp)
 10038ed:	c7 45 90 01 00 00 00 	movl   $0x1,-0x70(%ebp)
 10038f4:	c6 45 98 00          	movb   $0x0,-0x68(%ebp)
 10038f8:	c7 45 88 00 00 00 00 	movl   $0x0,-0x78(%ebp)
 10038ff:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003902:	8b 48 10             	mov    0x10(%eax),%ecx
 1003905:	8b 45 d4             	mov    -0x2c(%ebp),%eax
 1003908:	f7 d8                	neg    %eax
 100390a:	0f af 45 14          	imul   0x14(%ebp),%eax
 100390e:	89 c2                	mov    %eax,%edx
 1003910:	c1 fa 1f             	sar    $0x1f,%edx
 1003913:	f7 7d 10             	idivl  0x10(%ebp)
 1003916:	01 c8                	add    %ecx,%eax
 1003918:	89 45 8c             	mov    %eax,-0x74(%ebp)
 100391b:	8d 45 84             	lea    -0x7c(%ebp),%eax
 100391e:	89 44 24 04          	mov    %eax,0x4(%esp)
 1003922:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 1003929:	e8 52 0c 00 00       	call   1004580 <_ZN16bipriority_queue4pushER9BLOCKINFO>
 100392e:	e9 e7 01 00 00       	jmp    1003b1a <_ZN5CGame4MoveEP7CObjectii+0x6f0>
 1003933:	83 7d 10 00          	cmpl   $0x0,0x10(%ebp)
 1003937:	0f 8e dd 01 00 00    	jle    1003b1a <_ZN5CGame4MoveEP7CObjectii+0x6f0>
 100393d:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003940:	8b 50 0c             	mov    0xc(%eax),%edx
 1003943:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003946:	8b 40 14             	mov    0x14(%eax),%eax
 1003949:	01 d0                	add    %edx,%eax
 100394b:	89 45 d4             	mov    %eax,-0x2c(%ebp)
 100394e:	8b 45 10             	mov    0x10(%ebp),%eax
 1003951:	8b 55 d4             	mov    -0x2c(%ebp),%edx
 1003954:	01 d0                	add    %edx,%eax
 1003956:	89 45 d0             	mov    %eax,-0x30(%ebp)
 1003959:	8b 45 08             	mov    0x8(%ebp),%eax
 100395c:	83 c0 18             	add    $0x18,%eax
 100395f:	89 45 e4             	mov    %eax,-0x1c(%ebp)
 1003962:	e9 39 01 00 00       	jmp    1003aa0 <_ZN5CGame4MoveEP7CObjectii+0x676>
 1003967:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 100396a:	8b 00                	mov    (%eax),%eax
 100396c:	3b 45 0c             	cmp    0xc(%ebp),%eax
 100396f:	0f 84 26 01 00 00    	je     1003a9b <_ZN5CGame4MoveEP7CObjectii+0x671>
 1003975:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1003978:	8b 00                	mov    (%eax),%eax
 100397a:	8b 40 0c             	mov    0xc(%eax),%eax
 100397d:	89 45 a8             	mov    %eax,-0x58(%ebp)
 1003980:	8b 45 a8             	mov    -0x58(%ebp),%eax
 1003983:	3b 45 d4             	cmp    -0x2c(%ebp),%eax
 1003986:	0f 8c 10 01 00 00    	jl     1003a9c <_ZN5CGame4MoveEP7CObjectii+0x672>
 100398c:	8b 45 a8             	mov    -0x58(%ebp),%eax
 100398f:	3b 45 d0             	cmp    -0x30(%ebp),%eax
 1003992:	0f 8d 04 01 00 00    	jge    1003a9c <_ZN5CGame4MoveEP7CObjectii+0x672>
 1003998:	8b 45 0c             	mov    0xc(%ebp),%eax
 100399b:	8b 48 10             	mov    0x10(%eax),%ecx
 100399e:	8b 45 d4             	mov    -0x2c(%ebp),%eax
 10039a1:	8b 55 a8             	mov    -0x58(%ebp),%edx
 10039a4:	89 d3                	mov    %edx,%ebx
 10039a6:	29 c3                	sub    %eax,%ebx
 10039a8:	89 d8                	mov    %ebx,%eax
 10039aa:	0f af 45 14          	imul   0x14(%ebp),%eax
 10039ae:	89 c2                	mov    %eax,%edx
 10039b0:	c1 fa 1f             	sar    $0x1f,%edx
 10039b3:	f7 7d 10             	idivl  0x10(%ebp)
 10039b6:	01 c8                	add    %ecx,%eax
 10039b8:	89 45 a4             	mov    %eax,-0x5c(%ebp)
 10039bb:	8b 45 0c             	mov    0xc(%ebp),%eax
 10039be:	8b 40 18             	mov    0x18(%eax),%eax
 10039c1:	03 45 a4             	add    -0x5c(%ebp),%eax
 10039c4:	89 45 a0             	mov    %eax,-0x60(%ebp)
 10039c7:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 10039ca:	8b 00                	mov    (%eax),%eax
 10039cc:	8b 40 10             	mov    0x10(%eax),%eax
 10039cf:	3b 45 a0             	cmp    -0x60(%ebp),%eax
 10039d2:	7d 5e                	jge    1003a32 <_ZN5CGame4MoveEP7CObjectii+0x608>
 10039d4:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 10039d7:	8b 00                	mov    (%eax),%eax
 10039d9:	8b 50 10             	mov    0x10(%eax),%edx
 10039dc:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 10039df:	8b 00                	mov    (%eax),%eax
 10039e1:	8b 40 18             	mov    0x18(%eax),%eax
 10039e4:	01 d0                	add    %edx,%eax
 10039e6:	3b 45 a4             	cmp    -0x5c(%ebp),%eax
 10039e9:	7e 47                	jle    1003a32 <_ZN5CGame4MoveEP7CObjectii+0x608>
 10039eb:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 10039ee:	8b 00                	mov    (%eax),%eax
 10039f0:	89 45 84             	mov    %eax,-0x7c(%ebp)
 10039f3:	c7 45 90 01 00 00 00 	movl   $0x1,-0x70(%ebp)
 10039fa:	c7 45 94 03 00 00 00 	movl   $0x3,-0x6c(%ebp)
 1003a01:	c6 45 98 00          	movb   $0x0,-0x68(%ebp)
 1003a05:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003a08:	8b 40 14             	mov    0x14(%eax),%eax
 1003a0b:	8b 55 a8             	mov    -0x58(%ebp),%edx
 1003a0e:	89 d1                	mov    %edx,%ecx
 1003a10:	29 c1                	sub    %eax,%ecx
 1003a12:	89 c8                	mov    %ecx,%eax
 1003a14:	89 45 88             	mov    %eax,-0x78(%ebp)
 1003a17:	8b 45 a4             	mov    -0x5c(%ebp),%eax
 1003a1a:	89 45 8c             	mov    %eax,-0x74(%ebp)
 1003a1d:	8d 45 84             	lea    -0x7c(%ebp),%eax
 1003a20:	89 44 24 04          	mov    %eax,0x4(%esp)
 1003a24:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 1003a2b:	e8 50 0b 00 00       	call   1004580 <_ZN16bipriority_queue4pushER9BLOCKINFO>
 1003a30:	eb 6a                	jmp    1003a9c <_ZN5CGame4MoveEP7CObjectii+0x672>
 1003a32:	83 7d 14 00          	cmpl   $0x0,0x14(%ebp)
 1003a36:	7e 0d                	jle    1003a45 <_ZN5CGame4MoveEP7CObjectii+0x61b>
 1003a38:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1003a3b:	8b 00                	mov    (%eax),%eax
 1003a3d:	8b 40 10             	mov    0x10(%eax),%eax
 1003a40:	3b 45 a0             	cmp    -0x60(%ebp),%eax
 1003a43:	74 1d                	je     1003a62 <_ZN5CGame4MoveEP7CObjectii+0x638>
 1003a45:	83 7d 14 00          	cmpl   $0x0,0x14(%ebp)
 1003a49:	79 51                	jns    1003a9c <_ZN5CGame4MoveEP7CObjectii+0x672>
 1003a4b:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1003a4e:	8b 00                	mov    (%eax),%eax
 1003a50:	8b 50 10             	mov    0x10(%eax),%edx
 1003a53:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1003a56:	8b 00                	mov    (%eax),%eax
 1003a58:	8b 40 18             	mov    0x18(%eax),%eax
 1003a5b:	01 d0                	add    %edx,%eax
 1003a5d:	3b 45 a4             	cmp    -0x5c(%ebp),%eax
 1003a60:	75 3a                	jne    1003a9c <_ZN5CGame4MoveEP7CObjectii+0x672>
 1003a62:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1003a65:	8b 00                	mov    (%eax),%eax
 1003a67:	89 45 84             	mov    %eax,-0x7c(%ebp)
 1003a6a:	c6 45 98 01          	movb   $0x1,-0x68(%ebp)
 1003a6e:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003a71:	8b 40 14             	mov    0x14(%eax),%eax
 1003a74:	8b 55 a8             	mov    -0x58(%ebp),%edx
 1003a77:	89 d3                	mov    %edx,%ebx
 1003a79:	29 c3                	sub    %eax,%ebx
 1003a7b:	89 d8                	mov    %ebx,%eax
 1003a7d:	89 45 88             	mov    %eax,-0x78(%ebp)
 1003a80:	8b 45 a4             	mov    -0x5c(%ebp),%eax
 1003a83:	89 45 8c             	mov    %eax,-0x74(%ebp)
 1003a86:	8d 45 84             	lea    -0x7c(%ebp),%eax
 1003a89:	89 44 24 04          	mov    %eax,0x4(%esp)
 1003a8d:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 1003a94:	e8 e7 0a 00 00       	call   1004580 <_ZN16bipriority_queue4pushER9BLOCKINFO>
 1003a99:	eb 01                	jmp    1003a9c <_ZN5CGame4MoveEP7CObjectii+0x672>
 1003a9b:	90                   	nop
 1003a9c:	83 45 e4 04          	addl   $0x4,-0x1c(%ebp)
 1003aa0:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1003aa3:	8b 00                	mov    (%eax),%eax
 1003aa5:	85 c0                	test   %eax,%eax
 1003aa7:	0f 95 c0             	setne  %al
 1003aaa:	84 c0                	test   %al,%al
 1003aac:	0f 85 b5 fe ff ff    	jne    1003967 <_ZN5CGame4MoveEP7CObjectii+0x53d>
 1003ab2:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003ab5:	8b 40 14             	mov    0x14(%eax),%eax
 1003ab8:	03 45 d0             	add    -0x30(%ebp),%eax
 1003abb:	3d 20 01 00 00       	cmp    $0x120,%eax
 1003ac0:	7e 58                	jle    1003b1a <_ZN5CGame4MoveEP7CObjectii+0x6f0>
 1003ac2:	c7 45 84 00 00 00 00 	movl   $0x0,-0x7c(%ebp)
 1003ac9:	c7 45 90 01 00 00 00 	movl   $0x1,-0x70(%ebp)
 1003ad0:	c6 45 98 00          	movb   $0x0,-0x68(%ebp)
 1003ad4:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003ad7:	8b 40 14             	mov    0x14(%eax),%eax
 1003ada:	ba 20 01 00 00       	mov    $0x120,%edx
 1003adf:	89 d1                	mov    %edx,%ecx
 1003ae1:	29 c1                	sub    %eax,%ecx
 1003ae3:	89 c8                	mov    %ecx,%eax
 1003ae5:	89 45 88             	mov    %eax,-0x78(%ebp)
 1003ae8:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003aeb:	8b 48 10             	mov    0x10(%eax),%ecx
 1003aee:	b8 20 01 00 00       	mov    $0x120,%eax
 1003af3:	2b 45 d4             	sub    -0x2c(%ebp),%eax
 1003af6:	0f af 45 14          	imul   0x14(%ebp),%eax
 1003afa:	89 c2                	mov    %eax,%edx
 1003afc:	c1 fa 1f             	sar    $0x1f,%edx
 1003aff:	f7 7d 10             	idivl  0x10(%ebp)
 1003b02:	01 c8                	add    %ecx,%eax
 1003b04:	89 45 8c             	mov    %eax,-0x74(%ebp)
 1003b07:	8d 45 84             	lea    -0x7c(%ebp),%eax
 1003b0a:	89 44 24 04          	mov    %eax,0x4(%esp)
 1003b0e:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 1003b15:	e8 66 0a 00 00       	call   1004580 <_ZN16bipriority_queue4pushER9BLOCKINFO>
 1003b1a:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003b1d:	8b 55 dc             	mov    -0x24(%ebp),%edx
 1003b20:	89 50 0c             	mov    %edx,0xc(%eax)
 1003b23:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003b26:	8b 55 d8             	mov    -0x28(%ebp),%edx
 1003b29:	89 50 10             	mov    %edx,0x10(%eax)
 1003b2c:	e9 a8 03 00 00       	jmp    1003ed9 <_ZN5CGame4MoveEP7CObjectii+0xaaf>
 1003b31:	8d 85 48 ff ff ff    	lea    -0xb8(%ebp),%eax
 1003b37:	c7 44 24 04 80 53 02 	movl   $0x1025380,0x4(%esp)
 1003b3e:	01 
 1003b3f:	89 04 24             	mov    %eax,(%esp)
 1003b42:	e8 61 08 00 00       	call   10043a8 <_ZN16bipriority_queue3topEv>
 1003b47:	83 ec 04             	sub    $0x4,%esp
 1003b4a:	8b 85 48 ff ff ff    	mov    -0xb8(%ebp),%eax
 1003b50:	89 85 6c ff ff ff    	mov    %eax,-0x94(%ebp)
 1003b56:	8b 85 4c ff ff ff    	mov    -0xb4(%ebp),%eax
 1003b5c:	89 85 70 ff ff ff    	mov    %eax,-0x90(%ebp)
 1003b62:	8b 85 50 ff ff ff    	mov    -0xb0(%ebp),%eax
 1003b68:	89 85 74 ff ff ff    	mov    %eax,-0x8c(%ebp)
 1003b6e:	8b 85 54 ff ff ff    	mov    -0xac(%ebp),%eax
 1003b74:	89 85 78 ff ff ff    	mov    %eax,-0x88(%ebp)
 1003b7a:	8b 85 58 ff ff ff    	mov    -0xa8(%ebp),%eax
 1003b80:	89 85 7c ff ff ff    	mov    %eax,-0x84(%ebp)
 1003b86:	8b 85 5c ff ff ff    	mov    -0xa4(%ebp),%eax
 1003b8c:	89 45 80             	mov    %eax,-0x80(%ebp)
 1003b8f:	0f b6 45 80          	movzbl -0x80(%ebp),%eax
 1003b93:	84 c0                	test   %al,%al
 1003b95:	0f 84 ef 00 00 00    	je     1003c8a <_ZN5CGame4MoveEP7CObjectii+0x860>
 1003b9b:	8b 45 08             	mov    0x8(%ebp),%eax
 1003b9e:	8b 00                	mov    (%eax),%eax
 1003ba0:	3b 45 0c             	cmp    0xc(%ebp),%eax
 1003ba3:	75 1e                	jne    1003bc3 <_ZN5CGame4MoveEP7CObjectii+0x799>
 1003ba5:	c7 45 f4 02 00 00 00 	movl   $0x2,-0xc(%ebp)
 1003bac:	83 7d 14 00          	cmpl   $0x0,0x14(%ebp)
 1003bb0:	7e 07                	jle    1003bb9 <_ZN5CGame4MoveEP7CObjectii+0x78f>
 1003bb2:	b8 01 00 00 00       	mov    $0x1,%eax
 1003bb7:	eb 05                	jmp    1003bbe <_ZN5CGame4MoveEP7CObjectii+0x794>
 1003bb9:	b8 02 00 00 00       	mov    $0x2,%eax
 1003bbe:	89 45 e0             	mov    %eax,-0x20(%ebp)
 1003bc1:	eb 0e                	jmp    1003bd1 <_ZN5CGame4MoveEP7CObjectii+0x7a7>
 1003bc3:	c7 45 f4 01 00 00 00 	movl   $0x1,-0xc(%ebp)
 1003bca:	c7 45 e0 03 00 00 00 	movl   $0x3,-0x20(%ebp)
 1003bd1:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003bd4:	8b 00                	mov    (%eax),%eax
 1003bd6:	83 c0 0c             	add    $0xc,%eax
 1003bd9:	8b 08                	mov    (%eax),%ecx
 1003bdb:	8b 85 6c ff ff ff    	mov    -0x94(%ebp),%eax
 1003be1:	c7 44 24 0c 01 00 00 	movl   $0x1,0xc(%esp)
 1003be8:	00 
 1003be9:	8b 55 e0             	mov    -0x20(%ebp),%edx
 1003bec:	89 54 24 08          	mov    %edx,0x8(%esp)
 1003bf0:	89 44 24 04          	mov    %eax,0x4(%esp)
 1003bf4:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003bf7:	89 04 24             	mov    %eax,(%esp)
 1003bfa:	ff d1                	call   *%ecx
 1003bfc:	83 7d e0 01          	cmpl   $0x1,-0x20(%ebp)
 1003c00:	75 09                	jne    1003c0b <_ZN5CGame4MoveEP7CObjectii+0x7e1>
 1003c02:	c7 45 e0 02 00 00 00 	movl   $0x2,-0x20(%ebp)
 1003c09:	eb 0d                	jmp    1003c18 <_ZN5CGame4MoveEP7CObjectii+0x7ee>
 1003c0b:	83 7d e0 02          	cmpl   $0x2,-0x20(%ebp)
 1003c0f:	75 07                	jne    1003c18 <_ZN5CGame4MoveEP7CObjectii+0x7ee>
 1003c11:	c7 45 e0 01 00 00 00 	movl   $0x1,-0x20(%ebp)
 1003c18:	8b 85 6c ff ff ff    	mov    -0x94(%ebp),%eax
 1003c1e:	8b 00                	mov    (%eax),%eax
 1003c20:	83 c0 0c             	add    $0xc,%eax
 1003c23:	8b 08                	mov    (%eax),%ecx
 1003c25:	8b 85 6c ff ff ff    	mov    -0x94(%ebp),%eax
 1003c2b:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 1003c32:	00 
 1003c33:	8b 55 e0             	mov    -0x20(%ebp),%edx
 1003c36:	89 54 24 08          	mov    %edx,0x8(%esp)
 1003c3a:	8b 55 0c             	mov    0xc(%ebp),%edx
 1003c3d:	89 54 24 04          	mov    %edx,0x4(%esp)
 1003c41:	89 04 24             	mov    %eax,(%esp)
 1003c44:	ff d1                	call   *%ecx
 1003c46:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003c49:	8b 00                	mov    (%eax),%eax
 1003c4b:	83 c0 08             	add    $0x8,%eax
 1003c4e:	8b 10                	mov    (%eax),%edx
 1003c50:	8b 85 6c ff ff ff    	mov    -0x94(%ebp),%eax
 1003c56:	89 44 24 04          	mov    %eax,0x4(%esp)
 1003c5a:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003c5d:	89 04 24             	mov    %eax,(%esp)
 1003c60:	ff d2                	call   *%edx
 1003c62:	83 f0 01             	xor    $0x1,%eax
 1003c65:	84 c0                	test   %al,%al
 1003c67:	0f 85 5c 02 00 00    	jne    1003ec9 <_ZN5CGame4MoveEP7CObjectii+0xa9f>
 1003c6d:	8b 95 70 ff ff ff    	mov    -0x90(%ebp),%edx
 1003c73:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003c76:	89 50 0c             	mov    %edx,0xc(%eax)
 1003c79:	8b 95 74 ff ff ff    	mov    -0x8c(%ebp),%edx
 1003c7f:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003c82:	89 50 10             	mov    %edx,0x10(%eax)
 1003c85:	e9 66 02 00 00       	jmp    1003ef0 <_ZN5CGame4MoveEP7CObjectii+0xac6>
 1003c8a:	8b 85 6c ff ff ff    	mov    -0x94(%ebp),%eax
 1003c90:	85 c0                	test   %eax,%eax
 1003c92:	0f 84 8b 00 00 00    	je     1003d23 <_ZN5CGame4MoveEP7CObjectii+0x8f9>
 1003c98:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003c9b:	8b 00                	mov    (%eax),%eax
 1003c9d:	83 c0 0c             	add    $0xc,%eax
 1003ca0:	8b 08                	mov    (%eax),%ecx
 1003ca2:	8b 95 7c ff ff ff    	mov    -0x84(%ebp),%edx
 1003ca8:	8b 85 6c ff ff ff    	mov    -0x94(%ebp),%eax
 1003cae:	c7 44 24 0c 01 00 00 	movl   $0x1,0xc(%esp)
 1003cb5:	00 
 1003cb6:	89 54 24 08          	mov    %edx,0x8(%esp)
 1003cba:	89 44 24 04          	mov    %eax,0x4(%esp)
 1003cbe:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003cc1:	89 04 24             	mov    %eax,(%esp)
 1003cc4:	ff d1                	call   *%ecx
 1003cc6:	8b 85 7c ff ff ff    	mov    -0x84(%ebp),%eax
 1003ccc:	83 f8 01             	cmp    $0x1,%eax
 1003ccf:	75 09                	jne    1003cda <_ZN5CGame4MoveEP7CObjectii+0x8b0>
 1003cd1:	c7 45 e0 02 00 00 00 	movl   $0x2,-0x20(%ebp)
 1003cd8:	eb 1b                	jmp    1003cf5 <_ZN5CGame4MoveEP7CObjectii+0x8cb>
 1003cda:	8b 85 7c ff ff ff    	mov    -0x84(%ebp),%eax
 1003ce0:	83 f8 02             	cmp    $0x2,%eax
 1003ce3:	75 09                	jne    1003cee <_ZN5CGame4MoveEP7CObjectii+0x8c4>
 1003ce5:	c7 45 e0 01 00 00 00 	movl   $0x1,-0x20(%ebp)
 1003cec:	eb 07                	jmp    1003cf5 <_ZN5CGame4MoveEP7CObjectii+0x8cb>
 1003cee:	c7 45 e0 03 00 00 00 	movl   $0x3,-0x20(%ebp)
 1003cf5:	8b 85 6c ff ff ff    	mov    -0x94(%ebp),%eax
 1003cfb:	8b 00                	mov    (%eax),%eax
 1003cfd:	83 c0 0c             	add    $0xc,%eax
 1003d00:	8b 08                	mov    (%eax),%ecx
 1003d02:	8b 85 6c ff ff ff    	mov    -0x94(%ebp),%eax
 1003d08:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 1003d0f:	00 
 1003d10:	8b 55 e0             	mov    -0x20(%ebp),%edx
 1003d13:	89 54 24 08          	mov    %edx,0x8(%esp)
 1003d17:	8b 55 0c             	mov    0xc(%ebp),%edx
 1003d1a:	89 54 24 04          	mov    %edx,0x4(%esp)
 1003d1e:	89 04 24             	mov    %eax,(%esp)
 1003d21:	ff d1                	call   *%ecx
 1003d23:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003d26:	8b 00                	mov    (%eax),%eax
 1003d28:	83 c0 08             	add    $0x8,%eax
 1003d2b:	8b 10                	mov    (%eax),%edx
 1003d2d:	8b 85 6c ff ff ff    	mov    -0x94(%ebp),%eax
 1003d33:	89 44 24 04          	mov    %eax,0x4(%esp)
 1003d37:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003d3a:	89 04 24             	mov    %eax,(%esp)
 1003d3d:	ff d2                	call   *%edx
 1003d3f:	83 f0 01             	xor    $0x1,%eax
 1003d42:	84 c0                	test   %al,%al
 1003d44:	0f 85 82 01 00 00    	jne    1003ecc <_ZN5CGame4MoveEP7CObjectii+0xaa2>
 1003d4a:	8b 95 70 ff ff ff    	mov    -0x90(%ebp),%edx
 1003d50:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003d53:	89 50 0c             	mov    %edx,0xc(%eax)
 1003d56:	8b 95 74 ff ff ff    	mov    -0x8c(%ebp),%edx
 1003d5c:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003d5f:	89 50 10             	mov    %edx,0x10(%eax)
 1003d62:	8b 85 78 ff ff ff    	mov    -0x88(%ebp),%eax
 1003d68:	89 45 f4             	mov    %eax,-0xc(%ebp)
 1003d6b:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 1003d72:	e8 ff 06 00 00       	call   1004476 <_ZN16bipriority_queue3popEv>
 1003d77:	e9 2e 01 00 00       	jmp    1003eaa <_ZN5CGame4MoveEP7CObjectii+0xa80>
 1003d7c:	8d 85 48 ff ff ff    	lea    -0xb8(%ebp),%eax
 1003d82:	c7 44 24 04 80 53 02 	movl   $0x1025380,0x4(%esp)
 1003d89:	01 
 1003d8a:	89 04 24             	mov    %eax,(%esp)
 1003d8d:	e8 16 06 00 00       	call   10043a8 <_ZN16bipriority_queue3topEv>
 1003d92:	83 ec 04             	sub    $0x4,%esp
 1003d95:	8b 85 48 ff ff ff    	mov    -0xb8(%ebp),%eax
 1003d9b:	89 85 6c ff ff ff    	mov    %eax,-0x94(%ebp)
 1003da1:	8b 85 4c ff ff ff    	mov    -0xb4(%ebp),%eax
 1003da7:	89 85 70 ff ff ff    	mov    %eax,-0x90(%ebp)
 1003dad:	8b 85 50 ff ff ff    	mov    -0xb0(%ebp),%eax
 1003db3:	89 85 74 ff ff ff    	mov    %eax,-0x8c(%ebp)
 1003db9:	8b 85 54 ff ff ff    	mov    -0xac(%ebp),%eax
 1003dbf:	89 85 78 ff ff ff    	mov    %eax,-0x88(%ebp)
 1003dc5:	8b 85 58 ff ff ff    	mov    -0xa8(%ebp),%eax
 1003dcb:	89 85 7c ff ff ff    	mov    %eax,-0x84(%ebp)
 1003dd1:	8b 85 5c ff ff ff    	mov    -0xa4(%ebp),%eax
 1003dd7:	89 45 80             	mov    %eax,-0x80(%ebp)
 1003dda:	0f b6 45 80          	movzbl -0x80(%ebp),%eax
 1003dde:	84 c0                	test   %al,%al
 1003de0:	0f 85 dd 00 00 00    	jne    1003ec3 <_ZN5CGame4MoveEP7CObjectii+0xa99>
 1003de6:	8b 95 70 ff ff ff    	mov    -0x90(%ebp),%edx
 1003dec:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003def:	8b 40 0c             	mov    0xc(%eax),%eax
 1003df2:	39 c2                	cmp    %eax,%edx
 1003df4:	0f 85 cc 00 00 00    	jne    1003ec6 <_ZN5CGame4MoveEP7CObjectii+0xa9c>
 1003dfa:	8b 95 74 ff ff ff    	mov    -0x8c(%ebp),%edx
 1003e00:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003e03:	8b 40 10             	mov    0x10(%eax),%eax
 1003e06:	39 c2                	cmp    %eax,%edx
 1003e08:	0f 85 b8 00 00 00    	jne    1003ec6 <_ZN5CGame4MoveEP7CObjectii+0xa9c>
 1003e0e:	8b 85 6c ff ff ff    	mov    -0x94(%ebp),%eax
 1003e14:	85 c0                	test   %eax,%eax
 1003e16:	0f 84 82 00 00 00    	je     1003e9e <_ZN5CGame4MoveEP7CObjectii+0xa74>
 1003e1c:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003e1f:	8b 00                	mov    (%eax),%eax
 1003e21:	83 c0 0c             	add    $0xc,%eax
 1003e24:	8b 08                	mov    (%eax),%ecx
 1003e26:	8b 95 7c ff ff ff    	mov    -0x84(%ebp),%edx
 1003e2c:	8b 85 6c ff ff ff    	mov    -0x94(%ebp),%eax
 1003e32:	c7 44 24 0c 01 00 00 	movl   $0x1,0xc(%esp)
 1003e39:	00 
 1003e3a:	89 54 24 08          	mov    %edx,0x8(%esp)
 1003e3e:	89 44 24 04          	mov    %eax,0x4(%esp)
 1003e42:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003e45:	89 04 24             	mov    %eax,(%esp)
 1003e48:	ff d1                	call   *%ecx
 1003e4a:	8b 85 7c ff ff ff    	mov    -0x84(%ebp),%eax
 1003e50:	83 f8 01             	cmp    $0x1,%eax
 1003e53:	75 09                	jne    1003e5e <_ZN5CGame4MoveEP7CObjectii+0xa34>
 1003e55:	c7 45 e0 02 00 00 00 	movl   $0x2,-0x20(%ebp)
 1003e5c:	eb 12                	jmp    1003e70 <_ZN5CGame4MoveEP7CObjectii+0xa46>
 1003e5e:	8b 85 7c ff ff ff    	mov    -0x84(%ebp),%eax
 1003e64:	83 f8 02             	cmp    $0x2,%eax
 1003e67:	75 07                	jne    1003e70 <_ZN5CGame4MoveEP7CObjectii+0xa46>
 1003e69:	c7 45 e0 01 00 00 00 	movl   $0x1,-0x20(%ebp)
 1003e70:	8b 85 6c ff ff ff    	mov    -0x94(%ebp),%eax
 1003e76:	8b 00                	mov    (%eax),%eax
 1003e78:	83 c0 0c             	add    $0xc,%eax
 1003e7b:	8b 08                	mov    (%eax),%ecx
 1003e7d:	8b 85 6c ff ff ff    	mov    -0x94(%ebp),%eax
 1003e83:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 1003e8a:	00 
 1003e8b:	8b 55 e0             	mov    -0x20(%ebp),%edx
 1003e8e:	89 54 24 08          	mov    %edx,0x8(%esp)
 1003e92:	8b 55 0c             	mov    0xc(%ebp),%edx
 1003e95:	89 54 24 04          	mov    %edx,0x4(%esp)
 1003e99:	89 04 24             	mov    %eax,(%esp)
 1003e9c:	ff d1                	call   *%ecx
 1003e9e:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 1003ea5:	e8 cc 05 00 00       	call   1004476 <_ZN16bipriority_queue3popEv>
 1003eaa:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 1003eb1:	e8 7c 07 00 00       	call   1004632 <_ZN16bipriority_queue5emptyEv>
 1003eb6:	83 f0 01             	xor    $0x1,%eax
 1003eb9:	84 c0                	test   %al,%al
 1003ebb:	0f 85 bb fe ff ff    	jne    1003d7c <_ZN5CGame4MoveEP7CObjectii+0x952>
 1003ec1:	eb 2d                	jmp    1003ef0 <_ZN5CGame4MoveEP7CObjectii+0xac6>
 1003ec3:	90                   	nop
 1003ec4:	eb 01                	jmp    1003ec7 <_ZN5CGame4MoveEP7CObjectii+0xa9d>
 1003ec6:	90                   	nop
 1003ec7:	eb 27                	jmp    1003ef0 <_ZN5CGame4MoveEP7CObjectii+0xac6>
 1003ec9:	90                   	nop
 1003eca:	eb 01                	jmp    1003ecd <_ZN5CGame4MoveEP7CObjectii+0xaa3>
 1003ecc:	90                   	nop
 1003ecd:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 1003ed4:	e8 9d 05 00 00       	call   1004476 <_ZN16bipriority_queue3popEv>
 1003ed9:	c7 04 24 80 53 02 01 	movl   $0x1025380,(%esp)
 1003ee0:	e8 4d 07 00 00       	call   1004632 <_ZN16bipriority_queue5emptyEv>
 1003ee5:	83 f0 01             	xor    $0x1,%eax
 1003ee8:	84 c0                	test   %al,%al
 1003eea:	0f 85 41 fc ff ff    	jne    1003b31 <_ZN5CGame4MoveEP7CObjectii+0x707>
 1003ef0:	83 7d f4 01          	cmpl   $0x1,-0xc(%ebp)
 1003ef4:	75 3d                	jne    1003f33 <_ZN5CGame4MoveEP7CObjectii+0xb09>
 1003ef6:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003ef9:	8b 40 10             	mov    0x10(%eax),%eax
 1003efc:	3b 45 d8             	cmp    -0x28(%ebp),%eax
 1003eff:	74 79                	je     1003f7a <_ZN5CGame4MoveEP7CObjectii+0xb50>
 1003f01:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003f04:	8b 40 10             	mov    0x10(%eax),%eax
 1003f07:	8b 55 d8             	mov    -0x28(%ebp),%edx
 1003f0a:	89 d3                	mov    %edx,%ebx
 1003f0c:	29 c3                	sub    %eax,%ebx
 1003f0e:	89 d8                	mov    %ebx,%eax
 1003f10:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1003f14:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 1003f1b:	00 
 1003f1c:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003f1f:	89 44 24 04          	mov    %eax,0x4(%esp)
 1003f23:	8b 45 08             	mov    0x8(%ebp),%eax
 1003f26:	89 04 24             	mov    %eax,(%esp)
 1003f29:	e8 fc f4 ff ff       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 1003f2e:	09 45 f4             	or     %eax,-0xc(%ebp)
 1003f31:	eb 47                	jmp    1003f7a <_ZN5CGame4MoveEP7CObjectii+0xb50>
 1003f33:	83 7d f4 02          	cmpl   $0x2,-0xc(%ebp)
 1003f37:	74 06                	je     1003f3f <_ZN5CGame4MoveEP7CObjectii+0xb15>
 1003f39:	83 7d f4 04          	cmpl   $0x4,-0xc(%ebp)
 1003f3d:	75 3b                	jne    1003f7a <_ZN5CGame4MoveEP7CObjectii+0xb50>
 1003f3f:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003f42:	8b 40 0c             	mov    0xc(%eax),%eax
 1003f45:	3b 45 dc             	cmp    -0x24(%ebp),%eax
 1003f48:	74 30                	je     1003f7a <_ZN5CGame4MoveEP7CObjectii+0xb50>
 1003f4a:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003f4d:	8b 40 0c             	mov    0xc(%eax),%eax
 1003f50:	8b 55 dc             	mov    -0x24(%ebp),%edx
 1003f53:	89 d1                	mov    %edx,%ecx
 1003f55:	29 c1                	sub    %eax,%ecx
 1003f57:	89 c8                	mov    %ecx,%eax
 1003f59:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 1003f60:	00 
 1003f61:	89 44 24 08          	mov    %eax,0x8(%esp)
 1003f65:	8b 45 0c             	mov    0xc(%ebp),%eax
 1003f68:	89 44 24 04          	mov    %eax,0x4(%esp)
 1003f6c:	8b 45 08             	mov    0x8(%ebp),%eax
 1003f6f:	89 04 24             	mov    %eax,(%esp)
 1003f72:	e8 b3 f4 ff ff       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 1003f77:	09 45 f4             	or     %eax,-0xc(%ebp)
 1003f7a:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1003f7d:	8b 5d fc             	mov    -0x4(%ebp),%ebx
 1003f80:	c9                   	leave  
 1003f81:	c3                   	ret    

01003f82 <_ZN5CGame11LoadMapDataEv>:
 1003f82:	55                   	push   %ebp
 1003f83:	89 e5                	mov    %esp,%ebp
 1003f85:	83 ec 28             	sub    $0x28,%esp
 1003f88:	8b 45 08             	mov    0x8(%ebp),%eax
 1003f8b:	8b 40 14             	mov    0x14(%eax),%eax
 1003f8e:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 1003f95:	00 
 1003f96:	89 04 24             	mov    %eax,(%esp)
 1003f99:	e8 ea 23 00 00       	call   1006388 <_ZN9CSoundMan13PlayBackMusicEi>
 1003f9e:	8b 45 08             	mov    0x8(%ebp),%eax
 1003fa1:	8b 40 08             	mov    0x8(%eax),%eax
 1003fa4:	83 c0 04             	add    $0x4,%eax
 1003fa7:	8b 00                	mov    (%eax),%eax
 1003fa9:	89 c1                	mov    %eax,%ecx
 1003fab:	c1 e1 04             	shl    $0x4,%ecx
 1003fae:	8b 45 08             	mov    0x8(%ebp),%eax
 1003fb1:	8b 40 08             	mov    0x8(%eax),%eax
 1003fb4:	8b 00                	mov    (%eax),%eax
 1003fb6:	89 c2                	mov    %eax,%edx
 1003fb8:	c1 e2 04             	shl    $0x4,%edx
 1003fbb:	8b 45 08             	mov    0x8(%ebp),%eax
 1003fbe:	8b 00                	mov    (%eax),%eax
 1003fc0:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 1003fc4:	89 54 24 04          	mov    %edx,0x4(%esp)
 1003fc8:	89 04 24             	mov    %eax,(%esp)
 1003fcb:	e8 52 1d 00 00       	call   1005d22 <_ZN6CMario8ResetPosEii>
 1003fd0:	8b 45 08             	mov    0x8(%ebp),%eax
 1003fd3:	8b 40 08             	mov    0x8(%eax),%eax
 1003fd6:	83 c0 0c             	add    $0xc,%eax
 1003fd9:	89 45 ec             	mov    %eax,-0x14(%ebp)
 1003fdc:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 1003fe3:	eb 63                	jmp    1004048 <_ZN5CGame11LoadMapDataEv+0xc6>
 1003fe5:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 1003fec:	eb 4b                	jmp    1004039 <_ZN5CGame11LoadMapDataEv+0xb7>
 1003fee:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1003ff1:	c1 e0 06             	shl    $0x6,%eax
 1003ff4:	03 45 ec             	add    -0x14(%ebp),%eax
 1003ff7:	8b 55 f0             	mov    -0x10(%ebp),%edx
 1003ffa:	8b 04 90             	mov    (%eax,%edx,4),%eax
 1003ffd:	85 c0                	test   %eax,%eax
 1003fff:	74 34                	je     1004035 <_ZN5CGame11LoadMapDataEv+0xb3>
 1004001:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1004004:	c1 e0 06             	shl    $0x6,%eax
 1004007:	03 45 ec             	add    -0x14(%ebp),%eax
 100400a:	8b 55 f0             	mov    -0x10(%ebp),%edx
 100400d:	8b 04 90             	mov    (%eax,%edx,4),%eax
 1004010:	8b 55 f0             	mov    -0x10(%ebp),%edx
 1004013:	89 d1                	mov    %edx,%ecx
 1004015:	c1 e1 04             	shl    $0x4,%ecx
 1004018:	8b 55 f4             	mov    -0xc(%ebp),%edx
 100401b:	c1 e2 04             	shl    $0x4,%edx
 100401e:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1004022:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 1004026:	89 54 24 04          	mov    %edx,0x4(%esp)
 100402a:	8b 45 08             	mov    0x8(%ebp),%eax
 100402d:	89 04 24             	mov    %eax,(%esp)
 1004030:	e8 0f ec ff ff       	call   1002c44 <_ZN5CGame12InsertObjectEiii>
 1004035:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 1004039:	83 7d f0 0f          	cmpl   $0xf,-0x10(%ebp)
 100403d:	0f 9e c0             	setle  %al
 1004040:	84 c0                	test   %al,%al
 1004042:	75 aa                	jne    1003fee <_ZN5CGame11LoadMapDataEv+0x6c>
 1004044:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 1004048:	83 7d f4 13          	cmpl   $0x13,-0xc(%ebp)
 100404c:	0f 9e c0             	setle  %al
 100404f:	84 c0                	test   %al,%al
 1004051:	75 92                	jne    1003fe5 <_ZN5CGame11LoadMapDataEv+0x63>
 1004053:	8b 45 08             	mov    0x8(%ebp),%eax
 1004056:	c7 40 0c 00 00 00 00 	movl   $0x0,0xc(%eax)
 100405d:	8b 45 08             	mov    0x8(%ebp),%eax
 1004060:	c7 40 10 14 00 00 00 	movl   $0x14,0x10(%eax)
 1004067:	c9                   	leave  
 1004068:	c3                   	ret    
 1004069:	90                   	nop

0100406a <_ZN5CGame7MoveMapEi>:
 100406a:	55                   	push   %ebp
 100406b:	89 e5                	mov    %esp,%ebp
 100406d:	56                   	push   %esi
 100406e:	53                   	push   %ebx
 100406f:	83 ec 30             	sub    $0x30,%esp
 1004072:	8b 45 08             	mov    0x8(%ebp),%eax
 1004075:	8b 40 0c             	mov    0xc(%eax),%eax
 1004078:	03 45 0c             	add    0xc(%ebp),%eax
 100407b:	89 45 f4             	mov    %eax,-0xc(%ebp)
 100407e:	8b 45 08             	mov    0x8(%ebp),%eax
 1004081:	8b 40 08             	mov    0x8(%eax),%eax
 1004084:	83 c0 08             	add    $0x8,%eax
 1004087:	8b 00                	mov    (%eax),%eax
 1004089:	83 e8 12             	sub    $0x12,%eax
 100408c:	c1 e0 04             	shl    $0x4,%eax
 100408f:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 1004092:	7d 14                	jge    10040a8 <_ZN5CGame7MoveMapEi+0x3e>
 1004094:	8b 45 08             	mov    0x8(%ebp),%eax
 1004097:	8b 40 08             	mov    0x8(%eax),%eax
 100409a:	83 c0 08             	add    $0x8,%eax
 100409d:	8b 00                	mov    (%eax),%eax
 100409f:	83 e8 12             	sub    $0x12,%eax
 10040a2:	c1 e0 04             	shl    $0x4,%eax
 10040a5:	89 45 f4             	mov    %eax,-0xc(%ebp)
 10040a8:	8b 45 08             	mov    0x8(%ebp),%eax
 10040ab:	8b 40 0c             	mov    0xc(%eax),%eax
 10040ae:	8b 55 f4             	mov    -0xc(%ebp),%edx
 10040b1:	89 d1                	mov    %edx,%ecx
 10040b3:	29 c1                	sub    %eax,%ecx
 10040b5:	89 c8                	mov    %ecx,%eax
 10040b7:	89 45 0c             	mov    %eax,0xc(%ebp)
 10040ba:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
 10040be:	0f 84 13 01 00 00    	je     10041d7 <_ZN5CGame7MoveMapEi+0x16d>
 10040c4:	8b 45 08             	mov    0x8(%ebp),%eax
 10040c7:	8b 55 f4             	mov    -0xc(%ebp),%edx
 10040ca:	89 50 0c             	mov    %edx,0xc(%eax)
 10040cd:	8b 45 08             	mov    0x8(%ebp),%eax
 10040d0:	83 c0 18             	add    $0x18,%eax
 10040d3:	89 45 f0             	mov    %eax,-0x10(%ebp)
 10040d6:	eb 17                	jmp    10040ef <_ZN5CGame7MoveMapEi+0x85>
 10040d8:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10040db:	8b 00                	mov    (%eax),%eax
 10040dd:	8b 55 f0             	mov    -0x10(%ebp),%edx
 10040e0:	8b 12                	mov    (%edx),%edx
 10040e2:	8b 52 0c             	mov    0xc(%edx),%edx
 10040e5:	2b 55 0c             	sub    0xc(%ebp),%edx
 10040e8:	89 50 0c             	mov    %edx,0xc(%eax)
 10040eb:	83 45 f0 04          	addl   $0x4,-0x10(%ebp)
 10040ef:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10040f2:	8b 00                	mov    (%eax),%eax
 10040f4:	85 c0                	test   %eax,%eax
 10040f6:	0f 95 c0             	setne  %al
 10040f9:	84 c0                	test   %al,%al
 10040fb:	75 db                	jne    10040d8 <_ZN5CGame7MoveMapEi+0x6e>
 10040fd:	8b 45 08             	mov    0x8(%ebp),%eax
 1004100:	8b 40 0c             	mov    0xc(%eax),%eax
 1004103:	05 2f 01 00 00       	add    $0x12f,%eax
 1004108:	89 c2                	mov    %eax,%edx
 100410a:	c1 fa 1f             	sar    $0x1f,%edx
 100410d:	c1 ea 1c             	shr    $0x1c,%edx
 1004110:	01 d0                	add    %edx,%eax
 1004112:	c1 f8 04             	sar    $0x4,%eax
 1004115:	83 c0 01             	add    $0x1,%eax
 1004118:	89 45 ec             	mov    %eax,-0x14(%ebp)
 100411b:	8b 45 08             	mov    0x8(%ebp),%eax
 100411e:	8b 40 08             	mov    0x8(%eax),%eax
 1004121:	83 c0 08             	add    $0x8,%eax
 1004124:	8b 00                	mov    (%eax),%eax
 1004126:	3b 45 ec             	cmp    -0x14(%ebp),%eax
 1004129:	7d 0c                	jge    1004137 <_ZN5CGame7MoveMapEi+0xcd>
 100412b:	8b 45 08             	mov    0x8(%ebp),%eax
 100412e:	8b 40 08             	mov    0x8(%eax),%eax
 1004131:	8b 40 08             	mov    0x8(%eax),%eax
 1004134:	89 45 ec             	mov    %eax,-0x14(%ebp)
 1004137:	8b 45 08             	mov    0x8(%ebp),%eax
 100413a:	8b 40 08             	mov    0x8(%eax),%eax
 100413d:	83 c0 0c             	add    $0xc,%eax
 1004140:	89 45 e0             	mov    %eax,-0x20(%ebp)
 1004143:	8b 45 08             	mov    0x8(%ebp),%eax
 1004146:	8b 40 10             	mov    0x10(%eax),%eax
 1004149:	89 45 e8             	mov    %eax,-0x18(%ebp)
 100414c:	eb 71                	jmp    10041bf <_ZN5CGame7MoveMapEi+0x155>
 100414e:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%ebp)
 1004155:	eb 59                	jmp    10041b0 <_ZN5CGame7MoveMapEi+0x146>
 1004157:	8b 45 e8             	mov    -0x18(%ebp),%eax
 100415a:	c1 e0 06             	shl    $0x6,%eax
 100415d:	03 45 e0             	add    -0x20(%ebp),%eax
 1004160:	8b 55 e4             	mov    -0x1c(%ebp),%edx
 1004163:	8b 04 90             	mov    (%eax,%edx,4),%eax
 1004166:	85 c0                	test   %eax,%eax
 1004168:	74 42                	je     10041ac <_ZN5CGame7MoveMapEi+0x142>
 100416a:	8b 45 e8             	mov    -0x18(%ebp),%eax
 100416d:	c1 e0 06             	shl    $0x6,%eax
 1004170:	03 45 e0             	add    -0x20(%ebp),%eax
 1004173:	8b 55 e4             	mov    -0x1c(%ebp),%edx
 1004176:	8b 04 90             	mov    (%eax,%edx,4),%eax
 1004179:	8b 55 e4             	mov    -0x1c(%ebp),%edx
 100417c:	89 d1                	mov    %edx,%ecx
 100417e:	c1 e1 04             	shl    $0x4,%ecx
 1004181:	8b 55 e8             	mov    -0x18(%ebp),%edx
 1004184:	89 d3                	mov    %edx,%ebx
 1004186:	c1 e3 04             	shl    $0x4,%ebx
 1004189:	8b 55 08             	mov    0x8(%ebp),%edx
 100418c:	8b 52 0c             	mov    0xc(%edx),%edx
 100418f:	89 de                	mov    %ebx,%esi
 1004191:	29 d6                	sub    %edx,%esi
 1004193:	89 f2                	mov    %esi,%edx
 1004195:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1004199:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 100419d:	89 54 24 04          	mov    %edx,0x4(%esp)
 10041a1:	8b 45 08             	mov    0x8(%ebp),%eax
 10041a4:	89 04 24             	mov    %eax,(%esp)
 10041a7:	e8 98 ea ff ff       	call   1002c44 <_ZN5CGame12InsertObjectEiii>
 10041ac:	83 45 e4 01          	addl   $0x1,-0x1c(%ebp)
 10041b0:	83 7d e4 0f          	cmpl   $0xf,-0x1c(%ebp)
 10041b4:	0f 9e c0             	setle  %al
 10041b7:	84 c0                	test   %al,%al
 10041b9:	75 9c                	jne    1004157 <_ZN5CGame7MoveMapEi+0xed>
 10041bb:	83 45 e8 01          	addl   $0x1,-0x18(%ebp)
 10041bf:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10041c2:	3b 45 ec             	cmp    -0x14(%ebp),%eax
 10041c5:	0f 9c c0             	setl   %al
 10041c8:	84 c0                	test   %al,%al
 10041ca:	75 82                	jne    100414e <_ZN5CGame7MoveMapEi+0xe4>
 10041cc:	8b 45 08             	mov    0x8(%ebp),%eax
 10041cf:	8b 55 ec             	mov    -0x14(%ebp),%edx
 10041d2:	89 50 10             	mov    %edx,0x10(%eax)
 10041d5:	eb 01                	jmp    10041d8 <_ZN5CGame7MoveMapEi+0x16e>
 10041d7:	90                   	nop
 10041d8:	83 c4 30             	add    $0x30,%esp
 10041db:	5b                   	pop    %ebx
 10041dc:	5e                   	pop    %esi
 10041dd:	5d                   	pop    %ebp
 10041de:	c3                   	ret    
 10041df:	90                   	nop

010041e0 <_ZN5CGame6AddObjEP7CObject>:
 10041e0:	55                   	push   %ebp
 10041e1:	89 e5                	mov    %esp,%ebp
 10041e3:	83 ec 08             	sub    $0x8,%esp
 10041e6:	8b 45 0c             	mov    0xc(%ebp),%eax
 10041e9:	89 44 24 04          	mov    %eax,0x4(%esp)
 10041ed:	8b 45 08             	mov    0x8(%ebp),%eax
 10041f0:	89 04 24             	mov    %eax,(%esp)
 10041f3:	e8 e4 e8 ff ff       	call   1002adc <_ZN5CGame15m_Object_insertEP7CObject>
 10041f8:	c9                   	leave  
 10041f9:	c3                   	ret    

010041fa <_ZN5CGame8SetSoundEP9CSoundMan>:
 10041fa:	55                   	push   %ebp
 10041fb:	89 e5                	mov    %esp,%ebp
 10041fd:	8b 45 08             	mov    0x8(%ebp),%eax
 1004200:	8b 55 0c             	mov    0xc(%ebp),%edx
 1004203:	89 50 14             	mov    %edx,0x14(%eax)
 1004206:	5d                   	pop    %ebp
 1004207:	c3                   	ret    

01004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>:
 1004208:	55                   	push   %ebp
 1004209:	89 e5                	mov    %esp,%ebp
 100420b:	83 ec 18             	sub    $0x18,%esp
 100420e:	8b 45 08             	mov    0x8(%ebp),%eax
 1004211:	8b 40 14             	mov    0x14(%eax),%eax
 1004214:	8b 55 0c             	mov    0xc(%ebp),%edx
 1004217:	89 54 24 04          	mov    %edx,0x4(%esp)
 100421b:	89 04 24             	mov    %eax,(%esp)
 100421e:	e8 dd 21 00 00       	call   1006400 <_ZN9CSoundMan9PlaySoundENS_8SOUNDNUME>
 1004223:	c9                   	leave  
 1004224:	c3                   	ret    
 1004225:	90                   	nop

01004226 <_ZN5CGame13PlayBackMusicEi>:
 1004226:	55                   	push   %ebp
 1004227:	89 e5                	mov    %esp,%ebp
 1004229:	83 ec 18             	sub    $0x18,%esp
 100422c:	8b 45 08             	mov    0x8(%ebp),%eax
 100422f:	8b 40 14             	mov    0x14(%eax),%eax
 1004232:	8b 55 0c             	mov    0xc(%ebp),%edx
 1004235:	89 54 24 04          	mov    %edx,0x4(%esp)
 1004239:	89 04 24             	mov    %eax,(%esp)
 100423c:	e8 47 21 00 00       	call   1006388 <_ZN9CSoundMan13PlayBackMusicEi>
 1004241:	c9                   	leave  
 1004242:	c3                   	ret    

01004243 <_Z6memsetPvci>:
 1004243:	55                   	push   %ebp
 1004244:	89 e5                	mov    %esp,%ebp
 1004246:	57                   	push   %edi
 1004247:	83 ec 04             	sub    $0x4,%esp
 100424a:	8b 45 0c             	mov    0xc(%ebp),%eax
 100424d:	88 45 f8             	mov    %al,-0x8(%ebp)
 1004250:	0f b6 45 f8          	movzbl -0x8(%ebp),%eax
 1004254:	8b 55 08             	mov    0x8(%ebp),%edx
 1004257:	8b 4d 10             	mov    0x10(%ebp),%ecx
 100425a:	89 d7                	mov    %edx,%edi
 100425c:	fc                   	cld    
 100425d:	f3 aa                	rep stos %al,%es:(%edi)
 100425f:	8b 45 08             	mov    0x8(%ebp),%eax
 1004262:	83 c4 04             	add    $0x4,%esp
 1004265:	5f                   	pop    %edi
 1004266:	5d                   	pop    %ebp
 1004267:	c3                   	ret    

01004268 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_>:
 1004268:	55                   	push   %ebp
 1004269:	89 e5                	mov    %esp,%ebp
 100426b:	8b 45 08             	mov    0x8(%ebp),%eax
 100426e:	0f b6 00             	movzbl (%eax),%eax
 1004271:	84 c0                	test   %al,%al
 1004273:	74 34                	je     10042a9 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0x41>
 1004275:	8b 45 10             	mov    0x10(%ebp),%eax
 1004278:	8b 50 04             	mov    0x4(%eax),%edx
 100427b:	8b 45 0c             	mov    0xc(%ebp),%eax
 100427e:	8b 40 04             	mov    0x4(%eax),%eax
 1004281:	39 c2                	cmp    %eax,%edx
 1004283:	7e 0a                	jle    100428f <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0x27>
 1004285:	b8 01 00 00 00       	mov    $0x1,%eax
 100428a:	e9 da 00 00 00       	jmp    1004369 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0x101>
 100428f:	8b 45 10             	mov    0x10(%ebp),%eax
 1004292:	8b 50 04             	mov    0x4(%eax),%edx
 1004295:	8b 45 0c             	mov    0xc(%ebp),%eax
 1004298:	8b 40 04             	mov    0x4(%eax),%eax
 100429b:	39 c2                	cmp    %eax,%edx
 100429d:	7d 3e                	jge    10042dd <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0x75>
 100429f:	b8 00 00 00 00       	mov    $0x0,%eax
 10042a4:	e9 c0 00 00 00       	jmp    1004369 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0x101>
 10042a9:	8b 45 10             	mov    0x10(%ebp),%eax
 10042ac:	8b 50 04             	mov    0x4(%eax),%edx
 10042af:	8b 45 0c             	mov    0xc(%ebp),%eax
 10042b2:	8b 40 04             	mov    0x4(%eax),%eax
 10042b5:	39 c2                	cmp    %eax,%edx
 10042b7:	7d 0a                	jge    10042c3 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0x5b>
 10042b9:	b8 01 00 00 00       	mov    $0x1,%eax
 10042be:	e9 a6 00 00 00       	jmp    1004369 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0x101>
 10042c3:	8b 45 10             	mov    0x10(%ebp),%eax
 10042c6:	8b 50 04             	mov    0x4(%eax),%edx
 10042c9:	8b 45 0c             	mov    0xc(%ebp),%eax
 10042cc:	8b 40 04             	mov    0x4(%eax),%eax
 10042cf:	39 c2                	cmp    %eax,%edx
 10042d1:	7e 0a                	jle    10042dd <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0x75>
 10042d3:	b8 00 00 00 00       	mov    $0x0,%eax
 10042d8:	e9 8c 00 00 00       	jmp    1004369 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0x101>
 10042dd:	8b 45 08             	mov    0x8(%ebp),%eax
 10042e0:	0f b6 40 01          	movzbl 0x1(%eax),%eax
 10042e4:	84 c0                	test   %al,%al
 10042e6:	74 2e                	je     1004316 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0xae>
 10042e8:	8b 45 10             	mov    0x10(%ebp),%eax
 10042eb:	8b 50 08             	mov    0x8(%eax),%edx
 10042ee:	8b 45 0c             	mov    0xc(%ebp),%eax
 10042f1:	8b 40 08             	mov    0x8(%eax),%eax
 10042f4:	39 c2                	cmp    %eax,%edx
 10042f6:	7e 07                	jle    10042ff <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0x97>
 10042f8:	b8 01 00 00 00       	mov    $0x1,%eax
 10042fd:	eb 6a                	jmp    1004369 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0x101>
 10042ff:	8b 45 10             	mov    0x10(%ebp),%eax
 1004302:	8b 50 08             	mov    0x8(%eax),%edx
 1004305:	8b 45 0c             	mov    0xc(%ebp),%eax
 1004308:	8b 40 08             	mov    0x8(%eax),%eax
 100430b:	39 c2                	cmp    %eax,%edx
 100430d:	7d 35                	jge    1004344 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0xdc>
 100430f:	b8 00 00 00 00       	mov    $0x0,%eax
 1004314:	eb 53                	jmp    1004369 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0x101>
 1004316:	8b 45 10             	mov    0x10(%ebp),%eax
 1004319:	8b 50 08             	mov    0x8(%eax),%edx
 100431c:	8b 45 0c             	mov    0xc(%ebp),%eax
 100431f:	8b 40 08             	mov    0x8(%eax),%eax
 1004322:	39 c2                	cmp    %eax,%edx
 1004324:	7d 07                	jge    100432d <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0xc5>
 1004326:	b8 01 00 00 00       	mov    $0x1,%eax
 100432b:	eb 3c                	jmp    1004369 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0x101>
 100432d:	8b 45 10             	mov    0x10(%ebp),%eax
 1004330:	8b 50 08             	mov    0x8(%eax),%edx
 1004333:	8b 45 0c             	mov    0xc(%ebp),%eax
 1004336:	8b 40 08             	mov    0x8(%eax),%eax
 1004339:	39 c2                	cmp    %eax,%edx
 100433b:	7e 07                	jle    1004344 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0xdc>
 100433d:	b8 00 00 00 00       	mov    $0x0,%eax
 1004342:	eb 25                	jmp    1004369 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0x101>
 1004344:	8b 45 10             	mov    0x10(%ebp),%eax
 1004347:	0f b6 40 14          	movzbl 0x14(%eax),%eax
 100434b:	83 f0 01             	xor    $0x1,%eax
 100434e:	84 c0                	test   %al,%al
 1004350:	74 12                	je     1004364 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0xfc>
 1004352:	8b 45 0c             	mov    0xc(%ebp),%eax
 1004355:	0f b6 40 14          	movzbl 0x14(%eax),%eax
 1004359:	84 c0                	test   %al,%al
 100435b:	74 07                	je     1004364 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0xfc>
 100435d:	b8 01 00 00 00       	mov    $0x1,%eax
 1004362:	eb 05                	jmp    1004369 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_+0x101>
 1004364:	b8 00 00 00 00       	mov    $0x0,%eax
 1004369:	5d                   	pop    %ebp
 100436a:	c3                   	ret    
	...

0100436c <_ZN16bipriority_queue4initEP16BLOCKINFOCompare>:
 100436c:	55                   	push   %ebp
 100436d:	89 e5                	mov    %esp,%ebp
 100436f:	83 ec 18             	sub    $0x18,%esp
 1004372:	8b 45 08             	mov    0x8(%ebp),%eax
 1004375:	8b 55 0c             	mov    0xc(%ebp),%edx
 1004378:	89 90 64 09 00 00    	mov    %edx,0x964(%eax)
 100437e:	8b 45 08             	mov    0x8(%ebp),%eax
 1004381:	c7 80 60 09 00 00 00 	movl   $0x0,0x960(%eax)
 1004388:	00 00 00 
 100438b:	8b 45 08             	mov    0x8(%ebp),%eax
 100438e:	c7 44 24 08 60 09 00 	movl   $0x960,0x8(%esp)
 1004395:	00 
 1004396:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 100439d:	00 
 100439e:	89 04 24             	mov    %eax,(%esp)
 10043a1:	e8 9d fe ff ff       	call   1004243 <_Z6memsetPvci>
 10043a6:	c9                   	leave  
 10043a7:	c3                   	ret    

010043a8 <_ZN16bipriority_queue3topEv>:
 10043a8:	55                   	push   %ebp
 10043a9:	89 e5                	mov    %esp,%ebp
 10043ab:	53                   	push   %ebx
 10043ac:	83 ec 24             	sub    $0x24,%esp
 10043af:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 10043b6:	8b 45 0c             	mov    0xc(%ebp),%eax
 10043b9:	8b 80 60 09 00 00    	mov    0x960(%eax),%eax
 10043bf:	85 c0                	test   %eax,%eax
 10043c1:	75 0c                	jne    10043cf <_ZN16bipriority_queue3topEv+0x27>
 10043c3:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 10043ca:	e8 4f 2f 00 00       	call   100731e <exit>
 10043cf:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 10043d6:	eb 49                	jmp    1004421 <_ZN16bipriority_queue3topEv+0x79>
 10043d8:	8b 55 f4             	mov    -0xc(%ebp),%edx
 10043db:	89 d0                	mov    %edx,%eax
 10043dd:	01 c0                	add    %eax,%eax
 10043df:	01 d0                	add    %edx,%eax
 10043e1:	c1 e0 03             	shl    $0x3,%eax
 10043e4:	89 c1                	mov    %eax,%ecx
 10043e6:	03 4d 0c             	add    0xc(%ebp),%ecx
 10043e9:	8b 55 f0             	mov    -0x10(%ebp),%edx
 10043ec:	89 d0                	mov    %edx,%eax
 10043ee:	01 c0                	add    %eax,%eax
 10043f0:	01 d0                	add    %edx,%eax
 10043f2:	c1 e0 03             	shl    $0x3,%eax
 10043f5:	89 c2                	mov    %eax,%edx
 10043f7:	03 55 0c             	add    0xc(%ebp),%edx
 10043fa:	8b 45 0c             	mov    0xc(%ebp),%eax
 10043fd:	8b 80 64 09 00 00    	mov    0x964(%eax),%eax
 1004403:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 1004407:	89 54 24 04          	mov    %edx,0x4(%esp)
 100440b:	89 04 24             	mov    %eax,(%esp)
 100440e:	e8 55 fe ff ff       	call   1004268 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_>
 1004413:	84 c0                	test   %al,%al
 1004415:	74 06                	je     100441d <_ZN16bipriority_queue3topEv+0x75>
 1004417:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100441a:	89 45 f0             	mov    %eax,-0x10(%ebp)
 100441d:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 1004421:	8b 45 0c             	mov    0xc(%ebp),%eax
 1004424:	8b 80 60 09 00 00    	mov    0x960(%eax),%eax
 100442a:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 100442d:	0f 9f c0             	setg   %al
 1004430:	84 c0                	test   %al,%al
 1004432:	75 a4                	jne    10043d8 <_ZN16bipriority_queue3topEv+0x30>
 1004434:	8b 55 08             	mov    0x8(%ebp),%edx
 1004437:	8b 5d 0c             	mov    0xc(%ebp),%ebx
 100443a:	8b 4d f0             	mov    -0x10(%ebp),%ecx
 100443d:	89 c8                	mov    %ecx,%eax
 100443f:	01 c0                	add    %eax,%eax
 1004441:	01 c8                	add    %ecx,%eax
 1004443:	c1 e0 03             	shl    $0x3,%eax
 1004446:	01 d8                	add    %ebx,%eax
 1004448:	8b 08                	mov    (%eax),%ecx
 100444a:	89 0a                	mov    %ecx,(%edx)
 100444c:	8b 48 04             	mov    0x4(%eax),%ecx
 100444f:	89 4a 04             	mov    %ecx,0x4(%edx)
 1004452:	8b 48 08             	mov    0x8(%eax),%ecx
 1004455:	89 4a 08             	mov    %ecx,0x8(%edx)
 1004458:	8b 48 0c             	mov    0xc(%eax),%ecx
 100445b:	89 4a 0c             	mov    %ecx,0xc(%edx)
 100445e:	8b 48 10             	mov    0x10(%eax),%ecx
 1004461:	89 4a 10             	mov    %ecx,0x10(%edx)
 1004464:	8b 40 14             	mov    0x14(%eax),%eax
 1004467:	89 42 14             	mov    %eax,0x14(%edx)
 100446a:	8b 45 08             	mov    0x8(%ebp),%eax
 100446d:	83 c4 24             	add    $0x24,%esp
 1004470:	5b                   	pop    %ebx
 1004471:	5d                   	pop    %ebp
 1004472:	c2 04 00             	ret    $0x4
	...

01004476 <_ZN16bipriority_queue3popEv>:
 1004476:	55                   	push   %ebp
 1004477:	89 e5                	mov    %esp,%ebp
 1004479:	53                   	push   %ebx
 100447a:	83 ec 24             	sub    $0x24,%esp
 100447d:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 1004484:	8b 45 08             	mov    0x8(%ebp),%eax
 1004487:	8b 80 60 09 00 00    	mov    0x960(%eax),%eax
 100448d:	85 c0                	test   %eax,%eax
 100448f:	0f 84 e3 00 00 00    	je     1004578 <_ZN16bipriority_queue3popEv+0x102>
 1004495:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 100449c:	eb 49                	jmp    10044e7 <_ZN16bipriority_queue3popEv+0x71>
 100449e:	8b 55 f4             	mov    -0xc(%ebp),%edx
 10044a1:	89 d0                	mov    %edx,%eax
 10044a3:	01 c0                	add    %eax,%eax
 10044a5:	01 d0                	add    %edx,%eax
 10044a7:	c1 e0 03             	shl    $0x3,%eax
 10044aa:	89 c1                	mov    %eax,%ecx
 10044ac:	03 4d 08             	add    0x8(%ebp),%ecx
 10044af:	8b 55 f0             	mov    -0x10(%ebp),%edx
 10044b2:	89 d0                	mov    %edx,%eax
 10044b4:	01 c0                	add    %eax,%eax
 10044b6:	01 d0                	add    %edx,%eax
 10044b8:	c1 e0 03             	shl    $0x3,%eax
 10044bb:	89 c2                	mov    %eax,%edx
 10044bd:	03 55 08             	add    0x8(%ebp),%edx
 10044c0:	8b 45 08             	mov    0x8(%ebp),%eax
 10044c3:	8b 80 64 09 00 00    	mov    0x964(%eax),%eax
 10044c9:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 10044cd:	89 54 24 04          	mov    %edx,0x4(%esp)
 10044d1:	89 04 24             	mov    %eax,(%esp)
 10044d4:	e8 8f fd ff ff       	call   1004268 <_ZN16BLOCKINFOCompareclERK9BLOCKINFOS2_>
 10044d9:	84 c0                	test   %al,%al
 10044db:	74 06                	je     10044e3 <_ZN16bipriority_queue3popEv+0x6d>
 10044dd:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10044e0:	89 45 f0             	mov    %eax,-0x10(%ebp)
 10044e3:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 10044e7:	8b 45 08             	mov    0x8(%ebp),%eax
 10044ea:	8b 80 60 09 00 00    	mov    0x960(%eax),%eax
 10044f0:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 10044f3:	0f 9f c0             	setg   %al
 10044f6:	84 c0                	test   %al,%al
 10044f8:	75 a4                	jne    100449e <_ZN16bipriority_queue3popEv+0x28>
 10044fa:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10044fd:	89 45 f4             	mov    %eax,-0xc(%ebp)
 1004500:	eb 4c                	jmp    100454e <_ZN16bipriority_queue3popEv+0xd8>
 1004502:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1004505:	8d 48 01             	lea    0x1(%eax),%ecx
 1004508:	8b 5d 08             	mov    0x8(%ebp),%ebx
 100450b:	8b 55 f4             	mov    -0xc(%ebp),%edx
 100450e:	89 d0                	mov    %edx,%eax
 1004510:	01 c0                	add    %eax,%eax
 1004512:	01 d0                	add    %edx,%eax
 1004514:	c1 e0 03             	shl    $0x3,%eax
 1004517:	8d 14 03             	lea    (%ebx,%eax,1),%edx
 100451a:	8b 5d 08             	mov    0x8(%ebp),%ebx
 100451d:	89 c8                	mov    %ecx,%eax
 100451f:	01 c0                	add    %eax,%eax
 1004521:	01 c8                	add    %ecx,%eax
 1004523:	c1 e0 03             	shl    $0x3,%eax
 1004526:	01 d8                	add    %ebx,%eax
 1004528:	8b 08                	mov    (%eax),%ecx
 100452a:	89 0a                	mov    %ecx,(%edx)
 100452c:	8b 48 04             	mov    0x4(%eax),%ecx
 100452f:	89 4a 04             	mov    %ecx,0x4(%edx)
 1004532:	8b 48 08             	mov    0x8(%eax),%ecx
 1004535:	89 4a 08             	mov    %ecx,0x8(%edx)
 1004538:	8b 48 0c             	mov    0xc(%eax),%ecx
 100453b:	89 4a 0c             	mov    %ecx,0xc(%edx)
 100453e:	8b 48 10             	mov    0x10(%eax),%ecx
 1004541:	89 4a 10             	mov    %ecx,0x10(%edx)
 1004544:	8b 40 14             	mov    0x14(%eax),%eax
 1004547:	89 42 14             	mov    %eax,0x14(%edx)
 100454a:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 100454e:	8b 45 08             	mov    0x8(%ebp),%eax
 1004551:	8b 80 60 09 00 00    	mov    0x960(%eax),%eax
 1004557:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 100455a:	0f 9f c0             	setg   %al
 100455d:	84 c0                	test   %al,%al
 100455f:	75 a1                	jne    1004502 <_ZN16bipriority_queue3popEv+0x8c>
 1004561:	8b 45 08             	mov    0x8(%ebp),%eax
 1004564:	8b 80 60 09 00 00    	mov    0x960(%eax),%eax
 100456a:	8d 50 ff             	lea    -0x1(%eax),%edx
 100456d:	8b 45 08             	mov    0x8(%ebp),%eax
 1004570:	89 90 60 09 00 00    	mov    %edx,0x960(%eax)
 1004576:	eb 01                	jmp    1004579 <_ZN16bipriority_queue3popEv+0x103>
 1004578:	90                   	nop
 1004579:	83 c4 24             	add    $0x24,%esp
 100457c:	5b                   	pop    %ebx
 100457d:	5d                   	pop    %ebp
 100457e:	c3                   	ret    
	...

01004580 <_ZN16bipriority_queue4pushER9BLOCKINFO>:
 1004580:	55                   	push   %ebp
 1004581:	89 e5                	mov    %esp,%ebp
 1004583:	53                   	push   %ebx
 1004584:	83 ec 24             	sub    $0x24,%esp
 1004587:	8b 45 08             	mov    0x8(%ebp),%eax
 100458a:	8b 80 60 09 00 00    	mov    0x960(%eax),%eax
 1004590:	83 f8 63             	cmp    $0x63,%eax
 1004593:	75 0c                	jne    10045a1 <_ZN16bipriority_queue4pushER9BLOCKINFO+0x21>
 1004595:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
 100459c:	e8 7d 2d 00 00       	call   100731e <exit>
 10045a1:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 10045a8:	eb 20                	jmp    10045ca <_ZN16bipriority_queue4pushER9BLOCKINFO+0x4a>
 10045aa:	8b 45 0c             	mov    0xc(%ebp),%eax
 10045ad:	8b 08                	mov    (%eax),%ecx
 10045af:	8b 5d 08             	mov    0x8(%ebp),%ebx
 10045b2:	8b 55 f4             	mov    -0xc(%ebp),%edx
 10045b5:	89 d0                	mov    %edx,%eax
 10045b7:	01 c0                	add    %eax,%eax
 10045b9:	01 d0                	add    %edx,%eax
 10045bb:	c1 e0 03             	shl    $0x3,%eax
 10045be:	01 d8                	add    %ebx,%eax
 10045c0:	8b 00                	mov    (%eax),%eax
 10045c2:	39 c1                	cmp    %eax,%ecx
 10045c4:	74 64                	je     100462a <_ZN16bipriority_queue4pushER9BLOCKINFO+0xaa>
 10045c6:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 10045ca:	8b 45 08             	mov    0x8(%ebp),%eax
 10045cd:	8b 80 60 09 00 00    	mov    0x960(%eax),%eax
 10045d3:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 10045d6:	0f 9f c0             	setg   %al
 10045d9:	84 c0                	test   %al,%al
 10045db:	75 cd                	jne    10045aa <_ZN16bipriority_queue4pushER9BLOCKINFO+0x2a>
 10045dd:	8b 45 08             	mov    0x8(%ebp),%eax
 10045e0:	8b 88 60 09 00 00    	mov    0x960(%eax),%ecx
 10045e6:	89 ca                	mov    %ecx,%edx
 10045e8:	8b 5d 08             	mov    0x8(%ebp),%ebx
 10045eb:	89 d0                	mov    %edx,%eax
 10045ed:	01 c0                	add    %eax,%eax
 10045ef:	01 d0                	add    %edx,%eax
 10045f1:	c1 e0 03             	shl    $0x3,%eax
 10045f4:	8d 14 03             	lea    (%ebx,%eax,1),%edx
 10045f7:	8b 45 0c             	mov    0xc(%ebp),%eax
 10045fa:	8b 18                	mov    (%eax),%ebx
 10045fc:	89 1a                	mov    %ebx,(%edx)
 10045fe:	8b 58 04             	mov    0x4(%eax),%ebx
 1004601:	89 5a 04             	mov    %ebx,0x4(%edx)
 1004604:	8b 58 08             	mov    0x8(%eax),%ebx
 1004607:	89 5a 08             	mov    %ebx,0x8(%edx)
 100460a:	8b 58 0c             	mov    0xc(%eax),%ebx
 100460d:	89 5a 0c             	mov    %ebx,0xc(%edx)
 1004610:	8b 58 10             	mov    0x10(%eax),%ebx
 1004613:	89 5a 10             	mov    %ebx,0x10(%edx)
 1004616:	8b 40 14             	mov    0x14(%eax),%eax
 1004619:	89 42 14             	mov    %eax,0x14(%edx)
 100461c:	8d 51 01             	lea    0x1(%ecx),%edx
 100461f:	8b 45 08             	mov    0x8(%ebp),%eax
 1004622:	89 90 60 09 00 00    	mov    %edx,0x960(%eax)
 1004628:	eb 01                	jmp    100462b <_ZN16bipriority_queue4pushER9BLOCKINFO+0xab>
 100462a:	90                   	nop
 100462b:	83 c4 24             	add    $0x24,%esp
 100462e:	5b                   	pop    %ebx
 100462f:	5d                   	pop    %ebp
 1004630:	c3                   	ret    
	...

01004632 <_ZN16bipriority_queue5emptyEv>:
 1004632:	55                   	push   %ebp
 1004633:	89 e5                	mov    %esp,%ebp
 1004635:	8b 45 08             	mov    0x8(%ebp),%eax
 1004638:	8b 80 60 09 00 00    	mov    0x960(%eax),%eax
 100463e:	85 c0                	test   %eax,%eax
 1004640:	0f 94 c0             	sete   %al
 1004643:	5d                   	pop    %ebp
 1004644:	c3                   	ret    
 1004645:	00 00                	add    %al,(%eax)
	...

01004648 <_ZN6CGraph8GetMemDCEv>:
 1004648:	55                   	push   %ebp
 1004649:	89 e5                	mov    %esp,%ebp
 100464b:	8b 45 08             	mov    0x8(%ebp),%eax
 100464e:	8b 40 04             	mov    0x4(%eax),%eax
 1004651:	5d                   	pop    %ebp
 1004652:	c3                   	ret    
 1004653:	90                   	nop

01004654 <_ZN6CGraph11GetImageBufEv>:
 1004654:	55                   	push   %ebp
 1004655:	89 e5                	mov    %esp,%ebp
 1004657:	8b 45 08             	mov    0x8(%ebp),%eax
 100465a:	83 c0 08             	add    $0x8,%eax
 100465d:	5d                   	pop    %ebp
 100465e:	c3                   	ret    
 100465f:	90                   	nop

01004660 <_ZN6CGraph7RefreshEv>:
 1004660:	55                   	push   %ebp
 1004661:	89 e5                	mov    %esp,%ebp
 1004663:	83 ec 38             	sub    $0x38,%esp
 1004666:	c7 45 e8 20 01 00 00 	movl   $0x120,-0x18(%ebp)
 100466d:	c7 45 e4 00 01 00 00 	movl   $0x100,-0x1c(%ebp)
 1004674:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1004677:	83 e8 01             	sub    $0x1,%eax
 100467a:	89 45 f4             	mov    %eax,-0xc(%ebp)
 100467d:	e9 87 00 00 00       	jmp    1004709 <_ZN6CGraph7RefreshEv+0xa9>
 1004682:	8b 45 08             	mov    0x8(%ebp),%eax
 1004685:	8b 55 f4             	mov    -0xc(%ebp),%edx
 1004688:	8b 44 90 08          	mov    0x8(%eax,%edx,4),%eax
 100468c:	89 45 ec             	mov    %eax,-0x14(%ebp)
 100468f:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 1004696:	eb 60                	jmp    10046f8 <_ZN6CGraph7RefreshEv+0x98>
 1004698:	8b 45 ec             	mov    -0x14(%ebp),%eax
 100469b:	0f b6 40 02          	movzbl 0x2(%eax),%eax
 100469f:	c0 e8 03             	shr    $0x3,%al
 10046a2:	0f b6 c0             	movzbl %al,%eax
 10046a5:	89 c2                	mov    %eax,%edx
 10046a7:	c1 e2 0b             	shl    $0xb,%edx
 10046aa:	8b 45 ec             	mov    -0x14(%ebp),%eax
 10046ad:	0f b6 40 01          	movzbl 0x1(%eax),%eax
 10046b1:	c0 e8 02             	shr    $0x2,%al
 10046b4:	0f b6 c0             	movzbl %al,%eax
 10046b7:	c1 e0 05             	shl    $0x5,%eax
 10046ba:	01 c2                	add    %eax,%edx
 10046bc:	8b 45 ec             	mov    -0x14(%ebp),%eax
 10046bf:	0f b6 00             	movzbl (%eax),%eax
 10046c2:	c0 e8 03             	shr    $0x3,%al
 10046c5:	0f b6 c0             	movzbl %al,%eax
 10046c8:	01 d0                	add    %edx,%eax
 10046ca:	66 89 45 e2          	mov    %ax,-0x1e(%ebp)
 10046ce:	0f b7 4d e2          	movzwl -0x1e(%ebp),%ecx
 10046d2:	8b 55 f4             	mov    -0xc(%ebp),%edx
 10046d5:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10046d8:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 10046dc:	89 54 24 08          	mov    %edx,0x8(%esp)
 10046e0:	89 44 24 04          	mov    %eax,0x4(%esp)
 10046e4:	c7 04 24 c0 fd 02 01 	movl   $0x102fdc0,(%esp)
 10046eb:	e8 4d bb ff ff       	call   100023d <draw_set_point>
 10046f0:	83 45 ec 04          	addl   $0x4,-0x14(%ebp)
 10046f4:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 10046f8:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10046fb:	3b 45 e8             	cmp    -0x18(%ebp),%eax
 10046fe:	0f 9c c0             	setl   %al
 1004701:	84 c0                	test   %al,%al
 1004703:	75 93                	jne    1004698 <_ZN6CGraph7RefreshEv+0x38>
 1004705:	83 6d f4 01          	subl   $0x1,-0xc(%ebp)
 1004709:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100470c:	f7 d0                	not    %eax
 100470e:	c1 e8 1f             	shr    $0x1f,%eax
 1004711:	84 c0                	test   %al,%al
 1004713:	0f 85 69 ff ff ff    	jne    1004682 <_ZN6CGraph7RefreshEv+0x22>
 1004719:	c9                   	leave  
 100471a:	c3                   	ret    
 100471b:	90                   	nop

0100471c <_ZN6CGraph4InitEj>:
 100471c:	55                   	push   %ebp
 100471d:	89 e5                	mov    %esp,%ebp
 100471f:	83 ec 28             	sub    $0x28,%esp
 1004722:	8b 45 08             	mov    0x8(%ebp),%eax
 1004725:	8b 55 0c             	mov    0xc(%ebp),%edx
 1004728:	89 10                	mov    %edx,(%eax)
 100472a:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 1004731:	eb 1a                	jmp    100474d <_ZN6CGraph4InitEj+0x31>
 1004733:	c7 04 24 80 04 00 00 	movl   $0x480,(%esp)
 100473a:	e8 30 ba ff ff       	call   100016f <_Znaj>
 100473f:	8b 55 08             	mov    0x8(%ebp),%edx
 1004742:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 1004745:	89 44 8a 08          	mov    %eax,0x8(%edx,%ecx,4)
 1004749:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 100474d:	81 7d f4 ff 00 00 00 	cmpl   $0xff,-0xc(%ebp)
 1004754:	0f 9e c0             	setle  %al
 1004757:	84 c0                	test   %al,%al
 1004759:	75 d8                	jne    1004733 <_ZN6CGraph4InitEj+0x17>
 100475b:	c9                   	leave  
 100475c:	c3                   	ret    
 100475d:	90                   	nop

0100475e <_ZN6CGraph6UnInitEv>:
 100475e:	55                   	push   %ebp
 100475f:	89 e5                	mov    %esp,%ebp
 1004761:	83 ec 28             	sub    $0x28,%esp
 1004764:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 100476b:	eb 24                	jmp    1004791 <_ZN6CGraph6UnInitEv+0x33>
 100476d:	8b 45 08             	mov    0x8(%ebp),%eax
 1004770:	8b 55 f4             	mov    -0xc(%ebp),%edx
 1004773:	8b 44 90 08          	mov    0x8(%eax,%edx,4),%eax
 1004777:	85 c0                	test   %eax,%eax
 1004779:	74 12                	je     100478d <_ZN6CGraph6UnInitEv+0x2f>
 100477b:	8b 45 08             	mov    0x8(%ebp),%eax
 100477e:	8b 55 f4             	mov    -0xc(%ebp),%edx
 1004781:	8b 44 90 08          	mov    0x8(%eax,%edx,4),%eax
 1004785:	89 04 24             	mov    %eax,(%esp)
 1004788:	e8 fb b9 ff ff       	call   1000188 <_ZdaPv>
 100478d:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 1004791:	81 7d f4 ff 00 00 00 	cmpl   $0xff,-0xc(%ebp)
 1004798:	0f 9e c0             	setle  %al
 100479b:	84 c0                	test   %al,%al
 100479d:	75 ce                	jne    100476d <_ZN6CGraph6UnInitEv+0xf>
 100479f:	c9                   	leave  
 10047a0:	c3                   	ret    
 10047a1:	90                   	nop

010047a2 <_ZN6CGraph8ShowTextEiiPKci>:
 10047a2:	55                   	push   %ebp
 10047a3:	89 e5                	mov    %esp,%ebp
 10047a5:	5d                   	pop    %ebp
 10047a6:	c3                   	ret    
	...

010047a8 <_ZN9CGraphMan8SetGraphEP6CGraph>:
 10047a8:	55                   	push   %ebp
 10047a9:	89 e5                	mov    %esp,%ebp
 10047ab:	8b 45 08             	mov    0x8(%ebp),%eax
 10047ae:	8b 55 0c             	mov    0xc(%ebp),%edx
 10047b1:	89 10                	mov    %edx,(%eax)
 10047b3:	5d                   	pop    %ebp
 10047b4:	c3                   	ret    
 10047b5:	90                   	nop

010047b6 <_ZN9CGraphMan7SetGameEP5CGame>:
 10047b6:	55                   	push   %ebp
 10047b7:	89 e5                	mov    %esp,%ebp
 10047b9:	8b 45 08             	mov    0x8(%ebp),%eax
 10047bc:	8b 55 0c             	mov    0xc(%ebp),%edx
 10047bf:	89 50 04             	mov    %edx,0x4(%eax)
 10047c2:	5d                   	pop    %ebp
 10047c3:	c3                   	ret    

010047c4 <_ZN9CGraphMan6UpdateEv>:
 10047c4:	55                   	push   %ebp
 10047c5:	89 e5                	mov    %esp,%ebp
 10047c7:	83 ec 68             	sub    $0x68,%esp
 10047ca:	8b 45 08             	mov    0x8(%ebp),%eax
 10047cd:	8b 00                	mov    (%eax),%eax
 10047cf:	89 04 24             	mov    %eax,(%esp)
 10047d2:	e8 7d fe ff ff       	call   1004654 <_ZN6CGraph11GetImageBufEv>
 10047d7:	89 45 c8             	mov    %eax,-0x38(%ebp)
 10047da:	8b 45 08             	mov    0x8(%ebp),%eax
 10047dd:	8b 40 04             	mov    0x4(%eax),%eax
 10047e0:	89 04 24             	mov    %eax,(%esp)
 10047e3:	e8 d8 e2 ff ff       	call   1002ac0 <_ZN5CGame12GetAllObjectEv>
 10047e8:	89 45 c4             	mov    %eax,-0x3c(%ebp)
 10047eb:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 10047f2:	eb 38                	jmp    100482c <_ZN9CGraphMan6UpdateEv+0x68>
 10047f4:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 10047fb:	eb 1d                	jmp    100481a <_ZN9CGraphMan6UpdateEv+0x56>
 10047fd:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1004800:	c1 e0 02             	shl    $0x2,%eax
 1004803:	03 45 c8             	add    -0x38(%ebp),%eax
 1004806:	8b 00                	mov    (%eax),%eax
 1004808:	8b 55 f4             	mov    -0xc(%ebp),%edx
 100480b:	c1 e2 02             	shl    $0x2,%edx
 100480e:	01 d0                	add    %edx,%eax
 1004810:	c7 00 ff 80 50 00    	movl   $0x5080ff,(%eax)
 1004816:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 100481a:	81 7d f4 1f 01 00 00 	cmpl   $0x11f,-0xc(%ebp)
 1004821:	0f 9e c0             	setle  %al
 1004824:	84 c0                	test   %al,%al
 1004826:	75 d5                	jne    10047fd <_ZN9CGraphMan6UpdateEv+0x39>
 1004828:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 100482c:	81 7d f0 ff 00 00 00 	cmpl   $0xff,-0x10(%ebp)
 1004833:	0f 9e c0             	setle  %al
 1004836:	84 c0                	test   %al,%al
 1004838:	75 ba                	jne    10047f4 <_ZN9CGraphMan6UpdateEv+0x30>
 100483a:	83 7d c4 00          	cmpl   $0x0,-0x3c(%ebp)
 100483e:	0f 84 92 01 00 00    	je     10049d6 <_ZN9CGraphMan6UpdateEv+0x212>
 1004844:	c7 45 e8 ff ff ff ff 	movl   $0xffffffff,-0x18(%ebp)
 100484b:	e9 72 01 00 00       	jmp    10049c2 <_ZN9CGraphMan6UpdateEv+0x1fe>
 1004850:	8b 45 c4             	mov    -0x3c(%ebp),%eax
 1004853:	89 45 ec             	mov    %eax,-0x14(%ebp)
 1004856:	e9 51 01 00 00       	jmp    10049ac <_ZN9CGraphMan6UpdateEv+0x1e8>
 100485b:	8b 45 ec             	mov    -0x14(%ebp),%eax
 100485e:	8b 00                	mov    (%eax),%eax
 1004860:	8b 40 1c             	mov    0x1c(%eax),%eax
 1004863:	3b 45 e8             	cmp    -0x18(%ebp),%eax
 1004866:	0f 85 3b 01 00 00    	jne    10049a7 <_ZN9CGraphMan6UpdateEv+0x1e3>
 100486c:	8b 45 ec             	mov    -0x14(%ebp),%eax
 100486f:	8b 00                	mov    (%eax),%eax
 1004871:	8b 00                	mov    (%eax),%eax
 1004873:	8b 08                	mov    (%eax),%ecx
 1004875:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1004878:	8b 00                	mov    (%eax),%eax
 100487a:	8d 55 c2             	lea    -0x3e(%ebp),%edx
 100487d:	89 54 24 08          	mov    %edx,0x8(%esp)
 1004881:	8d 55 c3             	lea    -0x3d(%ebp),%edx
 1004884:	89 54 24 04          	mov    %edx,0x4(%esp)
 1004888:	89 04 24             	mov    %eax,(%esp)
 100488b:	ff d1                	call   *%ecx
 100488d:	89 45 e4             	mov    %eax,-0x1c(%ebp)
 1004890:	0f b6 45 c3          	movzbl -0x3d(%ebp),%eax
 1004894:	84 c0                	test   %al,%al
 1004896:	74 21                	je     10048b9 <_ZN9CGraphMan6UpdateEv+0xf5>
 1004898:	8b 45 ec             	mov    -0x14(%ebp),%eax
 100489b:	8b 00                	mov    (%eax),%eax
 100489d:	8b 50 0c             	mov    0xc(%eax),%edx
 10048a0:	8b 45 ec             	mov    -0x14(%ebp),%eax
 10048a3:	8b 00                	mov    (%eax),%eax
 10048a5:	8b 40 14             	mov    0x14(%eax),%eax
 10048a8:	01 d0                	add    %edx,%eax
 10048aa:	83 e8 01             	sub    $0x1,%eax
 10048ad:	89 45 d8             	mov    %eax,-0x28(%ebp)
 10048b0:	c7 45 d0 ff ff ff ff 	movl   $0xffffffff,-0x30(%ebp)
 10048b7:	eb 12                	jmp    10048cb <_ZN9CGraphMan6UpdateEv+0x107>
 10048b9:	8b 45 ec             	mov    -0x14(%ebp),%eax
 10048bc:	8b 00                	mov    (%eax),%eax
 10048be:	8b 40 0c             	mov    0xc(%eax),%eax
 10048c1:	89 45 d8             	mov    %eax,-0x28(%ebp)
 10048c4:	c7 45 d0 01 00 00 00 	movl   $0x1,-0x30(%ebp)
 10048cb:	0f b6 45 c2          	movzbl -0x3e(%ebp),%eax
 10048cf:	84 c0                	test   %al,%al
 10048d1:	74 21                	je     10048f4 <_ZN9CGraphMan6UpdateEv+0x130>
 10048d3:	8b 45 ec             	mov    -0x14(%ebp),%eax
 10048d6:	8b 00                	mov    (%eax),%eax
 10048d8:	8b 50 10             	mov    0x10(%eax),%edx
 10048db:	8b 45 ec             	mov    -0x14(%ebp),%eax
 10048de:	8b 00                	mov    (%eax),%eax
 10048e0:	8b 40 18             	mov    0x18(%eax),%eax
 10048e3:	01 d0                	add    %edx,%eax
 10048e5:	83 e8 01             	sub    $0x1,%eax
 10048e8:	89 45 d4             	mov    %eax,-0x2c(%ebp)
 10048eb:	c7 45 cc ff ff ff ff 	movl   $0xffffffff,-0x34(%ebp)
 10048f2:	eb 12                	jmp    1004906 <_ZN9CGraphMan6UpdateEv+0x142>
 10048f4:	8b 45 ec             	mov    -0x14(%ebp),%eax
 10048f7:	8b 00                	mov    (%eax),%eax
 10048f9:	8b 40 10             	mov    0x10(%eax),%eax
 10048fc:	89 45 d4             	mov    %eax,-0x2c(%ebp)
 10048ff:	c7 45 cc 01 00 00 00 	movl   $0x1,-0x34(%ebp)
 1004906:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 100490d:	8b 45 d4             	mov    -0x2c(%ebp),%eax
 1004910:	89 45 dc             	mov    %eax,-0x24(%ebp)
 1004913:	eb 7a                	jmp    100498f <_ZN9CGraphMan6UpdateEv+0x1cb>
 1004915:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 100491c:	8b 45 d8             	mov    -0x28(%ebp),%eax
 100491f:	89 45 e0             	mov    %eax,-0x20(%ebp)
 1004922:	eb 4f                	jmp    1004973 <_ZN9CGraphMan6UpdateEv+0x1af>
 1004924:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1004927:	8b 00                	mov    (%eax),%eax
 1004929:	85 c0                	test   %eax,%eax
 100492b:	78 38                	js     1004965 <_ZN9CGraphMan6UpdateEv+0x1a1>
 100492d:	83 7d dc 00          	cmpl   $0x0,-0x24(%ebp)
 1004931:	78 32                	js     1004965 <_ZN9CGraphMan6UpdateEv+0x1a1>
 1004933:	81 7d dc ff 00 00 00 	cmpl   $0xff,-0x24(%ebp)
 100493a:	7f 29                	jg     1004965 <_ZN9CGraphMan6UpdateEv+0x1a1>
 100493c:	83 7d e0 00          	cmpl   $0x0,-0x20(%ebp)
 1004940:	78 23                	js     1004965 <_ZN9CGraphMan6UpdateEv+0x1a1>
 1004942:	81 7d e0 1f 01 00 00 	cmpl   $0x11f,-0x20(%ebp)
 1004949:	7f 1a                	jg     1004965 <_ZN9CGraphMan6UpdateEv+0x1a1>
 100494b:	8b 45 dc             	mov    -0x24(%ebp),%eax
 100494e:	c1 e0 02             	shl    $0x2,%eax
 1004951:	03 45 c8             	add    -0x38(%ebp),%eax
 1004954:	8b 00                	mov    (%eax),%eax
 1004956:	8b 55 e0             	mov    -0x20(%ebp),%edx
 1004959:	c1 e2 02             	shl    $0x2,%edx
 100495c:	01 c2                	add    %eax,%edx
 100495e:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1004961:	8b 00                	mov    (%eax),%eax
 1004963:	89 02                	mov    %eax,(%edx)
 1004965:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 1004969:	8b 45 d0             	mov    -0x30(%ebp),%eax
 100496c:	01 45 e0             	add    %eax,-0x20(%ebp)
 100496f:	83 45 e4 04          	addl   $0x4,-0x1c(%ebp)
 1004973:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1004976:	8b 00                	mov    (%eax),%eax
 1004978:	8b 40 14             	mov    0x14(%eax),%eax
 100497b:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 100497e:	0f 9f c0             	setg   %al
 1004981:	84 c0                	test   %al,%al
 1004983:	75 9f                	jne    1004924 <_ZN9CGraphMan6UpdateEv+0x160>
 1004985:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 1004989:	8b 45 cc             	mov    -0x34(%ebp),%eax
 100498c:	01 45 dc             	add    %eax,-0x24(%ebp)
 100498f:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1004992:	8b 00                	mov    (%eax),%eax
 1004994:	8b 40 18             	mov    0x18(%eax),%eax
 1004997:	3b 45 f0             	cmp    -0x10(%ebp),%eax
 100499a:	0f 9f c0             	setg   %al
 100499d:	84 c0                	test   %al,%al
 100499f:	0f 85 70 ff ff ff    	jne    1004915 <_ZN9CGraphMan6UpdateEv+0x151>
 10049a5:	eb 01                	jmp    10049a8 <_ZN9CGraphMan6UpdateEv+0x1e4>
 10049a7:	90                   	nop
 10049a8:	83 45 ec 04          	addl   $0x4,-0x14(%ebp)
 10049ac:	8b 45 ec             	mov    -0x14(%ebp),%eax
 10049af:	8b 00                	mov    (%eax),%eax
 10049b1:	85 c0                	test   %eax,%eax
 10049b3:	0f 95 c0             	setne  %al
 10049b6:	84 c0                	test   %al,%al
 10049b8:	0f 85 9d fe ff ff    	jne    100485b <_ZN9CGraphMan6UpdateEv+0x97>
 10049be:	83 45 e8 01          	addl   $0x1,-0x18(%ebp)
 10049c2:	83 7d e8 01          	cmpl   $0x1,-0x18(%ebp)
 10049c6:	0f 9e c0             	setle  %al
 10049c9:	84 c0                	test   %al,%al
 10049cb:	0f 85 7f fe ff ff    	jne    1004850 <_ZN9CGraphMan6UpdateEv+0x8c>
 10049d1:	e9 95 01 00 00       	jmp    1004b6b <_ZN9CGraphMan6UpdateEv+0x3a7>
 10049d6:	8b 45 08             	mov    0x8(%ebp),%eax
 10049d9:	8b 00                	mov    (%eax),%eax
 10049db:	c7 44 24 10 00 ff ff 	movl   $0xffff00,0x10(%esp)
 10049e2:	00 
 10049e3:	c7 44 24 0c c4 91 00 	movl   $0x10091c4,0xc(%esp)
 10049ea:	01 
 10049eb:	c7 44 24 08 1e 00 00 	movl   $0x1e,0x8(%esp)
 10049f2:	00 
 10049f3:	c7 44 24 04 1e 00 00 	movl   $0x1e,0x4(%esp)
 10049fa:	00 
 10049fb:	89 04 24             	mov    %eax,(%esp)
 10049fe:	e8 9f fd ff ff       	call   10047a2 <_ZN6CGraph8ShowTextEiiPKci>
 1004a03:	8b 45 08             	mov    0x8(%ebp),%eax
 1004a06:	8b 00                	mov    (%eax),%eax
 1004a08:	c7 44 24 10 00 ff ff 	movl   $0xffff00,0x10(%esp)
 1004a0f:	00 
 1004a10:	c7 44 24 0c cf 91 00 	movl   $0x10091cf,0xc(%esp)
 1004a17:	01 
 1004a18:	c7 44 24 08 3c 00 00 	movl   $0x3c,0x8(%esp)
 1004a1f:	00 
 1004a20:	c7 44 24 04 32 00 00 	movl   $0x32,0x4(%esp)
 1004a27:	00 
 1004a28:	89 04 24             	mov    %eax,(%esp)
 1004a2b:	e8 72 fd ff ff       	call   10047a2 <_ZN6CGraph8ShowTextEiiPKci>
 1004a30:	8b 45 08             	mov    0x8(%ebp),%eax
 1004a33:	8b 00                	mov    (%eax),%eax
 1004a35:	c7 44 24 10 00 ff ff 	movl   $0xffff00,0x10(%esp)
 1004a3c:	00 
 1004a3d:	c7 44 24 0c db 91 00 	movl   $0x10091db,0xc(%esp)
 1004a44:	01 
 1004a45:	c7 44 24 08 50 00 00 	movl   $0x50,0x8(%esp)
 1004a4c:	00 
 1004a4d:	c7 44 24 04 32 00 00 	movl   $0x32,0x4(%esp)
 1004a54:	00 
 1004a55:	89 04 24             	mov    %eax,(%esp)
 1004a58:	e8 45 fd ff ff       	call   10047a2 <_ZN6CGraph8ShowTextEiiPKci>
 1004a5d:	8b 45 08             	mov    0x8(%ebp),%eax
 1004a60:	8b 00                	mov    (%eax),%eax
 1004a62:	c7 44 24 10 00 ff ff 	movl   $0xffff00,0x10(%esp)
 1004a69:	00 
 1004a6a:	c7 44 24 0c e5 91 00 	movl   $0x10091e5,0xc(%esp)
 1004a71:	01 
 1004a72:	c7 44 24 08 64 00 00 	movl   $0x64,0x8(%esp)
 1004a79:	00 
 1004a7a:	c7 44 24 04 32 00 00 	movl   $0x32,0x4(%esp)
 1004a81:	00 
 1004a82:	89 04 24             	mov    %eax,(%esp)
 1004a85:	e8 18 fd ff ff       	call   10047a2 <_ZN6CGraph8ShowTextEiiPKci>
 1004a8a:	8b 45 08             	mov    0x8(%ebp),%eax
 1004a8d:	8b 00                	mov    (%eax),%eax
 1004a8f:	c7 44 24 10 00 ff ff 	movl   $0xffff00,0x10(%esp)
 1004a96:	00 
 1004a97:	c7 44 24 0c f9 91 00 	movl   $0x10091f9,0xc(%esp)
 1004a9e:	01 
 1004a9f:	c7 44 24 08 78 00 00 	movl   $0x78,0x8(%esp)
 1004aa6:	00 
 1004aa7:	c7 44 24 04 32 00 00 	movl   $0x32,0x4(%esp)
 1004aae:	00 
 1004aaf:	89 04 24             	mov    %eax,(%esp)
 1004ab2:	e8 eb fc ff ff       	call   10047a2 <_ZN6CGraph8ShowTextEiiPKci>
 1004ab7:	8b 45 08             	mov    0x8(%ebp),%eax
 1004aba:	8b 00                	mov    (%eax),%eax
 1004abc:	c7 44 24 10 00 ff ff 	movl   $0xffff00,0x10(%esp)
 1004ac3:	00 
 1004ac4:	c7 44 24 0c 04 92 00 	movl   $0x1009204,0xc(%esp)
 1004acb:	01 
 1004acc:	c7 44 24 08 a0 00 00 	movl   $0xa0,0x8(%esp)
 1004ad3:	00 
 1004ad4:	c7 44 24 04 1e 00 00 	movl   $0x1e,0x4(%esp)
 1004adb:	00 
 1004adc:	89 04 24             	mov    %eax,(%esp)
 1004adf:	e8 be fc ff ff       	call   10047a2 <_ZN6CGraph8ShowTextEiiPKci>
 1004ae4:	8b 45 08             	mov    0x8(%ebp),%eax
 1004ae7:	8b 00                	mov    (%eax),%eax
 1004ae9:	c7 44 24 10 00 ff ff 	movl   $0xffff00,0x10(%esp)
 1004af0:	00 
 1004af1:	c7 44 24 0c 20 92 00 	movl   $0x1009220,0xc(%esp)
 1004af8:	01 
 1004af9:	c7 44 24 08 b4 00 00 	movl   $0xb4,0x8(%esp)
 1004b00:	00 
 1004b01:	c7 44 24 04 1e 00 00 	movl   $0x1e,0x4(%esp)
 1004b08:	00 
 1004b09:	89 04 24             	mov    %eax,(%esp)
 1004b0c:	e8 91 fc ff ff       	call   10047a2 <_ZN6CGraph8ShowTextEiiPKci>
 1004b11:	8b 45 08             	mov    0x8(%ebp),%eax
 1004b14:	8b 00                	mov    (%eax),%eax
 1004b16:	c7 44 24 10 00 ff ff 	movl   $0xffff00,0x10(%esp)
 1004b1d:	00 
 1004b1e:	c7 44 24 0c 38 92 00 	movl   $0x1009238,0xc(%esp)
 1004b25:	01 
 1004b26:	c7 44 24 08 c8 00 00 	movl   $0xc8,0x8(%esp)
 1004b2d:	00 
 1004b2e:	c7 44 24 04 1e 00 00 	movl   $0x1e,0x4(%esp)
 1004b35:	00 
 1004b36:	89 04 24             	mov    %eax,(%esp)
 1004b39:	e8 64 fc ff ff       	call   10047a2 <_ZN6CGraph8ShowTextEiiPKci>
 1004b3e:	8b 45 08             	mov    0x8(%ebp),%eax
 1004b41:	8b 00                	mov    (%eax),%eax
 1004b43:	c7 44 24 10 00 ff ff 	movl   $0xffff00,0x10(%esp)
 1004b4a:	00 
 1004b4b:	c7 44 24 0c 51 92 00 	movl   $0x1009251,0xc(%esp)
 1004b52:	01 
 1004b53:	c7 44 24 08 dc 00 00 	movl   $0xdc,0x8(%esp)
 1004b5a:	00 
 1004b5b:	c7 44 24 04 1e 00 00 	movl   $0x1e,0x4(%esp)
 1004b62:	00 
 1004b63:	89 04 24             	mov    %eax,(%esp)
 1004b66:	e8 37 fc ff ff       	call   10047a2 <_ZN6CGraph8ShowTextEiiPKci>
 1004b6b:	8b 45 08             	mov    0x8(%ebp),%eax
 1004b6e:	8b 00                	mov    (%eax),%eax
 1004b70:	89 04 24             	mov    %eax,(%esp)
 1004b73:	e8 e8 fa ff ff       	call   1004660 <_ZN6CGraph7RefreshEv>
 1004b78:	c9                   	leave  
 1004b79:	c3                   	ret    
	...

01004b7c <_ZN7CGroundC1EP5CGameii>:
 1004b7c:	55                   	push   %ebp
 1004b7d:	89 e5                	mov    %esp,%ebp
 1004b7f:	83 ec 28             	sub    $0x28,%esp
 1004b82:	8b 45 08             	mov    0x8(%ebp),%eax
 1004b85:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
 1004b8c:	00 
 1004b8d:	c7 44 24 18 10 00 00 	movl   $0x10,0x18(%esp)
 1004b94:	00 
 1004b95:	c7 44 24 14 10 00 00 	movl   $0x10,0x14(%esp)
 1004b9c:	00 
 1004b9d:	8b 55 14             	mov    0x14(%ebp),%edx
 1004ba0:	89 54 24 10          	mov    %edx,0x10(%esp)
 1004ba4:	8b 55 10             	mov    0x10(%ebp),%edx
 1004ba7:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1004bab:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 1004bb2:	00 
 1004bb3:	8b 55 0c             	mov    0xc(%ebp),%edx
 1004bb6:	89 54 24 04          	mov    %edx,0x4(%esp)
 1004bba:	89 04 24             	mov    %eax,(%esp)
 1004bbd:	e8 ce 12 00 00       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 1004bc2:	8b 45 08             	mov    0x8(%ebp),%eax
 1004bc5:	c7 00 78 92 00 01    	movl   $0x1009278,(%eax)
 1004bcb:	c9                   	leave  
 1004bcc:	c3                   	ret    
 1004bcd:	90                   	nop

01004bce <_ZN7CGround8GetImageEPbS0_>:
 1004bce:	55                   	push   %ebp
 1004bcf:	89 e5                	mov    %esp,%ebp
 1004bd1:	8b 45 10             	mov    0x10(%ebp),%eax
 1004bd4:	c6 00 00             	movb   $0x0,(%eax)
 1004bd7:	8b 45 0c             	mov    0xc(%ebp),%eax
 1004bda:	c6 00 00             	movb   $0x0,(%eax)
 1004bdd:	b8 00 00 01 01       	mov    $0x1010000,%eax
 1004be2:	5d                   	pop    %ebp
 1004be3:	c3                   	ret    

01004be4 <_Z8w_createiiiiiPc>:
 1004be4:	55                   	push   %ebp
 1004be5:	89 e5                	mov    %esp,%ebp
 1004be7:	83 ec 38             	sub    $0x38,%esp
 1004bea:	c7 45 d8 d2 07 00 00 	movl   $0x7d2,-0x28(%ebp)
 1004bf1:	8b 45 08             	mov    0x8(%ebp),%eax
 1004bf4:	89 45 e0             	mov    %eax,-0x20(%ebp)
 1004bf7:	8b 45 0c             	mov    0xc(%ebp),%eax
 1004bfa:	c1 e0 10             	shl    $0x10,%eax
 1004bfd:	0b 45 10             	or     0x10(%ebp),%eax
 1004c00:	89 45 e4             	mov    %eax,-0x1c(%ebp)
 1004c03:	8b 45 14             	mov    0x14(%ebp),%eax
 1004c06:	c1 e0 10             	shl    $0x10,%eax
 1004c09:	0b 45 18             	or     0x18(%ebp),%eax
 1004c0c:	89 45 e8             	mov    %eax,-0x18(%ebp)
 1004c0f:	8b 45 1c             	mov    0x1c(%ebp),%eax
 1004c12:	89 45 ec             	mov    %eax,-0x14(%ebp)
 1004c15:	8b 45 1c             	mov    0x1c(%ebp),%eax
 1004c18:	89 04 24             	mov    %eax,(%esp)
 1004c1b:	e8 da 05 00 00       	call   10051fa <_Z6strlenPKc>
 1004c20:	83 c0 01             	add    $0x1,%eax
 1004c23:	89 45 f0             	mov    %eax,-0x10(%ebp)
 1004c26:	a1 bc fd 02 01       	mov    0x102fdbc,%eax
 1004c2b:	8d 55 d8             	lea    -0x28(%ebp),%edx
 1004c2e:	89 54 24 04          	mov    %edx,0x4(%esp)
 1004c32:	89 04 24             	mov    %eax,(%esp)
 1004c35:	e8 ec 29 00 00       	call   1007626 <send>
 1004c3a:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 1004c41:	00 
 1004c42:	8d 45 d8             	lea    -0x28(%ebp),%eax
 1004c45:	89 44 24 04          	mov    %eax,0x4(%esp)
 1004c49:	c7 04 24 ff ff ff ff 	movl   $0xffffffff,(%esp)
 1004c50:	e8 15 2a 00 00       	call   100766a <recv>
 1004c55:	8b 45 d8             	mov    -0x28(%ebp),%eax
 1004c58:	3d a2 0f 00 00       	cmp    $0xfa2,%eax
 1004c5d:	0f 95 c0             	setne  %al
 1004c60:	84 c0                	test   %al,%al
 1004c62:	75 d6                	jne    1004c3a <_Z8w_createiiiiiPc+0x56>
 1004c64:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1004c67:	a3 d0 fd 02 01       	mov    %eax,0x102fdd0
 1004c6c:	8b 15 00 9f 01 01    	mov    0x1019f00,%edx
 1004c72:	a1 d0 fd 02 01       	mov    0x102fdd0,%eax
 1004c77:	c7 44 24 08 03 00 00 	movl   $0x3,0x8(%esp)
 1004c7e:	00 
 1004c7f:	89 54 24 04          	mov    %edx,0x4(%esp)
 1004c83:	89 04 24             	mov    %eax,(%esp)
 1004c86:	e8 90 2a 00 00       	call   100771b <shm_at>
 1004c8b:	8b 45 e0             	mov    -0x20(%ebp),%eax
 1004c8e:	c9                   	leave  
 1004c8f:	c3                   	ret    

01004c90 <_Z9w_refreshjiiii>:
 1004c90:	55                   	push   %ebp
 1004c91:	89 e5                	mov    %esp,%ebp
 1004c93:	83 ec 38             	sub    $0x38,%esp
 1004c96:	c7 45 d8 d4 07 00 00 	movl   $0x7d4,-0x28(%ebp)
 1004c9d:	8b 45 08             	mov    0x8(%ebp),%eax
 1004ca0:	89 45 e0             	mov    %eax,-0x20(%ebp)
 1004ca3:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%ebp)
 1004caa:	8b 45 0c             	mov    0xc(%ebp),%eax
 1004cad:	c1 e0 10             	shl    $0x10,%eax
 1004cb0:	0b 45 10             	or     0x10(%ebp),%eax
 1004cb3:	89 45 e8             	mov    %eax,-0x18(%ebp)
 1004cb6:	8b 45 14             	mov    0x14(%ebp),%eax
 1004cb9:	c1 e0 10             	shl    $0x10,%eax
 1004cbc:	0b 45 18             	or     0x18(%ebp),%eax
 1004cbf:	89 45 ec             	mov    %eax,-0x14(%ebp)
 1004cc2:	a1 bc fd 02 01       	mov    0x102fdbc,%eax
 1004cc7:	8d 55 d8             	lea    -0x28(%ebp),%edx
 1004cca:	89 54 24 04          	mov    %edx,0x4(%esp)
 1004cce:	89 04 24             	mov    %eax,(%esp)
 1004cd1:	e8 50 29 00 00       	call   1007626 <send>
 1004cd6:	c9                   	leave  
 1004cd7:	c3                   	ret    

01004cd8 <_Z9w_destroyj>:
 1004cd8:	55                   	push   %ebp
 1004cd9:	89 e5                	mov    %esp,%ebp
 1004cdb:	83 ec 38             	sub    $0x38,%esp
 1004cde:	c7 45 d8 d6 07 00 00 	movl   $0x7d6,-0x28(%ebp)
 1004ce5:	8b 45 08             	mov    0x8(%ebp),%eax
 1004ce8:	89 45 e0             	mov    %eax,-0x20(%ebp)
 1004ceb:	a1 bc fd 02 01       	mov    0x102fdbc,%eax
 1004cf0:	8d 55 d8             	lea    -0x28(%ebp),%edx
 1004cf3:	89 54 24 04          	mov    %edx,0x4(%esp)
 1004cf7:	89 04 24             	mov    %eax,(%esp)
 1004cfa:	e8 27 29 00 00       	call   1007626 <send>
 1004cff:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 1004d06:	00 
 1004d07:	8d 45 d8             	lea    -0x28(%ebp),%eax
 1004d0a:	89 44 24 04          	mov    %eax,0x4(%esp)
 1004d0e:	c7 04 24 ff ff ff ff 	movl   $0xffffffff,(%esp)
 1004d15:	e8 50 29 00 00       	call   100766a <recv>
 1004d1a:	8b 45 d8             	mov    -0x28(%ebp),%eax
 1004d1d:	89 44 24 04          	mov    %eax,0x4(%esp)
 1004d21:	c7 04 24 8c 92 00 01 	movl   $0x100928c,(%esp)
 1004d28:	e8 0f 2b 00 00       	call   100783c <printf>
 1004d2d:	8b 45 d8             	mov    -0x28(%ebp),%eax
 1004d30:	3d a2 0f 00 00       	cmp    $0xfa2,%eax
 1004d35:	0f 95 c0             	setne  %al
 1004d38:	84 c0                	test   %al,%al
 1004d3a:	75 c3                	jne    1004cff <_Z9w_destroyj+0x27>
 1004d3c:	8b 15 00 9f 01 01    	mov    0x1019f00,%edx
 1004d42:	a1 d0 fd 02 01       	mov    0x102fdd0,%eax
 1004d47:	89 54 24 04          	mov    %edx,0x4(%esp)
 1004d4b:	89 04 24             	mov    %eax,(%esp)
 1004d4e:	e8 09 2a 00 00       	call   100775c <shm_dt>
 1004d53:	8b 45 e0             	mov    -0x20(%ebp),%eax
 1004d56:	c9                   	leave  
 1004d57:	c3                   	ret    

01004d58 <_Z9main_loopv>:
 1004d58:	55                   	push   %ebp
 1004d59:	89 e5                	mov    %esp,%ebp
 1004d5b:	81 ec c8 00 00 00    	sub    $0xc8,%esp
 1004d61:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%ebp)
 1004d68:	c7 45 e8 00 00 00 00 	movl   $0x0,-0x18(%ebp)
 1004d6f:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%ebp)
 1004d76:	c7 45 f4 01 00 00 00 	movl   $0x1,-0xc(%ebp)
 1004d7d:	e9 29 02 00 00       	jmp    1004fab <_Z9main_loopv+0x253>
 1004d82:	8b 45 c8             	mov    -0x38(%ebp),%eax
 1004d85:	89 45 e0             	mov    %eax,-0x20(%ebp)
 1004d88:	8b 45 c0             	mov    -0x40(%ebp),%eax
 1004d8b:	83 e0 fe             	and    $0xfffffffe,%eax
 1004d8e:	3d a6 0f 00 00       	cmp    $0xfa6,%eax
 1004d93:	0f 84 fd 00 00 00    	je     1004e96 <_Z9main_loopv+0x13e>
 1004d99:	3d a6 0f 00 00       	cmp    $0xfa6,%eax
 1004d9e:	7f 0c                	jg     1004dac <_Z9main_loopv+0x54>
 1004da0:	3d a4 0f 00 00       	cmp    $0xfa4,%eax
 1004da5:	74 20                	je     1004dc7 <_Z9main_loopv+0x6f>
 1004da7:	e9 fc 01 00 00       	jmp    1004fa8 <_Z9main_loopv+0x250>
 1004dac:	3d a8 0f 00 00       	cmp    $0xfa8,%eax
 1004db1:	0f 84 be 01 00 00    	je     1004f75 <_Z9main_loopv+0x21d>
 1004db7:	3d aa 0f 00 00       	cmp    $0xfaa,%eax
 1004dbc:	0f 84 98 00 00 00    	je     1004e5a <_Z9main_loopv+0x102>
 1004dc2:	e9 e1 01 00 00       	jmp    1004fa8 <_Z9main_loopv+0x250>
 1004dc7:	8b 45 cc             	mov    -0x34(%ebp),%eax
 1004dca:	83 f8 71             	cmp    $0x71,%eax
 1004dcd:	75 18                	jne    1004de7 <_Z9main_loopv+0x8f>
 1004dcf:	8b 45 e0             	mov    -0x20(%ebp),%eax
 1004dd2:	89 04 24             	mov    %eax,(%esp)
 1004dd5:	e8 fe fe ff ff       	call   1004cd8 <_Z9w_destroyj>
 1004dda:	85 c0                	test   %eax,%eax
 1004ddc:	0f 95 c0             	setne  %al
 1004ddf:	84 c0                	test   %al,%al
 1004de1:	0f 85 ee 01 00 00    	jne    1004fd5 <_Z9main_loopv+0x27d>
 1004de7:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 1004dee:	8b 45 cc             	mov    -0x34(%ebp),%eax
 1004df1:	83 f8 77             	cmp    $0x77,%eax
 1004df4:	75 04                	jne    1004dfa <_Z9main_loopv+0xa2>
 1004df6:	83 4d f0 01          	orl    $0x1,-0x10(%ebp)
 1004dfa:	8b 45 cc             	mov    -0x34(%ebp),%eax
 1004dfd:	83 f8 73             	cmp    $0x73,%eax
 1004e00:	75 04                	jne    1004e06 <_Z9main_loopv+0xae>
 1004e02:	83 4d f0 02          	orl    $0x2,-0x10(%ebp)
 1004e06:	8b 45 cc             	mov    -0x34(%ebp),%eax
 1004e09:	83 f8 61             	cmp    $0x61,%eax
 1004e0c:	75 04                	jne    1004e12 <_Z9main_loopv+0xba>
 1004e0e:	83 4d f0 04          	orl    $0x4,-0x10(%ebp)
 1004e12:	8b 45 cc             	mov    -0x34(%ebp),%eax
 1004e15:	83 f8 64             	cmp    $0x64,%eax
 1004e18:	75 04                	jne    1004e1e <_Z9main_loopv+0xc6>
 1004e1a:	83 4d f0 08          	orl    $0x8,-0x10(%ebp)
 1004e1e:	8b 45 cc             	mov    -0x34(%ebp),%eax
 1004e21:	83 f8 6a             	cmp    $0x6a,%eax
 1004e24:	75 04                	jne    1004e2a <_Z9main_loopv+0xd2>
 1004e26:	83 4d f0 10          	orl    $0x10,-0x10(%ebp)
 1004e2a:	8b 45 cc             	mov    -0x34(%ebp),%eax
 1004e2d:	83 f8 6b             	cmp    $0x6b,%eax
 1004e30:	75 04                	jne    1004e36 <_Z9main_loopv+0xde>
 1004e32:	83 4d f0 20          	orl    $0x20,-0x10(%ebp)
 1004e36:	8b 45 cc             	mov    -0x34(%ebp),%eax
 1004e39:	83 f8 0a             	cmp    $0xa,%eax
 1004e3c:	75 04                	jne    1004e42 <_Z9main_loopv+0xea>
 1004e3e:	83 4d f0 40          	orl    $0x40,-0x10(%ebp)
 1004e42:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1004e45:	89 44 24 04          	mov    %eax,0x4(%esp)
 1004e49:	c7 04 24 3c 61 02 01 	movl   $0x102613c,(%esp)
 1004e50:	e8 a5 d0 ff ff       	call   1001efa <_ZN8CControl10KeyChangedEi>
 1004e55:	e9 51 01 00 00       	jmp    1004fab <_Z9main_loopv+0x253>
 1004e5a:	c7 04 24 3c 61 02 01 	movl   $0x102613c,(%esp)
 1004e61:	e8 62 d0 ff ff       	call   1001ec8 <_ZN8CControl5ClockEv>
 1004e66:	c7 44 24 10 00 01 00 	movl   $0x100,0x10(%esp)
 1004e6d:	00 
 1004e6e:	c7 44 24 0c 20 01 00 	movl   $0x120,0xc(%esp)
 1004e75:	00 
 1004e76:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 1004e7d:	00 
 1004e7e:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 1004e85:	00 
 1004e86:	8b 45 e0             	mov    -0x20(%ebp),%eax
 1004e89:	89 04 24             	mov    %eax,(%esp)
 1004e8c:	e8 ff fd ff ff       	call   1004c90 <_Z9w_refreshjiiii>
 1004e91:	e9 15 01 00 00       	jmp    1004fab <_Z9main_loopv+0x253>
 1004e96:	8b 45 cc             	mov    -0x34(%ebp),%eax
 1004e99:	89 45 ec             	mov    %eax,-0x14(%ebp)
 1004e9c:	8b 45 d0             	mov    -0x30(%ebp),%eax
 1004e9f:	89 45 e8             	mov    %eax,-0x18(%ebp)
 1004ea2:	8b 45 d4             	mov    -0x2c(%ebp),%eax
 1004ea5:	89 45 e4             	mov    %eax,-0x1c(%ebp)
 1004ea8:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1004eab:	83 e0 04             	and    $0x4,%eax
 1004eae:	85 c0                	test   %eax,%eax
 1004eb0:	74 07                	je     1004eb9 <_Z9main_loopv+0x161>
 1004eb2:	b9 9b 92 00 01       	mov    $0x100929b,%ecx
 1004eb7:	eb 05                	jmp    1004ebe <_Z9main_loopv+0x166>
 1004eb9:	b9 9d 92 00 01       	mov    $0x100929d,%ecx
 1004ebe:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1004ec1:	83 e0 02             	and    $0x2,%eax
 1004ec4:	85 c0                	test   %eax,%eax
 1004ec6:	74 07                	je     1004ecf <_Z9main_loopv+0x177>
 1004ec8:	ba 9f 92 00 01       	mov    $0x100929f,%edx
 1004ecd:	eb 05                	jmp    1004ed4 <_Z9main_loopv+0x17c>
 1004ecf:	ba 9d 92 00 01       	mov    $0x100929d,%edx
 1004ed4:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1004ed7:	83 e0 01             	and    $0x1,%eax
 1004eda:	84 c0                	test   %al,%al
 1004edc:	74 07                	je     1004ee5 <_Z9main_loopv+0x18d>
 1004ede:	b8 a1 92 00 01       	mov    $0x10092a1,%eax
 1004ee3:	eb 05                	jmp    1004eea <_Z9main_loopv+0x192>
 1004ee5:	b8 9d 92 00 01       	mov    $0x100929d,%eax
 1004eea:	89 4c 24 18          	mov    %ecx,0x18(%esp)
 1004eee:	89 54 24 14          	mov    %edx,0x14(%esp)
 1004ef2:	89 44 24 10          	mov    %eax,0x10(%esp)
 1004ef6:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1004ef9:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1004efd:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1004f00:	89 44 24 08          	mov    %eax,0x8(%esp)
 1004f04:	c7 44 24 04 a4 92 00 	movl   $0x10092a4,0x4(%esp)
 1004f0b:	01 
 1004f0c:	8d 85 5c ff ff ff    	lea    -0xa4(%ebp),%eax
 1004f12:	89 04 24             	mov    %eax,(%esp)
 1004f15:	e8 1b 31 00 00       	call   1008035 <sprintf>
 1004f1a:	c7 44 24 10 00 00 00 	movl   $0x0,0x10(%esp)
 1004f21:	00 
 1004f22:	8d 85 5c ff ff ff    	lea    -0xa4(%ebp),%eax
 1004f28:	89 44 24 0c          	mov    %eax,0xc(%esp)
 1004f2c:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 1004f33:	00 
 1004f34:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 1004f3b:	00 
 1004f3c:	c7 04 24 c0 fd 02 01 	movl   $0x102fdc0,(%esp)
 1004f43:	e8 49 ba ff ff       	call   1000991 <draw_string>
 1004f48:	c7 44 24 10 0f 00 00 	movl   $0xf,0x10(%esp)
 1004f4f:	00 
 1004f50:	c7 44 24 0c 58 02 00 	movl   $0x258,0xc(%esp)
 1004f57:	00 
 1004f58:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 1004f5f:	00 
 1004f60:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 1004f67:	00 
 1004f68:	8b 45 e0             	mov    -0x20(%ebp),%eax
 1004f6b:	89 04 24             	mov    %eax,(%esp)
 1004f6e:	e8 1d fd ff ff       	call   1004c90 <_Z9w_refreshjiiii>
 1004f73:	eb 36                	jmp    1004fab <_Z9main_loopv+0x253>
 1004f75:	8b 45 e0             	mov    -0x20(%ebp),%eax
 1004f78:	89 04 24             	mov    %eax,(%esp)
 1004f7b:	e8 58 fd ff ff       	call   1004cd8 <_Z9w_destroyj>
 1004f80:	85 c0                	test   %eax,%eax
 1004f82:	0f 95 c0             	setne  %al
 1004f85:	84 c0                	test   %al,%al
 1004f87:	74 04                	je     1004f8d <_Z9main_loopv+0x235>
 1004f89:	83 6d f4 01          	subl   $0x1,-0xc(%ebp)
 1004f8d:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1004f90:	89 44 24 04          	mov    %eax,0x4(%esp)
 1004f94:	c7 04 24 d2 92 00 01 	movl   $0x10092d2,(%esp)
 1004f9b:	e8 9c 28 00 00       	call   100783c <printf>
 1004fa0:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 1004fa4:	75 04                	jne    1004faa <_Z9main_loopv+0x252>
 1004fa6:	eb 2e                	jmp    1004fd6 <_Z9main_loopv+0x27e>
 1004fa8:	eb 01                	jmp    1004fab <_Z9main_loopv+0x253>
 1004faa:	90                   	nop
 1004fab:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 1004fb2:	00 
 1004fb3:	8d 45 c0             	lea    -0x40(%ebp),%eax
 1004fb6:	89 44 24 04          	mov    %eax,0x4(%esp)
 1004fba:	c7 04 24 ff ff ff ff 	movl   $0xffffffff,(%esp)
 1004fc1:	e8 a4 26 00 00       	call   100766a <recv>
 1004fc6:	85 c0                	test   %eax,%eax
 1004fc8:	0f 95 c0             	setne  %al
 1004fcb:	84 c0                	test   %al,%al
 1004fcd:	0f 85 af fd ff ff    	jne    1004d82 <_Z9main_loopv+0x2a>
 1004fd3:	eb 01                	jmp    1004fd6 <_Z9main_loopv+0x27e>
 1004fd5:	90                   	nop
 1004fd6:	c9                   	leave  
 1004fd7:	c3                   	ret    

01004fd8 <_Z7w_timerji>:
 1004fd8:	55                   	push   %ebp
 1004fd9:	89 e5                	mov    %esp,%ebp
 1004fdb:	83 ec 38             	sub    $0x38,%esp
 1004fde:	c7 45 d8 d8 07 00 00 	movl   $0x7d8,-0x28(%ebp)
 1004fe5:	8b 45 08             	mov    0x8(%ebp),%eax
 1004fe8:	89 45 e0             	mov    %eax,-0x20(%ebp)
 1004feb:	8b 45 0c             	mov    0xc(%ebp),%eax
 1004fee:	89 45 e4             	mov    %eax,-0x1c(%ebp)
 1004ff1:	a1 bc fd 02 01       	mov    0x102fdbc,%eax
 1004ff6:	8d 55 d8             	lea    -0x28(%ebp),%edx
 1004ff9:	89 54 24 04          	mov    %edx,0x4(%esp)
 1004ffd:	89 04 24             	mov    %eax,(%esp)
 1005000:	e8 21 26 00 00       	call   1007626 <send>
 1005005:	c9                   	leave  
 1005006:	c3                   	ret    

01005007 <main>:
 1005007:	55                   	push   %ebp
 1005008:	89 e5                	mov    %esp,%ebp
 100500a:	83 e4 f0             	and    $0xfffffff0,%esp
 100500d:	83 ec 30             	sub    $0x30,%esp
 1005010:	c7 04 24 e3 92 00 01 	movl   $0x10092e3,(%esp)
 1005017:	e8 20 28 00 00       	call   100783c <printf>
 100501c:	c7 44 24 04 bc fd 02 	movl   $0x102fdbc,0x4(%esp)
 1005023:	01 
 1005024:	c7 04 24 01 93 00 01 	movl   $0x1009301,(%esp)
 100502b:	e8 4d 35 00 00       	call   100857d <scanf>
 1005030:	e8 67 b1 ff ff       	call   100019c <draw_init>
 1005035:	a1 00 9f 01 01       	mov    0x1019f00,%eax
 100503a:	89 44 24 04          	mov    %eax,0x4(%esp)
 100503e:	c7 04 24 c0 fd 02 01 	movl   $0x102fdc0,(%esp)
 1005045:	e8 a7 b1 ff ff       	call   10001f1 <draw_set_canvas>
 100504a:	c7 44 24 14 04 93 00 	movl   $0x1009304,0x14(%esp)
 1005051:	01 
 1005052:	c7 44 24 10 00 01 00 	movl   $0x100,0x10(%esp)
 1005059:	00 
 100505a:	c7 44 24 0c 20 01 00 	movl   $0x120,0xc(%esp)
 1005061:	00 
 1005062:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 1005069:	00 
 100506a:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 1005071:	00 
 1005072:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 1005079:	e8 66 fb ff ff       	call   1004be4 <_Z8w_createiiiiiPc>
 100507e:	89 44 24 2c          	mov    %eax,0x2c(%esp)
 1005082:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 1005086:	89 44 24 04          	mov    %eax,0x4(%esp)
 100508a:	c7 04 24 0b 93 00 01 	movl   $0x100930b,(%esp)
 1005091:	e8 a6 27 00 00       	call   100783c <printf>
 1005096:	c7 44 24 10 00 01 00 	movl   $0x100,0x10(%esp)
 100509d:	00 
 100509e:	c7 44 24 0c 20 01 00 	movl   $0x120,0xc(%esp)
 10050a5:	00 
 10050a6:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 10050ad:	00 
 10050ae:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 10050b5:	00 
 10050b6:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 10050ba:	89 04 24             	mov    %eax,(%esp)
 10050bd:	e8 ce fb ff ff       	call   1004c90 <_Z9w_refreshjiiii>
 10050c2:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 10050c6:	89 44 24 04          	mov    %eax,0x4(%esp)
 10050ca:	c7 04 24 20 5d 02 01 	movl   $0x1025d20,(%esp)
 10050d1:	e8 46 f6 ff ff       	call   100471c <_ZN6CGraph4InitEj>
 10050d6:	c7 44 24 04 20 5d 02 	movl   $0x1025d20,0x4(%esp)
 10050dd:	01 
 10050de:	c7 04 24 28 61 02 01 	movl   $0x1026128,(%esp)
 10050e5:	e8 be f6 ff ff       	call   10047a8 <_ZN9CGraphMan8SetGraphEP6CGraph>
 10050ea:	c7 44 24 04 60 61 02 	movl   $0x1026160,0x4(%esp)
 10050f1:	01 
 10050f2:	c7 04 24 28 61 02 01 	movl   $0x1026128,(%esp)
 10050f9:	e8 b8 f6 ff ff       	call   10047b6 <_ZN9CGraphMan7SetGameEP5CGame>
 10050fe:	c7 04 24 30 61 02 01 	movl   $0x1026130,(%esp)
 1005105:	e8 2a 12 00 00       	call   1006334 <_ZN6CSound4InitEv>
 100510a:	c7 44 24 04 30 61 02 	movl   $0x1026130,0x4(%esp)
 1005111:	01 
 1005112:	c7 04 24 34 61 02 01 	movl   $0x1026134,(%esp)
 1005119:	e8 5c 12 00 00       	call   100637a <_ZN9CSoundMan8SetSoundEP6CSound>
 100511e:	c7 44 24 04 28 61 02 	movl   $0x1026128,0x4(%esp)
 1005125:	01 
 1005126:	c7 04 24 3c 61 02 01 	movl   $0x102613c,(%esp)
 100512d:	e8 ba cd ff ff       	call   1001eec <_ZN8CControl8SetGraphEP9CGraphMan>
 1005132:	c7 44 24 04 60 61 02 	movl   $0x1026160,0x4(%esp)
 1005139:	01 
 100513a:	c7 04 24 3c 61 02 01 	movl   $0x102613c,(%esp)
 1005141:	e8 88 cf ff ff       	call   10020ce <_ZN8CControl7SetGameEP5CGame>
 1005146:	c7 44 24 04 34 61 02 	movl   $0x1026134,0x4(%esp)
 100514d:	01 
 100514e:	c7 04 24 60 61 02 01 	movl   $0x1026160,(%esp)
 1005155:	e8 a0 f0 ff ff       	call   10041fa <_ZN5CGame8SetSoundEP9CSoundMan>
 100515a:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 1005161:	00 
 1005162:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 1005166:	89 04 24             	mov    %eax,(%esp)
 1005169:	e8 6a fe ff ff       	call   1004fd8 <_Z7w_timerji>
 100516e:	e8 e5 fb ff ff       	call   1004d58 <_Z9main_loopv>
 1005173:	c7 04 24 15 93 00 01 	movl   $0x1009315,(%esp)
 100517a:	e8 bd 26 00 00       	call   100783c <printf>
 100517f:	b8 00 00 00 00       	mov    $0x0,%eax
 1005184:	c9                   	leave  
 1005185:	c3                   	ret    

01005186 <_Z41__static_initialization_and_destruction_0ii>:
 1005186:	55                   	push   %ebp
 1005187:	89 e5                	mov    %esp,%ebp
 1005189:	83 ec 18             	sub    $0x18,%esp
 100518c:	83 7d 08 01          	cmpl   $0x1,0x8(%ebp)
 1005190:	75 4a                	jne    10051dc <_Z41__static_initialization_and_destruction_0ii+0x56>
 1005192:	81 7d 0c ff ff 00 00 	cmpl   $0xffff,0xc(%ebp)
 1005199:	75 41                	jne    10051dc <_Z41__static_initialization_and_destruction_0ii+0x56>
 100519b:	b8 64 63 00 01       	mov    $0x1006364,%eax
 10051a0:	c7 44 24 08 00 40 02 	movl   $0x1024000,0x8(%esp)
 10051a7:	01 
 10051a8:	c7 44 24 04 30 61 02 	movl   $0x1026130,0x4(%esp)
 10051af:	01 
 10051b0:	89 04 24             	mov    %eax,(%esp)
 10051b3:	e8 a8 ae ff ff       	call   1000060 <__cxa_atexit>
 10051b8:	c7 04 24 34 61 02 01 	movl   $0x1026134,(%esp)
 10051bf:	e8 a8 11 00 00       	call   100636c <_ZN9CSoundManC1Ev>
 10051c4:	c7 04 24 3c 61 02 01 	movl   $0x102613c,(%esp)
 10051cb:	e8 0c cf ff ff       	call   10020dc <_ZN8CControlC1Ev>
 10051d0:	c7 04 24 60 61 02 01 	movl   $0x1026160,(%esp)
 10051d7:	e8 b0 d8 ff ff       	call   1002a8c <_ZN5CGameC1Ev>
 10051dc:	c9                   	leave  
 10051dd:	c3                   	ret    

010051de <_GLOBAL__sub_I_gGraph>:
 10051de:	55                   	push   %ebp
 10051df:	89 e5                	mov    %esp,%ebp
 10051e1:	83 ec 18             	sub    $0x18,%esp
 10051e4:	c7 44 24 04 ff ff 00 	movl   $0xffff,0x4(%esp)
 10051eb:	00 
 10051ec:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 10051f3:	e8 8e ff ff ff       	call   1005186 <_Z41__static_initialization_and_destruction_0ii>
 10051f8:	c9                   	leave  
 10051f9:	c3                   	ret    

010051fa <_Z6strlenPKc>:
 10051fa:	55                   	push   %ebp
 10051fb:	89 e5                	mov    %esp,%ebp
 10051fd:	57                   	push   %edi
 10051fe:	8b 55 08             	mov    0x8(%ebp),%edx
 1005201:	b8 00 00 00 00       	mov    $0x0,%eax
 1005206:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 100520b:	89 d7                	mov    %edx,%edi
 100520d:	fc                   	cld    
 100520e:	f2 ae                	repnz scas %es:(%edi),%al
 1005210:	f7 d1                	not    %ecx
 1005212:	49                   	dec    %ecx
 1005213:	89 c8                	mov    %ecx,%eax
 1005215:	5f                   	pop    %edi
 1005216:	5d                   	pop    %ebp
 1005217:	c3                   	ret    

01005218 <_ZN6CMarioC1EP5CGameiii>:
 1005218:	55                   	push   %ebp
 1005219:	89 e5                	mov    %esp,%ebp
 100521b:	83 ec 28             	sub    $0x28,%esp
 100521e:	8b 45 08             	mov    0x8(%ebp),%eax
 1005221:	c7 44 24 1c ff ff ff 	movl   $0xffffffff,0x1c(%esp)
 1005228:	ff 
 1005229:	c7 44 24 18 10 00 00 	movl   $0x10,0x18(%esp)
 1005230:	00 
 1005231:	c7 44 24 14 10 00 00 	movl   $0x10,0x14(%esp)
 1005238:	00 
 1005239:	8b 55 14             	mov    0x14(%ebp),%edx
 100523c:	89 54 24 10          	mov    %edx,0x10(%esp)
 1005240:	8b 55 10             	mov    0x10(%ebp),%edx
 1005243:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1005247:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 100524e:	00 
 100524f:	8b 55 0c             	mov    0xc(%ebp),%edx
 1005252:	89 54 24 04          	mov    %edx,0x4(%esp)
 1005256:	89 04 24             	mov    %eax,(%esp)
 1005259:	e8 32 0c 00 00       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 100525e:	8b 45 08             	mov    0x8(%ebp),%eax
 1005261:	c7 00 38 93 00 01    	movl   $0x1009338,(%eax)
 1005267:	8b 45 08             	mov    0x8(%ebp),%eax
 100526a:	8b 55 18             	mov    0x18(%ebp),%edx
 100526d:	89 50 2c             	mov    %edx,0x2c(%eax)
 1005270:	83 7d 18 01          	cmpl   $0x1,0x18(%ebp)
 1005274:	75 16                	jne    100528c <_ZN6CMarioC1EP5CGameiii+0x74>
 1005276:	8b 45 08             	mov    0x8(%ebp),%eax
 1005279:	c7 40 14 10 00 00 00 	movl   $0x10,0x14(%eax)
 1005280:	8b 45 08             	mov    0x8(%ebp),%eax
 1005283:	c7 40 18 10 00 00 00 	movl   $0x10,0x18(%eax)
 100528a:	eb 14                	jmp    10052a0 <_ZN6CMarioC1EP5CGameiii+0x88>
 100528c:	8b 45 08             	mov    0x8(%ebp),%eax
 100528f:	c7 40 14 10 00 00 00 	movl   $0x10,0x14(%eax)
 1005296:	8b 45 08             	mov    0x8(%ebp),%eax
 1005299:	c7 40 18 20 00 00 00 	movl   $0x20,0x18(%eax)
 10052a0:	8b 45 08             	mov    0x8(%ebp),%eax
 10052a3:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 10052aa:	8b 45 08             	mov    0x8(%ebp),%eax
 10052ad:	c6 40 34 00          	movb   $0x0,0x34(%eax)
 10052b1:	8b 45 08             	mov    0x8(%ebp),%eax
 10052b4:	c7 40 38 00 00 00 00 	movl   $0x0,0x38(%eax)
 10052bb:	8b 45 08             	mov    0x8(%ebp),%eax
 10052be:	c6 40 3d 00          	movb   $0x0,0x3d(%eax)
 10052c2:	8b 45 08             	mov    0x8(%ebp),%eax
 10052c5:	c7 40 40 00 00 00 00 	movl   $0x0,0x40(%eax)
 10052cc:	8b 45 08             	mov    0x8(%ebp),%eax
 10052cf:	c7 40 44 00 00 00 00 	movl   $0x0,0x44(%eax)
 10052d6:	8b 45 08             	mov    0x8(%ebp),%eax
 10052d9:	c7 40 48 00 00 00 00 	movl   $0x0,0x48(%eax)
 10052e0:	c9                   	leave  
 10052e1:	c3                   	ret    

010052e2 <_ZN6CMario8GetImageEPbS0_>:
 10052e2:	55                   	push   %ebp
 10052e3:	89 e5                	mov    %esp,%ebp
 10052e5:	83 ec 28             	sub    $0x28,%esp
 10052e8:	8b 45 10             	mov    0x10(%ebp),%eax
 10052eb:	c6 00 00             	movb   $0x0,(%eax)
 10052ee:	8b 45 08             	mov    0x8(%ebp),%eax
 10052f1:	0f b6 50 34          	movzbl 0x34(%eax),%edx
 10052f5:	8b 45 0c             	mov    0xc(%ebp),%eax
 10052f8:	88 10                	mov    %dl,(%eax)
 10052fa:	8b 45 08             	mov    0x8(%ebp),%eax
 10052fd:	8b 40 48             	mov    0x48(%eax),%eax
 1005300:	85 c0                	test   %eax,%eax
 1005302:	0f 84 bd 00 00 00    	je     10053c5 <_ZN6CMario8GetImageEPbS0_+0xe3>
 1005308:	0f b6 05 3c 38 02 01 	movzbl 0x102383c,%eax
 100530f:	83 f0 01             	xor    $0x1,%eax
 1005312:	a2 3c 38 02 01       	mov    %al,0x102383c
 1005317:	0f b6 05 3c 38 02 01 	movzbl 0x102383c,%eax
 100531e:	84 c0                	test   %al,%al
 1005320:	0f 84 9f 00 00 00    	je     10053c5 <_ZN6CMario8GetImageEPbS0_+0xe3>
 1005326:	8b 45 08             	mov    0x8(%ebp),%eax
 1005329:	8b 40 2c             	mov    0x2c(%eax),%eax
 100532c:	83 f8 01             	cmp    $0x1,%eax
 100532f:	75 46                	jne    1005377 <_ZN6CMario8GetImageEPbS0_+0x95>
 1005331:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 1005338:	eb 30                	jmp    100536a <_ZN6CMario8GetImageEPbS0_+0x88>
 100533a:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 1005341:	eb 18                	jmp    100535b <_ZN6CMario8GetImageEPbS0_+0x79>
 1005343:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1005346:	c1 e0 04             	shl    $0x4,%eax
 1005349:	03 45 f4             	add    -0xc(%ebp),%eax
 100534c:	c7 04 85 e0 fd 02 01 	movl   $0xff000000,0x102fde0(,%eax,4)
 1005353:	00 00 00 ff 
 1005357:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 100535b:	83 7d f4 0f          	cmpl   $0xf,-0xc(%ebp)
 100535f:	0f 9e c0             	setle  %al
 1005362:	84 c0                	test   %al,%al
 1005364:	75 dd                	jne    1005343 <_ZN6CMario8GetImageEPbS0_+0x61>
 1005366:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 100536a:	83 7d f0 0f          	cmpl   $0xf,-0x10(%ebp)
 100536e:	0f 9e c0             	setle  %al
 1005371:	84 c0                	test   %al,%al
 1005373:	75 c5                	jne    100533a <_ZN6CMario8GetImageEPbS0_+0x58>
 1005375:	eb 44                	jmp    10053bb <_ZN6CMario8GetImageEPbS0_+0xd9>
 1005377:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 100537e:	eb 30                	jmp    10053b0 <_ZN6CMario8GetImageEPbS0_+0xce>
 1005380:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 1005387:	eb 18                	jmp    10053a1 <_ZN6CMario8GetImageEPbS0_+0xbf>
 1005389:	8b 45 f0             	mov    -0x10(%ebp),%eax
 100538c:	c1 e0 04             	shl    $0x4,%eax
 100538f:	03 45 f4             	add    -0xc(%ebp),%eax
 1005392:	c7 04 85 e0 fd 02 01 	movl   $0xff000000,0x102fde0(,%eax,4)
 1005399:	00 00 00 ff 
 100539d:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 10053a1:	83 7d f4 0f          	cmpl   $0xf,-0xc(%ebp)
 10053a5:	0f 9e c0             	setle  %al
 10053a8:	84 c0                	test   %al,%al
 10053aa:	75 dd                	jne    1005389 <_ZN6CMario8GetImageEPbS0_+0xa7>
 10053ac:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 10053b0:	83 7d f0 1f          	cmpl   $0x1f,-0x10(%ebp)
 10053b4:	0f 9e c0             	setle  %al
 10053b7:	84 c0                	test   %al,%al
 10053b9:	75 c5                	jne    1005380 <_ZN6CMario8GetImageEPbS0_+0x9e>
 10053bb:	b8 e0 fd 02 01       	mov    $0x102fde0,%eax
 10053c0:	e9 f6 02 00 00       	jmp    10056bb <_ZN6CMario8GetImageEPbS0_+0x3d9>
 10053c5:	8b 45 08             	mov    0x8(%ebp),%eax
 10053c8:	8b 40 44             	mov    0x44(%eax),%eax
 10053cb:	85 c0                	test   %eax,%eax
 10053cd:	0f 84 0c 02 00 00    	je     10055df <_ZN6CMario8GetImageEPbS0_+0x2fd>
 10053d3:	a1 40 38 02 01       	mov    0x1023840,%eax
 10053d8:	3d 00 a0 ff 00       	cmp    $0xffa000,%eax
 10053dd:	74 09                	je     10053e8 <_ZN6CMario8GetImageEPbS0_+0x106>
 10053df:	3d b8 c8 ff 00       	cmp    $0xffc8b8,%eax
 10053e4:	74 1c                	je     1005402 <_ZN6CMario8GetImageEPbS0_+0x120>
 10053e6:	eb 34                	jmp    100541c <_ZN6CMario8GetImageEPbS0_+0x13a>
 10053e8:	c7 05 40 38 02 01 b8 	movl   $0xffc8b8,0x1023840
 10053ef:	c8 ff 00 
 10053f2:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%ebp)
 10053f9:	c7 45 e8 00 70 c0 00 	movl   $0xc07000,-0x18(%ebp)
 1005400:	eb 24                	jmp    1005426 <_ZN6CMario8GetImageEPbS0_+0x144>
 1005402:	c7 05 40 38 02 01 ff 	movl   $0xffffff,0x1023840
 1005409:	ff ff 00 
 100540c:	c7 45 ec 00 50 e0 00 	movl   $0xe05000,-0x14(%ebp)
 1005413:	c7 45 e8 00 a0 ff 00 	movl   $0xffa000,-0x18(%ebp)
 100541a:	eb 0a                	jmp    1005426 <_ZN6CMario8GetImageEPbS0_+0x144>
 100541c:	c7 05 40 38 02 01 00 	movl   $0xffa000,0x1023840
 1005423:	a0 ff 00 
 1005426:	a1 40 38 02 01       	mov    0x1023840,%eax
 100542b:	3d 00 a0 ff 00       	cmp    $0xffa000,%eax
 1005430:	0f 84 a8 01 00 00    	je     10055de <_ZN6CMario8GetImageEPbS0_+0x2fc>
 1005436:	8b 45 08             	mov    0x8(%ebp),%eax
 1005439:	8b 40 2c             	mov    0x2c(%eax),%eax
 100543c:	83 f8 01             	cmp    $0x1,%eax
 100543f:	0f 85 ca 00 00 00    	jne    100550f <_ZN6CMario8GetImageEPbS0_+0x22d>
 1005445:	8b 45 08             	mov    0x8(%ebp),%eax
 1005448:	8b 40 30             	mov    0x30(%eax),%eax
 100544b:	c1 e0 0a             	shl    $0xa,%eax
 100544e:	05 00 c0 00 01       	add    $0x100c000,%eax
 1005453:	c7 44 24 08 00 04 00 	movl   $0x400,0x8(%esp)
 100545a:	00 
 100545b:	89 44 24 04          	mov    %eax,0x4(%esp)
 100545f:	c7 04 24 e0 fd 02 01 	movl   $0x102fde0,(%esp)
 1005466:	e8 05 0a 00 00       	call   1005e70 <_Z6memcpyPvPKvi>
 100546b:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 1005472:	e9 84 00 00 00       	jmp    10054fb <_ZN6CMario8GetImageEPbS0_+0x219>
 1005477:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 100547e:	eb 6c                	jmp    10054ec <_ZN6CMario8GetImageEPbS0_+0x20a>
 1005480:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1005483:	c1 e0 04             	shl    $0x4,%eax
 1005486:	03 45 f4             	add    -0xc(%ebp),%eax
 1005489:	8b 04 85 e0 fd 02 01 	mov    0x102fde0(,%eax,4),%eax
 1005490:	3d 00 50 e0 00       	cmp    $0xe05000,%eax
 1005495:	74 28                	je     10054bf <_ZN6CMario8GetImageEPbS0_+0x1dd>
 1005497:	3d 00 a0 ff 00       	cmp    $0xffa000,%eax
 100549c:	74 09                	je     10054a7 <_ZN6CMario8GetImageEPbS0_+0x1c5>
 100549e:	3d 00 88 88 00       	cmp    $0x888800,%eax
 10054a3:	74 2f                	je     10054d4 <_ZN6CMario8GetImageEPbS0_+0x1f2>
 10054a5:	eb 41                	jmp    10054e8 <_ZN6CMario8GetImageEPbS0_+0x206>
 10054a7:	8b 15 40 38 02 01    	mov    0x1023840,%edx
 10054ad:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10054b0:	c1 e0 04             	shl    $0x4,%eax
 10054b3:	03 45 f4             	add    -0xc(%ebp),%eax
 10054b6:	89 14 85 e0 fd 02 01 	mov    %edx,0x102fde0(,%eax,4)
 10054bd:	eb 29                	jmp    10054e8 <_ZN6CMario8GetImageEPbS0_+0x206>
 10054bf:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10054c2:	c1 e0 04             	shl    $0x4,%eax
 10054c5:	03 45 f4             	add    -0xc(%ebp),%eax
 10054c8:	8b 55 ec             	mov    -0x14(%ebp),%edx
 10054cb:	89 14 85 e0 fd 02 01 	mov    %edx,0x102fde0(,%eax,4)
 10054d2:	eb 14                	jmp    10054e8 <_ZN6CMario8GetImageEPbS0_+0x206>
 10054d4:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10054d7:	c1 e0 04             	shl    $0x4,%eax
 10054da:	03 45 f4             	add    -0xc(%ebp),%eax
 10054dd:	8b 55 e8             	mov    -0x18(%ebp),%edx
 10054e0:	89 14 85 e0 fd 02 01 	mov    %edx,0x102fde0(,%eax,4)
 10054e7:	90                   	nop
 10054e8:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 10054ec:	83 7d f4 0f          	cmpl   $0xf,-0xc(%ebp)
 10054f0:	0f 9e c0             	setle  %al
 10054f3:	84 c0                	test   %al,%al
 10054f5:	75 89                	jne    1005480 <_ZN6CMario8GetImageEPbS0_+0x19e>
 10054f7:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 10054fb:	83 7d f0 0f          	cmpl   $0xf,-0x10(%ebp)
 10054ff:	0f 9e c0             	setle  %al
 1005502:	84 c0                	test   %al,%al
 1005504:	0f 85 6d ff ff ff    	jne    1005477 <_ZN6CMario8GetImageEPbS0_+0x195>
 100550a:	e9 c5 00 00 00       	jmp    10055d4 <_ZN6CMario8GetImageEPbS0_+0x2f2>
 100550f:	8b 45 08             	mov    0x8(%ebp),%eax
 1005512:	8b 40 30             	mov    0x30(%eax),%eax
 1005515:	c1 e0 0b             	shl    $0xb,%eax
 1005518:	05 00 d8 00 01       	add    $0x100d800,%eax
 100551d:	c7 44 24 08 00 08 00 	movl   $0x800,0x8(%esp)
 1005524:	00 
 1005525:	89 44 24 04          	mov    %eax,0x4(%esp)
 1005529:	c7 04 24 e0 fd 02 01 	movl   $0x102fde0,(%esp)
 1005530:	e8 3b 09 00 00       	call   1005e70 <_Z6memcpyPvPKvi>
 1005535:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 100553c:	e9 84 00 00 00       	jmp    10055c5 <_ZN6CMario8GetImageEPbS0_+0x2e3>
 1005541:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 1005548:	eb 6c                	jmp    10055b6 <_ZN6CMario8GetImageEPbS0_+0x2d4>
 100554a:	8b 45 f0             	mov    -0x10(%ebp),%eax
 100554d:	c1 e0 04             	shl    $0x4,%eax
 1005550:	03 45 f4             	add    -0xc(%ebp),%eax
 1005553:	8b 04 85 e0 fd 02 01 	mov    0x102fde0(,%eax,4),%eax
 100555a:	3d 00 50 e0 00       	cmp    $0xe05000,%eax
 100555f:	74 28                	je     1005589 <_ZN6CMario8GetImageEPbS0_+0x2a7>
 1005561:	3d 00 a0 ff 00       	cmp    $0xffa000,%eax
 1005566:	74 09                	je     1005571 <_ZN6CMario8GetImageEPbS0_+0x28f>
 1005568:	3d 00 88 88 00       	cmp    $0x888800,%eax
 100556d:	74 2f                	je     100559e <_ZN6CMario8GetImageEPbS0_+0x2bc>
 100556f:	eb 41                	jmp    10055b2 <_ZN6CMario8GetImageEPbS0_+0x2d0>
 1005571:	8b 15 40 38 02 01    	mov    0x1023840,%edx
 1005577:	8b 45 f0             	mov    -0x10(%ebp),%eax
 100557a:	c1 e0 04             	shl    $0x4,%eax
 100557d:	03 45 f4             	add    -0xc(%ebp),%eax
 1005580:	89 14 85 e0 fd 02 01 	mov    %edx,0x102fde0(,%eax,4)
 1005587:	eb 29                	jmp    10055b2 <_ZN6CMario8GetImageEPbS0_+0x2d0>
 1005589:	8b 45 f0             	mov    -0x10(%ebp),%eax
 100558c:	c1 e0 04             	shl    $0x4,%eax
 100558f:	03 45 f4             	add    -0xc(%ebp),%eax
 1005592:	8b 55 ec             	mov    -0x14(%ebp),%edx
 1005595:	89 14 85 e0 fd 02 01 	mov    %edx,0x102fde0(,%eax,4)
 100559c:	eb 14                	jmp    10055b2 <_ZN6CMario8GetImageEPbS0_+0x2d0>
 100559e:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10055a1:	c1 e0 04             	shl    $0x4,%eax
 10055a4:	03 45 f4             	add    -0xc(%ebp),%eax
 10055a7:	8b 55 e8             	mov    -0x18(%ebp),%edx
 10055aa:	89 14 85 e0 fd 02 01 	mov    %edx,0x102fde0(,%eax,4)
 10055b1:	90                   	nop
 10055b2:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 10055b6:	83 7d f4 0f          	cmpl   $0xf,-0xc(%ebp)
 10055ba:	0f 9e c0             	setle  %al
 10055bd:	84 c0                	test   %al,%al
 10055bf:	75 89                	jne    100554a <_ZN6CMario8GetImageEPbS0_+0x268>
 10055c1:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 10055c5:	83 7d f0 1f          	cmpl   $0x1f,-0x10(%ebp)
 10055c9:	0f 9e c0             	setle  %al
 10055cc:	84 c0                	test   %al,%al
 10055ce:	0f 85 6d ff ff ff    	jne    1005541 <_ZN6CMario8GetImageEPbS0_+0x25f>
 10055d4:	b8 e0 fd 02 01       	mov    $0x102fde0,%eax
 10055d9:	e9 dd 00 00 00       	jmp    10056bb <_ZN6CMario8GetImageEPbS0_+0x3d9>
 10055de:	90                   	nop
 10055df:	8b 45 08             	mov    0x8(%ebp),%eax
 10055e2:	8b 40 2c             	mov    0x2c(%eax),%eax
 10055e5:	83 f8 01             	cmp    $0x1,%eax
 10055e8:	74 07                	je     10055f1 <_ZN6CMario8GetImageEPbS0_+0x30f>
 10055ea:	83 f8 02             	cmp    $0x2,%eax
 10055ed:	74 15                	je     1005604 <_ZN6CMario8GetImageEPbS0_+0x322>
 10055ef:	eb 26                	jmp    1005617 <_ZN6CMario8GetImageEPbS0_+0x335>
 10055f1:	8b 45 08             	mov    0x8(%ebp),%eax
 10055f4:	8b 40 30             	mov    0x30(%eax),%eax
 10055f7:	c1 e0 0a             	shl    $0xa,%eax
 10055fa:	05 00 c0 00 01       	add    $0x100c000,%eax
 10055ff:	e9 b7 00 00 00       	jmp    10056bb <_ZN6CMario8GetImageEPbS0_+0x3d9>
 1005604:	8b 45 08             	mov    0x8(%ebp),%eax
 1005607:	8b 40 30             	mov    0x30(%eax),%eax
 100560a:	c1 e0 0b             	shl    $0xb,%eax
 100560d:	05 00 d8 00 01       	add    $0x100d800,%eax
 1005612:	e9 a4 00 00 00       	jmp    10056bb <_ZN6CMario8GetImageEPbS0_+0x3d9>
 1005617:	8b 45 08             	mov    0x8(%ebp),%eax
 100561a:	8b 40 30             	mov    0x30(%eax),%eax
 100561d:	c1 e0 0b             	shl    $0xb,%eax
 1005620:	05 00 d8 00 01       	add    $0x100d800,%eax
 1005625:	c7 44 24 08 00 08 00 	movl   $0x800,0x8(%esp)
 100562c:	00 
 100562d:	89 44 24 04          	mov    %eax,0x4(%esp)
 1005631:	c7 04 24 e0 fd 02 01 	movl   $0x102fde0,(%esp)
 1005638:	e8 33 08 00 00       	call   1005e70 <_Z6memcpyPvPKvi>
 100563d:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 1005644:	eb 65                	jmp    10056ab <_ZN6CMario8GetImageEPbS0_+0x3c9>
 1005646:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 100564d:	eb 4d                	jmp    100569c <_ZN6CMario8GetImageEPbS0_+0x3ba>
 100564f:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1005652:	c1 e0 04             	shl    $0x4,%eax
 1005655:	03 45 f4             	add    -0xc(%ebp),%eax
 1005658:	8b 04 85 e0 fd 02 01 	mov    0x102fde0(,%eax,4),%eax
 100565f:	3d 00 88 88 00       	cmp    $0x888800,%eax
 1005664:	74 1d                	je     1005683 <_ZN6CMario8GetImageEPbS0_+0x3a1>
 1005666:	3d 00 50 e0 00       	cmp    $0xe05000,%eax
 100566b:	75 2b                	jne    1005698 <_ZN6CMario8GetImageEPbS0_+0x3b6>
 100566d:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1005670:	c1 e0 04             	shl    $0x4,%eax
 1005673:	03 45 f4             	add    -0xc(%ebp),%eax
 1005676:	c7 04 85 e0 fd 02 01 	movl   $0xffd8a0,0x102fde0(,%eax,4)
 100567d:	a0 d8 ff 00 
 1005681:	eb 15                	jmp    1005698 <_ZN6CMario8GetImageEPbS0_+0x3b6>
 1005683:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1005686:	c1 e0 04             	shl    $0x4,%eax
 1005689:	03 45 f4             	add    -0xc(%ebp),%eax
 100568c:	c7 04 85 e0 fd 02 01 	movl   $0xe05000,0x102fde0(,%eax,4)
 1005693:	00 50 e0 00 
 1005697:	90                   	nop
 1005698:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 100569c:	83 7d f4 0f          	cmpl   $0xf,-0xc(%ebp)
 10056a0:	0f 9e c0             	setle  %al
 10056a3:	84 c0                	test   %al,%al
 10056a5:	75 a8                	jne    100564f <_ZN6CMario8GetImageEPbS0_+0x36d>
 10056a7:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 10056ab:	83 7d f0 1f          	cmpl   $0x1f,-0x10(%ebp)
 10056af:	0f 9e c0             	setle  %al
 10056b2:	84 c0                	test   %al,%al
 10056b4:	75 90                	jne    1005646 <_ZN6CMario8GetImageEPbS0_+0x364>
 10056b6:	b8 e0 fd 02 01       	mov    $0x102fde0,%eax
 10056bb:	c9                   	leave  
 10056bc:	c3                   	ret    
 10056bd:	90                   	nop

010056be <_ZN6CMario4JumpEv>:
 10056be:	55                   	push   %ebp
 10056bf:	89 e5                	mov    %esp,%ebp
 10056c1:	83 ec 18             	sub    $0x18,%esp
 10056c4:	8b 45 08             	mov    0x8(%ebp),%eax
 10056c7:	8b 40 08             	mov    0x8(%eax),%eax
 10056ca:	83 f8 01             	cmp    $0x1,%eax
 10056cd:	75 4e                	jne    100571d <_ZN6CMario4JumpEv+0x5f>
 10056cf:	8b 45 08             	mov    0x8(%ebp),%eax
 10056d2:	0f b6 40 3d          	movzbl 0x3d(%eax),%eax
 10056d6:	83 f0 01             	xor    $0x1,%eax
 10056d9:	84 c0                	test   %al,%al
 10056db:	75 43                	jne    1005720 <_ZN6CMario4JumpEv+0x62>
 10056dd:	8b 45 08             	mov    0x8(%ebp),%eax
 10056e0:	8b 40 20             	mov    0x20(%eax),%eax
 10056e3:	c7 44 24 04 08 00 00 	movl   $0x8,0x4(%esp)
 10056ea:	00 
 10056eb:	89 04 24             	mov    %eax,(%esp)
 10056ee:	e8 15 eb ff ff       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 10056f3:	8b 45 08             	mov    0x8(%ebp),%eax
 10056f6:	8b 40 24             	mov    0x24(%eax),%eax
 10056f9:	83 f8 05             	cmp    $0x5,%eax
 10056fc:	7e 0c                	jle    100570a <_ZN6CMario4JumpEv+0x4c>
 10056fe:	8b 45 08             	mov    0x8(%ebp),%eax
 1005701:	c7 40 28 ec ff ff ff 	movl   $0xffffffec,0x28(%eax)
 1005708:	eb 0a                	jmp    1005714 <_ZN6CMario4JumpEv+0x56>
 100570a:	8b 45 08             	mov    0x8(%ebp),%eax
 100570d:	c7 40 28 ee ff ff ff 	movl   $0xffffffee,0x28(%eax)
 1005714:	8b 45 08             	mov    0x8(%ebp),%eax
 1005717:	c6 40 3d 00          	movb   $0x0,0x3d(%eax)
 100571b:	eb 04                	jmp    1005721 <_ZN6CMario4JumpEv+0x63>
 100571d:	90                   	nop
 100571e:	eb 01                	jmp    1005721 <_ZN6CMario4JumpEv+0x63>
 1005720:	90                   	nop
 1005721:	c9                   	leave  
 1005722:	c3                   	ret    
 1005723:	90                   	nop

01005724 <_ZN6CMario4MoveEib>:
 1005724:	55                   	push   %ebp
 1005725:	89 e5                	mov    %esp,%ebp
 1005727:	83 ec 04             	sub    $0x4,%esp
 100572a:	8b 45 10             	mov    0x10(%ebp),%eax
 100572d:	88 45 fc             	mov    %al,-0x4(%ebp)
 1005730:	8b 45 08             	mov    0x8(%ebp),%eax
 1005733:	8b 40 08             	mov    0x8(%eax),%eax
 1005736:	83 f8 01             	cmp    $0x1,%eax
 1005739:	75 3b                	jne    1005776 <_ZN6CMario4MoveEib+0x52>
 100573b:	8b 45 08             	mov    0x8(%ebp),%eax
 100573e:	8b 55 0c             	mov    0xc(%ebp),%edx
 1005741:	89 50 38             	mov    %edx,0x38(%eax)
 1005744:	8b 45 08             	mov    0x8(%ebp),%eax
 1005747:	0f b6 55 fc          	movzbl -0x4(%ebp),%edx
 100574b:	88 50 3c             	mov    %dl,0x3c(%eax)
 100574e:	83 7d 0c 03          	cmpl   $0x3,0xc(%ebp)
 1005752:	75 09                	jne    100575d <_ZN6CMario4MoveEib+0x39>
 1005754:	8b 45 08             	mov    0x8(%ebp),%eax
 1005757:	c6 40 34 01          	movb   $0x1,0x34(%eax)
 100575b:	eb 1a                	jmp    1005777 <_ZN6CMario4MoveEib+0x53>
 100575d:	83 7d 0c 04          	cmpl   $0x4,0xc(%ebp)
 1005761:	75 14                	jne    1005777 <_ZN6CMario4MoveEib+0x53>
 1005763:	8b 45 08             	mov    0x8(%ebp),%eax
 1005766:	c6 40 34 00          	movb   $0x0,0x34(%eax)
 100576a:	8b 45 08             	mov    0x8(%ebp),%eax
 100576d:	c7 40 38 03 00 00 00 	movl   $0x3,0x38(%eax)
 1005774:	eb 01                	jmp    1005777 <_ZN6CMario4MoveEib+0x53>
 1005776:	90                   	nop
 1005777:	c9                   	leave  
 1005778:	c3                   	ret    
 1005779:	90                   	nop

0100577a <_ZN6CMario4FireEv>:
 100577a:	55                   	push   %ebp
 100577b:	89 e5                	mov    %esp,%ebp
 100577d:	53                   	push   %ebx
 100577e:	83 ec 24             	sub    $0x24,%esp
 1005781:	8b 45 08             	mov    0x8(%ebp),%eax
 1005784:	8b 40 08             	mov    0x8(%eax),%eax
 1005787:	83 f8 01             	cmp    $0x1,%eax
 100578a:	0f 85 e1 00 00 00    	jne    1005871 <_ZN6CMario4FireEv+0xf7>
 1005790:	8b 45 08             	mov    0x8(%ebp),%eax
 1005793:	8b 40 2c             	mov    0x2c(%eax),%eax
 1005796:	83 f8 03             	cmp    $0x3,%eax
 1005799:	0f 85 d5 00 00 00    	jne    1005874 <_ZN6CMario4FireEv+0xfa>
 100579f:	8b 45 08             	mov    0x8(%ebp),%eax
 10057a2:	8b 40 20             	mov    0x20(%eax),%eax
 10057a5:	c7 44 24 04 03 00 00 	movl   $0x3,0x4(%esp)
 10057ac:	00 
 10057ad:	89 04 24             	mov    %eax,(%esp)
 10057b0:	e8 53 ea ff ff       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 10057b5:	8b 45 08             	mov    0x8(%ebp),%eax
 10057b8:	0f b6 40 34          	movzbl 0x34(%eax),%eax
 10057bc:	84 c0                	test   %al,%al
 10057be:	74 53                	je     1005813 <_ZN6CMario4FireEv+0x99>
 10057c0:	c7 04 24 30 00 00 00 	movl   $0x30,(%esp)
 10057c7:	e8 77 a9 ff ff       	call   1000143 <_Znwj>
 10057cc:	89 c3                	mov    %eax,%ebx
 10057ce:	8b 45 08             	mov    0x8(%ebp),%eax
 10057d1:	8b 40 10             	mov    0x10(%eax),%eax
 10057d4:	8d 48 08             	lea    0x8(%eax),%ecx
 10057d7:	8b 45 08             	mov    0x8(%ebp),%eax
 10057da:	8b 50 0c             	mov    0xc(%eax),%edx
 10057dd:	8b 45 08             	mov    0x8(%ebp),%eax
 10057e0:	8b 40 20             	mov    0x20(%eax),%eax
 10057e3:	c7 44 24 10 01 00 00 	movl   $0x1,0x10(%esp)
 10057ea:	00 
 10057eb:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 10057ef:	89 54 24 08          	mov    %edx,0x8(%esp)
 10057f3:	89 44 24 04          	mov    %eax,0x4(%esp)
 10057f7:	89 1c 24             	mov    %ebx,(%esp)
 10057fa:	e8 15 c1 ff ff       	call   1001914 <_ZN7CBulletC1EP5CGameiii>
 10057ff:	8b 45 08             	mov    0x8(%ebp),%eax
 1005802:	8b 40 20             	mov    0x20(%eax),%eax
 1005805:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1005809:	89 04 24             	mov    %eax,(%esp)
 100580c:	e8 cf e9 ff ff       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 1005811:	eb 62                	jmp    1005875 <_ZN6CMario4FireEv+0xfb>
 1005813:	c7 04 24 30 00 00 00 	movl   $0x30,(%esp)
 100581a:	e8 24 a9 ff ff       	call   1000143 <_Znwj>
 100581f:	89 c3                	mov    %eax,%ebx
 1005821:	8b 45 08             	mov    0x8(%ebp),%eax
 1005824:	8b 40 10             	mov    0x10(%eax),%eax
 1005827:	8d 48 08             	lea    0x8(%eax),%ecx
 100582a:	8b 45 08             	mov    0x8(%ebp),%eax
 100582d:	8b 50 0c             	mov    0xc(%eax),%edx
 1005830:	8b 45 08             	mov    0x8(%ebp),%eax
 1005833:	8b 40 14             	mov    0x14(%eax),%eax
 1005836:	01 d0                	add    %edx,%eax
 1005838:	8d 50 f8             	lea    -0x8(%eax),%edx
 100583b:	8b 45 08             	mov    0x8(%ebp),%eax
 100583e:	8b 40 20             	mov    0x20(%eax),%eax
 1005841:	c7 44 24 10 00 00 00 	movl   $0x0,0x10(%esp)
 1005848:	00 
 1005849:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 100584d:	89 54 24 08          	mov    %edx,0x8(%esp)
 1005851:	89 44 24 04          	mov    %eax,0x4(%esp)
 1005855:	89 1c 24             	mov    %ebx,(%esp)
 1005858:	e8 b7 c0 ff ff       	call   1001914 <_ZN7CBulletC1EP5CGameiii>
 100585d:	8b 45 08             	mov    0x8(%ebp),%eax
 1005860:	8b 40 20             	mov    0x20(%eax),%eax
 1005863:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1005867:	89 04 24             	mov    %eax,(%esp)
 100586a:	e8 71 e9 ff ff       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 100586f:	eb 04                	jmp    1005875 <_ZN6CMario4FireEv+0xfb>
 1005871:	90                   	nop
 1005872:	eb 01                	jmp    1005875 <_ZN6CMario4FireEv+0xfb>
 1005874:	90                   	nop
 1005875:	83 c4 24             	add    $0x24,%esp
 1005878:	5b                   	pop    %ebx
 1005879:	5d                   	pop    %ebp
 100587a:	c3                   	ret    
 100587b:	90                   	nop

0100587c <_ZN6CMario5ClockEv>:
 100587c:	55                   	push   %ebp
 100587d:	89 e5                	mov    %esp,%ebp
 100587f:	53                   	push   %ebx
 1005880:	83 ec 24             	sub    $0x24,%esp
 1005883:	8b 45 08             	mov    0x8(%ebp),%eax
 1005886:	8b 40 44             	mov    0x44(%eax),%eax
 1005889:	85 c0                	test   %eax,%eax
 100588b:	74 2f                	je     10058bc <_ZN6CMario5ClockEv+0x40>
 100588d:	8b 45 08             	mov    0x8(%ebp),%eax
 1005890:	8b 40 44             	mov    0x44(%eax),%eax
 1005893:	8d 50 ff             	lea    -0x1(%eax),%edx
 1005896:	8b 45 08             	mov    0x8(%ebp),%eax
 1005899:	89 50 44             	mov    %edx,0x44(%eax)
 100589c:	8b 45 08             	mov    0x8(%ebp),%eax
 100589f:	8b 40 44             	mov    0x44(%eax),%eax
 10058a2:	85 c0                	test   %eax,%eax
 10058a4:	75 16                	jne    10058bc <_ZN6CMario5ClockEv+0x40>
 10058a6:	8b 45 08             	mov    0x8(%ebp),%eax
 10058a9:	8b 40 20             	mov    0x20(%eax),%eax
 10058ac:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 10058b3:	00 
 10058b4:	89 04 24             	mov    %eax,(%esp)
 10058b7:	e8 6a e9 ff ff       	call   1004226 <_ZN5CGame13PlayBackMusicEi>
 10058bc:	8b 45 08             	mov    0x8(%ebp),%eax
 10058bf:	8b 40 48             	mov    0x48(%eax),%eax
 10058c2:	85 c0                	test   %eax,%eax
 10058c4:	74 0f                	je     10058d5 <_ZN6CMario5ClockEv+0x59>
 10058c6:	8b 45 08             	mov    0x8(%ebp),%eax
 10058c9:	8b 40 48             	mov    0x48(%eax),%eax
 10058cc:	8d 50 ff             	lea    -0x1(%eax),%edx
 10058cf:	8b 45 08             	mov    0x8(%ebp),%eax
 10058d2:	89 50 48             	mov    %edx,0x48(%eax)
 10058d5:	8b 45 08             	mov    0x8(%ebp),%eax
 10058d8:	8b 40 40             	mov    0x40(%eax),%eax
 10058db:	83 f8 01             	cmp    $0x1,%eax
 10058de:	75 46                	jne    1005926 <_ZN6CMario5ClockEv+0xaa>
 10058e0:	8b 45 08             	mov    0x8(%ebp),%eax
 10058e3:	8b 40 2c             	mov    0x2c(%eax),%eax
 10058e6:	83 f8 01             	cmp    $0x1,%eax
 10058e9:	75 25                	jne    1005910 <_ZN6CMario5ClockEv+0x94>
 10058eb:	8b 45 08             	mov    0x8(%ebp),%eax
 10058ee:	c7 40 2c 02 00 00 00 	movl   $0x2,0x2c(%eax)
 10058f5:	8b 45 08             	mov    0x8(%ebp),%eax
 10058f8:	8b 40 10             	mov    0x10(%eax),%eax
 10058fb:	8d 50 f0             	lea    -0x10(%eax),%edx
 10058fe:	8b 45 08             	mov    0x8(%ebp),%eax
 1005901:	89 50 10             	mov    %edx,0x10(%eax)
 1005904:	8b 45 08             	mov    0x8(%ebp),%eax
 1005907:	c7 40 18 20 00 00 00 	movl   $0x20,0x18(%eax)
 100590e:	eb 0a                	jmp    100591a <_ZN6CMario5ClockEv+0x9e>
 1005910:	8b 45 08             	mov    0x8(%ebp),%eax
 1005913:	c7 40 2c 03 00 00 00 	movl   $0x3,0x2c(%eax)
 100591a:	8b 45 08             	mov    0x8(%ebp),%eax
 100591d:	c7 40 40 00 00 00 00 	movl   $0x0,0x40(%eax)
 1005924:	eb 38                	jmp    100595e <_ZN6CMario5ClockEv+0xe2>
 1005926:	8b 45 08             	mov    0x8(%ebp),%eax
 1005929:	8b 40 40             	mov    0x40(%eax),%eax
 100592c:	83 f8 ff             	cmp    $0xffffffff,%eax
 100592f:	75 2d                	jne    100595e <_ZN6CMario5ClockEv+0xe2>
 1005931:	8b 45 08             	mov    0x8(%ebp),%eax
 1005934:	c7 40 2c 01 00 00 00 	movl   $0x1,0x2c(%eax)
 100593b:	8b 45 08             	mov    0x8(%ebp),%eax
 100593e:	8b 40 10             	mov    0x10(%eax),%eax
 1005941:	8d 50 10             	lea    0x10(%eax),%edx
 1005944:	8b 45 08             	mov    0x8(%ebp),%eax
 1005947:	89 50 10             	mov    %edx,0x10(%eax)
 100594a:	8b 45 08             	mov    0x8(%ebp),%eax
 100594d:	c7 40 18 10 00 00 00 	movl   $0x10,0x18(%eax)
 1005954:	8b 45 08             	mov    0x8(%ebp),%eax
 1005957:	c7 40 40 00 00 00 00 	movl   $0x0,0x40(%eax)
 100595e:	8b 45 08             	mov    0x8(%ebp),%eax
 1005961:	8b 40 38             	mov    0x38(%eax),%eax
 1005964:	83 f8 03             	cmp    $0x3,%eax
 1005967:	75 2c                	jne    1005995 <_ZN6CMario5ClockEv+0x119>
 1005969:	8b 45 08             	mov    0x8(%ebp),%eax
 100596c:	0f b6 40 34          	movzbl 0x34(%eax),%eax
 1005970:	84 c0                	test   %al,%al
 1005972:	74 11                	je     1005985 <_ZN6CMario5ClockEv+0x109>
 1005974:	8b 45 08             	mov    0x8(%ebp),%eax
 1005977:	8b 40 24             	mov    0x24(%eax),%eax
 100597a:	8d 50 ff             	lea    -0x1(%eax),%edx
 100597d:	8b 45 08             	mov    0x8(%ebp),%eax
 1005980:	89 50 24             	mov    %edx,0x24(%eax)
 1005983:	eb 0f                	jmp    1005994 <_ZN6CMario5ClockEv+0x118>
 1005985:	8b 45 08             	mov    0x8(%ebp),%eax
 1005988:	8b 40 24             	mov    0x24(%eax),%eax
 100598b:	8d 50 01             	lea    0x1(%eax),%edx
 100598e:	8b 45 08             	mov    0x8(%ebp),%eax
 1005991:	89 50 24             	mov    %edx,0x24(%eax)
 1005994:	90                   	nop
 1005995:	8b 45 08             	mov    0x8(%ebp),%eax
 1005998:	0f b6 40 3c          	movzbl 0x3c(%eax),%eax
 100599c:	84 c0                	test   %al,%al
 100599e:	74 2e                	je     10059ce <_ZN6CMario5ClockEv+0x152>
 10059a0:	8b 45 08             	mov    0x8(%ebp),%eax
 10059a3:	8b 40 24             	mov    0x24(%eax),%eax
 10059a6:	83 f8 0a             	cmp    $0xa,%eax
 10059a9:	7e 0c                	jle    10059b7 <_ZN6CMario5ClockEv+0x13b>
 10059ab:	8b 45 08             	mov    0x8(%ebp),%eax
 10059ae:	c7 40 24 0a 00 00 00 	movl   $0xa,0x24(%eax)
 10059b5:	eb 43                	jmp    10059fa <_ZN6CMario5ClockEv+0x17e>
 10059b7:	8b 45 08             	mov    0x8(%ebp),%eax
 10059ba:	8b 40 24             	mov    0x24(%eax),%eax
 10059bd:	83 f8 f6             	cmp    $0xfffffff6,%eax
 10059c0:	7d 38                	jge    10059fa <_ZN6CMario5ClockEv+0x17e>
 10059c2:	8b 45 08             	mov    0x8(%ebp),%eax
 10059c5:	c7 40 24 f6 ff ff ff 	movl   $0xfffffff6,0x24(%eax)
 10059cc:	eb 2c                	jmp    10059fa <_ZN6CMario5ClockEv+0x17e>
 10059ce:	8b 45 08             	mov    0x8(%ebp),%eax
 10059d1:	8b 40 24             	mov    0x24(%eax),%eax
 10059d4:	83 f8 05             	cmp    $0x5,%eax
 10059d7:	7e 0c                	jle    10059e5 <_ZN6CMario5ClockEv+0x169>
 10059d9:	8b 45 08             	mov    0x8(%ebp),%eax
 10059dc:	c7 40 24 05 00 00 00 	movl   $0x5,0x24(%eax)
 10059e3:	eb 15                	jmp    10059fa <_ZN6CMario5ClockEv+0x17e>
 10059e5:	8b 45 08             	mov    0x8(%ebp),%eax
 10059e8:	8b 40 24             	mov    0x24(%eax),%eax
 10059eb:	83 f8 fb             	cmp    $0xfffffffb,%eax
 10059ee:	7d 0a                	jge    10059fa <_ZN6CMario5ClockEv+0x17e>
 10059f0:	8b 45 08             	mov    0x8(%ebp),%eax
 10059f3:	c7 40 24 fb ff ff ff 	movl   $0xfffffffb,0x24(%eax)
 10059fa:	8b 45 08             	mov    0x8(%ebp),%eax
 10059fd:	8b 40 08             	mov    0x8(%eax),%eax
 1005a00:	83 f8 01             	cmp    $0x1,%eax
 1005a03:	75 51                	jne    1005a56 <_ZN6CMario5ClockEv+0x1da>
 1005a05:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a08:	0f b6 40 3d          	movzbl 0x3d(%eax),%eax
 1005a0c:	84 c0                	test   %al,%al
 1005a0e:	74 3c                	je     1005a4c <_ZN6CMario5ClockEv+0x1d0>
 1005a10:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a13:	8b 40 24             	mov    0x24(%eax),%eax
 1005a16:	85 c0                	test   %eax,%eax
 1005a18:	74 26                	je     1005a40 <_ZN6CMario5ClockEv+0x1c4>
 1005a1a:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a1d:	8b 40 30             	mov    0x30(%eax),%eax
 1005a20:	8d 50 01             	lea    0x1(%eax),%edx
 1005a23:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a26:	89 50 30             	mov    %edx,0x30(%eax)
 1005a29:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a2c:	8b 40 30             	mov    0x30(%eax),%eax
 1005a2f:	83 f8 03             	cmp    $0x3,%eax
 1005a32:	7e 22                	jle    1005a56 <_ZN6CMario5ClockEv+0x1da>
 1005a34:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a37:	c7 40 30 01 00 00 00 	movl   $0x1,0x30(%eax)
 1005a3e:	eb 16                	jmp    1005a56 <_ZN6CMario5ClockEv+0x1da>
 1005a40:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a43:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 1005a4a:	eb 0a                	jmp    1005a56 <_ZN6CMario5ClockEv+0x1da>
 1005a4c:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a4f:	c7 40 30 04 00 00 00 	movl   $0x4,0x30(%eax)
 1005a56:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a59:	8b 40 28             	mov    0x28(%eax),%eax
 1005a5c:	8d 50 02             	lea    0x2(%eax),%edx
 1005a5f:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a62:	89 50 28             	mov    %edx,0x28(%eax)
 1005a65:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a68:	8b 40 28             	mov    0x28(%eax),%eax
 1005a6b:	83 f8 14             	cmp    $0x14,%eax
 1005a6e:	7e 0a                	jle    1005a7a <_ZN6CMario5ClockEv+0x1fe>
 1005a70:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a73:	c7 40 28 14 00 00 00 	movl   $0x14,0x28(%eax)
 1005a7a:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a7d:	c6 40 3d 00          	movb   $0x0,0x3d(%eax)
 1005a81:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a84:	8b 40 24             	mov    0x24(%eax),%eax
 1005a87:	85 c0                	test   %eax,%eax
 1005a89:	75 0a                	jne    1005a95 <_ZN6CMario5ClockEv+0x219>
 1005a8b:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a8e:	8b 40 28             	mov    0x28(%eax),%eax
 1005a91:	85 c0                	test   %eax,%eax
 1005a93:	74 68                	je     1005afd <_ZN6CMario5ClockEv+0x281>
 1005a95:	8b 45 08             	mov    0x8(%ebp),%eax
 1005a98:	8b 40 28             	mov    0x28(%eax),%eax
 1005a9b:	89 45 f4             	mov    %eax,-0xc(%ebp)
 1005a9e:	8b 45 08             	mov    0x8(%ebp),%eax
 1005aa1:	8b 58 28             	mov    0x28(%eax),%ebx
 1005aa4:	8b 45 08             	mov    0x8(%ebp),%eax
 1005aa7:	8b 48 24             	mov    0x24(%eax),%ecx
 1005aaa:	8b 55 08             	mov    0x8(%ebp),%edx
 1005aad:	8b 45 08             	mov    0x8(%ebp),%eax
 1005ab0:	8b 40 20             	mov    0x20(%eax),%eax
 1005ab3:	89 5c 24 0c          	mov    %ebx,0xc(%esp)
 1005ab7:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 1005abb:	89 54 24 04          	mov    %edx,0x4(%esp)
 1005abf:	89 04 24             	mov    %eax,(%esp)
 1005ac2:	e8 63 d9 ff ff       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 1005ac7:	89 45 f0             	mov    %eax,-0x10(%ebp)
 1005aca:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1005acd:	83 e0 01             	and    $0x1,%eax
 1005ad0:	84 c0                	test   %al,%al
 1005ad2:	74 0a                	je     1005ade <_ZN6CMario5ClockEv+0x262>
 1005ad4:	8b 45 08             	mov    0x8(%ebp),%eax
 1005ad7:	c7 40 24 00 00 00 00 	movl   $0x0,0x24(%eax)
 1005ade:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1005ae1:	83 e0 02             	and    $0x2,%eax
 1005ae4:	85 c0                	test   %eax,%eax
 1005ae6:	74 15                	je     1005afd <_ZN6CMario5ClockEv+0x281>
 1005ae8:	8b 45 08             	mov    0x8(%ebp),%eax
 1005aeb:	8b 40 28             	mov    0x28(%eax),%eax
 1005aee:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 1005af1:	75 0a                	jne    1005afd <_ZN6CMario5ClockEv+0x281>
 1005af3:	8b 45 08             	mov    0x8(%ebp),%eax
 1005af6:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%eax)
 1005afd:	83 c4 24             	add    $0x24,%esp
 1005b00:	5b                   	pop    %ebx
 1005b01:	5d                   	pop    %ebp
 1005b02:	c3                   	ret    
 1005b03:	90                   	nop

01005b04 <_ZN6CMario4BumpEP7CObjectib>:
 1005b04:	55                   	push   %ebp
 1005b05:	89 e5                	mov    %esp,%ebp
 1005b07:	83 ec 28             	sub    $0x28,%esp
 1005b0a:	8b 45 14             	mov    0x14(%ebp),%eax
 1005b0d:	88 45 f4             	mov    %al,-0xc(%ebp)
 1005b10:	8b 45 08             	mov    0x8(%ebp),%eax
 1005b13:	8b 40 08             	mov    0x8(%eax),%eax
 1005b16:	83 f8 01             	cmp    $0x1,%eax
 1005b19:	0f 85 94 01 00 00    	jne    1005cb3 <_ZN6CMario4BumpEP7CObjectib+0x1af>
 1005b1f:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005b22:	8b 40 04             	mov    0x4(%eax),%eax
 1005b25:	83 f8 05             	cmp    $0x5,%eax
 1005b28:	75 26                	jne    1005b50 <_ZN6CMario4BumpEP7CObjectib+0x4c>
 1005b2a:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005b2d:	8b 00                	mov    (%eax),%eax
 1005b2f:	83 c0 10             	add    $0x10,%eax
 1005b32:	8b 10                	mov    (%eax),%edx
 1005b34:	8b 45 08             	mov    0x8(%ebp),%eax
 1005b37:	c7 44 24 08 03 00 00 	movl   $0x3,0x8(%esp)
 1005b3e:	00 
 1005b3f:	89 44 24 04          	mov    %eax,0x4(%esp)
 1005b43:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005b46:	89 04 24             	mov    %eax,(%esp)
 1005b49:	ff d2                	call   *%edx
 1005b4b:	e9 64 01 00 00       	jmp    1005cb4 <_ZN6CMario4BumpEP7CObjectib+0x1b0>
 1005b50:	8b 45 08             	mov    0x8(%ebp),%eax
 1005b53:	8b 40 44             	mov    0x44(%eax),%eax
 1005b56:	85 c0                	test   %eax,%eax
 1005b58:	74 37                	je     1005b91 <_ZN6CMario4BumpEP7CObjectib+0x8d>
 1005b5a:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005b5d:	8b 40 04             	mov    0x4(%eax),%eax
 1005b60:	83 f8 03             	cmp    $0x3,%eax
 1005b63:	75 2c                	jne    1005b91 <_ZN6CMario4BumpEP7CObjectib+0x8d>
 1005b65:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005b68:	8b 40 08             	mov    0x8(%eax),%eax
 1005b6b:	83 f8 01             	cmp    $0x1,%eax
 1005b6e:	75 21                	jne    1005b91 <_ZN6CMario4BumpEP7CObjectib+0x8d>
 1005b70:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005b73:	8b 00                	mov    (%eax),%eax
 1005b75:	83 c0 10             	add    $0x10,%eax
 1005b78:	8b 10                	mov    (%eax),%edx
 1005b7a:	8b 45 08             	mov    0x8(%ebp),%eax
 1005b7d:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 1005b84:	00 
 1005b85:	89 44 24 04          	mov    %eax,0x4(%esp)
 1005b89:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005b8c:	89 04 24             	mov    %eax,(%esp)
 1005b8f:	ff d2                	call   *%edx
 1005b91:	83 7d 10 01          	cmpl   $0x1,0x10(%ebp)
 1005b95:	0f 85 c3 00 00 00    	jne    1005c5e <_ZN6CMario4BumpEP7CObjectib+0x15a>
 1005b9b:	8b 45 08             	mov    0x8(%ebp),%eax
 1005b9e:	c6 40 3d 01          	movb   $0x1,0x3d(%eax)
 1005ba2:	8b 45 08             	mov    0x8(%ebp),%eax
 1005ba5:	8b 40 24             	mov    0x24(%eax),%eax
 1005ba8:	85 c0                	test   %eax,%eax
 1005baa:	7e 27                	jle    1005bd3 <_ZN6CMario4BumpEP7CObjectib+0xcf>
 1005bac:	8b 45 08             	mov    0x8(%ebp),%eax
 1005baf:	8b 40 38             	mov    0x38(%eax),%eax
 1005bb2:	83 f8 03             	cmp    $0x3,%eax
 1005bb5:	75 0b                	jne    1005bc2 <_ZN6CMario4BumpEP7CObjectib+0xbe>
 1005bb7:	8b 45 08             	mov    0x8(%ebp),%eax
 1005bba:	0f b6 40 34          	movzbl 0x34(%eax),%eax
 1005bbe:	84 c0                	test   %al,%al
 1005bc0:	74 43                	je     1005c05 <_ZN6CMario4BumpEP7CObjectib+0x101>
 1005bc2:	8b 45 08             	mov    0x8(%ebp),%eax
 1005bc5:	8b 40 24             	mov    0x24(%eax),%eax
 1005bc8:	8d 50 ff             	lea    -0x1(%eax),%edx
 1005bcb:	8b 45 08             	mov    0x8(%ebp),%eax
 1005bce:	89 50 24             	mov    %edx,0x24(%eax)
 1005bd1:	eb 32                	jmp    1005c05 <_ZN6CMario4BumpEP7CObjectib+0x101>
 1005bd3:	8b 45 08             	mov    0x8(%ebp),%eax
 1005bd6:	8b 40 24             	mov    0x24(%eax),%eax
 1005bd9:	85 c0                	test   %eax,%eax
 1005bdb:	79 28                	jns    1005c05 <_ZN6CMario4BumpEP7CObjectib+0x101>
 1005bdd:	8b 45 08             	mov    0x8(%ebp),%eax
 1005be0:	8b 40 38             	mov    0x38(%eax),%eax
 1005be3:	83 f8 03             	cmp    $0x3,%eax
 1005be6:	75 0e                	jne    1005bf6 <_ZN6CMario4BumpEP7CObjectib+0xf2>
 1005be8:	8b 45 08             	mov    0x8(%ebp),%eax
 1005beb:	0f b6 40 34          	movzbl 0x34(%eax),%eax
 1005bef:	83 f0 01             	xor    $0x1,%eax
 1005bf2:	84 c0                	test   %al,%al
 1005bf4:	74 0f                	je     1005c05 <_ZN6CMario4BumpEP7CObjectib+0x101>
 1005bf6:	8b 45 08             	mov    0x8(%ebp),%eax
 1005bf9:	8b 40 24             	mov    0x24(%eax),%eax
 1005bfc:	8d 50 01             	lea    0x1(%eax),%edx
 1005bff:	8b 45 08             	mov    0x8(%ebp),%eax
 1005c02:	89 50 24             	mov    %edx,0x24(%eax)
 1005c05:	8b 45 08             	mov    0x8(%ebp),%eax
 1005c08:	8b 40 44             	mov    0x44(%eax),%eax
 1005c0b:	85 c0                	test   %eax,%eax
 1005c0d:	0f 85 a1 00 00 00    	jne    1005cb4 <_ZN6CMario4BumpEP7CObjectib+0x1b0>
 1005c13:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005c16:	8b 40 04             	mov    0x4(%eax),%eax
 1005c19:	83 f8 03             	cmp    $0x3,%eax
 1005c1c:	0f 85 92 00 00 00    	jne    1005cb4 <_ZN6CMario4BumpEP7CObjectib+0x1b0>
 1005c22:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005c25:	8b 40 08             	mov    0x8(%eax),%eax
 1005c28:	83 f8 01             	cmp    $0x1,%eax
 1005c2b:	0f 85 83 00 00 00    	jne    1005cb4 <_ZN6CMario4BumpEP7CObjectib+0x1b0>
 1005c31:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005c34:	8b 00                	mov    (%eax),%eax
 1005c36:	83 c0 10             	add    $0x10,%eax
 1005c39:	8b 10                	mov    (%eax),%edx
 1005c3b:	8b 45 08             	mov    0x8(%ebp),%eax
 1005c3e:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 1005c45:	00 
 1005c46:	89 44 24 04          	mov    %eax,0x4(%esp)
 1005c4a:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005c4d:	89 04 24             	mov    %eax,(%esp)
 1005c50:	ff d2                	call   *%edx
 1005c52:	8b 45 08             	mov    0x8(%ebp),%eax
 1005c55:	c7 40 28 f6 ff ff ff 	movl   $0xfffffff6,0x28(%eax)
 1005c5c:	eb 56                	jmp    1005cb4 <_ZN6CMario4BumpEP7CObjectib+0x1b0>
 1005c5e:	83 7d 10 02          	cmpl   $0x2,0x10(%ebp)
 1005c62:	75 50                	jne    1005cb4 <_ZN6CMario4BumpEP7CObjectib+0x1b0>
 1005c64:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005c67:	8b 40 04             	mov    0x4(%eax),%eax
 1005c6a:	83 f8 02             	cmp    $0x2,%eax
 1005c6d:	75 45                	jne    1005cb4 <_ZN6CMario4BumpEP7CObjectib+0x1b0>
 1005c6f:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005c72:	8b 40 08             	mov    0x8(%eax),%eax
 1005c75:	83 f8 01             	cmp    $0x1,%eax
 1005c78:	75 3a                	jne    1005cb4 <_ZN6CMario4BumpEP7CObjectib+0x1b0>
 1005c7a:	8b 45 08             	mov    0x8(%ebp),%eax
 1005c7d:	8b 40 20             	mov    0x20(%eax),%eax
 1005c80:	c7 44 24 04 02 00 00 	movl   $0x2,0x4(%esp)
 1005c87:	00 
 1005c88:	89 04 24             	mov    %eax,(%esp)
 1005c8b:	e8 78 e5 ff ff       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1005c90:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005c93:	8b 00                	mov    (%eax),%eax
 1005c95:	83 c0 10             	add    $0x10,%eax
 1005c98:	8b 10                	mov    (%eax),%edx
 1005c9a:	8b 45 08             	mov    0x8(%ebp),%eax
 1005c9d:	c7 44 24 08 03 00 00 	movl   $0x3,0x8(%esp)
 1005ca4:	00 
 1005ca5:	89 44 24 04          	mov    %eax,0x4(%esp)
 1005ca9:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005cac:	89 04 24             	mov    %eax,(%esp)
 1005caf:	ff d2                	call   *%edx
 1005cb1:	eb 01                	jmp    1005cb4 <_ZN6CMario4BumpEP7CObjectib+0x1b0>
 1005cb3:	90                   	nop
 1005cb4:	c9                   	leave  
 1005cb5:	c3                   	ret    

01005cb6 <_ZN6CMario5BlockEP7CObject>:
 1005cb6:	55                   	push   %ebp
 1005cb7:	89 e5                	mov    %esp,%ebp
 1005cb9:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
 1005cbd:	74 4a                	je     1005d09 <_ZN6CMario5BlockEP7CObject+0x53>
 1005cbf:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005cc2:	8b 40 08             	mov    0x8(%eax),%eax
 1005cc5:	83 f8 02             	cmp    $0x2,%eax
 1005cc8:	75 07                	jne    1005cd1 <_ZN6CMario5BlockEP7CObject+0x1b>
 1005cca:	b8 00 00 00 00       	mov    $0x0,%eax
 1005ccf:	eb 4f                	jmp    1005d20 <_ZN6CMario5BlockEP7CObject+0x6a>
 1005cd1:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005cd4:	8b 40 04             	mov    0x4(%eax),%eax
 1005cd7:	83 f8 05             	cmp    $0x5,%eax
 1005cda:	75 07                	jne    1005ce3 <_ZN6CMario5BlockEP7CObject+0x2d>
 1005cdc:	b8 00 00 00 00       	mov    $0x0,%eax
 1005ce1:	eb 3d                	jmp    1005d20 <_ZN6CMario5BlockEP7CObject+0x6a>
 1005ce3:	8b 45 08             	mov    0x8(%ebp),%eax
 1005ce6:	8b 40 44             	mov    0x44(%eax),%eax
 1005ce9:	85 c0                	test   %eax,%eax
 1005ceb:	75 0a                	jne    1005cf7 <_ZN6CMario5BlockEP7CObject+0x41>
 1005ced:	8b 45 08             	mov    0x8(%ebp),%eax
 1005cf0:	8b 40 48             	mov    0x48(%eax),%eax
 1005cf3:	85 c0                	test   %eax,%eax
 1005cf5:	74 12                	je     1005d09 <_ZN6CMario5BlockEP7CObject+0x53>
 1005cf7:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005cfa:	8b 40 04             	mov    0x4(%eax),%eax
 1005cfd:	83 f8 03             	cmp    $0x3,%eax
 1005d00:	75 07                	jne    1005d09 <_ZN6CMario5BlockEP7CObject+0x53>
 1005d02:	b8 00 00 00 00       	mov    $0x0,%eax
 1005d07:	eb 17                	jmp    1005d20 <_ZN6CMario5BlockEP7CObject+0x6a>
 1005d09:	8b 45 08             	mov    0x8(%ebp),%eax
 1005d0c:	8b 40 08             	mov    0x8(%eax),%eax
 1005d0f:	83 f8 01             	cmp    $0x1,%eax
 1005d12:	75 07                	jne    1005d1b <_ZN6CMario5BlockEP7CObject+0x65>
 1005d14:	b8 01 00 00 00       	mov    $0x1,%eax
 1005d19:	eb 05                	jmp    1005d20 <_ZN6CMario5BlockEP7CObject+0x6a>
 1005d1b:	b8 00 00 00 00       	mov    $0x0,%eax
 1005d20:	5d                   	pop    %ebp
 1005d21:	c3                   	ret    

01005d22 <_ZN6CMario8ResetPosEii>:
 1005d22:	55                   	push   %ebp
 1005d23:	89 e5                	mov    %esp,%ebp
 1005d25:	8b 45 08             	mov    0x8(%ebp),%eax
 1005d28:	8b 55 0c             	mov    0xc(%ebp),%edx
 1005d2b:	89 50 0c             	mov    %edx,0xc(%eax)
 1005d2e:	8b 45 08             	mov    0x8(%ebp),%eax
 1005d31:	8b 55 10             	mov    0x10(%ebp),%edx
 1005d34:	89 50 10             	mov    %edx,0x10(%eax)
 1005d37:	8b 45 08             	mov    0x8(%ebp),%eax
 1005d3a:	c7 40 24 00 00 00 00 	movl   $0x0,0x24(%eax)
 1005d41:	8b 45 08             	mov    0x8(%ebp),%eax
 1005d44:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%eax)
 1005d4b:	5d                   	pop    %ebp
 1005d4c:	c3                   	ret    
 1005d4d:	90                   	nop

01005d4e <_ZN6CMario5IsBigEv>:
 1005d4e:	55                   	push   %ebp
 1005d4f:	89 e5                	mov    %esp,%ebp
 1005d51:	8b 45 08             	mov    0x8(%ebp),%eax
 1005d54:	8b 40 2c             	mov    0x2c(%eax),%eax
 1005d57:	83 f8 01             	cmp    $0x1,%eax
 1005d5a:	0f 95 c0             	setne  %al
 1005d5d:	5d                   	pop    %ebp
 1005d5e:	c3                   	ret    
 1005d5f:	90                   	nop

01005d60 <_ZN6CMario8AddPowerEv>:
 1005d60:	55                   	push   %ebp
 1005d61:	89 e5                	mov    %esp,%ebp
 1005d63:	8b 45 08             	mov    0x8(%ebp),%eax
 1005d66:	c7 40 40 01 00 00 00 	movl   $0x1,0x40(%eax)
 1005d6d:	5d                   	pop    %ebp
 1005d6e:	c3                   	ret    
 1005d6f:	90                   	nop

01005d70 <_ZN6CMario7AddStarEv>:
 1005d70:	55                   	push   %ebp
 1005d71:	89 e5                	mov    %esp,%ebp
 1005d73:	83 ec 18             	sub    $0x18,%esp
 1005d76:	8b 45 08             	mov    0x8(%ebp),%eax
 1005d79:	8b 40 20             	mov    0x20(%eax),%eax
 1005d7c:	c7 44 24 04 02 00 00 	movl   $0x2,0x4(%esp)
 1005d83:	00 
 1005d84:	89 04 24             	mov    %eax,(%esp)
 1005d87:	e8 9a e4 ff ff       	call   1004226 <_ZN5CGame13PlayBackMusicEi>
 1005d8c:	8b 45 08             	mov    0x8(%ebp),%eax
 1005d8f:	c7 40 44 c8 00 00 00 	movl   $0xc8,0x44(%eax)
 1005d96:	c9                   	leave  
 1005d97:	c3                   	ret    

01005d98 <_ZN6CMario6AttackEP7CObjecti>:
 1005d98:	55                   	push   %ebp
 1005d99:	89 e5                	mov    %esp,%ebp
 1005d9b:	83 ec 18             	sub    $0x18,%esp
 1005d9e:	8b 45 08             	mov    0x8(%ebp),%eax
 1005da1:	8b 40 44             	mov    0x44(%eax),%eax
 1005da4:	85 c0                	test   %eax,%eax
 1005da6:	0f 85 be 00 00 00    	jne    1005e6a <_ZN6CMario6AttackEP7CObjecti+0xd2>
 1005dac:	8b 45 08             	mov    0x8(%ebp),%eax
 1005daf:	8b 40 48             	mov    0x48(%eax),%eax
 1005db2:	85 c0                	test   %eax,%eax
 1005db4:	0f 85 b0 00 00 00    	jne    1005e6a <_ZN6CMario6AttackEP7CObjecti+0xd2>
 1005dba:	8b 45 08             	mov    0x8(%ebp),%eax
 1005dbd:	8b 40 08             	mov    0x8(%eax),%eax
 1005dc0:	83 f8 01             	cmp    $0x1,%eax
 1005dc3:	0f 85 a4 00 00 00    	jne    1005e6d <_ZN6CMario6AttackEP7CObjecti+0xd5>
 1005dc9:	8b 45 08             	mov    0x8(%ebp),%eax
 1005dcc:	8b 40 2c             	mov    0x2c(%eax),%eax
 1005dcf:	83 f8 01             	cmp    $0x1,%eax
 1005dd2:	74 2c                	je     1005e00 <_ZN6CMario6AttackEP7CObjecti+0x68>
 1005dd4:	8b 45 08             	mov    0x8(%ebp),%eax
 1005dd7:	8b 40 20             	mov    0x20(%eax),%eax
 1005dda:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 1005de1:	00 
 1005de2:	89 04 24             	mov    %eax,(%esp)
 1005de5:	e8 1e e4 ff ff       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1005dea:	8b 45 08             	mov    0x8(%ebp),%eax
 1005ded:	c7 40 40 ff ff ff ff 	movl   $0xffffffff,0x40(%eax)
 1005df4:	8b 45 08             	mov    0x8(%ebp),%eax
 1005df7:	c7 40 48 28 00 00 00 	movl   $0x28,0x48(%eax)
 1005dfe:	eb 6e                	jmp    1005e6e <_ZN6CMario6AttackEP7CObjecti+0xd6>
 1005e00:	8b 45 08             	mov    0x8(%ebp),%eax
 1005e03:	8b 40 20             	mov    0x20(%eax),%eax
 1005e06:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 1005e0d:	00 
 1005e0e:	89 04 24             	mov    %eax,(%esp)
 1005e11:	e8 10 e4 ff ff       	call   1004226 <_ZN5CGame13PlayBackMusicEi>
 1005e16:	8b 45 08             	mov    0x8(%ebp),%eax
 1005e19:	8b 40 20             	mov    0x20(%eax),%eax
 1005e1c:	c7 44 24 04 05 00 00 	movl   $0x5,0x4(%esp)
 1005e23:	00 
 1005e24:	89 04 24             	mov    %eax,(%esp)
 1005e27:	e8 dc e3 ff ff       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1005e2c:	8b 45 08             	mov    0x8(%ebp),%eax
 1005e2f:	c7 40 08 02 00 00 00 	movl   $0x2,0x8(%eax)
 1005e36:	8b 45 08             	mov    0x8(%ebp),%eax
 1005e39:	c7 40 1c 01 00 00 00 	movl   $0x1,0x1c(%eax)
 1005e40:	8b 45 08             	mov    0x8(%ebp),%eax
 1005e43:	c7 40 30 05 00 00 00 	movl   $0x5,0x30(%eax)
 1005e4a:	8b 45 08             	mov    0x8(%ebp),%eax
 1005e4d:	c7 40 38 00 00 00 00 	movl   $0x0,0x38(%eax)
 1005e54:	8b 45 08             	mov    0x8(%ebp),%eax
 1005e57:	c7 40 24 00 00 00 00 	movl   $0x0,0x24(%eax)
 1005e5e:	8b 45 08             	mov    0x8(%ebp),%eax
 1005e61:	c7 40 28 ec ff ff ff 	movl   $0xffffffec,0x28(%eax)
 1005e68:	eb 04                	jmp    1005e6e <_ZN6CMario6AttackEP7CObjecti+0xd6>
 1005e6a:	90                   	nop
 1005e6b:	eb 01                	jmp    1005e6e <_ZN6CMario6AttackEP7CObjecti+0xd6>
 1005e6d:	90                   	nop
 1005e6e:	c9                   	leave  
 1005e6f:	c3                   	ret    

01005e70 <_Z6memcpyPvPKvi>:
 1005e70:	55                   	push   %ebp
 1005e71:	89 e5                	mov    %esp,%ebp
 1005e73:	57                   	push   %edi
 1005e74:	56                   	push   %esi
 1005e75:	53                   	push   %ebx
 1005e76:	8b 45 10             	mov    0x10(%ebp),%eax
 1005e79:	8b 55 0c             	mov    0xc(%ebp),%edx
 1005e7c:	8b 5d 08             	mov    0x8(%ebp),%ebx
 1005e7f:	89 c1                	mov    %eax,%ecx
 1005e81:	89 d6                	mov    %edx,%esi
 1005e83:	89 df                	mov    %ebx,%edi
 1005e85:	fc                   	cld    
 1005e86:	f3 a4                	rep movsb %ds:(%esi),%es:(%edi)
 1005e88:	8b 45 08             	mov    0x8(%ebp),%eax
 1005e8b:	5b                   	pop    %ebx
 1005e8c:	5e                   	pop    %esi
 1005e8d:	5f                   	pop    %edi
 1005e8e:	5d                   	pop    %ebp
 1005e8f:	c3                   	ret    

01005e90 <_ZN7CObjectC1EP5CGameiiiiii>:
 1005e90:	55                   	push   %ebp
 1005e91:	89 e5                	mov    %esp,%ebp
 1005e93:	8b 45 08             	mov    0x8(%ebp),%eax
 1005e96:	c7 00 58 93 00 01    	movl   $0x1009358,(%eax)
 1005e9c:	8b 45 08             	mov    0x8(%ebp),%eax
 1005e9f:	8b 55 0c             	mov    0xc(%ebp),%edx
 1005ea2:	89 50 20             	mov    %edx,0x20(%eax)
 1005ea5:	8b 45 08             	mov    0x8(%ebp),%eax
 1005ea8:	8b 55 10             	mov    0x10(%ebp),%edx
 1005eab:	89 50 04             	mov    %edx,0x4(%eax)
 1005eae:	8b 45 08             	mov    0x8(%ebp),%eax
 1005eb1:	8b 55 14             	mov    0x14(%ebp),%edx
 1005eb4:	89 50 0c             	mov    %edx,0xc(%eax)
 1005eb7:	8b 45 08             	mov    0x8(%ebp),%eax
 1005eba:	8b 55 18             	mov    0x18(%ebp),%edx
 1005ebd:	89 50 10             	mov    %edx,0x10(%eax)
 1005ec0:	8b 45 08             	mov    0x8(%ebp),%eax
 1005ec3:	8b 55 1c             	mov    0x1c(%ebp),%edx
 1005ec6:	89 50 14             	mov    %edx,0x14(%eax)
 1005ec9:	8b 45 08             	mov    0x8(%ebp),%eax
 1005ecc:	8b 55 20             	mov    0x20(%ebp),%edx
 1005ecf:	89 50 18             	mov    %edx,0x18(%eax)
 1005ed2:	8b 45 08             	mov    0x8(%ebp),%eax
 1005ed5:	8b 55 24             	mov    0x24(%ebp),%edx
 1005ed8:	89 50 1c             	mov    %edx,0x1c(%eax)
 1005edb:	8b 45 08             	mov    0x8(%ebp),%eax
 1005ede:	c7 40 24 00 00 00 00 	movl   $0x0,0x24(%eax)
 1005ee5:	8b 45 08             	mov    0x8(%ebp),%eax
 1005ee8:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%eax)
 1005eef:	8b 45 08             	mov    0x8(%ebp),%eax
 1005ef2:	c7 40 08 01 00 00 00 	movl   $0x1,0x8(%eax)
 1005ef9:	5d                   	pop    %ebp
 1005efa:	c3                   	ret    
 1005efb:	90                   	nop

01005efc <_ZN7CObject5ClockEv>:
 1005efc:	55                   	push   %ebp
 1005efd:	89 e5                	mov    %esp,%ebp
 1005eff:	5d                   	pop    %ebp
 1005f00:	c3                   	ret    
 1005f01:	90                   	nop

01005f02 <_ZN7CObject5BlockEPS_>:
 1005f02:	55                   	push   %ebp
 1005f03:	89 e5                	mov    %esp,%ebp
 1005f05:	8b 45 08             	mov    0x8(%ebp),%eax
 1005f08:	8b 40 08             	mov    0x8(%eax),%eax
 1005f0b:	83 f8 01             	cmp    $0x1,%eax
 1005f0e:	74 07                	je     1005f17 <_ZN7CObject5BlockEPS_+0x15>
 1005f10:	b8 00 00 00 00       	mov    $0x0,%eax
 1005f15:	eb 24                	jmp    1005f3b <_ZN7CObject5BlockEPS_+0x39>
 1005f17:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
 1005f1b:	74 19                	je     1005f36 <_ZN7CObject5BlockEPS_+0x34>
 1005f1d:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005f20:	8b 40 04             	mov    0x4(%eax),%eax
 1005f23:	83 f8 05             	cmp    $0x5,%eax
 1005f26:	75 07                	jne    1005f2f <_ZN7CObject5BlockEPS_+0x2d>
 1005f28:	b8 00 00 00 00       	mov    $0x0,%eax
 1005f2d:	eb 0c                	jmp    1005f3b <_ZN7CObject5BlockEPS_+0x39>
 1005f2f:	b8 01 00 00 00       	mov    $0x1,%eax
 1005f34:	eb 05                	jmp    1005f3b <_ZN7CObject5BlockEPS_+0x39>
 1005f36:	b8 00 00 00 00       	mov    $0x0,%eax
 1005f3b:	5d                   	pop    %ebp
 1005f3c:	c3                   	ret    
 1005f3d:	90                   	nop

01005f3e <_ZN7CObject4BumpEPS_ib>:
 1005f3e:	55                   	push   %ebp
 1005f3f:	89 e5                	mov    %esp,%ebp
 1005f41:	83 ec 04             	sub    $0x4,%esp
 1005f44:	8b 45 14             	mov    0x14(%ebp),%eax
 1005f47:	88 45 fc             	mov    %al,-0x4(%ebp)
 1005f4a:	c9                   	leave  
 1005f4b:	c3                   	ret    

01005f4c <_ZN7CObject6AttackEPS_i>:
 1005f4c:	55                   	push   %ebp
 1005f4d:	89 e5                	mov    %esp,%ebp
 1005f4f:	5d                   	pop    %ebp
 1005f50:	c3                   	ret    
 1005f51:	00 00                	add    %al,(%eax)
	...

01005f54 <_ZN9CPipeBodyC1EP5CGameii>:
 1005f54:	55                   	push   %ebp
 1005f55:	89 e5                	mov    %esp,%ebp
 1005f57:	83 ec 28             	sub    $0x28,%esp
 1005f5a:	8b 45 08             	mov    0x8(%ebp),%eax
 1005f5d:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
 1005f64:	00 
 1005f65:	c7 44 24 18 10 00 00 	movl   $0x10,0x18(%esp)
 1005f6c:	00 
 1005f6d:	c7 44 24 14 20 00 00 	movl   $0x20,0x14(%esp)
 1005f74:	00 
 1005f75:	8b 55 14             	mov    0x14(%ebp),%edx
 1005f78:	89 54 24 10          	mov    %edx,0x10(%esp)
 1005f7c:	8b 55 10             	mov    0x10(%ebp),%edx
 1005f7f:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1005f83:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 1005f8a:	00 
 1005f8b:	8b 55 0c             	mov    0xc(%ebp),%edx
 1005f8e:	89 54 24 04          	mov    %edx,0x4(%esp)
 1005f92:	89 04 24             	mov    %eax,(%esp)
 1005f95:	e8 f6 fe ff ff       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 1005f9a:	8b 45 08             	mov    0x8(%ebp),%eax
 1005f9d:	c7 00 78 93 00 01    	movl   $0x1009378,(%eax)
 1005fa3:	c9                   	leave  
 1005fa4:	c3                   	ret    
 1005fa5:	90                   	nop

01005fa6 <_ZN9CPipeBody8GetImageEPbS0_>:
 1005fa6:	55                   	push   %ebp
 1005fa7:	89 e5                	mov    %esp,%ebp
 1005fa9:	8b 45 10             	mov    0x10(%ebp),%eax
 1005fac:	c6 00 00             	movb   $0x0,(%eax)
 1005faf:	8b 45 0c             	mov    0xc(%ebp),%eax
 1005fb2:	c6 00 00             	movb   $0x0,(%eax)
 1005fb5:	b8 00 08 01 01       	mov    $0x1010800,%eax
 1005fba:	5d                   	pop    %ebp
 1005fbb:	c3                   	ret    

01005fbc <_ZN8CPipeTopC1EP5CGameii>:
 1005fbc:	55                   	push   %ebp
 1005fbd:	89 e5                	mov    %esp,%ebp
 1005fbf:	83 ec 28             	sub    $0x28,%esp
 1005fc2:	8b 45 08             	mov    0x8(%ebp),%eax
 1005fc5:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
 1005fcc:	00 
 1005fcd:	c7 44 24 18 10 00 00 	movl   $0x10,0x18(%esp)
 1005fd4:	00 
 1005fd5:	c7 44 24 14 20 00 00 	movl   $0x20,0x14(%esp)
 1005fdc:	00 
 1005fdd:	8b 55 14             	mov    0x14(%ebp),%edx
 1005fe0:	89 54 24 10          	mov    %edx,0x10(%esp)
 1005fe4:	8b 55 10             	mov    0x10(%ebp),%edx
 1005fe7:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1005feb:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 1005ff2:	00 
 1005ff3:	8b 55 0c             	mov    0xc(%ebp),%edx
 1005ff6:	89 54 24 04          	mov    %edx,0x4(%esp)
 1005ffa:	89 04 24             	mov    %eax,(%esp)
 1005ffd:	e8 8e fe ff ff       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 1006002:	8b 45 08             	mov    0x8(%ebp),%eax
 1006005:	c7 00 98 93 00 01    	movl   $0x1009398,(%eax)
 100600b:	c9                   	leave  
 100600c:	c3                   	ret    
 100600d:	90                   	nop

0100600e <_ZN8CPipeTop8GetImageEPbS0_>:
 100600e:	55                   	push   %ebp
 100600f:	89 e5                	mov    %esp,%ebp
 1006011:	8b 45 10             	mov    0x10(%ebp),%eax
 1006014:	c6 00 00             	movb   $0x0,(%eax)
 1006017:	8b 45 0c             	mov    0xc(%ebp),%eax
 100601a:	c6 00 00             	movb   $0x0,(%eax)
 100601d:	b8 00 10 01 01       	mov    $0x1011000,%eax
 1006022:	5d                   	pop    %ebp
 1006023:	c3                   	ret    

01006024 <_ZN9CQuestionC1EP5CGameiii>:
 1006024:	55                   	push   %ebp
 1006025:	89 e5                	mov    %esp,%ebp
 1006027:	83 ec 28             	sub    $0x28,%esp
 100602a:	8b 45 08             	mov    0x8(%ebp),%eax
 100602d:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
 1006034:	00 
 1006035:	c7 44 24 18 10 00 00 	movl   $0x10,0x18(%esp)
 100603c:	00 
 100603d:	c7 44 24 14 10 00 00 	movl   $0x10,0x14(%esp)
 1006044:	00 
 1006045:	8b 55 14             	mov    0x14(%ebp),%edx
 1006048:	89 54 24 10          	mov    %edx,0x10(%esp)
 100604c:	8b 55 10             	mov    0x10(%ebp),%edx
 100604f:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1006053:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 100605a:	00 
 100605b:	8b 55 0c             	mov    0xc(%ebp),%edx
 100605e:	89 54 24 04          	mov    %edx,0x4(%esp)
 1006062:	89 04 24             	mov    %eax,(%esp)
 1006065:	e8 26 fe ff ff       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 100606a:	8b 45 08             	mov    0x8(%ebp),%eax
 100606d:	c7 00 b8 93 00 01    	movl   $0x10093b8,(%eax)
 1006073:	8b 45 08             	mov    0x8(%ebp),%eax
 1006076:	8b 55 14             	mov    0x14(%ebp),%edx
 1006079:	89 50 2c             	mov    %edx,0x2c(%eax)
 100607c:	8b 45 18             	mov    0x18(%ebp),%eax
 100607f:	83 f8 02             	cmp    $0x2,%eax
 1006082:	74 16                	je     100609a <_ZN9CQuestionC1EP5CGameiii+0x76>
 1006084:	83 f8 03             	cmp    $0x3,%eax
 1006087:	74 1d                	je     10060a6 <_ZN9CQuestionC1EP5CGameiii+0x82>
 1006089:	83 f8 01             	cmp    $0x1,%eax
 100608c:	75 24                	jne    10060b2 <_ZN9CQuestionC1EP5CGameiii+0x8e>
 100608e:	8b 45 08             	mov    0x8(%ebp),%eax
 1006091:	c7 40 34 ff ff ff ff 	movl   $0xffffffff,0x34(%eax)
 1006098:	eb 22                	jmp    10060bc <_ZN9CQuestionC1EP5CGameiii+0x98>
 100609a:	8b 45 08             	mov    0x8(%ebp),%eax
 100609d:	c7 40 34 0a 00 00 00 	movl   $0xa,0x34(%eax)
 10060a4:	eb 16                	jmp    10060bc <_ZN9CQuestionC1EP5CGameiii+0x98>
 10060a6:	8b 45 08             	mov    0x8(%ebp),%eax
 10060a9:	c7 40 34 01 00 00 00 	movl   $0x1,0x34(%eax)
 10060b0:	eb 0a                	jmp    10060bc <_ZN9CQuestionC1EP5CGameiii+0x98>
 10060b2:	8b 45 08             	mov    0x8(%ebp),%eax
 10060b5:	c7 40 34 00 00 00 00 	movl   $0x0,0x34(%eax)
 10060bc:	c9                   	leave  
 10060bd:	c3                   	ret    

010060be <_ZN9CQuestion8GetImageEPbS0_>:
 10060be:	55                   	push   %ebp
 10060bf:	89 e5                	mov    %esp,%ebp
 10060c1:	8b 45 10             	mov    0x10(%ebp),%eax
 10060c4:	c6 00 00             	movb   $0x0,(%eax)
 10060c7:	8b 45 0c             	mov    0xc(%ebp),%eax
 10060ca:	c6 00 00             	movb   $0x0,(%eax)
 10060cd:	8b 45 08             	mov    0x8(%ebp),%eax
 10060d0:	8b 40 34             	mov    0x34(%eax),%eax
 10060d3:	85 c0                	test   %eax,%eax
 10060d5:	75 07                	jne    10060de <_ZN9CQuestion8GetImageEPbS0_+0x20>
 10060d7:	b8 00 28 01 01       	mov    $0x1012800,%eax
 10060dc:	eb 0d                	jmp    10060eb <_ZN9CQuestion8GetImageEPbS0_+0x2d>
 10060de:	a1 60 53 02 01       	mov    0x1025360,%eax
 10060e3:	c1 e0 0a             	shl    $0xa,%eax
 10060e6:	05 00 1c 01 01       	add    $0x1011c00,%eax
 10060eb:	5d                   	pop    %ebp
 10060ec:	c3                   	ret    
 10060ed:	90                   	nop

010060ee <_ZN9CQuestion6MoveUpEv>:
 10060ee:	55                   	push   %ebp
 10060ef:	89 e5                	mov    %esp,%ebp
 10060f1:	83 ec 18             	sub    $0x18,%esp
 10060f4:	8b 55 08             	mov    0x8(%ebp),%edx
 10060f7:	8b 45 08             	mov    0x8(%ebp),%eax
 10060fa:	8b 40 20             	mov    0x20(%eax),%eax
 10060fd:	c7 44 24 0c fc ff ff 	movl   $0xfffffffc,0xc(%esp)
 1006104:	ff 
 1006105:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 100610c:	00 
 100610d:	89 54 24 04          	mov    %edx,0x4(%esp)
 1006111:	89 04 24             	mov    %eax,(%esp)
 1006114:	e8 11 d3 ff ff       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 1006119:	8b 45 08             	mov    0x8(%ebp),%eax
 100611c:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 1006123:	c9                   	leave  
 1006124:	c3                   	ret    
 1006125:	90                   	nop

01006126 <_ZN9CQuestion6AttackEP7CObjecti>:
 1006126:	55                   	push   %ebp
 1006127:	89 e5                	mov    %esp,%ebp
 1006129:	53                   	push   %ebx
 100612a:	83 ec 24             	sub    $0x24,%esp
 100612d:	8b 45 08             	mov    0x8(%ebp),%eax
 1006130:	8b 40 34             	mov    0x34(%eax),%eax
 1006133:	85 c0                	test   %eax,%eax
 1006135:	0f 84 2e 01 00 00    	je     1006269 <_ZN9CQuestion6AttackEP7CObjecti+0x143>
 100613b:	8b 45 08             	mov    0x8(%ebp),%eax
 100613e:	8b 40 34             	mov    0x34(%eax),%eax
 1006141:	83 f8 ff             	cmp    $0xffffffff,%eax
 1006144:	0f 85 a9 00 00 00    	jne    10061f3 <_ZN9CQuestion6AttackEP7CObjecti+0xcd>
 100614a:	8b 45 0c             	mov    0xc(%ebp),%eax
 100614d:	89 04 24             	mov    %eax,(%esp)
 1006150:	e8 f9 fb ff ff       	call   1005d4e <_ZN6CMario5IsBigEv>
 1006155:	84 c0                	test   %al,%al
 1006157:	74 48                	je     10061a1 <_ZN9CQuestion6AttackEP7CObjecti+0x7b>
 1006159:	c7 04 24 34 00 00 00 	movl   $0x34,(%esp)
 1006160:	e8 de 9f ff ff       	call   1000143 <_Znwj>
 1006165:	89 c3                	mov    %eax,%ebx
 1006167:	8b 45 08             	mov    0x8(%ebp),%eax
 100616a:	8b 48 10             	mov    0x10(%eax),%ecx
 100616d:	8b 45 08             	mov    0x8(%ebp),%eax
 1006170:	8b 50 0c             	mov    0xc(%eax),%edx
 1006173:	8b 45 08             	mov    0x8(%ebp),%eax
 1006176:	8b 40 20             	mov    0x20(%eax),%eax
 1006179:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 100617d:	89 54 24 08          	mov    %edx,0x8(%esp)
 1006181:	89 44 24 04          	mov    %eax,0x4(%esp)
 1006185:	89 1c 24             	mov    %ebx,(%esp)
 1006188:	e8 6f bf ff ff       	call   10020fc <_ZN7CFlowerC1EP5CGameii>
 100618d:	8b 45 08             	mov    0x8(%ebp),%eax
 1006190:	8b 40 20             	mov    0x20(%eax),%eax
 1006193:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 1006197:	89 04 24             	mov    %eax,(%esp)
 100619a:	e8 41 e0 ff ff       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 100619f:	eb 46                	jmp    10061e7 <_ZN9CQuestion6AttackEP7CObjecti+0xc1>
 10061a1:	c7 04 24 30 00 00 00 	movl   $0x30,(%esp)
 10061a8:	e8 96 9f ff ff       	call   1000143 <_Znwj>
 10061ad:	89 c3                	mov    %eax,%ebx
 10061af:	8b 45 08             	mov    0x8(%ebp),%eax
 10061b2:	8b 48 10             	mov    0x10(%eax),%ecx
 10061b5:	8b 45 08             	mov    0x8(%ebp),%eax
 10061b8:	8b 50 0c             	mov    0xc(%eax),%edx
 10061bb:	8b 45 08             	mov    0x8(%ebp),%eax
 10061be:	8b 40 20             	mov    0x20(%eax),%eax
 10061c1:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 10061c5:	89 54 24 08          	mov    %edx,0x8(%esp)
 10061c9:	89 44 24 04          	mov    %eax,0x4(%esp)
 10061cd:	89 1c 24             	mov    %ebx,(%esp)
 10061d0:	e8 b3 c3 ff ff       	call   1002588 <_ZN7CFungusC1EP5CGameii>
 10061d5:	8b 45 08             	mov    0x8(%ebp),%eax
 10061d8:	8b 40 20             	mov    0x20(%eax),%eax
 10061db:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 10061df:	89 04 24             	mov    %eax,(%esp)
 10061e2:	e8 f9 df ff ff       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 10061e7:	8b 45 08             	mov    0x8(%ebp),%eax
 10061ea:	c7 40 34 00 00 00 00 	movl   $0x0,0x34(%eax)
 10061f1:	eb 69                	jmp    100625c <_ZN9CQuestion6AttackEP7CObjecti+0x136>
 10061f3:	c7 04 24 38 00 00 00 	movl   $0x38,(%esp)
 10061fa:	e8 44 9f ff ff       	call   1000143 <_Znwj>
 10061ff:	89 c3                	mov    %eax,%ebx
 1006201:	8b 45 08             	mov    0x8(%ebp),%eax
 1006204:	8b 40 10             	mov    0x10(%eax),%eax
 1006207:	8d 48 f0             	lea    -0x10(%eax),%ecx
 100620a:	8b 45 08             	mov    0x8(%ebp),%eax
 100620d:	8b 50 0c             	mov    0xc(%eax),%edx
 1006210:	8b 45 08             	mov    0x8(%ebp),%eax
 1006213:	8b 40 20             	mov    0x20(%eax),%eax
 1006216:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 100621a:	89 54 24 08          	mov    %edx,0x8(%esp)
 100621e:	89 44 24 04          	mov    %eax,0x4(%esp)
 1006222:	89 1c 24             	mov    %ebx,(%esp)
 1006225:	e8 ae ba ff ff       	call   1001cd8 <_ZN5CCoinC1EP5CGameii>
 100622a:	89 5d f4             	mov    %ebx,-0xc(%ebp)
 100622d:	8b 45 08             	mov    0x8(%ebp),%eax
 1006230:	8b 40 20             	mov    0x20(%eax),%eax
 1006233:	8b 55 f4             	mov    -0xc(%ebp),%edx
 1006236:	89 54 24 04          	mov    %edx,0x4(%esp)
 100623a:	89 04 24             	mov    %eax,(%esp)
 100623d:	e8 9e df ff ff       	call   10041e0 <_ZN5CGame6AddObjEP7CObject>
 1006242:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1006245:	89 04 24             	mov    %eax,(%esp)
 1006248:	e8 3f bc ff ff       	call   1001e8c <_ZN5CCoin7ThrowUpEv>
 100624d:	8b 45 08             	mov    0x8(%ebp),%eax
 1006250:	8b 40 34             	mov    0x34(%eax),%eax
 1006253:	8d 50 ff             	lea    -0x1(%eax),%edx
 1006256:	8b 45 08             	mov    0x8(%ebp),%eax
 1006259:	89 50 34             	mov    %edx,0x34(%eax)
 100625c:	8b 45 08             	mov    0x8(%ebp),%eax
 100625f:	89 04 24             	mov    %eax,(%esp)
 1006262:	e8 87 fe ff ff       	call   10060ee <_ZN9CQuestion6MoveUpEv>
 1006267:	eb 01                	jmp    100626a <_ZN9CQuestion6AttackEP7CObjecti+0x144>
 1006269:	90                   	nop
 100626a:	83 c4 24             	add    $0x24,%esp
 100626d:	5b                   	pop    %ebx
 100626e:	5d                   	pop    %ebp
 100626f:	c3                   	ret    

01006270 <_ZN9CQuestion4BumpEP7CObjectib>:
 1006270:	55                   	push   %ebp
 1006271:	89 e5                	mov    %esp,%ebp
 1006273:	83 ec 28             	sub    $0x28,%esp
 1006276:	8b 45 14             	mov    0x14(%ebp),%eax
 1006279:	88 45 f4             	mov    %al,-0xc(%ebp)
 100627c:	0f b6 45 f4          	movzbl -0xc(%ebp),%eax
 1006280:	83 f0 01             	xor    $0x1,%eax
 1006283:	84 c0                	test   %al,%al
 1006285:	75 39                	jne    10062c0 <_ZN9CQuestion4BumpEP7CObjectib+0x50>
 1006287:	8b 45 0c             	mov    0xc(%ebp),%eax
 100628a:	8b 40 04             	mov    0x4(%eax),%eax
 100628d:	83 f8 03             	cmp    $0x3,%eax
 1006290:	75 2f                	jne    10062c1 <_ZN9CQuestion4BumpEP7CObjectib+0x51>
 1006292:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006295:	8b 40 08             	mov    0x8(%eax),%eax
 1006298:	83 f8 01             	cmp    $0x1,%eax
 100629b:	75 24                	jne    10062c1 <_ZN9CQuestion4BumpEP7CObjectib+0x51>
 100629d:	8b 45 0c             	mov    0xc(%ebp),%eax
 10062a0:	8b 00                	mov    (%eax),%eax
 10062a2:	83 c0 10             	add    $0x10,%eax
 10062a5:	8b 10                	mov    (%eax),%edx
 10062a7:	8b 45 08             	mov    0x8(%ebp),%eax
 10062aa:	c7 44 24 08 03 00 00 	movl   $0x3,0x8(%esp)
 10062b1:	00 
 10062b2:	89 44 24 04          	mov    %eax,0x4(%esp)
 10062b6:	8b 45 0c             	mov    0xc(%ebp),%eax
 10062b9:	89 04 24             	mov    %eax,(%esp)
 10062bc:	ff d2                	call   *%edx
 10062be:	eb 01                	jmp    10062c1 <_ZN9CQuestion4BumpEP7CObjectib+0x51>
 10062c0:	90                   	nop
 10062c1:	c9                   	leave  
 10062c2:	c3                   	ret    
 10062c3:	90                   	nop

010062c4 <_ZN9CQuestion5BlockEP7CObject>:
 10062c4:	55                   	push   %ebp
 10062c5:	89 e5                	mov    %esp,%ebp
 10062c7:	b8 00 00 00 00       	mov    $0x0,%eax
 10062cc:	5d                   	pop    %ebp
 10062cd:	c3                   	ret    

010062ce <_ZN9CQuestion5ClockEv>:
 10062ce:	55                   	push   %ebp
 10062cf:	89 e5                	mov    %esp,%ebp
 10062d1:	83 ec 18             	sub    $0x18,%esp
 10062d4:	8b 45 08             	mov    0x8(%ebp),%eax
 10062d7:	8b 50 10             	mov    0x10(%eax),%edx
 10062da:	8b 45 08             	mov    0x8(%ebp),%eax
 10062dd:	8b 40 2c             	mov    0x2c(%eax),%eax
 10062e0:	39 c2                	cmp    %eax,%edx
 10062e2:	74 4d                	je     1006331 <_ZN9CQuestion5ClockEv+0x63>
 10062e4:	8b 45 08             	mov    0x8(%ebp),%eax
 10062e7:	8b 40 30             	mov    0x30(%eax),%eax
 10062ea:	8d 50 01             	lea    0x1(%eax),%edx
 10062ed:	8b 45 08             	mov    0x8(%ebp),%eax
 10062f0:	89 50 30             	mov    %edx,0x30(%eax)
 10062f3:	8b 45 08             	mov    0x8(%ebp),%eax
 10062f6:	8b 40 30             	mov    0x30(%eax),%eax
 10062f9:	83 f8 03             	cmp    $0x3,%eax
 10062fc:	75 34                	jne    1006332 <_ZN9CQuestion5ClockEv+0x64>
 10062fe:	8b 45 08             	mov    0x8(%ebp),%eax
 1006301:	8b 50 2c             	mov    0x2c(%eax),%edx
 1006304:	8b 45 08             	mov    0x8(%ebp),%eax
 1006307:	8b 40 10             	mov    0x10(%eax),%eax
 100630a:	89 d1                	mov    %edx,%ecx
 100630c:	29 c1                	sub    %eax,%ecx
 100630e:	8b 55 08             	mov    0x8(%ebp),%edx
 1006311:	8b 45 08             	mov    0x8(%ebp),%eax
 1006314:	8b 40 20             	mov    0x20(%eax),%eax
 1006317:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 100631b:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 1006322:	00 
 1006323:	89 54 24 04          	mov    %edx,0x4(%esp)
 1006327:	89 04 24             	mov    %eax,(%esp)
 100632a:	e8 fb d0 ff ff       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 100632f:	eb 01                	jmp    1006332 <_ZN9CQuestion5ClockEv+0x64>
 1006331:	90                   	nop
 1006332:	c9                   	leave  
 1006333:	c3                   	ret    

01006334 <_ZN6CSound4InitEv>:
 1006334:	55                   	push   %ebp
 1006335:	89 e5                	mov    %esp,%ebp
 1006337:	b8 01 00 00 00       	mov    $0x1,%eax
 100633c:	5d                   	pop    %ebp
 100633d:	c3                   	ret    

0100633e <_ZN6CSound10AddChannelEPKvmb>:
 100633e:	55                   	push   %ebp
 100633f:	89 e5                	mov    %esp,%ebp
 1006341:	83 ec 04             	sub    $0x4,%esp
 1006344:	8b 45 14             	mov    0x14(%ebp),%eax
 1006347:	88 45 fc             	mov    %al,-0x4(%ebp)
 100634a:	b8 00 00 00 00       	mov    $0x0,%eax
 100634f:	c9                   	leave  
 1006350:	c3                   	ret    
 1006351:	90                   	nop

01006352 <_ZN6CSound13DeleteChannelEPv>:
 1006352:	55                   	push   %ebp
 1006353:	89 e5                	mov    %esp,%ebp
 1006355:	5d                   	pop    %ebp
 1006356:	c3                   	ret    
 1006357:	90                   	nop

01006358 <_ZN6CSound8ReadDataEPvi>:
 1006358:	55                   	push   %ebp
 1006359:	89 e5                	mov    %esp,%ebp
 100635b:	5d                   	pop    %ebp
 100635c:	c3                   	ret    
 100635d:	90                   	nop

0100635e <_ZN6CSound4StopEv>:
 100635e:	55                   	push   %ebp
 100635f:	89 e5                	mov    %esp,%ebp
 1006361:	5d                   	pop    %ebp
 1006362:	c3                   	ret    
 1006363:	90                   	nop

01006364 <_ZN6CSoundD1Ev>:
 1006364:	55                   	push   %ebp
 1006365:	89 e5                	mov    %esp,%ebp
 1006367:	5d                   	pop    %ebp
 1006368:	c3                   	ret    
 1006369:	00 00                	add    %al,(%eax)
	...

0100636c <_ZN9CSoundManC1Ev>:
 100636c:	55                   	push   %ebp
 100636d:	89 e5                	mov    %esp,%ebp
 100636f:	8b 45 08             	mov    0x8(%ebp),%eax
 1006372:	c7 00 00 00 00 00    	movl   $0x0,(%eax)
 1006378:	5d                   	pop    %ebp
 1006379:	c3                   	ret    

0100637a <_ZN9CSoundMan8SetSoundEP6CSound>:
 100637a:	55                   	push   %ebp
 100637b:	89 e5                	mov    %esp,%ebp
 100637d:	8b 45 08             	mov    0x8(%ebp),%eax
 1006380:	8b 55 0c             	mov    0xc(%ebp),%edx
 1006383:	89 50 04             	mov    %edx,0x4(%eax)
 1006386:	5d                   	pop    %ebp
 1006387:	c3                   	ret    

01006388 <_ZN9CSoundMan13PlayBackMusicEi>:
 1006388:	55                   	push   %ebp
 1006389:	89 e5                	mov    %esp,%ebp
 100638b:	83 ec 18             	sub    $0x18,%esp
 100638e:	8b 45 08             	mov    0x8(%ebp),%eax
 1006391:	8b 00                	mov    (%eax),%eax
 1006393:	85 c0                	test   %eax,%eax
 1006395:	74 17                	je     10063ae <_ZN9CSoundMan13PlayBackMusicEi+0x26>
 1006397:	8b 45 08             	mov    0x8(%ebp),%eax
 100639a:	8b 10                	mov    (%eax),%edx
 100639c:	8b 45 08             	mov    0x8(%ebp),%eax
 100639f:	8b 40 04             	mov    0x4(%eax),%eax
 10063a2:	89 54 24 04          	mov    %edx,0x4(%esp)
 10063a6:	89 04 24             	mov    %eax,(%esp)
 10063a9:	e8 a4 ff ff ff       	call   1006352 <_ZN6CSound13DeleteChannelEPv>
 10063ae:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
 10063b2:	75 0b                	jne    10063bf <_ZN9CSoundMan13PlayBackMusicEi+0x37>
 10063b4:	8b 45 08             	mov    0x8(%ebp),%eax
 10063b7:	c7 00 00 00 00 00    	movl   $0x0,(%eax)
 10063bd:	eb 3f                	jmp    10063fe <_ZN9CSoundMan13PlayBackMusicEi+0x76>
 10063bf:	8b 45 0c             	mov    0xc(%ebp),%eax
 10063c2:	83 e8 01             	sub    $0x1,%eax
 10063c5:	8b 04 85 e8 05 03 01 	mov    0x10305e8(,%eax,4),%eax
 10063cc:	89 c1                	mov    %eax,%ecx
 10063ce:	8b 45 0c             	mov    0xc(%ebp),%eax
 10063d1:	83 e8 01             	sub    $0x1,%eax
 10063d4:	8b 14 85 e0 05 03 01 	mov    0x10305e0(,%eax,4),%edx
 10063db:	8b 45 08             	mov    0x8(%ebp),%eax
 10063de:	8b 40 04             	mov    0x4(%eax),%eax
 10063e1:	c7 44 24 0c 01 00 00 	movl   $0x1,0xc(%esp)
 10063e8:	00 
 10063e9:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 10063ed:	89 54 24 04          	mov    %edx,0x4(%esp)
 10063f1:	89 04 24             	mov    %eax,(%esp)
 10063f4:	e8 45 ff ff ff       	call   100633e <_ZN6CSound10AddChannelEPKvmb>
 10063f9:	8b 55 08             	mov    0x8(%ebp),%edx
 10063fc:	89 02                	mov    %eax,(%edx)
 10063fe:	c9                   	leave  
 10063ff:	c3                   	ret    

01006400 <_ZN9CSoundMan9PlaySoundENS_8SOUNDNUME>:
 1006400:	55                   	push   %ebp
 1006401:	89 e5                	mov    %esp,%ebp
 1006403:	83 ec 18             	sub    $0x18,%esp
 1006406:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006409:	83 f8 0a             	cmp    $0xa,%eax
 100640c:	0f 87 0f 02 00 00    	ja     1006621 <_ZN9CSoundMan9PlaySoundENS_8SOUNDNUME+0x221>
 1006412:	8b 04 85 cc 93 00 01 	mov    0x10093cc(,%eax,4),%eax
 1006419:	ff e0                	jmp    *%eax
 100641b:	a1 f4 05 03 01       	mov    0x10305f4,%eax
 1006420:	89 c1                	mov    %eax,%ecx
 1006422:	8b 15 f0 05 03 01    	mov    0x10305f0,%edx
 1006428:	8b 45 08             	mov    0x8(%ebp),%eax
 100642b:	8b 40 04             	mov    0x4(%eax),%eax
 100642e:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 1006435:	00 
 1006436:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 100643a:	89 54 24 04          	mov    %edx,0x4(%esp)
 100643e:	89 04 24             	mov    %eax,(%esp)
 1006441:	e8 f8 fe ff ff       	call   100633e <_ZN6CSound10AddChannelEPKvmb>
 1006446:	e9 d6 01 00 00       	jmp    1006621 <_ZN9CSoundMan9PlaySoundENS_8SOUNDNUME+0x221>
 100644b:	a1 fc 05 03 01       	mov    0x10305fc,%eax
 1006450:	89 c1                	mov    %eax,%ecx
 1006452:	8b 15 f8 05 03 01    	mov    0x10305f8,%edx
 1006458:	8b 45 08             	mov    0x8(%ebp),%eax
 100645b:	8b 40 04             	mov    0x4(%eax),%eax
 100645e:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 1006465:	00 
 1006466:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 100646a:	89 54 24 04          	mov    %edx,0x4(%esp)
 100646e:	89 04 24             	mov    %eax,(%esp)
 1006471:	e8 c8 fe ff ff       	call   100633e <_ZN6CSound10AddChannelEPKvmb>
 1006476:	e9 a6 01 00 00       	jmp    1006621 <_ZN9CSoundMan9PlaySoundENS_8SOUNDNUME+0x221>
 100647b:	a1 04 06 03 01       	mov    0x1030604,%eax
 1006480:	89 c1                	mov    %eax,%ecx
 1006482:	8b 15 00 06 03 01    	mov    0x1030600,%edx
 1006488:	8b 45 08             	mov    0x8(%ebp),%eax
 100648b:	8b 40 04             	mov    0x4(%eax),%eax
 100648e:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 1006495:	00 
 1006496:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 100649a:	89 54 24 04          	mov    %edx,0x4(%esp)
 100649e:	89 04 24             	mov    %eax,(%esp)
 10064a1:	e8 98 fe ff ff       	call   100633e <_ZN6CSound10AddChannelEPKvmb>
 10064a6:	e9 76 01 00 00       	jmp    1006621 <_ZN9CSoundMan9PlaySoundENS_8SOUNDNUME+0x221>
 10064ab:	a1 0c 06 03 01       	mov    0x103060c,%eax
 10064b0:	89 c1                	mov    %eax,%ecx
 10064b2:	8b 15 08 06 03 01    	mov    0x1030608,%edx
 10064b8:	8b 45 08             	mov    0x8(%ebp),%eax
 10064bb:	8b 40 04             	mov    0x4(%eax),%eax
 10064be:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 10064c5:	00 
 10064c6:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 10064ca:	89 54 24 04          	mov    %edx,0x4(%esp)
 10064ce:	89 04 24             	mov    %eax,(%esp)
 10064d1:	e8 68 fe ff ff       	call   100633e <_ZN6CSound10AddChannelEPKvmb>
 10064d6:	e9 46 01 00 00       	jmp    1006621 <_ZN9CSoundMan9PlaySoundENS_8SOUNDNUME+0x221>
 10064db:	a1 14 06 03 01       	mov    0x1030614,%eax
 10064e0:	89 c1                	mov    %eax,%ecx
 10064e2:	8b 15 10 06 03 01    	mov    0x1030610,%edx
 10064e8:	8b 45 08             	mov    0x8(%ebp),%eax
 10064eb:	8b 40 04             	mov    0x4(%eax),%eax
 10064ee:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 10064f5:	00 
 10064f6:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 10064fa:	89 54 24 04          	mov    %edx,0x4(%esp)
 10064fe:	89 04 24             	mov    %eax,(%esp)
 1006501:	e8 38 fe ff ff       	call   100633e <_ZN6CSound10AddChannelEPKvmb>
 1006506:	e9 16 01 00 00       	jmp    1006621 <_ZN9CSoundMan9PlaySoundENS_8SOUNDNUME+0x221>
 100650b:	a1 1c 06 03 01       	mov    0x103061c,%eax
 1006510:	89 c1                	mov    %eax,%ecx
 1006512:	8b 15 18 06 03 01    	mov    0x1030618,%edx
 1006518:	8b 45 08             	mov    0x8(%ebp),%eax
 100651b:	8b 40 04             	mov    0x4(%eax),%eax
 100651e:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 1006525:	00 
 1006526:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 100652a:	89 54 24 04          	mov    %edx,0x4(%esp)
 100652e:	89 04 24             	mov    %eax,(%esp)
 1006531:	e8 08 fe ff ff       	call   100633e <_ZN6CSound10AddChannelEPKvmb>
 1006536:	e9 e6 00 00 00       	jmp    1006621 <_ZN9CSoundMan9PlaySoundENS_8SOUNDNUME+0x221>
 100653b:	a1 24 06 03 01       	mov    0x1030624,%eax
 1006540:	89 c1                	mov    %eax,%ecx
 1006542:	8b 15 20 06 03 01    	mov    0x1030620,%edx
 1006548:	8b 45 08             	mov    0x8(%ebp),%eax
 100654b:	8b 40 04             	mov    0x4(%eax),%eax
 100654e:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 1006555:	00 
 1006556:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 100655a:	89 54 24 04          	mov    %edx,0x4(%esp)
 100655e:	89 04 24             	mov    %eax,(%esp)
 1006561:	e8 d8 fd ff ff       	call   100633e <_ZN6CSound10AddChannelEPKvmb>
 1006566:	e9 b6 00 00 00       	jmp    1006621 <_ZN9CSoundMan9PlaySoundENS_8SOUNDNUME+0x221>
 100656b:	a1 2c 06 03 01       	mov    0x103062c,%eax
 1006570:	89 c1                	mov    %eax,%ecx
 1006572:	8b 15 28 06 03 01    	mov    0x1030628,%edx
 1006578:	8b 45 08             	mov    0x8(%ebp),%eax
 100657b:	8b 40 04             	mov    0x4(%eax),%eax
 100657e:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 1006585:	00 
 1006586:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 100658a:	89 54 24 04          	mov    %edx,0x4(%esp)
 100658e:	89 04 24             	mov    %eax,(%esp)
 1006591:	e8 a8 fd ff ff       	call   100633e <_ZN6CSound10AddChannelEPKvmb>
 1006596:	e9 86 00 00 00       	jmp    1006621 <_ZN9CSoundMan9PlaySoundENS_8SOUNDNUME+0x221>
 100659b:	a1 34 06 03 01       	mov    0x1030634,%eax
 10065a0:	89 c1                	mov    %eax,%ecx
 10065a2:	8b 15 30 06 03 01    	mov    0x1030630,%edx
 10065a8:	8b 45 08             	mov    0x8(%ebp),%eax
 10065ab:	8b 40 04             	mov    0x4(%eax),%eax
 10065ae:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 10065b5:	00 
 10065b6:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 10065ba:	89 54 24 04          	mov    %edx,0x4(%esp)
 10065be:	89 04 24             	mov    %eax,(%esp)
 10065c1:	e8 78 fd ff ff       	call   100633e <_ZN6CSound10AddChannelEPKvmb>
 10065c6:	eb 59                	jmp    1006621 <_ZN9CSoundMan9PlaySoundENS_8SOUNDNUME+0x221>
 10065c8:	a1 3c 06 03 01       	mov    0x103063c,%eax
 10065cd:	89 c1                	mov    %eax,%ecx
 10065cf:	8b 15 38 06 03 01    	mov    0x1030638,%edx
 10065d5:	8b 45 08             	mov    0x8(%ebp),%eax
 10065d8:	8b 40 04             	mov    0x4(%eax),%eax
 10065db:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 10065e2:	00 
 10065e3:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 10065e7:	89 54 24 04          	mov    %edx,0x4(%esp)
 10065eb:	89 04 24             	mov    %eax,(%esp)
 10065ee:	e8 4b fd ff ff       	call   100633e <_ZN6CSound10AddChannelEPKvmb>
 10065f3:	eb 2c                	jmp    1006621 <_ZN9CSoundMan9PlaySoundENS_8SOUNDNUME+0x221>
 10065f5:	a1 44 06 03 01       	mov    0x1030644,%eax
 10065fa:	89 c1                	mov    %eax,%ecx
 10065fc:	8b 15 40 06 03 01    	mov    0x1030640,%edx
 1006602:	8b 45 08             	mov    0x8(%ebp),%eax
 1006605:	8b 40 04             	mov    0x4(%eax),%eax
 1006608:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 100660f:	00 
 1006610:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 1006614:	89 54 24 04          	mov    %edx,0x4(%esp)
 1006618:	89 04 24             	mov    %eax,(%esp)
 100661b:	e8 1e fd ff ff       	call   100633e <_ZN6CSound10AddChannelEPKvmb>
 1006620:	90                   	nop
 1006621:	c9                   	leave  
 1006622:	c3                   	ret    
	...

01006624 <_ZN5CStarC1EP5CGameii>:
 1006624:	55                   	push   %ebp
 1006625:	89 e5                	mov    %esp,%ebp
 1006627:	83 ec 28             	sub    $0x28,%esp
 100662a:	8b 45 08             	mov    0x8(%ebp),%eax
 100662d:	c7 44 24 1c ff ff ff 	movl   $0xffffffff,0x1c(%esp)
 1006634:	ff 
 1006635:	c7 44 24 18 10 00 00 	movl   $0x10,0x18(%esp)
 100663c:	00 
 100663d:	c7 44 24 14 10 00 00 	movl   $0x10,0x14(%esp)
 1006644:	00 
 1006645:	8b 55 14             	mov    0x14(%ebp),%edx
 1006648:	89 54 24 10          	mov    %edx,0x10(%esp)
 100664c:	8b 55 10             	mov    0x10(%ebp),%edx
 100664f:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1006653:	c7 44 24 08 05 00 00 	movl   $0x5,0x8(%esp)
 100665a:	00 
 100665b:	8b 55 0c             	mov    0xc(%ebp),%edx
 100665e:	89 54 24 04          	mov    %edx,0x4(%esp)
 1006662:	89 04 24             	mov    %eax,(%esp)
 1006665:	e8 26 f8 ff ff       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 100666a:	8b 45 08             	mov    0x8(%ebp),%eax
 100666d:	c7 00 00 94 00 01    	movl   $0x1009400,(%eax)
 1006673:	8b 45 08             	mov    0x8(%ebp),%eax
 1006676:	8b 40 20             	mov    0x20(%eax),%eax
 1006679:	c7 44 24 04 07 00 00 	movl   $0x7,0x4(%esp)
 1006680:	00 
 1006681:	89 04 24             	mov    %eax,(%esp)
 1006684:	e8 7f db ff ff       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1006689:	8b 45 08             	mov    0x8(%ebp),%eax
 100668c:	8b 55 14             	mov    0x14(%ebp),%edx
 100668f:	89 50 2c             	mov    %edx,0x2c(%eax)
 1006692:	8b 45 08             	mov    0x8(%ebp),%eax
 1006695:	c7 40 28 ff ff ff ff 	movl   $0xffffffff,0x28(%eax)
 100669c:	8b 45 08             	mov    0x8(%ebp),%eax
 100669f:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 10066a6:	c9                   	leave  
 10066a7:	c3                   	ret    

010066a8 <_ZN5CStar8GetImageEPbS0_>:
 10066a8:	55                   	push   %ebp
 10066a9:	89 e5                	mov    %esp,%ebp
 10066ab:	8b 45 0c             	mov    0xc(%ebp),%eax
 10066ae:	c6 00 00             	movb   $0x0,(%eax)
 10066b1:	8b 45 10             	mov    0x10(%ebp),%eax
 10066b4:	c6 00 00             	movb   $0x0,(%eax)
 10066b7:	8b 45 08             	mov    0x8(%ebp),%eax
 10066ba:	8b 40 30             	mov    0x30(%eax),%eax
 10066bd:	c1 e0 0a             	shl    $0xa,%eax
 10066c0:	05 00 72 01 01       	add    $0x1017200,%eax
 10066c5:	5d                   	pop    %ebp
 10066c6:	c3                   	ret    
 10066c7:	90                   	nop

010066c8 <_ZN5CStar5ClockEv>:
 10066c8:	55                   	push   %ebp
 10066c9:	89 e5                	mov    %esp,%ebp
 10066cb:	53                   	push   %ebx
 10066cc:	83 ec 24             	sub    $0x24,%esp
 10066cf:	8b 45 08             	mov    0x8(%ebp),%eax
 10066d2:	8b 40 30             	mov    0x30(%eax),%eax
 10066d5:	85 c0                	test   %eax,%eax
 10066d7:	0f 94 c0             	sete   %al
 10066da:	0f b6 d0             	movzbl %al,%edx
 10066dd:	8b 45 08             	mov    0x8(%ebp),%eax
 10066e0:	89 50 30             	mov    %edx,0x30(%eax)
 10066e3:	8b 45 08             	mov    0x8(%ebp),%eax
 10066e6:	8b 40 2c             	mov    0x2c(%eax),%eax
 10066e9:	85 c0                	test   %eax,%eax
 10066eb:	74 37                	je     1006724 <_ZN5CStar5ClockEv+0x5c>
 10066ed:	8b 45 08             	mov    0x8(%ebp),%eax
 10066f0:	8b 50 2c             	mov    0x2c(%eax),%edx
 10066f3:	8b 45 08             	mov    0x8(%ebp),%eax
 10066f6:	8b 40 10             	mov    0x10(%eax),%eax
 10066f9:	89 d1                	mov    %edx,%ecx
 10066fb:	29 c1                	sub    %eax,%ecx
 10066fd:	89 c8                	mov    %ecx,%eax
 10066ff:	83 f8 10             	cmp    $0x10,%eax
 1006702:	75 44                	jne    1006748 <_ZN5CStar5ClockEv+0x80>
 1006704:	8b 45 08             	mov    0x8(%ebp),%eax
 1006707:	c7 40 2c 00 00 00 00 	movl   $0x0,0x2c(%eax)
 100670e:	8b 45 08             	mov    0x8(%ebp),%eax
 1006711:	c7 40 28 f8 ff ff ff 	movl   $0xfffffff8,0x28(%eax)
 1006718:	8b 45 08             	mov    0x8(%ebp),%eax
 100671b:	c7 40 24 03 00 00 00 	movl   $0x3,0x24(%eax)
 1006722:	eb 24                	jmp    1006748 <_ZN5CStar5ClockEv+0x80>
 1006724:	8b 45 08             	mov    0x8(%ebp),%eax
 1006727:	8b 40 28             	mov    0x28(%eax),%eax
 100672a:	8d 50 01             	lea    0x1(%eax),%edx
 100672d:	8b 45 08             	mov    0x8(%ebp),%eax
 1006730:	89 50 28             	mov    %edx,0x28(%eax)
 1006733:	8b 45 08             	mov    0x8(%ebp),%eax
 1006736:	8b 40 28             	mov    0x28(%eax),%eax
 1006739:	83 f8 08             	cmp    $0x8,%eax
 100673c:	7e 0a                	jle    1006748 <_ZN5CStar5ClockEv+0x80>
 100673e:	8b 45 08             	mov    0x8(%ebp),%eax
 1006741:	c7 40 28 08 00 00 00 	movl   $0x8,0x28(%eax)
 1006748:	8b 45 08             	mov    0x8(%ebp),%eax
 100674b:	8b 40 24             	mov    0x24(%eax),%eax
 100674e:	85 c0                	test   %eax,%eax
 1006750:	75 0a                	jne    100675c <_ZN5CStar5ClockEv+0x94>
 1006752:	8b 45 08             	mov    0x8(%ebp),%eax
 1006755:	8b 40 28             	mov    0x28(%eax),%eax
 1006758:	85 c0                	test   %eax,%eax
 100675a:	74 70                	je     10067cc <_ZN5CStar5ClockEv+0x104>
 100675c:	8b 45 08             	mov    0x8(%ebp),%eax
 100675f:	8b 58 28             	mov    0x28(%eax),%ebx
 1006762:	8b 45 08             	mov    0x8(%ebp),%eax
 1006765:	8b 48 24             	mov    0x24(%eax),%ecx
 1006768:	8b 55 08             	mov    0x8(%ebp),%edx
 100676b:	8b 45 08             	mov    0x8(%ebp),%eax
 100676e:	8b 40 20             	mov    0x20(%eax),%eax
 1006771:	89 5c 24 0c          	mov    %ebx,0xc(%esp)
 1006775:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 1006779:	89 54 24 04          	mov    %edx,0x4(%esp)
 100677d:	89 04 24             	mov    %eax,(%esp)
 1006780:	e8 a5 cc ff ff       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 1006785:	89 45 f4             	mov    %eax,-0xc(%ebp)
 1006788:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100678b:	83 e0 01             	and    $0x1,%eax
 100678e:	84 c0                	test   %al,%al
 1006790:	74 10                	je     10067a2 <_ZN5CStar5ClockEv+0xda>
 1006792:	8b 45 08             	mov    0x8(%ebp),%eax
 1006795:	8b 40 24             	mov    0x24(%eax),%eax
 1006798:	89 c2                	mov    %eax,%edx
 100679a:	f7 da                	neg    %edx
 100679c:	8b 45 08             	mov    0x8(%ebp),%eax
 100679f:	89 50 24             	mov    %edx,0x24(%eax)
 10067a2:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10067a5:	83 e0 02             	and    $0x2,%eax
 10067a8:	85 c0                	test   %eax,%eax
 10067aa:	74 20                	je     10067cc <_ZN5CStar5ClockEv+0x104>
 10067ac:	8b 45 08             	mov    0x8(%ebp),%eax
 10067af:	8b 40 28             	mov    0x28(%eax),%eax
 10067b2:	85 c0                	test   %eax,%eax
 10067b4:	7e 0c                	jle    10067c2 <_ZN5CStar5ClockEv+0xfa>
 10067b6:	8b 45 08             	mov    0x8(%ebp),%eax
 10067b9:	c7 40 28 f8 ff ff ff 	movl   $0xfffffff8,0x28(%eax)
 10067c0:	eb 0a                	jmp    10067cc <_ZN5CStar5ClockEv+0x104>
 10067c2:	8b 45 08             	mov    0x8(%ebp),%eax
 10067c5:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%eax)
 10067cc:	83 c4 24             	add    $0x24,%esp
 10067cf:	5b                   	pop    %ebx
 10067d0:	5d                   	pop    %ebp
 10067d1:	c3                   	ret    

010067d2 <_ZN5CStar6AttackEP7CObjecti>:
 10067d2:	55                   	push   %ebp
 10067d3:	89 e5                	mov    %esp,%ebp
 10067d5:	83 ec 18             	sub    $0x18,%esp
 10067d8:	8b 45 08             	mov    0x8(%ebp),%eax
 10067db:	8b 40 20             	mov    0x20(%eax),%eax
 10067de:	c7 44 24 04 06 00 00 	movl   $0x6,0x4(%esp)
 10067e5:	00 
 10067e6:	89 04 24             	mov    %eax,(%esp)
 10067e9:	e8 1a da ff ff       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 10067ee:	8b 45 08             	mov    0x8(%ebp),%eax
 10067f1:	c7 40 08 03 00 00 00 	movl   $0x3,0x8(%eax)
 10067f8:	8b 45 0c             	mov    0xc(%ebp),%eax
 10067fb:	89 04 24             	mov    %eax,(%esp)
 10067fe:	e8 6d f5 ff ff       	call   1005d70 <_ZN6CMario7AddStarEv>
 1006803:	c9                   	leave  
 1006804:	c3                   	ret    
 1006805:	90                   	nop

01006806 <_ZN5CStar5BlockEP7CObject>:
 1006806:	55                   	push   %ebp
 1006807:	89 e5                	mov    %esp,%ebp
 1006809:	8b 45 08             	mov    0x8(%ebp),%eax
 100680c:	8b 40 2c             	mov    0x2c(%eax),%eax
 100680f:	85 c0                	test   %eax,%eax
 1006811:	74 07                	je     100681a <_ZN5CStar5BlockEP7CObject+0x14>
 1006813:	b8 00 00 00 00       	mov    $0x0,%eax
 1006818:	eb 1d                	jmp    1006837 <_ZN5CStar5BlockEP7CObject+0x31>
 100681a:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
 100681e:	74 12                	je     1006832 <_ZN5CStar5BlockEP7CObject+0x2c>
 1006820:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006823:	8b 40 04             	mov    0x4(%eax),%eax
 1006826:	83 f8 02             	cmp    $0x2,%eax
 1006829:	75 07                	jne    1006832 <_ZN5CStar5BlockEP7CObject+0x2c>
 100682b:	b8 01 00 00 00       	mov    $0x1,%eax
 1006830:	eb 05                	jmp    1006837 <_ZN5CStar5BlockEP7CObject+0x31>
 1006832:	b8 00 00 00 00       	mov    $0x0,%eax
 1006837:	5d                   	pop    %ebp
 1006838:	c3                   	ret    
 1006839:	00 00                	add    %al,(%eax)
	...

0100683c <_ZN6CStoneC1EP5CGameii>:
 100683c:	55                   	push   %ebp
 100683d:	89 e5                	mov    %esp,%ebp
 100683f:	83 ec 28             	sub    $0x28,%esp
 1006842:	8b 45 08             	mov    0x8(%ebp),%eax
 1006845:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
 100684c:	00 
 100684d:	c7 44 24 18 10 00 00 	movl   $0x10,0x18(%esp)
 1006854:	00 
 1006855:	c7 44 24 14 10 00 00 	movl   $0x10,0x14(%esp)
 100685c:	00 
 100685d:	8b 55 14             	mov    0x14(%ebp),%edx
 1006860:	89 54 24 10          	mov    %edx,0x10(%esp)
 1006864:	8b 55 10             	mov    0x10(%ebp),%edx
 1006867:	89 54 24 0c          	mov    %edx,0xc(%esp)
 100686b:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 1006872:	00 
 1006873:	8b 55 0c             	mov    0xc(%ebp),%edx
 1006876:	89 54 24 04          	mov    %edx,0x4(%esp)
 100687a:	89 04 24             	mov    %eax,(%esp)
 100687d:	e8 0e f6 ff ff       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 1006882:	8b 45 08             	mov    0x8(%ebp),%eax
 1006885:	c7 00 20 94 00 01    	movl   $0x1009420,(%eax)
 100688b:	c9                   	leave  
 100688c:	c3                   	ret    
 100688d:	90                   	nop

0100688e <_ZN6CStone8GetImageEPbS0_>:
 100688e:	55                   	push   %ebp
 100688f:	89 e5                	mov    %esp,%ebp
 1006891:	8b 45 10             	mov    0x10(%ebp),%eax
 1006894:	c6 00 00             	movb   $0x0,(%eax)
 1006897:	8b 45 0c             	mov    0xc(%ebp),%eax
 100689a:	c6 00 00             	movb   $0x0,(%eax)
 100689d:	b8 00 04 01 01       	mov    $0x1010400,%eax
 10068a2:	5d                   	pop    %ebp
 10068a3:	c3                   	ret    

010068a4 <_ZN14CTortoiseDemonC1EP5CGameii>:
 10068a4:	55                   	push   %ebp
 10068a5:	89 e5                	mov    %esp,%ebp
 10068a7:	83 ec 28             	sub    $0x28,%esp
 10068aa:	8b 45 14             	mov    0x14(%ebp),%eax
 10068ad:	8d 50 08             	lea    0x8(%eax),%edx
 10068b0:	8b 45 08             	mov    0x8(%ebp),%eax
 10068b3:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
 10068ba:	00 
 10068bb:	c7 44 24 18 18 00 00 	movl   $0x18,0x18(%esp)
 10068c2:	00 
 10068c3:	c7 44 24 14 10 00 00 	movl   $0x10,0x14(%esp)
 10068ca:	00 
 10068cb:	89 54 24 10          	mov    %edx,0x10(%esp)
 10068cf:	8b 55 10             	mov    0x10(%ebp),%edx
 10068d2:	89 54 24 0c          	mov    %edx,0xc(%esp)
 10068d6:	c7 44 24 08 03 00 00 	movl   $0x3,0x8(%esp)
 10068dd:	00 
 10068de:	8b 55 0c             	mov    0xc(%ebp),%edx
 10068e1:	89 54 24 04          	mov    %edx,0x4(%esp)
 10068e5:	89 04 24             	mov    %eax,(%esp)
 10068e8:	e8 a3 f5 ff ff       	call   1005e90 <_ZN7CObjectC1EP5CGameiiiiii>
 10068ed:	8b 45 08             	mov    0x8(%ebp),%eax
 10068f0:	c7 00 40 94 00 01    	movl   $0x1009440,(%eax)
 10068f6:	8b 45 08             	mov    0x8(%ebp),%eax
 10068f9:	c7 40 2c 00 00 00 00 	movl   $0x0,0x2c(%eax)
 1006900:	8b 45 08             	mov    0x8(%ebp),%eax
 1006903:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 100690a:	8b 45 08             	mov    0x8(%ebp),%eax
 100690d:	c7 40 24 fe ff ff ff 	movl   $0xfffffffe,0x24(%eax)
 1006914:	8b 45 08             	mov    0x8(%ebp),%eax
 1006917:	c6 40 34 00          	movb   $0x0,0x34(%eax)
 100691b:	c9                   	leave  
 100691c:	c3                   	ret    
 100691d:	90                   	nop

0100691e <_ZN14CTortoiseDemon8GetImageEPbS0_>:
 100691e:	55                   	push   %ebp
 100691f:	89 e5                	mov    %esp,%ebp
 1006921:	8b 45 10             	mov    0x10(%ebp),%eax
 1006924:	c6 00 00             	movb   $0x0,(%eax)
 1006927:	8b 45 08             	mov    0x8(%ebp),%eax
 100692a:	0f b6 50 34          	movzbl 0x34(%eax),%edx
 100692e:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006931:	88 10                	mov    %dl,(%eax)
 1006933:	8b 45 08             	mov    0x8(%ebp),%eax
 1006936:	8b 50 2c             	mov    0x2c(%eax),%edx
 1006939:	89 d0                	mov    %edx,%eax
 100693b:	01 c0                	add    %eax,%eax
 100693d:	01 d0                	add    %edx,%eax
 100693f:	c1 e0 09             	shl    $0x9,%eax
 1006942:	05 00 38 01 01       	add    $0x1013800,%eax
 1006947:	5d                   	pop    %ebp
 1006948:	c3                   	ret    
 1006949:	90                   	nop

0100694a <_ZN14CTortoiseDemon5ClockEv>:
 100694a:	55                   	push   %ebp
 100694b:	89 e5                	mov    %esp,%ebp
 100694d:	53                   	push   %ebx
 100694e:	83 ec 24             	sub    $0x24,%esp
 1006951:	8b 45 08             	mov    0x8(%ebp),%eax
 1006954:	8b 40 2c             	mov    0x2c(%eax),%eax
 1006957:	83 f8 02             	cmp    $0x2,%eax
 100695a:	75 5a                	jne    10069b6 <_ZN14CTortoiseDemon5ClockEv+0x6c>
 100695c:	8b 45 08             	mov    0x8(%ebp),%eax
 100695f:	8b 40 08             	mov    0x8(%eax),%eax
 1006962:	83 f8 01             	cmp    $0x1,%eax
 1006965:	0f 85 83 00 00 00    	jne    10069ee <_ZN14CTortoiseDemon5ClockEv+0xa4>
 100696b:	8b 45 08             	mov    0x8(%ebp),%eax
 100696e:	8b 40 24             	mov    0x24(%eax),%eax
 1006971:	85 c0                	test   %eax,%eax
 1006973:	75 79                	jne    10069ee <_ZN14CTortoiseDemon5ClockEv+0xa4>
 1006975:	8b 45 08             	mov    0x8(%ebp),%eax
 1006978:	8b 40 30             	mov    0x30(%eax),%eax
 100697b:	8d 50 01             	lea    0x1(%eax),%edx
 100697e:	8b 45 08             	mov    0x8(%ebp),%eax
 1006981:	89 50 30             	mov    %edx,0x30(%eax)
 1006984:	8b 45 08             	mov    0x8(%ebp),%eax
 1006987:	8b 40 30             	mov    0x30(%eax),%eax
 100698a:	83 f8 63             	cmp    $0x63,%eax
 100698d:	7e 5f                	jle    10069ee <_ZN14CTortoiseDemon5ClockEv+0xa4>
 100698f:	8b 45 08             	mov    0x8(%ebp),%eax
 1006992:	c7 40 2c 00 00 00 00 	movl   $0x0,0x2c(%eax)
 1006999:	8b 45 08             	mov    0x8(%ebp),%eax
 100699c:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 10069a3:	8b 45 08             	mov    0x8(%ebp),%eax
 10069a6:	c7 40 24 fe ff ff ff 	movl   $0xfffffffe,0x24(%eax)
 10069ad:	8b 45 08             	mov    0x8(%ebp),%eax
 10069b0:	c6 40 34 00          	movb   $0x0,0x34(%eax)
 10069b4:	eb 38                	jmp    10069ee <_ZN14CTortoiseDemon5ClockEv+0xa4>
 10069b6:	8b 45 08             	mov    0x8(%ebp),%eax
 10069b9:	8b 40 30             	mov    0x30(%eax),%eax
 10069bc:	8d 50 01             	lea    0x1(%eax),%edx
 10069bf:	8b 45 08             	mov    0x8(%ebp),%eax
 10069c2:	89 50 30             	mov    %edx,0x30(%eax)
 10069c5:	8b 45 08             	mov    0x8(%ebp),%eax
 10069c8:	8b 40 30             	mov    0x30(%eax),%eax
 10069cb:	83 f8 04             	cmp    $0x4,%eax
 10069ce:	7e 1e                	jle    10069ee <_ZN14CTortoiseDemon5ClockEv+0xa4>
 10069d0:	8b 45 08             	mov    0x8(%ebp),%eax
 10069d3:	8b 40 2c             	mov    0x2c(%eax),%eax
 10069d6:	85 c0                	test   %eax,%eax
 10069d8:	0f 94 c0             	sete   %al
 10069db:	0f b6 d0             	movzbl %al,%edx
 10069de:	8b 45 08             	mov    0x8(%ebp),%eax
 10069e1:	89 50 2c             	mov    %edx,0x2c(%eax)
 10069e4:	8b 45 08             	mov    0x8(%ebp),%eax
 10069e7:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 10069ee:	8b 45 08             	mov    0x8(%ebp),%eax
 10069f1:	8b 40 28             	mov    0x28(%eax),%eax
 10069f4:	8d 50 02             	lea    0x2(%eax),%edx
 10069f7:	8b 45 08             	mov    0x8(%ebp),%eax
 10069fa:	89 50 28             	mov    %edx,0x28(%eax)
 10069fd:	8b 45 08             	mov    0x8(%ebp),%eax
 1006a00:	8b 40 28             	mov    0x28(%eax),%eax
 1006a03:	83 f8 14             	cmp    $0x14,%eax
 1006a06:	7e 0a                	jle    1006a12 <_ZN14CTortoiseDemon5ClockEv+0xc8>
 1006a08:	8b 45 08             	mov    0x8(%ebp),%eax
 1006a0b:	c7 40 28 14 00 00 00 	movl   $0x14,0x28(%eax)
 1006a12:	8b 45 08             	mov    0x8(%ebp),%eax
 1006a15:	8b 40 24             	mov    0x24(%eax),%eax
 1006a18:	85 c0                	test   %eax,%eax
 1006a1a:	75 0e                	jne    1006a2a <_ZN14CTortoiseDemon5ClockEv+0xe0>
 1006a1c:	8b 45 08             	mov    0x8(%ebp),%eax
 1006a1f:	8b 40 28             	mov    0x28(%eax),%eax
 1006a22:	85 c0                	test   %eax,%eax
 1006a24:	0f 84 8d 00 00 00    	je     1006ab7 <_ZN14CTortoiseDemon5ClockEv+0x16d>
 1006a2a:	8b 45 08             	mov    0x8(%ebp),%eax
 1006a2d:	8b 58 28             	mov    0x28(%eax),%ebx
 1006a30:	8b 45 08             	mov    0x8(%ebp),%eax
 1006a33:	8b 48 24             	mov    0x24(%eax),%ecx
 1006a36:	8b 55 08             	mov    0x8(%ebp),%edx
 1006a39:	8b 45 08             	mov    0x8(%ebp),%eax
 1006a3c:	8b 40 20             	mov    0x20(%eax),%eax
 1006a3f:	89 5c 24 0c          	mov    %ebx,0xc(%esp)
 1006a43:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 1006a47:	89 54 24 04          	mov    %edx,0x4(%esp)
 1006a4b:	89 04 24             	mov    %eax,(%esp)
 1006a4e:	e8 d7 c9 ff ff       	call   100342a <_ZN5CGame4MoveEP7CObjectii>
 1006a53:	89 45 f4             	mov    %eax,-0xc(%ebp)
 1006a56:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1006a59:	83 e0 01             	and    $0x1,%eax
 1006a5c:	84 c0                	test   %al,%al
 1006a5e:	74 43                	je     1006aa3 <_ZN14CTortoiseDemon5ClockEv+0x159>
 1006a60:	8b 45 08             	mov    0x8(%ebp),%eax
 1006a63:	8b 40 2c             	mov    0x2c(%eax),%eax
 1006a66:	83 f8 02             	cmp    $0x2,%eax
 1006a69:	75 16                	jne    1006a81 <_ZN14CTortoiseDemon5ClockEv+0x137>
 1006a6b:	8b 45 08             	mov    0x8(%ebp),%eax
 1006a6e:	8b 40 20             	mov    0x20(%eax),%eax
 1006a71:	c7 44 24 04 02 00 00 	movl   $0x2,0x4(%esp)
 1006a78:	00 
 1006a79:	89 04 24             	mov    %eax,(%esp)
 1006a7c:	e8 87 d7 ff ff       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1006a81:	8b 45 08             	mov    0x8(%ebp),%eax
 1006a84:	8b 40 24             	mov    0x24(%eax),%eax
 1006a87:	89 c2                	mov    %eax,%edx
 1006a89:	f7 da                	neg    %edx
 1006a8b:	8b 45 08             	mov    0x8(%ebp),%eax
 1006a8e:	89 50 24             	mov    %edx,0x24(%eax)
 1006a91:	8b 45 08             	mov    0x8(%ebp),%eax
 1006a94:	0f b6 40 34          	movzbl 0x34(%eax),%eax
 1006a98:	89 c2                	mov    %eax,%edx
 1006a9a:	83 f2 01             	xor    $0x1,%edx
 1006a9d:	8b 45 08             	mov    0x8(%ebp),%eax
 1006aa0:	88 50 34             	mov    %dl,0x34(%eax)
 1006aa3:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1006aa6:	83 e0 02             	and    $0x2,%eax
 1006aa9:	85 c0                	test   %eax,%eax
 1006aab:	74 0a                	je     1006ab7 <_ZN14CTortoiseDemon5ClockEv+0x16d>
 1006aad:	8b 45 08             	mov    0x8(%ebp),%eax
 1006ab0:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%eax)
 1006ab7:	83 c4 24             	add    $0x24,%esp
 1006aba:	5b                   	pop    %ebx
 1006abb:	5d                   	pop    %ebp
 1006abc:	c3                   	ret    
 1006abd:	90                   	nop

01006abe <_ZN14CTortoiseDemon6AttackEP7CObjecti>:
 1006abe:	55                   	push   %ebp
 1006abf:	89 e5                	mov    %esp,%ebp
 1006ac1:	83 ec 18             	sub    $0x18,%esp
 1006ac4:	8b 45 08             	mov    0x8(%ebp),%eax
 1006ac7:	8b 40 08             	mov    0x8(%eax),%eax
 1006aca:	83 f8 01             	cmp    $0x1,%eax
 1006acd:	0f 85 20 01 00 00    	jne    1006bf3 <_ZN14CTortoiseDemon6AttackEP7CObjecti+0x135>
 1006ad3:	8b 45 10             	mov    0x10(%ebp),%eax
 1006ad6:	83 f8 01             	cmp    $0x1,%eax
 1006ad9:	74 0a                	je     1006ae5 <_ZN14CTortoiseDemon6AttackEP7CObjecti+0x27>
 1006adb:	83 f8 02             	cmp    $0x2,%eax
 1006ade:	74 52                	je     1006b32 <_ZN14CTortoiseDemon6AttackEP7CObjecti+0x74>
 1006ae0:	e9 bc 00 00 00       	jmp    1006ba1 <_ZN14CTortoiseDemon6AttackEP7CObjecti+0xe3>
 1006ae5:	8b 45 08             	mov    0x8(%ebp),%eax
 1006ae8:	8b 40 20             	mov    0x20(%eax),%eax
 1006aeb:	c7 44 24 04 09 00 00 	movl   $0x9,0x4(%esp)
 1006af2:	00 
 1006af3:	89 04 24             	mov    %eax,(%esp)
 1006af6:	e8 0d d7 ff ff       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1006afb:	8b 45 08             	mov    0x8(%ebp),%eax
 1006afe:	c7 40 2c 02 00 00 00 	movl   $0x2,0x2c(%eax)
 1006b05:	8b 45 08             	mov    0x8(%ebp),%eax
 1006b08:	c7 40 08 02 00 00 00 	movl   $0x2,0x8(%eax)
 1006b0f:	8b 45 08             	mov    0x8(%ebp),%eax
 1006b12:	c7 40 28 f6 ff ff ff 	movl   $0xfffffff6,0x28(%eax)
 1006b19:	8b 45 08             	mov    0x8(%ebp),%eax
 1006b1c:	c7 40 24 02 00 00 00 	movl   $0x2,0x24(%eax)
 1006b23:	8b 45 08             	mov    0x8(%ebp),%eax
 1006b26:	c7 40 1c 01 00 00 00 	movl   $0x1,0x1c(%eax)
 1006b2d:	e9 c5 00 00 00       	jmp    1006bf7 <_ZN14CTortoiseDemon6AttackEP7CObjecti+0x139>
 1006b32:	8b 45 08             	mov    0x8(%ebp),%eax
 1006b35:	8b 40 2c             	mov    0x2c(%eax),%eax
 1006b38:	83 f8 02             	cmp    $0x2,%eax
 1006b3b:	75 1d                	jne    1006b5a <_ZN14CTortoiseDemon6AttackEP7CObjecti+0x9c>
 1006b3d:	8b 45 08             	mov    0x8(%ebp),%eax
 1006b40:	8b 40 2c             	mov    0x2c(%eax),%eax
 1006b43:	83 f8 02             	cmp    $0x2,%eax
 1006b46:	0f 85 aa 00 00 00    	jne    1006bf6 <_ZN14CTortoiseDemon6AttackEP7CObjecti+0x138>
 1006b4c:	8b 45 08             	mov    0x8(%ebp),%eax
 1006b4f:	8b 40 24             	mov    0x24(%eax),%eax
 1006b52:	85 c0                	test   %eax,%eax
 1006b54:	0f 84 9c 00 00 00    	je     1006bf6 <_ZN14CTortoiseDemon6AttackEP7CObjecti+0x138>
 1006b5a:	8b 45 08             	mov    0x8(%ebp),%eax
 1006b5d:	8b 40 20             	mov    0x20(%eax),%eax
 1006b60:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 1006b67:	00 
 1006b68:	89 04 24             	mov    %eax,(%esp)
 1006b6b:	e8 98 d6 ff ff       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1006b70:	8b 45 08             	mov    0x8(%ebp),%eax
 1006b73:	c7 40 2c 02 00 00 00 	movl   $0x2,0x2c(%eax)
 1006b7a:	8b 45 08             	mov    0x8(%ebp),%eax
 1006b7d:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%eax)
 1006b84:	8b 45 08             	mov    0x8(%ebp),%eax
 1006b87:	c7 40 24 00 00 00 00 	movl   $0x0,0x24(%eax)
 1006b8e:	8b 45 08             	mov    0x8(%ebp),%eax
 1006b91:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 1006b98:	8b 45 08             	mov    0x8(%ebp),%eax
 1006b9b:	c6 40 35 00          	movb   $0x0,0x35(%eax)
 1006b9f:	eb 55                	jmp    1006bf6 <_ZN14CTortoiseDemon6AttackEP7CObjecti+0x138>
 1006ba1:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006ba4:	8b 40 04             	mov    0x4(%eax),%eax
 1006ba7:	83 f8 02             	cmp    $0x2,%eax
 1006baa:	75 4b                	jne    1006bf7 <_ZN14CTortoiseDemon6AttackEP7CObjecti+0x139>
 1006bac:	8b 45 08             	mov    0x8(%ebp),%eax
 1006baf:	8b 40 20             	mov    0x20(%eax),%eax
 1006bb2:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 1006bb9:	00 
 1006bba:	89 04 24             	mov    %eax,(%esp)
 1006bbd:	e8 46 d6 ff ff       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1006bc2:	8b 45 08             	mov    0x8(%ebp),%eax
 1006bc5:	c7 40 2c 02 00 00 00 	movl   $0x2,0x2c(%eax)
 1006bcc:	8b 45 08             	mov    0x8(%ebp),%eax
 1006bcf:	c7 40 28 fc ff ff ff 	movl   $0xfffffffc,0x28(%eax)
 1006bd6:	8b 45 08             	mov    0x8(%ebp),%eax
 1006bd9:	c7 40 24 00 00 00 00 	movl   $0x0,0x24(%eax)
 1006be0:	8b 45 08             	mov    0x8(%ebp),%eax
 1006be3:	c7 40 30 00 00 00 00 	movl   $0x0,0x30(%eax)
 1006bea:	8b 45 08             	mov    0x8(%ebp),%eax
 1006bed:	c6 40 35 01          	movb   $0x1,0x35(%eax)
 1006bf1:	eb 04                	jmp    1006bf7 <_ZN14CTortoiseDemon6AttackEP7CObjecti+0x139>
 1006bf3:	90                   	nop
 1006bf4:	eb 01                	jmp    1006bf7 <_ZN14CTortoiseDemon6AttackEP7CObjecti+0x139>
 1006bf6:	90                   	nop
 1006bf7:	c9                   	leave  
 1006bf8:	c3                   	ret    
 1006bf9:	90                   	nop

01006bfa <_ZN14CTortoiseDemon4BumpEP7CObjectib>:
 1006bfa:	55                   	push   %ebp
 1006bfb:	89 e5                	mov    %esp,%ebp
 1006bfd:	83 ec 28             	sub    $0x28,%esp
 1006c00:	8b 45 14             	mov    0x14(%ebp),%eax
 1006c03:	88 45 f4             	mov    %al,-0xc(%ebp)
 1006c06:	8b 45 08             	mov    0x8(%ebp),%eax
 1006c09:	8b 40 08             	mov    0x8(%eax),%eax
 1006c0c:	83 f8 01             	cmp    $0x1,%eax
 1006c0f:	0f 85 14 01 00 00    	jne    1006d29 <_ZN14CTortoiseDemon4BumpEP7CObjectib+0x12f>
 1006c15:	8b 45 08             	mov    0x8(%ebp),%eax
 1006c18:	8b 40 2c             	mov    0x2c(%eax),%eax
 1006c1b:	83 f8 02             	cmp    $0x2,%eax
 1006c1e:	0f 85 cb 00 00 00    	jne    1006cef <_ZN14CTortoiseDemon4BumpEP7CObjectib+0xf5>
 1006c24:	8b 45 08             	mov    0x8(%ebp),%eax
 1006c27:	8b 40 24             	mov    0x24(%eax),%eax
 1006c2a:	85 c0                	test   %eax,%eax
 1006c2c:	75 6d                	jne    1006c9b <_ZN14CTortoiseDemon4BumpEP7CObjectib+0xa1>
 1006c2e:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006c31:	8b 40 04             	mov    0x4(%eax),%eax
 1006c34:	83 f8 01             	cmp    $0x1,%eax
 1006c37:	0f 85 ed 00 00 00    	jne    1006d2a <_ZN14CTortoiseDemon4BumpEP7CObjectib+0x130>
 1006c3d:	8b 45 08             	mov    0x8(%ebp),%eax
 1006c40:	0f b6 40 35          	movzbl 0x35(%eax),%eax
 1006c44:	84 c0                	test   %al,%al
 1006c46:	74 47                	je     1006c8f <_ZN14CTortoiseDemon4BumpEP7CObjectib+0x95>
 1006c48:	8b 45 08             	mov    0x8(%ebp),%eax
 1006c4b:	8b 40 20             	mov    0x20(%eax),%eax
 1006c4e:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 1006c55:	00 
 1006c56:	89 04 24             	mov    %eax,(%esp)
 1006c59:	e8 aa d5 ff ff       	call   1004208 <_ZN5CGame9PlaySoundEN9CSoundMan8SOUNDNUME>
 1006c5e:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006c61:	8b 50 0c             	mov    0xc(%eax),%edx
 1006c64:	8b 45 08             	mov    0x8(%ebp),%eax
 1006c67:	8b 40 0c             	mov    0xc(%eax),%eax
 1006c6a:	83 c0 08             	add    $0x8,%eax
 1006c6d:	39 c2                	cmp    %eax,%edx
 1006c6f:	7e 0f                	jle    1006c80 <_ZN14CTortoiseDemon4BumpEP7CObjectib+0x86>
 1006c71:	8b 45 08             	mov    0x8(%ebp),%eax
 1006c74:	c7 40 24 f6 ff ff ff 	movl   $0xfffffff6,0x24(%eax)
 1006c7b:	e9 aa 00 00 00       	jmp    1006d2a <_ZN14CTortoiseDemon4BumpEP7CObjectib+0x130>
 1006c80:	8b 45 08             	mov    0x8(%ebp),%eax
 1006c83:	c7 40 24 0a 00 00 00 	movl   $0xa,0x24(%eax)
 1006c8a:	e9 9b 00 00 00       	jmp    1006d2a <_ZN14CTortoiseDemon4BumpEP7CObjectib+0x130>
 1006c8f:	8b 45 08             	mov    0x8(%ebp),%eax
 1006c92:	c6 40 35 01          	movb   $0x1,0x35(%eax)
 1006c96:	e9 8f 00 00 00       	jmp    1006d2a <_ZN14CTortoiseDemon4BumpEP7CObjectib+0x130>
 1006c9b:	8b 45 08             	mov    0x8(%ebp),%eax
 1006c9e:	8b 40 08             	mov    0x8(%eax),%eax
 1006ca1:	83 f8 01             	cmp    $0x1,%eax
 1006ca4:	0f 85 80 00 00 00    	jne    1006d2a <_ZN14CTortoiseDemon4BumpEP7CObjectib+0x130>
 1006caa:	83 7d 10 03          	cmpl   $0x3,0x10(%ebp)
 1006cae:	74 06                	je     1006cb6 <_ZN14CTortoiseDemon4BumpEP7CObjectib+0xbc>
 1006cb0:	83 7d 10 01          	cmpl   $0x1,0x10(%ebp)
 1006cb4:	75 74                	jne    1006d2a <_ZN14CTortoiseDemon4BumpEP7CObjectib+0x130>
 1006cb6:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006cb9:	8b 40 04             	mov    0x4(%eax),%eax
 1006cbc:	83 f8 01             	cmp    $0x1,%eax
 1006cbf:	74 0b                	je     1006ccc <_ZN14CTortoiseDemon4BumpEP7CObjectib+0xd2>
 1006cc1:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006cc4:	8b 40 04             	mov    0x4(%eax),%eax
 1006cc7:	83 f8 03             	cmp    $0x3,%eax
 1006cca:	75 5e                	jne    1006d2a <_ZN14CTortoiseDemon4BumpEP7CObjectib+0x130>
 1006ccc:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006ccf:	8b 00                	mov    (%eax),%eax
 1006cd1:	83 c0 10             	add    $0x10,%eax
 1006cd4:	8b 10                	mov    (%eax),%edx
 1006cd6:	8b 45 08             	mov    0x8(%ebp),%eax
 1006cd9:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 1006ce0:	00 
 1006ce1:	89 44 24 04          	mov    %eax,0x4(%esp)
 1006ce5:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006ce8:	89 04 24             	mov    %eax,(%esp)
 1006ceb:	ff d2                	call   *%edx
 1006ced:	eb 3b                	jmp    1006d2a <_ZN14CTortoiseDemon4BumpEP7CObjectib+0x130>
 1006cef:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006cf2:	8b 40 04             	mov    0x4(%eax),%eax
 1006cf5:	83 f8 01             	cmp    $0x1,%eax
 1006cf8:	75 30                	jne    1006d2a <_ZN14CTortoiseDemon4BumpEP7CObjectib+0x130>
 1006cfa:	83 7d 10 03          	cmpl   $0x3,0x10(%ebp)
 1006cfe:	74 06                	je     1006d06 <_ZN14CTortoiseDemon4BumpEP7CObjectib+0x10c>
 1006d00:	83 7d 10 01          	cmpl   $0x1,0x10(%ebp)
 1006d04:	75 24                	jne    1006d2a <_ZN14CTortoiseDemon4BumpEP7CObjectib+0x130>
 1006d06:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006d09:	8b 00                	mov    (%eax),%eax
 1006d0b:	83 c0 10             	add    $0x10,%eax
 1006d0e:	8b 10                	mov    (%eax),%edx
 1006d10:	8b 45 08             	mov    0x8(%ebp),%eax
 1006d13:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 1006d1a:	00 
 1006d1b:	89 44 24 04          	mov    %eax,0x4(%esp)
 1006d1f:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006d22:	89 04 24             	mov    %eax,(%esp)
 1006d25:	ff d2                	call   *%edx
 1006d27:	eb 01                	jmp    1006d2a <_ZN14CTortoiseDemon4BumpEP7CObjectib+0x130>
 1006d29:	90                   	nop
 1006d2a:	c9                   	leave  
 1006d2b:	c3                   	ret    

01006d2c <_ZN14CTortoiseDemon5BlockEP7CObject>:
 1006d2c:	55                   	push   %ebp
 1006d2d:	89 e5                	mov    %esp,%ebp
 1006d2f:	8b 45 08             	mov    0x8(%ebp),%eax
 1006d32:	8b 40 08             	mov    0x8(%eax),%eax
 1006d35:	83 f8 01             	cmp    $0x1,%eax
 1006d38:	74 07                	je     1006d41 <_ZN14CTortoiseDemon5BlockEP7CObject+0x15>
 1006d3a:	b8 00 00 00 00       	mov    $0x0,%eax
 1006d3f:	eb 4b                	jmp    1006d8c <_ZN14CTortoiseDemon5BlockEP7CObject+0x60>
 1006d41:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
 1006d45:	74 40                	je     1006d87 <_ZN14CTortoiseDemon5BlockEP7CObject+0x5b>
 1006d47:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006d4a:	8b 40 04             	mov    0x4(%eax),%eax
 1006d4d:	83 f8 05             	cmp    $0x5,%eax
 1006d50:	75 07                	jne    1006d59 <_ZN14CTortoiseDemon5BlockEP7CObject+0x2d>
 1006d52:	b8 00 00 00 00       	mov    $0x0,%eax
 1006d57:	eb 33                	jmp    1006d8c <_ZN14CTortoiseDemon5BlockEP7CObject+0x60>
 1006d59:	8b 45 08             	mov    0x8(%ebp),%eax
 1006d5c:	8b 40 2c             	mov    0x2c(%eax),%eax
 1006d5f:	83 f8 02             	cmp    $0x2,%eax
 1006d62:	75 1c                	jne    1006d80 <_ZN14CTortoiseDemon5BlockEP7CObject+0x54>
 1006d64:	8b 45 08             	mov    0x8(%ebp),%eax
 1006d67:	8b 40 24             	mov    0x24(%eax),%eax
 1006d6a:	85 c0                	test   %eax,%eax
 1006d6c:	74 12                	je     1006d80 <_ZN14CTortoiseDemon5BlockEP7CObject+0x54>
 1006d6e:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006d71:	8b 40 04             	mov    0x4(%eax),%eax
 1006d74:	83 f8 03             	cmp    $0x3,%eax
 1006d77:	75 07                	jne    1006d80 <_ZN14CTortoiseDemon5BlockEP7CObject+0x54>
 1006d79:	b8 00 00 00 00       	mov    $0x0,%eax
 1006d7e:	eb 0c                	jmp    1006d8c <_ZN14CTortoiseDemon5BlockEP7CObject+0x60>
 1006d80:	b8 01 00 00 00       	mov    $0x1,%eax
 1006d85:	eb 05                	jmp    1006d8c <_ZN14CTortoiseDemon5BlockEP7CObject+0x60>
 1006d87:	b8 00 00 00 00       	mov    $0x0,%eax
 1006d8c:	5d                   	pop    %ebp
 1006d8d:	c3                   	ret    
	...

01006d90 <strcpy>:
 1006d90:	55                   	push   %ebp
 1006d91:	89 e5                	mov    %esp,%ebp
 1006d93:	57                   	push   %edi
 1006d94:	56                   	push   %esi
 1006d95:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006d98:	8b 55 08             	mov    0x8(%ebp),%edx
 1006d9b:	89 c6                	mov    %eax,%esi
 1006d9d:	89 d7                	mov    %edx,%edi
 1006d9f:	fc                   	cld    
 1006da0:	ac                   	lods   %ds:(%esi),%al
 1006da1:	aa                   	stos   %al,%es:(%edi)
 1006da2:	84 c0                	test   %al,%al
 1006da4:	75 fa                	jne    1006da0 <strcpy+0x10>
 1006da6:	8b 45 08             	mov    0x8(%ebp),%eax
 1006da9:	5e                   	pop    %esi
 1006daa:	5f                   	pop    %edi
 1006dab:	5d                   	pop    %ebp
 1006dac:	c3                   	ret    

01006dad <strncpy>:
 1006dad:	55                   	push   %ebp
 1006dae:	89 e5                	mov    %esp,%ebp
 1006db0:	57                   	push   %edi
 1006db1:	56                   	push   %esi
 1006db2:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006db5:	8b 55 08             	mov    0x8(%ebp),%edx
 1006db8:	8b 4d 10             	mov    0x10(%ebp),%ecx
 1006dbb:	89 c6                	mov    %eax,%esi
 1006dbd:	89 d7                	mov    %edx,%edi
 1006dbf:	fc                   	cld    
 1006dc0:	49                   	dec    %ecx
 1006dc1:	78 08                	js     1006dcb <strncpy+0x1e>
 1006dc3:	ac                   	lods   %ds:(%esi),%al
 1006dc4:	aa                   	stos   %al,%es:(%edi)
 1006dc5:	84 c0                	test   %al,%al
 1006dc7:	75 f7                	jne    1006dc0 <strncpy+0x13>
 1006dc9:	f3 aa                	rep stos %al,%es:(%edi)
 1006dcb:	8b 45 08             	mov    0x8(%ebp),%eax
 1006dce:	5e                   	pop    %esi
 1006dcf:	5f                   	pop    %edi
 1006dd0:	5d                   	pop    %ebp
 1006dd1:	c3                   	ret    

01006dd2 <strcat>:
 1006dd2:	55                   	push   %ebp
 1006dd3:	89 e5                	mov    %esp,%ebp
 1006dd5:	57                   	push   %edi
 1006dd6:	56                   	push   %esi
 1006dd7:	53                   	push   %ebx
 1006dd8:	8b 55 0c             	mov    0xc(%ebp),%edx
 1006ddb:	8b 5d 08             	mov    0x8(%ebp),%ebx
 1006dde:	b8 00 00 00 00       	mov    $0x0,%eax
 1006de3:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 1006de8:	89 d6                	mov    %edx,%esi
 1006dea:	89 df                	mov    %ebx,%edi
 1006dec:	fc                   	cld    
 1006ded:	f2 ae                	repnz scas %es:(%edi),%al
 1006def:	4f                   	dec    %edi
 1006df0:	ac                   	lods   %ds:(%esi),%al
 1006df1:	aa                   	stos   %al,%es:(%edi)
 1006df2:	84 c0                	test   %al,%al
 1006df4:	75 fa                	jne    1006df0 <strcat+0x1e>
 1006df6:	8b 45 08             	mov    0x8(%ebp),%eax
 1006df9:	5b                   	pop    %ebx
 1006dfa:	5e                   	pop    %esi
 1006dfb:	5f                   	pop    %edi
 1006dfc:	5d                   	pop    %ebp
 1006dfd:	c3                   	ret    

01006dfe <strncat>:
 1006dfe:	55                   	push   %ebp
 1006dff:	89 e5                	mov    %esp,%ebp
 1006e01:	57                   	push   %edi
 1006e02:	56                   	push   %esi
 1006e03:	53                   	push   %ebx
 1006e04:	8b 55 0c             	mov    0xc(%ebp),%edx
 1006e07:	8b 5d 08             	mov    0x8(%ebp),%ebx
 1006e0a:	b8 00 00 00 00       	mov    $0x0,%eax
 1006e0f:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 1006e14:	89 d6                	mov    %edx,%esi
 1006e16:	89 df                	mov    %ebx,%edi
 1006e18:	fc                   	cld    
 1006e19:	f2 ae                	repnz scas %es:(%edi),%al
 1006e1b:	4f                   	dec    %edi
 1006e1c:	8b 4d 10             	mov    0x10(%ebp),%ecx
 1006e1f:	49                   	dec    %ecx
 1006e20:	78 06                	js     1006e28 <strncat+0x2a>
 1006e22:	ac                   	lods   %ds:(%esi),%al
 1006e23:	aa                   	stos   %al,%es:(%edi)
 1006e24:	84 c0                	test   %al,%al
 1006e26:	75 f7                	jne    1006e1f <strncat+0x21>
 1006e28:	31 c0                	xor    %eax,%eax
 1006e2a:	aa                   	stos   %al,%es:(%edi)
 1006e2b:	8b 45 08             	mov    0x8(%ebp),%eax
 1006e2e:	5b                   	pop    %ebx
 1006e2f:	5e                   	pop    %esi
 1006e30:	5f                   	pop    %edi
 1006e31:	5d                   	pop    %ebp
 1006e32:	c3                   	ret    

01006e33 <strcmp>:
 1006e33:	55                   	push   %ebp
 1006e34:	89 e5                	mov    %esp,%ebp
 1006e36:	57                   	push   %edi
 1006e37:	56                   	push   %esi
 1006e38:	8b 45 08             	mov    0x8(%ebp),%eax
 1006e3b:	8b 55 0c             	mov    0xc(%ebp),%edx
 1006e3e:	89 c7                	mov    %eax,%edi
 1006e40:	89 d6                	mov    %edx,%esi
 1006e42:	fc                   	cld    
 1006e43:	ac                   	lods   %ds:(%esi),%al
 1006e44:	ae                   	scas   %es:(%edi),%al
 1006e45:	75 08                	jne    1006e4f <strcmp+0x1c>
 1006e47:	84 c0                	test   %al,%al
 1006e49:	75 f8                	jne    1006e43 <strcmp+0x10>
 1006e4b:	31 c0                	xor    %eax,%eax
 1006e4d:	eb 09                	jmp    1006e58 <strcmp+0x25>
 1006e4f:	b8 01 00 00 00       	mov    $0x1,%eax
 1006e54:	7c 02                	jl     1006e58 <strcmp+0x25>
 1006e56:	f7 d8                	neg    %eax
 1006e58:	5e                   	pop    %esi
 1006e59:	5f                   	pop    %edi
 1006e5a:	5d                   	pop    %ebp
 1006e5b:	c3                   	ret    

01006e5c <strncmp>:
 1006e5c:	55                   	push   %ebp
 1006e5d:	89 e5                	mov    %esp,%ebp
 1006e5f:	57                   	push   %edi
 1006e60:	56                   	push   %esi
 1006e61:	8b 45 08             	mov    0x8(%ebp),%eax
 1006e64:	8b 55 0c             	mov    0xc(%ebp),%edx
 1006e67:	8b 4d 10             	mov    0x10(%ebp),%ecx
 1006e6a:	89 c7                	mov    %eax,%edi
 1006e6c:	89 d6                	mov    %edx,%esi
 1006e6e:	fc                   	cld    
 1006e6f:	49                   	dec    %ecx
 1006e70:	78 08                	js     1006e7a <strncmp+0x1e>
 1006e72:	ac                   	lods   %ds:(%esi),%al
 1006e73:	ae                   	scas   %es:(%edi),%al
 1006e74:	75 08                	jne    1006e7e <strncmp+0x22>
 1006e76:	84 c0                	test   %al,%al
 1006e78:	75 f5                	jne    1006e6f <strncmp+0x13>
 1006e7a:	31 c0                	xor    %eax,%eax
 1006e7c:	eb 09                	jmp    1006e87 <strncmp+0x2b>
 1006e7e:	b8 01 00 00 00       	mov    $0x1,%eax
 1006e83:	7c 02                	jl     1006e87 <strncmp+0x2b>
 1006e85:	f7 d8                	neg    %eax
 1006e87:	5e                   	pop    %esi
 1006e88:	5f                   	pop    %edi
 1006e89:	5d                   	pop    %ebp
 1006e8a:	c3                   	ret    

01006e8b <strchr>:
 1006e8b:	55                   	push   %ebp
 1006e8c:	89 e5                	mov    %esp,%ebp
 1006e8e:	56                   	push   %esi
 1006e8f:	83 ec 04             	sub    $0x4,%esp
 1006e92:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006e95:	88 45 f8             	mov    %al,-0x8(%ebp)
 1006e98:	8b 55 08             	mov    0x8(%ebp),%edx
 1006e9b:	0f b6 45 f8          	movzbl -0x8(%ebp),%eax
 1006e9f:	89 d6                	mov    %edx,%esi
 1006ea1:	fc                   	cld    
 1006ea2:	88 c4                	mov    %al,%ah
 1006ea4:	ac                   	lods   %ds:(%esi),%al
 1006ea5:	38 e0                	cmp    %ah,%al
 1006ea7:	74 09                	je     1006eb2 <strchr+0x27>
 1006ea9:	84 c0                	test   %al,%al
 1006eab:	75 f7                	jne    1006ea4 <strchr+0x19>
 1006ead:	be 01 00 00 00       	mov    $0x1,%esi
 1006eb2:	89 f0                	mov    %esi,%eax
 1006eb4:	48                   	dec    %eax
 1006eb5:	83 c4 04             	add    $0x4,%esp
 1006eb8:	5e                   	pop    %esi
 1006eb9:	5d                   	pop    %ebp
 1006eba:	c3                   	ret    

01006ebb <strrchr>:
 1006ebb:	55                   	push   %ebp
 1006ebc:	89 e5                	mov    %esp,%ebp
 1006ebe:	56                   	push   %esi
 1006ebf:	83 ec 04             	sub    $0x4,%esp
 1006ec2:	8b 45 0c             	mov    0xc(%ebp),%eax
 1006ec5:	88 45 f8             	mov    %al,-0x8(%ebp)
 1006ec8:	ba 00 00 00 00       	mov    $0x0,%edx
 1006ecd:	8b 4d 08             	mov    0x8(%ebp),%ecx
 1006ed0:	0f b6 45 f8          	movzbl -0x8(%ebp),%eax
 1006ed4:	89 ce                	mov    %ecx,%esi
 1006ed6:	fc                   	cld    
 1006ed7:	88 c4                	mov    %al,%ah
 1006ed9:	ac                   	lods   %ds:(%esi),%al
 1006eda:	38 e0                	cmp    %ah,%al
 1006edc:	75 03                	jne    1006ee1 <strrchr+0x26>
 1006ede:	89 f2                	mov    %esi,%edx
 1006ee0:	4a                   	dec    %edx
 1006ee1:	84 c0                	test   %al,%al
 1006ee3:	75 f4                	jne    1006ed9 <strrchr+0x1e>
 1006ee5:	89 d0                	mov    %edx,%eax
 1006ee7:	83 c4 04             	add    $0x4,%esp
 1006eea:	5e                   	pop    %esi
 1006eeb:	5d                   	pop    %ebp
 1006eec:	c3                   	ret    

01006eed <strspn>:
 1006eed:	55                   	push   %ebp
 1006eee:	89 e5                	mov    %esp,%ebp
 1006ef0:	56                   	push   %esi
 1006ef1:	b8 00 00 00 00       	mov    $0x0,%eax
 1006ef6:	ba ff ff ff ff       	mov    $0xffffffff,%edx
 1006efb:	8b 4d 08             	mov    0x8(%ebp),%ecx
 1006efe:	89 ce                	mov    %ecx,%esi
 1006f00:	89 d1                	mov    %edx,%ecx
 1006f02:	fc                   	cld    
 1006f03:	8b 7d 0c             	mov    0xc(%ebp),%edi
 1006f06:	f2 ae                	repnz scas %es:(%edi),%al
 1006f08:	f7 d1                	not    %ecx
 1006f0a:	49                   	dec    %ecx
 1006f0b:	89 ca                	mov    %ecx,%edx
 1006f0d:	ac                   	lods   %ds:(%esi),%al
 1006f0e:	84 c0                	test   %al,%al
 1006f10:	74 09                	je     1006f1b <strspn+0x2e>
 1006f12:	8b 7d 0c             	mov    0xc(%ebp),%edi
 1006f15:	89 d1                	mov    %edx,%ecx
 1006f17:	f2 ae                	repnz scas %es:(%edi),%al
 1006f19:	74 f2                	je     1006f0d <strspn+0x20>
 1006f1b:	4e                   	dec    %esi
 1006f1c:	89 f0                	mov    %esi,%eax
 1006f1e:	89 c2                	mov    %eax,%edx
 1006f20:	8b 45 08             	mov    0x8(%ebp),%eax
 1006f23:	89 d1                	mov    %edx,%ecx
 1006f25:	29 c1                	sub    %eax,%ecx
 1006f27:	89 c8                	mov    %ecx,%eax
 1006f29:	5e                   	pop    %esi
 1006f2a:	5d                   	pop    %ebp
 1006f2b:	c3                   	ret    

01006f2c <strcspn>:
 1006f2c:	55                   	push   %ebp
 1006f2d:	89 e5                	mov    %esp,%ebp
 1006f2f:	56                   	push   %esi
 1006f30:	b8 00 00 00 00       	mov    $0x0,%eax
 1006f35:	ba ff ff ff ff       	mov    $0xffffffff,%edx
 1006f3a:	8b 4d 08             	mov    0x8(%ebp),%ecx
 1006f3d:	89 ce                	mov    %ecx,%esi
 1006f3f:	89 d1                	mov    %edx,%ecx
 1006f41:	fc                   	cld    
 1006f42:	8b 7d 0c             	mov    0xc(%ebp),%edi
 1006f45:	f2 ae                	repnz scas %es:(%edi),%al
 1006f47:	f7 d1                	not    %ecx
 1006f49:	49                   	dec    %ecx
 1006f4a:	89 ca                	mov    %ecx,%edx
 1006f4c:	ac                   	lods   %ds:(%esi),%al
 1006f4d:	84 c0                	test   %al,%al
 1006f4f:	74 09                	je     1006f5a <strcspn+0x2e>
 1006f51:	8b 7d 0c             	mov    0xc(%ebp),%edi
 1006f54:	89 d1                	mov    %edx,%ecx
 1006f56:	f2 ae                	repnz scas %es:(%edi),%al
 1006f58:	75 f2                	jne    1006f4c <strcspn+0x20>
 1006f5a:	4e                   	dec    %esi
 1006f5b:	89 f0                	mov    %esi,%eax
 1006f5d:	89 c2                	mov    %eax,%edx
 1006f5f:	8b 45 08             	mov    0x8(%ebp),%eax
 1006f62:	89 d1                	mov    %edx,%ecx
 1006f64:	29 c1                	sub    %eax,%ecx
 1006f66:	89 c8                	mov    %ecx,%eax
 1006f68:	5e                   	pop    %esi
 1006f69:	5d                   	pop    %ebp
 1006f6a:	c3                   	ret    

01006f6b <strpbrk>:
 1006f6b:	55                   	push   %ebp
 1006f6c:	89 e5                	mov    %esp,%ebp
 1006f6e:	56                   	push   %esi
 1006f6f:	b8 00 00 00 00       	mov    $0x0,%eax
 1006f74:	ba ff ff ff ff       	mov    $0xffffffff,%edx
 1006f79:	8b 4d 08             	mov    0x8(%ebp),%ecx
 1006f7c:	89 ce                	mov    %ecx,%esi
 1006f7e:	89 d1                	mov    %edx,%ecx
 1006f80:	fc                   	cld    
 1006f81:	8b 7d 0c             	mov    0xc(%ebp),%edi
 1006f84:	f2 ae                	repnz scas %es:(%edi),%al
 1006f86:	f7 d1                	not    %ecx
 1006f88:	49                   	dec    %ecx
 1006f89:	89 ca                	mov    %ecx,%edx
 1006f8b:	ac                   	lods   %ds:(%esi),%al
 1006f8c:	84 c0                	test   %al,%al
 1006f8e:	74 0c                	je     1006f9c <strpbrk+0x31>
 1006f90:	8b 7d 0c             	mov    0xc(%ebp),%edi
 1006f93:	89 d1                	mov    %edx,%ecx
 1006f95:	f2 ae                	repnz scas %es:(%edi),%al
 1006f97:	75 f2                	jne    1006f8b <strpbrk+0x20>
 1006f99:	4e                   	dec    %esi
 1006f9a:	eb 02                	jmp    1006f9e <strpbrk+0x33>
 1006f9c:	31 f6                	xor    %esi,%esi
 1006f9e:	89 f0                	mov    %esi,%eax
 1006fa0:	5e                   	pop    %esi
 1006fa1:	5d                   	pop    %ebp
 1006fa2:	c3                   	ret    

01006fa3 <strstr>:
 1006fa3:	55                   	push   %ebp
 1006fa4:	89 e5                	mov    %esp,%ebp
 1006fa6:	56                   	push   %esi
 1006fa7:	53                   	push   %ebx
 1006fa8:	b8 00 00 00 00       	mov    $0x0,%eax
 1006fad:	ba ff ff ff ff       	mov    $0xffffffff,%edx
 1006fb2:	8b 5d 08             	mov    0x8(%ebp),%ebx
 1006fb5:	89 d1                	mov    %edx,%ecx
 1006fb7:	89 de                	mov    %ebx,%esi
 1006fb9:	fc                   	cld    
 1006fba:	8b 7d 0c             	mov    0xc(%ebp),%edi
 1006fbd:	f2 ae                	repnz scas %es:(%edi),%al
 1006fbf:	f7 d1                	not    %ecx
 1006fc1:	49                   	dec    %ecx
 1006fc2:	89 ca                	mov    %ecx,%edx
 1006fc4:	8b 7d 0c             	mov    0xc(%ebp),%edi
 1006fc7:	89 f0                	mov    %esi,%eax
 1006fc9:	89 d1                	mov    %edx,%ecx
 1006fcb:	f3 a6                	repz cmpsb %es:(%edi),%ds:(%esi)
 1006fcd:	74 0a                	je     1006fd9 <strstr+0x36>
 1006fcf:	96                   	xchg   %eax,%esi
 1006fd0:	46                   	inc    %esi
 1006fd1:	80 78 ff 00          	cmpb   $0x0,-0x1(%eax)
 1006fd5:	75 ed                	jne    1006fc4 <strstr+0x21>
 1006fd7:	31 c0                	xor    %eax,%eax
 1006fd9:	5b                   	pop    %ebx
 1006fda:	5e                   	pop    %esi
 1006fdb:	5d                   	pop    %ebp
 1006fdc:	c3                   	ret    

01006fdd <strlen>:
 1006fdd:	55                   	push   %ebp
 1006fde:	89 e5                	mov    %esp,%ebp
 1006fe0:	57                   	push   %edi
 1006fe1:	8b 55 08             	mov    0x8(%ebp),%edx
 1006fe4:	b8 00 00 00 00       	mov    $0x0,%eax
 1006fe9:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 1006fee:	89 d7                	mov    %edx,%edi
 1006ff0:	fc                   	cld    
 1006ff1:	f2 ae                	repnz scas %es:(%edi),%al
 1006ff3:	f7 d1                	not    %ecx
 1006ff5:	49                   	dec    %ecx
 1006ff6:	89 c8                	mov    %ecx,%eax
 1006ff8:	5f                   	pop    %edi
 1006ff9:	5d                   	pop    %ebp
 1006ffa:	c3                   	ret    

01006ffb <memcpy>:
 1006ffb:	55                   	push   %ebp
 1006ffc:	89 e5                	mov    %esp,%ebp
 1006ffe:	57                   	push   %edi
 1006fff:	56                   	push   %esi
 1007000:	53                   	push   %ebx
 1007001:	8b 45 10             	mov    0x10(%ebp),%eax
 1007004:	8b 55 0c             	mov    0xc(%ebp),%edx
 1007007:	8b 5d 08             	mov    0x8(%ebp),%ebx
 100700a:	89 c1                	mov    %eax,%ecx
 100700c:	89 d6                	mov    %edx,%esi
 100700e:	89 df                	mov    %ebx,%edi
 1007010:	fc                   	cld    
 1007011:	f3 a4                	rep movsb %ds:(%esi),%es:(%edi)
 1007013:	8b 45 08             	mov    0x8(%ebp),%eax
 1007016:	5b                   	pop    %ebx
 1007017:	5e                   	pop    %esi
 1007018:	5f                   	pop    %edi
 1007019:	5d                   	pop    %ebp
 100701a:	c3                   	ret    

0100701b <memmove>:
 100701b:	55                   	push   %ebp
 100701c:	89 e5                	mov    %esp,%ebp
 100701e:	57                   	push   %edi
 100701f:	56                   	push   %esi
 1007020:	53                   	push   %ebx
 1007021:	8b 45 08             	mov    0x8(%ebp),%eax
 1007024:	3b 45 0c             	cmp    0xc(%ebp),%eax
 1007027:	73 14                	jae    100703d <memmove+0x22>
 1007029:	8b 45 10             	mov    0x10(%ebp),%eax
 100702c:	8b 55 0c             	mov    0xc(%ebp),%edx
 100702f:	8b 5d 08             	mov    0x8(%ebp),%ebx
 1007032:	89 c1                	mov    %eax,%ecx
 1007034:	89 d6                	mov    %edx,%esi
 1007036:	89 df                	mov    %ebx,%edi
 1007038:	fc                   	cld    
 1007039:	f3 a4                	rep movsb %ds:(%esi),%es:(%edi)
 100703b:	eb 22                	jmp    100705f <memmove+0x44>
 100703d:	8b 45 10             	mov    0x10(%ebp),%eax
 1007040:	83 e8 01             	sub    $0x1,%eax
 1007043:	89 c2                	mov    %eax,%edx
 1007045:	03 55 0c             	add    0xc(%ebp),%edx
 1007048:	8b 45 10             	mov    0x10(%ebp),%eax
 100704b:	83 e8 01             	sub    $0x1,%eax
 100704e:	89 c3                	mov    %eax,%ebx
 1007050:	03 5d 08             	add    0x8(%ebp),%ebx
 1007053:	8b 45 10             	mov    0x10(%ebp),%eax
 1007056:	89 c1                	mov    %eax,%ecx
 1007058:	89 d6                	mov    %edx,%esi
 100705a:	89 df                	mov    %ebx,%edi
 100705c:	fd                   	std    
 100705d:	f3 a4                	rep movsb %ds:(%esi),%es:(%edi)
 100705f:	8b 45 08             	mov    0x8(%ebp),%eax
 1007062:	5b                   	pop    %ebx
 1007063:	5e                   	pop    %esi
 1007064:	5f                   	pop    %edi
 1007065:	5d                   	pop    %ebp
 1007066:	c3                   	ret    

01007067 <memcmp>:
 1007067:	55                   	push   %ebp
 1007068:	89 e5                	mov    %esp,%ebp
 100706a:	57                   	push   %edi
 100706b:	56                   	push   %esi
 100706c:	53                   	push   %ebx
 100706d:	b8 00 00 00 00       	mov    $0x0,%eax
 1007072:	8b 55 08             	mov    0x8(%ebp),%edx
 1007075:	8b 5d 0c             	mov    0xc(%ebp),%ebx
 1007078:	8b 4d 10             	mov    0x10(%ebp),%ecx
 100707b:	89 d7                	mov    %edx,%edi
 100707d:	89 de                	mov    %ebx,%esi
 100707f:	fc                   	cld    
 1007080:	f3 a6                	repz cmpsb %es:(%edi),%ds:(%esi)
 1007082:	74 09                	je     100708d <memcmp+0x26>
 1007084:	b8 01 00 00 00       	mov    $0x1,%eax
 1007089:	7c 02                	jl     100708d <memcmp+0x26>
 100708b:	f7 d8                	neg    %eax
 100708d:	5b                   	pop    %ebx
 100708e:	5e                   	pop    %esi
 100708f:	5f                   	pop    %edi
 1007090:	5d                   	pop    %ebp
 1007091:	c3                   	ret    

01007092 <memset>:
 1007092:	55                   	push   %ebp
 1007093:	89 e5                	mov    %esp,%ebp
 1007095:	57                   	push   %edi
 1007096:	83 ec 04             	sub    $0x4,%esp
 1007099:	8b 45 0c             	mov    0xc(%ebp),%eax
 100709c:	88 45 f8             	mov    %al,-0x8(%ebp)
 100709f:	0f b6 45 f8          	movzbl -0x8(%ebp),%eax
 10070a3:	8b 55 08             	mov    0x8(%ebp),%edx
 10070a6:	8b 4d 10             	mov    0x10(%ebp),%ecx
 10070a9:	89 d7                	mov    %edx,%edi
 10070ab:	fc                   	cld    
 10070ac:	f3 aa                	rep stos %al,%es:(%edi)
 10070ae:	8b 45 08             	mov    0x8(%ebp),%eax
 10070b1:	83 c4 04             	add    $0x4,%esp
 10070b4:	5f                   	pop    %edi
 10070b5:	5d                   	pop    %ebp
 10070b6:	c3                   	ret    

010070b7 <clock>:
 10070b7:	55                   	push   %ebp
 10070b8:	89 e5                	mov    %esp,%ebp
 10070ba:	53                   	push   %ebx
 10070bb:	83 ec 14             	sub    $0x14,%esp
 10070be:	c7 45 e8 0b 00 00 00 	movl   $0xb,-0x18(%ebp)
 10070c5:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10070c8:	cd 80                	int    $0x80
 10070ca:	89 c3                	mov    %eax,%ebx
 10070cc:	89 5d f8             	mov    %ebx,-0x8(%ebp)
 10070cf:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 10070d3:	79 11                	jns    10070e6 <clock+0x2f>
 10070d5:	8b 45 f8             	mov    -0x8(%ebp),%eax
 10070d8:	f7 d8                	neg    %eax
 10070da:	a3 5a 00 00 01       	mov    %eax,0x100005a
 10070df:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 10070e4:	eb 03                	jmp    10070e9 <clock+0x32>
 10070e6:	8b 45 f8             	mov    -0x8(%ebp),%eax
 10070e9:	83 c4 14             	add    $0x14,%esp
 10070ec:	5b                   	pop    %ebx
 10070ed:	5d                   	pop    %ebp
 10070ee:	c3                   	ret    

010070ef <rand>:
 10070ef:	55                   	push   %ebp
 10070f0:	89 e5                	mov    %esp,%ebp
 10070f2:	53                   	push   %ebx
 10070f3:	a1 48 06 03 01       	mov    0x1030648,%eax
 10070f8:	8b 15 4c 06 03 01    	mov    0x103064c,%edx
 10070fe:	69 da 2d 7f 95 4c    	imul   $0x4c957f2d,%edx,%ebx
 1007104:	69 c8 2d f4 51 58    	imul   $0x5851f42d,%eax,%ecx
 100710a:	01 cb                	add    %ecx,%ebx
 100710c:	b9 2d 7f 95 4c       	mov    $0x4c957f2d,%ecx
 1007111:	f7 e1                	mul    %ecx
 1007113:	8d 0c 13             	lea    (%ebx,%edx,1),%ecx
 1007116:	89 ca                	mov    %ecx,%edx
 1007118:	83 c0 01             	add    $0x1,%eax
 100711b:	83 d2 00             	adc    $0x0,%edx
 100711e:	a3 48 06 03 01       	mov    %eax,0x1030648
 1007123:	89 15 4c 06 03 01    	mov    %edx,0x103064c
 1007129:	a1 48 06 03 01       	mov    0x1030648,%eax
 100712e:	8b 15 4c 06 03 01    	mov    0x103064c,%edx
 1007134:	89 d0                	mov    %edx,%eax
 1007136:	31 d2                	xor    %edx,%edx
 1007138:	25 ff 7f 00 00       	and    $0x7fff,%eax
 100713d:	5b                   	pop    %ebx
 100713e:	5d                   	pop    %ebp
 100713f:	c3                   	ret    

01007140 <srand>:
 1007140:	55                   	push   %ebp
 1007141:	89 e5                	mov    %esp,%ebp
 1007143:	8b 45 08             	mov    0x8(%ebp),%eax
 1007146:	ba 00 00 00 00       	mov    $0x0,%edx
 100714b:	a3 48 06 03 01       	mov    %eax,0x1030648
 1007150:	89 15 4c 06 03 01    	mov    %edx,0x103064c
 1007156:	5d                   	pop    %ebp
 1007157:	c3                   	ret    

01007158 <freopen>:
 1007158:	55                   	push   %ebp
 1007159:	89 e5                	mov    %esp,%ebp
 100715b:	53                   	push   %ebx
 100715c:	83 ec 20             	sub    $0x20,%esp
 100715f:	c7 45 f8 ff ff ff ff 	movl   $0xffffffff,-0x8(%ebp)
 1007166:	c7 44 24 04 54 94 00 	movl   $0x1009454,0x4(%esp)
 100716d:	01 
 100716e:	8b 45 08             	mov    0x8(%ebp),%eax
 1007171:	89 04 24             	mov    %eax,(%esp)
 1007174:	e8 ba fc ff ff       	call   1006e33 <strcmp>
 1007179:	85 c0                	test   %eax,%eax
 100717b:	75 09                	jne    1007186 <freopen+0x2e>
 100717d:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%ebp)
 1007184:	eb 5e                	jmp    10071e4 <freopen+0x8c>
 1007186:	c7 44 24 04 5a 94 00 	movl   $0x100945a,0x4(%esp)
 100718d:	01 
 100718e:	8b 45 08             	mov    0x8(%ebp),%eax
 1007191:	89 04 24             	mov    %eax,(%esp)
 1007194:	e8 9a fc ff ff       	call   1006e33 <strcmp>
 1007199:	85 c0                	test   %eax,%eax
 100719b:	75 09                	jne    10071a6 <freopen+0x4e>
 100719d:	c7 45 f8 01 00 00 00 	movl   $0x1,-0x8(%ebp)
 10071a4:	eb 3e                	jmp    10071e4 <freopen+0x8c>
 10071a6:	c7 44 24 04 60 94 00 	movl   $0x1009460,0x4(%esp)
 10071ad:	01 
 10071ae:	8b 45 08             	mov    0x8(%ebp),%eax
 10071b1:	89 04 24             	mov    %eax,(%esp)
 10071b4:	e8 7a fc ff ff       	call   1006e33 <strcmp>
 10071b9:	85 c0                	test   %eax,%eax
 10071bb:	75 09                	jne    10071c6 <freopen+0x6e>
 10071bd:	c7 45 f8 02 00 00 00 	movl   $0x2,-0x8(%ebp)
 10071c4:	eb 1e                	jmp    10071e4 <freopen+0x8c>
 10071c6:	c7 44 24 04 66 94 00 	movl   $0x1009466,0x4(%esp)
 10071cd:	01 
 10071ce:	8b 45 08             	mov    0x8(%ebp),%eax
 10071d1:	89 04 24             	mov    %eax,(%esp)
 10071d4:	e8 5a fc ff ff       	call   1006e33 <strcmp>
 10071d9:	85 c0                	test   %eax,%eax
 10071db:	75 07                	jne    10071e4 <freopen+0x8c>
 10071dd:	c7 45 f8 03 00 00 00 	movl   $0x3,-0x8(%ebp)
 10071e4:	83 7d f8 ff          	cmpl   $0xffffffff,-0x8(%ebp)
 10071e8:	75 07                	jne    10071f1 <freopen+0x99>
 10071ea:	b8 00 00 00 00       	mov    $0x0,%eax
 10071ef:	eb 2f                	jmp    1007220 <freopen+0xc8>
 10071f1:	c7 45 e4 01 00 00 00 	movl   $0x1,-0x1c(%ebp)
 10071f8:	8b 55 f8             	mov    -0x8(%ebp),%edx
 10071fb:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 10071fe:	89 d3                	mov    %edx,%ebx
 1007200:	cd 80                	int    $0x80
 1007202:	89 45 e8             	mov    %eax,-0x18(%ebp)
 1007205:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1007208:	89 45 f4             	mov    %eax,-0xc(%ebp)
 100720b:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 100720f:	79 0a                	jns    100721b <freopen+0xc3>
 1007211:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1007214:	f7 d8                	neg    %eax
 1007216:	a3 5a 00 00 01       	mov    %eax,0x100005a
 100721b:	b8 01 00 00 00       	mov    $0x1,%eax
 1007220:	83 c4 20             	add    $0x20,%esp
 1007223:	5b                   	pop    %ebx
 1007224:	5d                   	pop    %ebp
 1007225:	c3                   	ret    

01007226 <gettime>:
 1007226:	55                   	push   %ebp
 1007227:	89 e5                	mov    %esp,%ebp
 1007229:	53                   	push   %ebx
 100722a:	83 ec 14             	sub    $0x14,%esp
 100722d:	c7 45 e8 11 00 00 00 	movl   $0x11,-0x18(%ebp)
 1007234:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1007237:	cd 80                	int    $0x80
 1007239:	89 c3                	mov    %eax,%ebx
 100723b:	89 5d f8             	mov    %ebx,-0x8(%ebp)
 100723e:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 1007242:	79 11                	jns    1007255 <gettime+0x2f>
 1007244:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007247:	f7 d8                	neg    %eax
 1007249:	a3 5a 00 00 01       	mov    %eax,0x100005a
 100724e:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 1007253:	eb 03                	jmp    1007258 <gettime+0x32>
 1007255:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007258:	83 c4 14             	add    $0x14,%esp
 100725b:	5b                   	pop    %ebx
 100725c:	5d                   	pop    %ebp
 100725d:	c3                   	ret    

0100725e <tty_read>:
 100725e:	55                   	push   %ebp
 100725f:	89 e5                	mov    %esp,%ebp
 1007261:	53                   	push   %ebx
 1007262:	83 ec 18             	sub    $0x18,%esp
 1007265:	c7 45 e4 03 00 00 00 	movl   $0x3,-0x1c(%ebp)
 100726c:	8b 55 08             	mov    0x8(%ebp),%edx
 100726f:	8b 4d 0c             	mov    0xc(%ebp),%ecx
 1007272:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1007275:	89 d3                	mov    %edx,%ebx
 1007277:	cd 80                	int    $0x80
 1007279:	89 45 e8             	mov    %eax,-0x18(%ebp)
 100727c:	8b 45 e8             	mov    -0x18(%ebp),%eax
 100727f:	89 45 f8             	mov    %eax,-0x8(%ebp)
 1007282:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 1007286:	79 11                	jns    1007299 <tty_read+0x3b>
 1007288:	8b 45 f8             	mov    -0x8(%ebp),%eax
 100728b:	f7 d8                	neg    %eax
 100728d:	a3 5a 00 00 01       	mov    %eax,0x100005a
 1007292:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 1007297:	eb 03                	jmp    100729c <tty_read+0x3e>
 1007299:	8b 45 f8             	mov    -0x8(%ebp),%eax
 100729c:	83 c4 18             	add    $0x18,%esp
 100729f:	5b                   	pop    %ebx
 10072a0:	5d                   	pop    %ebp
 10072a1:	c3                   	ret    

010072a2 <tty_write>:
 10072a2:	55                   	push   %ebp
 10072a3:	89 e5                	mov    %esp,%ebp
 10072a5:	53                   	push   %ebx
 10072a6:	83 ec 18             	sub    $0x18,%esp
 10072a9:	c7 45 e4 04 00 00 00 	movl   $0x4,-0x1c(%ebp)
 10072b0:	8b 55 08             	mov    0x8(%ebp),%edx
 10072b3:	8b 4d 0c             	mov    0xc(%ebp),%ecx
 10072b6:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 10072b9:	89 d3                	mov    %edx,%ebx
 10072bb:	cd 80                	int    $0x80
 10072bd:	89 45 e8             	mov    %eax,-0x18(%ebp)
 10072c0:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10072c3:	89 45 f8             	mov    %eax,-0x8(%ebp)
 10072c6:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 10072ca:	79 11                	jns    10072dd <tty_write+0x3b>
 10072cc:	8b 45 f8             	mov    -0x8(%ebp),%eax
 10072cf:	f7 d8                	neg    %eax
 10072d1:	a3 5a 00 00 01       	mov    %eax,0x100005a
 10072d6:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 10072db:	eb 03                	jmp    10072e0 <tty_write+0x3e>
 10072dd:	8b 45 f8             	mov    -0x8(%ebp),%eax
 10072e0:	83 c4 18             	add    $0x18,%esp
 10072e3:	5b                   	pop    %ebx
 10072e4:	5d                   	pop    %ebp
 10072e5:	c3                   	ret    

010072e6 <fork>:
 10072e6:	55                   	push   %ebp
 10072e7:	89 e5                	mov    %esp,%ebp
 10072e9:	53                   	push   %ebx
 10072ea:	83 ec 14             	sub    $0x14,%esp
 10072ed:	c7 45 e8 08 00 00 00 	movl   $0x8,-0x18(%ebp)
 10072f4:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10072f7:	cd 80                	int    $0x80
 10072f9:	89 c3                	mov    %eax,%ebx
 10072fb:	89 5d f8             	mov    %ebx,-0x8(%ebp)
 10072fe:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 1007302:	79 11                	jns    1007315 <fork+0x2f>
 1007304:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007307:	f7 d8                	neg    %eax
 1007309:	a3 5a 00 00 01       	mov    %eax,0x100005a
 100730e:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 1007313:	eb 03                	jmp    1007318 <fork+0x32>
 1007315:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007318:	83 c4 14             	add    $0x14,%esp
 100731b:	5b                   	pop    %ebx
 100731c:	5d                   	pop    %ebp
 100731d:	c3                   	ret    

0100731e <exit>:
 100731e:	55                   	push   %ebp
 100731f:	89 e5                	mov    %esp,%ebp
 1007321:	53                   	push   %ebx
 1007322:	83 ec 18             	sub    $0x18,%esp
 1007325:	c7 45 e4 09 00 00 00 	movl   $0x9,-0x1c(%ebp)
 100732c:	8b 55 08             	mov    0x8(%ebp),%edx
 100732f:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1007332:	89 d3                	mov    %edx,%ebx
 1007334:	cd 80                	int    $0x80
 1007336:	89 45 e8             	mov    %eax,-0x18(%ebp)
 1007339:	8b 45 e8             	mov    -0x18(%ebp),%eax
 100733c:	89 45 f8             	mov    %eax,-0x8(%ebp)
 100733f:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 1007343:	79 0a                	jns    100734f <exit+0x31>
 1007345:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007348:	f7 d8                	neg    %eax
 100734a:	a3 5a 00 00 01       	mov    %eax,0x100005a
 100734f:	83 c4 18             	add    $0x18,%esp
 1007352:	5b                   	pop    %ebx
 1007353:	5d                   	pop    %ebp
 1007354:	c3                   	ret    

01007355 <waitpid>:
 1007355:	55                   	push   %ebp
 1007356:	89 e5                	mov    %esp,%ebp
 1007358:	53                   	push   %ebx
 1007359:	83 ec 14             	sub    $0x14,%esp
 100735c:	c7 45 e8 0d 00 00 00 	movl   $0xd,-0x18(%ebp)
 1007363:	8b 5d 08             	mov    0x8(%ebp),%ebx
 1007366:	8b 4d 0c             	mov    0xc(%ebp),%ecx
 1007369:	8b 55 10             	mov    0x10(%ebp),%edx
 100736c:	8b 45 e8             	mov    -0x18(%ebp),%eax
 100736f:	cd 80                	int    $0x80
 1007371:	89 c3                	mov    %eax,%ebx
 1007373:	89 5d f8             	mov    %ebx,-0x8(%ebp)
 1007376:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 100737a:	79 11                	jns    100738d <waitpid+0x38>
 100737c:	8b 45 f8             	mov    -0x8(%ebp),%eax
 100737f:	f7 d8                	neg    %eax
 1007381:	a3 5a 00 00 01       	mov    %eax,0x100005a
 1007386:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 100738b:	eb 03                	jmp    1007390 <waitpid+0x3b>
 100738d:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007390:	83 c4 14             	add    $0x14,%esp
 1007393:	5b                   	pop    %ebx
 1007394:	5d                   	pop    %ebp
 1007395:	c3                   	ret    

01007396 <exec>:
 1007396:	55                   	push   %ebp
 1007397:	89 e5                	mov    %esp,%ebp
 1007399:	53                   	push   %ebx
 100739a:	83 ec 18             	sub    $0x18,%esp
 100739d:	c7 45 e4 0e 00 00 00 	movl   $0xe,-0x1c(%ebp)
 10073a4:	8b 55 08             	mov    0x8(%ebp),%edx
 10073a7:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 10073aa:	89 d3                	mov    %edx,%ebx
 10073ac:	cd 80                	int    $0x80
 10073ae:	89 45 e8             	mov    %eax,-0x18(%ebp)
 10073b1:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10073b4:	89 45 f8             	mov    %eax,-0x8(%ebp)
 10073b7:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 10073bb:	79 11                	jns    10073ce <exec+0x38>
 10073bd:	8b 45 f8             	mov    -0x8(%ebp),%eax
 10073c0:	f7 d8                	neg    %eax
 10073c2:	a3 5a 00 00 01       	mov    %eax,0x100005a
 10073c7:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 10073cc:	eb 03                	jmp    10073d1 <exec+0x3b>
 10073ce:	8b 45 f8             	mov    -0x8(%ebp),%eax
 10073d1:	83 c4 18             	add    $0x18,%esp
 10073d4:	5b                   	pop    %ebx
 10073d5:	5d                   	pop    %ebp
 10073d6:	c3                   	ret    

010073d7 <getline>:
 10073d7:	55                   	push   %ebp
 10073d8:	89 e5                	mov    %esp,%ebp
 10073da:	83 ec 28             	sub    $0x28,%esp
 10073dd:	c6 45 ef 00          	movb   $0x0,-0x11(%ebp)
 10073e1:	c6 45 ee 00          	movb   $0x0,-0x12(%ebp)
 10073e5:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 10073ec:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 10073f3:	00 
 10073f4:	8d 45 ee             	lea    -0x12(%ebp),%eax
 10073f7:	89 04 24             	mov    %eax,(%esp)
 10073fa:	e8 5f fe ff ff       	call   100725e <tty_read>
 10073ff:	89 45 f0             	mov    %eax,-0x10(%ebp)
 1007402:	83 7d f0 00          	cmpl   $0x0,-0x10(%ebp)
 1007406:	74 0c                	je     1007414 <getline+0x3d>
 1007408:	c7 04 24 6c 94 00 01 	movl   $0x100946c,(%esp)
 100740f:	e8 5e 00 00 00       	call   1007472 <uprint>
 1007414:	83 7d f0 00          	cmpl   $0x0,-0x10(%ebp)
 1007418:	75 48                	jne    1007462 <getline+0x8b>
 100741a:	0f b6 45 ee          	movzbl -0x12(%ebp),%eax
 100741e:	3c 08                	cmp    $0x8,%al
 1007420:	75 21                	jne    1007443 <getline+0x6c>
 1007422:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 1007426:	74 39                	je     1007461 <getline+0x8a>
 1007428:	83 6d f4 01          	subl   $0x1,-0xc(%ebp)
 100742c:	83 6d 08 01          	subl   $0x1,0x8(%ebp)
 1007430:	8b 45 08             	mov    0x8(%ebp),%eax
 1007433:	c6 00 00             	movb   $0x0,(%eax)
 1007436:	8d 45 ee             	lea    -0x12(%ebp),%eax
 1007439:	89 04 24             	mov    %eax,(%esp)
 100743c:	e8 31 00 00 00       	call   1007472 <uprint>
 1007441:	eb 1e                	jmp    1007461 <getline+0x8a>
 1007443:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 1007447:	8d 45 ee             	lea    -0x12(%ebp),%eax
 100744a:	89 04 24             	mov    %eax,(%esp)
 100744d:	e8 20 00 00 00       	call   1007472 <uprint>
 1007452:	0f b6 55 ee          	movzbl -0x12(%ebp),%edx
 1007456:	8b 45 08             	mov    0x8(%ebp),%eax
 1007459:	88 10                	mov    %dl,(%eax)
 100745b:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 100745f:	eb 01                	jmp    1007462 <getline+0x8b>
 1007461:	90                   	nop
 1007462:	0f b6 45 ee          	movzbl -0x12(%ebp),%eax
 1007466:	3c 0a                	cmp    $0xa,%al
 1007468:	75 82                	jne    10073ec <getline+0x15>
 100746a:	8b 45 08             	mov    0x8(%ebp),%eax
 100746d:	c6 00 00             	movb   $0x0,(%eax)
 1007470:	c9                   	leave  
 1007471:	c3                   	ret    

01007472 <uprint>:
 1007472:	55                   	push   %ebp
 1007473:	89 e5                	mov    %esp,%ebp
 1007475:	83 ec 18             	sub    $0x18,%esp
 1007478:	8b 45 08             	mov    0x8(%ebp),%eax
 100747b:	89 04 24             	mov    %eax,(%esp)
 100747e:	e8 5a fb ff ff       	call   1006fdd <strlen>
 1007483:	89 45 fc             	mov    %eax,-0x4(%ebp)
 1007486:	8b 45 fc             	mov    -0x4(%ebp),%eax
 1007489:	89 44 24 04          	mov    %eax,0x4(%esp)
 100748d:	8b 45 08             	mov    0x8(%ebp),%eax
 1007490:	89 04 24             	mov    %eax,(%esp)
 1007493:	e8 0a fe ff ff       	call   10072a2 <tty_write>
 1007498:	c9                   	leave  
 1007499:	c3                   	ret    

0100749a <set_tty_attr>:
 100749a:	55                   	push   %ebp
 100749b:	89 e5                	mov    %esp,%ebp
 100749d:	53                   	push   %ebx
 100749e:	83 ec 18             	sub    $0x18,%esp
 10074a1:	c7 45 e4 06 00 00 00 	movl   $0x6,-0x1c(%ebp)
 10074a8:	8b 55 08             	mov    0x8(%ebp),%edx
 10074ab:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 10074ae:	89 d3                	mov    %edx,%ebx
 10074b0:	cd 80                	int    $0x80
 10074b2:	89 45 e8             	mov    %eax,-0x18(%ebp)
 10074b5:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10074b8:	89 45 f8             	mov    %eax,-0x8(%ebp)
 10074bb:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 10074bf:	79 11                	jns    10074d2 <set_tty_attr+0x38>
 10074c1:	8b 45 f8             	mov    -0x8(%ebp),%eax
 10074c4:	f7 d8                	neg    %eax
 10074c6:	a3 5a 00 00 01       	mov    %eax,0x100005a
 10074cb:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 10074d0:	eb 03                	jmp    10074d5 <set_tty_attr+0x3b>
 10074d2:	8b 45 f8             	mov    -0x8(%ebp),%eax
 10074d5:	83 c4 18             	add    $0x18,%esp
 10074d8:	5b                   	pop    %ebx
 10074d9:	5d                   	pop    %ebp
 10074da:	c3                   	ret    

010074db <tty_goxy>:
 10074db:	55                   	push   %ebp
 10074dc:	89 e5                	mov    %esp,%ebp
 10074de:	53                   	push   %ebx
 10074df:	83 ec 18             	sub    $0x18,%esp
 10074e2:	c7 45 e4 05 00 00 00 	movl   $0x5,-0x1c(%ebp)
 10074e9:	8b 55 08             	mov    0x8(%ebp),%edx
 10074ec:	8b 4d 0c             	mov    0xc(%ebp),%ecx
 10074ef:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 10074f2:	89 d3                	mov    %edx,%ebx
 10074f4:	cd 80                	int    $0x80
 10074f6:	89 45 e8             	mov    %eax,-0x18(%ebp)
 10074f9:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10074fc:	89 45 f8             	mov    %eax,-0x8(%ebp)
 10074ff:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 1007503:	79 11                	jns    1007516 <tty_goxy+0x3b>
 1007505:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007508:	f7 d8                	neg    %eax
 100750a:	a3 5a 00 00 01       	mov    %eax,0x100005a
 100750f:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 1007514:	eb 03                	jmp    1007519 <tty_goxy+0x3e>
 1007516:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007519:	83 c4 18             	add    $0x18,%esp
 100751c:	5b                   	pop    %ebx
 100751d:	5d                   	pop    %ebp
 100751e:	c3                   	ret    

0100751f <get_graph_info>:
 100751f:	55                   	push   %ebp
 1007520:	89 e5                	mov    %esp,%ebp
 1007522:	53                   	push   %ebx
 1007523:	83 ec 18             	sub    $0x18,%esp
 1007526:	c7 45 e4 12 00 00 00 	movl   $0x12,-0x1c(%ebp)
 100752d:	8b 55 08             	mov    0x8(%ebp),%edx
 1007530:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1007533:	89 d3                	mov    %edx,%ebx
 1007535:	cd 80                	int    $0x80
 1007537:	89 45 e8             	mov    %eax,-0x18(%ebp)
 100753a:	8b 45 e8             	mov    -0x18(%ebp),%eax
 100753d:	89 45 f8             	mov    %eax,-0x8(%ebp)
 1007540:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 1007544:	79 11                	jns    1007557 <get_graph_info+0x38>
 1007546:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007549:	f7 d8                	neg    %eax
 100754b:	a3 5a 00 00 01       	mov    %eax,0x100005a
 1007550:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 1007555:	eb 03                	jmp    100755a <get_graph_info+0x3b>
 1007557:	8b 45 f8             	mov    -0x8(%ebp),%eax
 100755a:	83 c4 18             	add    $0x18,%esp
 100755d:	5b                   	pop    %ebx
 100755e:	5d                   	pop    %ebp
 100755f:	c3                   	ret    

01007560 <tty_switch>:
 1007560:	55                   	push   %ebp
 1007561:	89 e5                	mov    %esp,%ebp
 1007563:	53                   	push   %ebx
 1007564:	83 ec 18             	sub    $0x18,%esp
 1007567:	c7 45 e4 02 00 00 00 	movl   $0x2,-0x1c(%ebp)
 100756e:	8b 55 08             	mov    0x8(%ebp),%edx
 1007571:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1007574:	89 d3                	mov    %edx,%ebx
 1007576:	cd 80                	int    $0x80
 1007578:	89 45 e8             	mov    %eax,-0x18(%ebp)
 100757b:	8b 45 e8             	mov    -0x18(%ebp),%eax
 100757e:	89 45 f8             	mov    %eax,-0x8(%ebp)
 1007581:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 1007585:	79 11                	jns    1007598 <tty_switch+0x38>
 1007587:	8b 45 f8             	mov    -0x8(%ebp),%eax
 100758a:	f7 d8                	neg    %eax
 100758c:	a3 5a 00 00 01       	mov    %eax,0x100005a
 1007591:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 1007596:	eb 03                	jmp    100759b <tty_switch+0x3b>
 1007598:	8b 45 f8             	mov    -0x8(%ebp),%eax
 100759b:	83 c4 18             	add    $0x18,%esp
 100759e:	5b                   	pop    %ebx
 100759f:	5d                   	pop    %ebp
 10075a0:	c3                   	ret    

010075a1 <get_module_size>:
 10075a1:	55                   	push   %ebp
 10075a2:	89 e5                	mov    %esp,%ebp
 10075a4:	53                   	push   %ebx
 10075a5:	83 ec 18             	sub    $0x18,%esp
 10075a8:	c7 45 e4 10 00 00 00 	movl   $0x10,-0x1c(%ebp)
 10075af:	8b 55 08             	mov    0x8(%ebp),%edx
 10075b2:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 10075b5:	89 d3                	mov    %edx,%ebx
 10075b7:	cd 80                	int    $0x80
 10075b9:	89 45 e8             	mov    %eax,-0x18(%ebp)
 10075bc:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10075bf:	89 45 f8             	mov    %eax,-0x8(%ebp)
 10075c2:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 10075c6:	79 11                	jns    10075d9 <get_module_size+0x38>
 10075c8:	8b 45 f8             	mov    -0x8(%ebp),%eax
 10075cb:	f7 d8                	neg    %eax
 10075cd:	a3 5a 00 00 01       	mov    %eax,0x100005a
 10075d2:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 10075d7:	eb 03                	jmp    10075dc <get_module_size+0x3b>
 10075d9:	8b 45 f8             	mov    -0x8(%ebp),%eax
 10075dc:	83 c4 18             	add    $0x18,%esp
 10075df:	5b                   	pop    %ebx
 10075e0:	5d                   	pop    %ebp
 10075e1:	c3                   	ret    

010075e2 <get_module>:
 10075e2:	55                   	push   %ebp
 10075e3:	89 e5                	mov    %esp,%ebp
 10075e5:	53                   	push   %ebx
 10075e6:	83 ec 18             	sub    $0x18,%esp
 10075e9:	c7 45 e4 0f 00 00 00 	movl   $0xf,-0x1c(%ebp)
 10075f0:	8b 55 08             	mov    0x8(%ebp),%edx
 10075f3:	8b 4d 0c             	mov    0xc(%ebp),%ecx
 10075f6:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 10075f9:	89 d3                	mov    %edx,%ebx
 10075fb:	cd 80                	int    $0x80
 10075fd:	89 45 e8             	mov    %eax,-0x18(%ebp)
 1007600:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1007603:	89 45 f8             	mov    %eax,-0x8(%ebp)
 1007606:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 100760a:	79 11                	jns    100761d <get_module+0x3b>
 100760c:	8b 45 f8             	mov    -0x8(%ebp),%eax
 100760f:	f7 d8                	neg    %eax
 1007611:	a3 5a 00 00 01       	mov    %eax,0x100005a
 1007616:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 100761b:	eb 03                	jmp    1007620 <get_module+0x3e>
 100761d:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007620:	83 c4 18             	add    $0x18,%esp
 1007623:	5b                   	pop    %ebx
 1007624:	5d                   	pop    %ebp
 1007625:	c3                   	ret    

01007626 <send>:
 1007626:	55                   	push   %ebp
 1007627:	89 e5                	mov    %esp,%ebp
 1007629:	53                   	push   %ebx
 100762a:	83 ec 18             	sub    $0x18,%esp
 100762d:	c7 45 e4 14 00 00 00 	movl   $0x14,-0x1c(%ebp)
 1007634:	8b 55 08             	mov    0x8(%ebp),%edx
 1007637:	8b 4d 0c             	mov    0xc(%ebp),%ecx
 100763a:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 100763d:	89 d3                	mov    %edx,%ebx
 100763f:	cd 80                	int    $0x80
 1007641:	89 45 e8             	mov    %eax,-0x18(%ebp)
 1007644:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1007647:	89 45 f8             	mov    %eax,-0x8(%ebp)
 100764a:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 100764e:	79 11                	jns    1007661 <send+0x3b>
 1007650:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007653:	f7 d8                	neg    %eax
 1007655:	a3 5a 00 00 01       	mov    %eax,0x100005a
 100765a:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 100765f:	eb 03                	jmp    1007664 <send+0x3e>
 1007661:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007664:	83 c4 18             	add    $0x18,%esp
 1007667:	5b                   	pop    %ebx
 1007668:	5d                   	pop    %ebp
 1007669:	c3                   	ret    

0100766a <recv>:
 100766a:	55                   	push   %ebp
 100766b:	89 e5                	mov    %esp,%ebp
 100766d:	53                   	push   %ebx
 100766e:	83 ec 14             	sub    $0x14,%esp
 1007671:	c7 45 e8 15 00 00 00 	movl   $0x15,-0x18(%ebp)
 1007678:	8b 5d 08             	mov    0x8(%ebp),%ebx
 100767b:	8b 4d 0c             	mov    0xc(%ebp),%ecx
 100767e:	8b 55 10             	mov    0x10(%ebp),%edx
 1007681:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1007684:	cd 80                	int    $0x80
 1007686:	89 c3                	mov    %eax,%ebx
 1007688:	89 5d f8             	mov    %ebx,-0x8(%ebp)
 100768b:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 100768f:	79 11                	jns    10076a2 <recv+0x38>
 1007691:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007694:	f7 d8                	neg    %eax
 1007696:	a3 5a 00 00 01       	mov    %eax,0x100005a
 100769b:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 10076a0:	eb 03                	jmp    10076a5 <recv+0x3b>
 10076a2:	8b 45 f8             	mov    -0x8(%ebp),%eax
 10076a5:	83 c4 14             	add    $0x14,%esp
 10076a8:	5b                   	pop    %ebx
 10076a9:	5d                   	pop    %ebp
 10076aa:	c3                   	ret    

010076ab <getpid>:
 10076ab:	55                   	push   %ebp
 10076ac:	89 e5                	mov    %esp,%ebp
 10076ae:	53                   	push   %ebx
 10076af:	83 ec 14             	sub    $0x14,%esp
 10076b2:	c7 45 e8 16 00 00 00 	movl   $0x16,-0x18(%ebp)
 10076b9:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10076bc:	cd 80                	int    $0x80
 10076be:	89 c3                	mov    %eax,%ebx
 10076c0:	89 5d f8             	mov    %ebx,-0x8(%ebp)
 10076c3:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 10076c7:	79 11                	jns    10076da <getpid+0x2f>
 10076c9:	8b 45 f8             	mov    -0x8(%ebp),%eax
 10076cc:	f7 d8                	neg    %eax
 10076ce:	a3 5a 00 00 01       	mov    %eax,0x100005a
 10076d3:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 10076d8:	eb 03                	jmp    10076dd <getpid+0x32>
 10076da:	8b 45 f8             	mov    -0x8(%ebp),%eax
 10076dd:	83 c4 14             	add    $0x14,%esp
 10076e0:	5b                   	pop    %ebx
 10076e1:	5d                   	pop    %ebp
 10076e2:	c3                   	ret    

010076e3 <getppid>:
 10076e3:	55                   	push   %ebp
 10076e4:	89 e5                	mov    %esp,%ebp
 10076e6:	53                   	push   %ebx
 10076e7:	83 ec 14             	sub    $0x14,%esp
 10076ea:	c7 45 e8 17 00 00 00 	movl   $0x17,-0x18(%ebp)
 10076f1:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10076f4:	cd 80                	int    $0x80
 10076f6:	89 c3                	mov    %eax,%ebx
 10076f8:	89 5d f8             	mov    %ebx,-0x8(%ebp)
 10076fb:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 10076ff:	79 11                	jns    1007712 <getppid+0x2f>
 1007701:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007704:	f7 d8                	neg    %eax
 1007706:	a3 5a 00 00 01       	mov    %eax,0x100005a
 100770b:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 1007710:	eb 03                	jmp    1007715 <getppid+0x32>
 1007712:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007715:	83 c4 14             	add    $0x14,%esp
 1007718:	5b                   	pop    %ebx
 1007719:	5d                   	pop    %ebp
 100771a:	c3                   	ret    

0100771b <shm_at>:
 100771b:	55                   	push   %ebp
 100771c:	89 e5                	mov    %esp,%ebp
 100771e:	53                   	push   %ebx
 100771f:	83 ec 14             	sub    $0x14,%esp
 1007722:	c7 45 e8 19 00 00 00 	movl   $0x19,-0x18(%ebp)
 1007729:	8b 5d 08             	mov    0x8(%ebp),%ebx
 100772c:	8b 4d 0c             	mov    0xc(%ebp),%ecx
 100772f:	8b 55 10             	mov    0x10(%ebp),%edx
 1007732:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1007735:	cd 80                	int    $0x80
 1007737:	89 c3                	mov    %eax,%ebx
 1007739:	89 5d f8             	mov    %ebx,-0x8(%ebp)
 100773c:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 1007740:	79 11                	jns    1007753 <shm_at+0x38>
 1007742:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007745:	f7 d8                	neg    %eax
 1007747:	a3 5a 00 00 01       	mov    %eax,0x100005a
 100774c:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 1007751:	eb 03                	jmp    1007756 <shm_at+0x3b>
 1007753:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007756:	83 c4 14             	add    $0x14,%esp
 1007759:	5b                   	pop    %ebx
 100775a:	5d                   	pop    %ebp
 100775b:	c3                   	ret    

0100775c <shm_dt>:
 100775c:	55                   	push   %ebp
 100775d:	89 e5                	mov    %esp,%ebp
 100775f:	53                   	push   %ebx
 1007760:	83 ec 18             	sub    $0x18,%esp
 1007763:	c7 45 e4 1a 00 00 00 	movl   $0x1a,-0x1c(%ebp)
 100776a:	8b 55 08             	mov    0x8(%ebp),%edx
 100776d:	8b 4d 0c             	mov    0xc(%ebp),%ecx
 1007770:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1007773:	89 d3                	mov    %edx,%ebx
 1007775:	cd 80                	int    $0x80
 1007777:	89 45 e8             	mov    %eax,-0x18(%ebp)
 100777a:	8b 45 e8             	mov    -0x18(%ebp),%eax
 100777d:	89 45 f8             	mov    %eax,-0x8(%ebp)
 1007780:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 1007784:	79 11                	jns    1007797 <shm_dt+0x3b>
 1007786:	8b 45 f8             	mov    -0x8(%ebp),%eax
 1007789:	f7 d8                	neg    %eax
 100778b:	a3 5a 00 00 01       	mov    %eax,0x100005a
 1007790:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 1007795:	eb 03                	jmp    100779a <shm_dt+0x3e>
 1007797:	8b 45 f8             	mov    -0x8(%ebp),%eax
 100779a:	83 c4 18             	add    $0x18,%esp
 100779d:	5b                   	pop    %ebx
 100779e:	5d                   	pop    %ebp
 100779f:	c3                   	ret    

010077a0 <shm_get>:
 10077a0:	55                   	push   %ebp
 10077a1:	89 e5                	mov    %esp,%ebp
 10077a3:	53                   	push   %ebx
 10077a4:	83 ec 18             	sub    $0x18,%esp
 10077a7:	c7 45 e4 18 00 00 00 	movl   $0x18,-0x1c(%ebp)
 10077ae:	8b 55 08             	mov    0x8(%ebp),%edx
 10077b1:	8b 4d 0c             	mov    0xc(%ebp),%ecx
 10077b4:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 10077b7:	89 d3                	mov    %edx,%ebx
 10077b9:	cd 80                	int    $0x80
 10077bb:	89 45 e8             	mov    %eax,-0x18(%ebp)
 10077be:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10077c1:	89 45 f8             	mov    %eax,-0x8(%ebp)
 10077c4:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 10077c8:	79 11                	jns    10077db <shm_get+0x3b>
 10077ca:	8b 45 f8             	mov    -0x8(%ebp),%eax
 10077cd:	f7 d8                	neg    %eax
 10077cf:	a3 5a 00 00 01       	mov    %eax,0x100005a
 10077d4:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 10077d9:	eb 03                	jmp    10077de <shm_get+0x3e>
 10077db:	8b 45 f8             	mov    -0x8(%ebp),%eax
 10077de:	83 c4 18             	add    $0x18,%esp
 10077e1:	5b                   	pop    %ebx
 10077e2:	5d                   	pop    %ebp
 10077e3:	c3                   	ret    

010077e4 <shm_free>:
 10077e4:	55                   	push   %ebp
 10077e5:	89 e5                	mov    %esp,%ebp
 10077e7:	53                   	push   %ebx
 10077e8:	83 ec 18             	sub    $0x18,%esp
 10077eb:	c7 45 e4 1b 00 00 00 	movl   $0x1b,-0x1c(%ebp)
 10077f2:	8b 55 08             	mov    0x8(%ebp),%edx
 10077f5:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 10077f8:	89 d3                	mov    %edx,%ebx
 10077fa:	cd 80                	int    $0x80
 10077fc:	89 45 e8             	mov    %eax,-0x18(%ebp)
 10077ff:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1007802:	89 45 f8             	mov    %eax,-0x8(%ebp)
 1007805:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 1007809:	79 11                	jns    100781c <shm_free+0x38>
 100780b:	8b 45 f8             	mov    -0x8(%ebp),%eax
 100780e:	f7 d8                	neg    %eax
 1007810:	a3 5a 00 00 01       	mov    %eax,0x100005a
 1007815:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 100781a:	eb 03                	jmp    100781f <shm_free+0x3b>
 100781c:	8b 45 f8             	mov    -0x8(%ebp),%eax
 100781f:	83 c4 18             	add    $0x18,%esp
 1007822:	5b                   	pop    %ebx
 1007823:	5d                   	pop    %ebp
 1007824:	c3                   	ret    
 1007825:	00 00                	add    %al,(%eax)
	...

01007828 <libc_init>:
 1007828:	55                   	push   %ebp
 1007829:	89 e5                	mov    %esp,%ebp
 100782b:	83 ec 08             	sub    $0x8,%esp
 100782e:	e8 81 0f 00 00       	call   10087b4 <malloc_init>
 1007833:	e8 30 08 00 00       	call   1008068 <inbuf_init>
 1007838:	c9                   	leave  
 1007839:	c3                   	ret    
	...

0100783c <printf>:
 100783c:	55                   	push   %ebp
 100783d:	89 e5                	mov    %esp,%ebp
 100783f:	81 ec 18 02 00 00    	sub    $0x218,%esp
 1007845:	8d 45 0c             	lea    0xc(%ebp),%eax
 1007848:	89 45 f4             	mov    %eax,-0xc(%ebp)
 100784b:	8b 45 08             	mov    0x8(%ebp),%eax
 100784e:	8b 55 f4             	mov    -0xc(%ebp),%edx
 1007851:	89 54 24 08          	mov    %edx,0x8(%esp)
 1007855:	89 44 24 04          	mov    %eax,0x4(%esp)
 1007859:	8d 85 fc fd ff ff    	lea    -0x204(%ebp),%eax
 100785f:	89 04 24             	mov    %eax,(%esp)
 1007862:	e8 9d 03 00 00       	call   1007c04 <vsprintf>
 1007867:	89 45 f0             	mov    %eax,-0x10(%ebp)
 100786a:	8d 85 fc fd ff ff    	lea    -0x204(%ebp),%eax
 1007870:	89 04 24             	mov    %eax,(%esp)
 1007873:	e8 fa fb ff ff       	call   1007472 <uprint>
 1007878:	8b 45 f0             	mov    -0x10(%ebp),%eax
 100787b:	c9                   	leave  
 100787c:	c3                   	ret    

0100787d <simple_strtoul>:
 100787d:	55                   	push   %ebp
 100787e:	89 e5                	mov    %esp,%ebp
 1007880:	83 ec 28             	sub    $0x28,%esp
 1007883:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 100788a:	83 7d 10 00          	cmpl   $0x0,0x10(%ebp)
 100788e:	75 5e                	jne    10078ee <simple_strtoul+0x71>
 1007890:	c7 45 10 0a 00 00 00 	movl   $0xa,0x10(%ebp)
 1007897:	8b 45 08             	mov    0x8(%ebp),%eax
 100789a:	0f b6 00             	movzbl (%eax),%eax
 100789d:	3c 30                	cmp    $0x30,%al
 100789f:	75 4d                	jne    10078ee <simple_strtoul+0x71>
 10078a1:	c7 45 10 08 00 00 00 	movl   $0x8,0x10(%ebp)
 10078a8:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 10078ac:	8b 45 08             	mov    0x8(%ebp),%eax
 10078af:	0f b6 00             	movzbl (%eax),%eax
 10078b2:	3c 78                	cmp    $0x78,%al
 10078b4:	75 38                	jne    10078ee <simple_strtoul+0x71>
 10078b6:	8b 45 08             	mov    0x8(%ebp),%eax
 10078b9:	83 c0 01             	add    $0x1,%eax
 10078bc:	0f b6 00             	movzbl (%eax),%eax
 10078bf:	0f be c0             	movsbl %al,%eax
 10078c2:	89 04 24             	mov    %eax,(%esp)
 10078c5:	e8 63 11 00 00       	call   1008a2d <isxdigit>
 10078ca:	85 c0                	test   %eax,%eax
 10078cc:	74 20                	je     10078ee <simple_strtoul+0x71>
 10078ce:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 10078d2:	c7 45 10 10 00 00 00 	movl   $0x10,0x10(%ebp)
 10078d9:	eb 13                	jmp    10078ee <simple_strtoul+0x71>
 10078db:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10078de:	0f af 45 10          	imul   0x10(%ebp),%eax
 10078e2:	03 45 f0             	add    -0x10(%ebp),%eax
 10078e5:	89 45 f4             	mov    %eax,-0xc(%ebp)
 10078e8:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 10078ec:	eb 01                	jmp    10078ef <simple_strtoul+0x72>
 10078ee:	90                   	nop
 10078ef:	8b 45 08             	mov    0x8(%ebp),%eax
 10078f2:	0f b6 00             	movzbl (%eax),%eax
 10078f5:	0f be c0             	movsbl %al,%eax
 10078f8:	89 04 24             	mov    %eax,(%esp)
 10078fb:	e8 2d 11 00 00       	call   1008a2d <isxdigit>
 1007900:	85 c0                	test   %eax,%eax
 1007902:	74 69                	je     100796d <simple_strtoul+0xf0>
 1007904:	8b 45 08             	mov    0x8(%ebp),%eax
 1007907:	0f b6 00             	movzbl (%eax),%eax
 100790a:	0f be c0             	movsbl %al,%eax
 100790d:	89 04 24             	mov    %eax,(%esp)
 1007910:	e8 fb 10 00 00       	call   1008a10 <isdigit>
 1007915:	85 c0                	test   %eax,%eax
 1007917:	74 0e                	je     1007927 <simple_strtoul+0xaa>
 1007919:	8b 45 08             	mov    0x8(%ebp),%eax
 100791c:	0f b6 00             	movzbl (%eax),%eax
 100791f:	0f be c0             	movsbl %al,%eax
 1007922:	83 e8 30             	sub    $0x30,%eax
 1007925:	eb 37                	jmp    100795e <simple_strtoul+0xe1>
 1007927:	8b 45 08             	mov    0x8(%ebp),%eax
 100792a:	0f b6 00             	movzbl (%eax),%eax
 100792d:	0f be c0             	movsbl %al,%eax
 1007930:	89 04 24             	mov    %eax,(%esp)
 1007933:	e8 2a 11 00 00       	call   1008a62 <islower>
 1007938:	85 c0                	test   %eax,%eax
 100793a:	74 16                	je     1007952 <simple_strtoul+0xd5>
 100793c:	8b 45 08             	mov    0x8(%ebp),%eax
 100793f:	0f b6 00             	movzbl (%eax),%eax
 1007942:	0f be c0             	movsbl %al,%eax
 1007945:	89 04 24             	mov    %eax,(%esp)
 1007948:	e8 9b 11 00 00       	call   1008ae8 <toupper>
 100794d:	83 e8 37             	sub    $0x37,%eax
 1007950:	eb 0c                	jmp    100795e <simple_strtoul+0xe1>
 1007952:	8b 45 08             	mov    0x8(%ebp),%eax
 1007955:	0f b6 00             	movzbl (%eax),%eax
 1007958:	0f be c0             	movsbl %al,%eax
 100795b:	83 e8 37             	sub    $0x37,%eax
 100795e:	89 45 f0             	mov    %eax,-0x10(%ebp)
 1007961:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1007964:	3b 45 10             	cmp    0x10(%ebp),%eax
 1007967:	0f 82 6e ff ff ff    	jb     10078db <simple_strtoul+0x5e>
 100796d:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
 1007971:	74 08                	je     100797b <simple_strtoul+0xfe>
 1007973:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007976:	8b 55 08             	mov    0x8(%ebp),%edx
 1007979:	89 10                	mov    %edx,(%eax)
 100797b:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100797e:	c9                   	leave  
 100797f:	c3                   	ret    

01007980 <skip_atoi>:
 1007980:	55                   	push   %ebp
 1007981:	89 e5                	mov    %esp,%ebp
 1007983:	83 ec 28             	sub    $0x28,%esp
 1007986:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 100798d:	eb 29                	jmp    10079b8 <skip_atoi+0x38>
 100798f:	8b 55 f4             	mov    -0xc(%ebp),%edx
 1007992:	89 d0                	mov    %edx,%eax
 1007994:	c1 e0 02             	shl    $0x2,%eax
 1007997:	01 d0                	add    %edx,%eax
 1007999:	01 c0                	add    %eax,%eax
 100799b:	89 c1                	mov    %eax,%ecx
 100799d:	8b 45 08             	mov    0x8(%ebp),%eax
 10079a0:	8b 00                	mov    (%eax),%eax
 10079a2:	0f b6 10             	movzbl (%eax),%edx
 10079a5:	0f be d2             	movsbl %dl,%edx
 10079a8:	01 ca                	add    %ecx,%edx
 10079aa:	83 ea 30             	sub    $0x30,%edx
 10079ad:	89 55 f4             	mov    %edx,-0xc(%ebp)
 10079b0:	8d 50 01             	lea    0x1(%eax),%edx
 10079b3:	8b 45 08             	mov    0x8(%ebp),%eax
 10079b6:	89 10                	mov    %edx,(%eax)
 10079b8:	8b 45 08             	mov    0x8(%ebp),%eax
 10079bb:	8b 00                	mov    (%eax),%eax
 10079bd:	0f b6 00             	movzbl (%eax),%eax
 10079c0:	0f be c0             	movsbl %al,%eax
 10079c3:	89 04 24             	mov    %eax,(%esp)
 10079c6:	e8 45 10 00 00       	call   1008a10 <isdigit>
 10079cb:	85 c0                	test   %eax,%eax
 10079cd:	75 c0                	jne    100798f <skip_atoi+0xf>
 10079cf:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10079d2:	c9                   	leave  
 10079d3:	c3                   	ret    

010079d4 <number>:
 10079d4:	55                   	push   %ebp
 10079d5:	89 e5                	mov    %esp,%ebp
 10079d7:	53                   	push   %ebx
 10079d8:	83 ec 40             	sub    $0x40,%esp
 10079db:	c7 45 f4 70 94 00 01 	movl   $0x1009470,-0xc(%ebp)
 10079e2:	8b 45 1c             	mov    0x1c(%ebp),%eax
 10079e5:	83 e0 40             	and    $0x40,%eax
 10079e8:	85 c0                	test   %eax,%eax
 10079ea:	74 07                	je     10079f3 <number+0x1f>
 10079ec:	c7 45 f4 98 94 00 01 	movl   $0x1009498,-0xc(%ebp)
 10079f3:	8b 45 1c             	mov    0x1c(%ebp),%eax
 10079f6:	83 e0 10             	and    $0x10,%eax
 10079f9:	85 c0                	test   %eax,%eax
 10079fb:	74 04                	je     1007a01 <number+0x2d>
 10079fd:	83 65 1c fe          	andl   $0xfffffffe,0x1c(%ebp)
 1007a01:	83 7d 10 01          	cmpl   $0x1,0x10(%ebp)
 1007a05:	7e 06                	jle    1007a0d <number+0x39>
 1007a07:	83 7d 10 24          	cmpl   $0x24,0x10(%ebp)
 1007a0b:	7e 0a                	jle    1007a17 <number+0x43>
 1007a0d:	b8 00 00 00 00       	mov    $0x0,%eax
 1007a12:	e9 e7 01 00 00       	jmp    1007bfe <number+0x22a>
 1007a17:	8b 45 1c             	mov    0x1c(%ebp),%eax
 1007a1a:	83 e0 01             	and    $0x1,%eax
 1007a1d:	84 c0                	test   %al,%al
 1007a1f:	74 07                	je     1007a28 <number+0x54>
 1007a21:	b8 30 00 00 00       	mov    $0x30,%eax
 1007a26:	eb 05                	jmp    1007a2d <number+0x59>
 1007a28:	b8 20 00 00 00       	mov    $0x20,%eax
 1007a2d:	88 45 ef             	mov    %al,-0x11(%ebp)
 1007a30:	8b 45 1c             	mov    0x1c(%ebp),%eax
 1007a33:	83 e0 02             	and    $0x2,%eax
 1007a36:	85 c0                	test   %eax,%eax
 1007a38:	74 0f                	je     1007a49 <number+0x75>
 1007a3a:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
 1007a3e:	79 09                	jns    1007a49 <number+0x75>
 1007a40:	c6 45 fb 2d          	movb   $0x2d,-0x5(%ebp)
 1007a44:	f7 5d 0c             	negl   0xc(%ebp)
 1007a47:	eb 2a                	jmp    1007a73 <number+0x9f>
 1007a49:	8b 45 1c             	mov    0x1c(%ebp),%eax
 1007a4c:	83 e0 04             	and    $0x4,%eax
 1007a4f:	85 c0                	test   %eax,%eax
 1007a51:	75 18                	jne    1007a6b <number+0x97>
 1007a53:	8b 45 1c             	mov    0x1c(%ebp),%eax
 1007a56:	83 e0 08             	and    $0x8,%eax
 1007a59:	85 c0                	test   %eax,%eax
 1007a5b:	74 07                	je     1007a64 <number+0x90>
 1007a5d:	b8 20 00 00 00       	mov    $0x20,%eax
 1007a62:	eb 05                	jmp    1007a69 <number+0x95>
 1007a64:	b8 00 00 00 00       	mov    $0x0,%eax
 1007a69:	eb 05                	jmp    1007a70 <number+0x9c>
 1007a6b:	b8 2b 00 00 00       	mov    $0x2b,%eax
 1007a70:	88 45 fb             	mov    %al,-0x5(%ebp)
 1007a73:	80 7d fb 00          	cmpb   $0x0,-0x5(%ebp)
 1007a77:	74 04                	je     1007a7d <number+0xa9>
 1007a79:	83 6d 14 01          	subl   $0x1,0x14(%ebp)
 1007a7d:	8b 45 1c             	mov    0x1c(%ebp),%eax
 1007a80:	83 e0 20             	and    $0x20,%eax
 1007a83:	85 c0                	test   %eax,%eax
 1007a85:	74 16                	je     1007a9d <number+0xc9>
 1007a87:	83 7d 10 10          	cmpl   $0x10,0x10(%ebp)
 1007a8b:	75 06                	jne    1007a93 <number+0xbf>
 1007a8d:	83 6d 14 02          	subl   $0x2,0x14(%ebp)
 1007a91:	eb 0a                	jmp    1007a9d <number+0xc9>
 1007a93:	83 7d 10 08          	cmpl   $0x8,0x10(%ebp)
 1007a97:	75 04                	jne    1007a9d <number+0xc9>
 1007a99:	83 6d 14 01          	subl   $0x1,0x14(%ebp)
 1007a9d:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 1007aa4:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
 1007aa8:	75 3d                	jne    1007ae7 <number+0x113>
 1007aaa:	8d 45 c4             	lea    -0x3c(%ebp),%eax
 1007aad:	03 45 f0             	add    -0x10(%ebp),%eax
 1007ab0:	c6 00 30             	movb   $0x30,(%eax)
 1007ab3:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 1007ab7:	eb 34                	jmp    1007aed <number+0x119>
 1007ab9:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007abc:	ba 00 00 00 00       	mov    $0x0,%edx
 1007ac1:	8b 4d 10             	mov    0x10(%ebp),%ecx
 1007ac4:	89 d3                	mov    %edx,%ebx
 1007ac6:	89 da                	mov    %ebx,%edx
 1007ac8:	f7 f1                	div    %ecx
 1007aca:	89 d3                	mov    %edx,%ebx
 1007acc:	89 45 0c             	mov    %eax,0xc(%ebp)
 1007acf:	89 5d e8             	mov    %ebx,-0x18(%ebp)
 1007ad2:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1007ad5:	03 45 f4             	add    -0xc(%ebp),%eax
 1007ad8:	0f b6 10             	movzbl (%eax),%edx
 1007adb:	8d 45 c4             	lea    -0x3c(%ebp),%eax
 1007ade:	03 45 f0             	add    -0x10(%ebp),%eax
 1007ae1:	88 10                	mov    %dl,(%eax)
 1007ae3:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 1007ae7:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
 1007aeb:	75 cc                	jne    1007ab9 <number+0xe5>
 1007aed:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1007af0:	3b 45 18             	cmp    0x18(%ebp),%eax
 1007af3:	7e 06                	jle    1007afb <number+0x127>
 1007af5:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1007af8:	89 45 18             	mov    %eax,0x18(%ebp)
 1007afb:	8b 45 18             	mov    0x18(%ebp),%eax
 1007afe:	29 45 14             	sub    %eax,0x14(%ebp)
 1007b01:	8b 45 1c             	mov    0x1c(%ebp),%eax
 1007b04:	83 e0 11             	and    $0x11,%eax
 1007b07:	85 c0                	test   %eax,%eax
 1007b09:	75 1b                	jne    1007b26 <number+0x152>
 1007b0b:	eb 0a                	jmp    1007b17 <number+0x143>
 1007b0d:	8b 45 08             	mov    0x8(%ebp),%eax
 1007b10:	c6 00 20             	movb   $0x20,(%eax)
 1007b13:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 1007b17:	83 7d 14 00          	cmpl   $0x0,0x14(%ebp)
 1007b1b:	0f 9f c0             	setg   %al
 1007b1e:	83 6d 14 01          	subl   $0x1,0x14(%ebp)
 1007b22:	84 c0                	test   %al,%al
 1007b24:	75 e7                	jne    1007b0d <number+0x139>
 1007b26:	80 7d fb 00          	cmpb   $0x0,-0x5(%ebp)
 1007b2a:	74 0d                	je     1007b39 <number+0x165>
 1007b2c:	8b 45 08             	mov    0x8(%ebp),%eax
 1007b2f:	0f b6 55 fb          	movzbl -0x5(%ebp),%edx
 1007b33:	88 10                	mov    %dl,(%eax)
 1007b35:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 1007b39:	8b 45 1c             	mov    0x1c(%ebp),%eax
 1007b3c:	83 e0 20             	and    $0x20,%eax
 1007b3f:	85 c0                	test   %eax,%eax
 1007b41:	74 32                	je     1007b75 <number+0x1a1>
 1007b43:	83 7d 10 08          	cmpl   $0x8,0x10(%ebp)
 1007b47:	75 0c                	jne    1007b55 <number+0x181>
 1007b49:	8b 45 08             	mov    0x8(%ebp),%eax
 1007b4c:	c6 00 30             	movb   $0x30,(%eax)
 1007b4f:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 1007b53:	eb 20                	jmp    1007b75 <number+0x1a1>
 1007b55:	83 7d 10 10          	cmpl   $0x10,0x10(%ebp)
 1007b59:	75 1a                	jne    1007b75 <number+0x1a1>
 1007b5b:	8b 45 08             	mov    0x8(%ebp),%eax
 1007b5e:	c6 00 30             	movb   $0x30,(%eax)
 1007b61:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 1007b65:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1007b68:	0f b6 50 21          	movzbl 0x21(%eax),%edx
 1007b6c:	8b 45 08             	mov    0x8(%ebp),%eax
 1007b6f:	88 10                	mov    %dl,(%eax)
 1007b71:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 1007b75:	8b 45 1c             	mov    0x1c(%ebp),%eax
 1007b78:	83 e0 10             	and    $0x10,%eax
 1007b7b:	85 c0                	test   %eax,%eax
 1007b7d:	75 2c                	jne    1007bab <number+0x1d7>
 1007b7f:	eb 0d                	jmp    1007b8e <number+0x1ba>
 1007b81:	8b 45 08             	mov    0x8(%ebp),%eax
 1007b84:	0f b6 55 ef          	movzbl -0x11(%ebp),%edx
 1007b88:	88 10                	mov    %dl,(%eax)
 1007b8a:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 1007b8e:	83 7d 14 00          	cmpl   $0x0,0x14(%ebp)
 1007b92:	0f 9f c0             	setg   %al
 1007b95:	83 6d 14 01          	subl   $0x1,0x14(%ebp)
 1007b99:	84 c0                	test   %al,%al
 1007b9b:	75 e4                	jne    1007b81 <number+0x1ad>
 1007b9d:	eb 0c                	jmp    1007bab <number+0x1d7>
 1007b9f:	8b 45 08             	mov    0x8(%ebp),%eax
 1007ba2:	c6 00 30             	movb   $0x30,(%eax)
 1007ba5:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 1007ba9:	eb 01                	jmp    1007bac <number+0x1d8>
 1007bab:	90                   	nop
 1007bac:	8b 45 18             	mov    0x18(%ebp),%eax
 1007baf:	3b 45 f0             	cmp    -0x10(%ebp),%eax
 1007bb2:	0f 9f c0             	setg   %al
 1007bb5:	83 6d 18 01          	subl   $0x1,0x18(%ebp)
 1007bb9:	84 c0                	test   %al,%al
 1007bbb:	75 e2                	jne    1007b9f <number+0x1cb>
 1007bbd:	eb 12                	jmp    1007bd1 <number+0x1fd>
 1007bbf:	8d 45 c4             	lea    -0x3c(%ebp),%eax
 1007bc2:	03 45 f0             	add    -0x10(%ebp),%eax
 1007bc5:	0f b6 10             	movzbl (%eax),%edx
 1007bc8:	8b 45 08             	mov    0x8(%ebp),%eax
 1007bcb:	88 10                	mov    %dl,(%eax)
 1007bcd:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 1007bd1:	83 7d f0 00          	cmpl   $0x0,-0x10(%ebp)
 1007bd5:	0f 9f c0             	setg   %al
 1007bd8:	83 6d f0 01          	subl   $0x1,-0x10(%ebp)
 1007bdc:	84 c0                	test   %al,%al
 1007bde:	75 df                	jne    1007bbf <number+0x1eb>
 1007be0:	eb 0a                	jmp    1007bec <number+0x218>
 1007be2:	8b 45 08             	mov    0x8(%ebp),%eax
 1007be5:	c6 00 20             	movb   $0x20,(%eax)
 1007be8:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 1007bec:	83 7d 14 00          	cmpl   $0x0,0x14(%ebp)
 1007bf0:	0f 9f c0             	setg   %al
 1007bf3:	83 6d 14 01          	subl   $0x1,0x14(%ebp)
 1007bf7:	84 c0                	test   %al,%al
 1007bf9:	75 e7                	jne    1007be2 <number+0x20e>
 1007bfb:	8b 45 08             	mov    0x8(%ebp),%eax
 1007bfe:	83 c4 40             	add    $0x40,%esp
 1007c01:	5b                   	pop    %ebx
 1007c02:	5d                   	pop    %ebp
 1007c03:	c3                   	ret    

01007c04 <vsprintf>:
 1007c04:	55                   	push   %ebp
 1007c05:	89 e5                	mov    %esp,%ebp
 1007c07:	83 ec 58             	sub    $0x58,%esp
 1007c0a:	8b 45 08             	mov    0x8(%ebp),%eax
 1007c0d:	89 45 ec             	mov    %eax,-0x14(%ebp)
 1007c10:	e9 fe 03 00 00       	jmp    1008013 <vsprintf+0x40f>
 1007c15:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007c18:	0f b6 00             	movzbl (%eax),%eax
 1007c1b:	3c 25                	cmp    $0x25,%al
 1007c1d:	74 14                	je     1007c33 <vsprintf+0x2f>
 1007c1f:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007c22:	0f b6 10             	movzbl (%eax),%edx
 1007c25:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1007c28:	88 10                	mov    %dl,(%eax)
 1007c2a:	83 45 ec 01          	addl   $0x1,-0x14(%ebp)
 1007c2e:	e9 d7 03 00 00       	jmp    100800a <vsprintf+0x406>
 1007c33:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%ebp)
 1007c3a:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007c3d:	83 c0 01             	add    $0x1,%eax
 1007c40:	89 45 0c             	mov    %eax,0xc(%ebp)
 1007c43:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007c46:	0f b6 00             	movzbl (%eax),%eax
 1007c49:	0f be c0             	movsbl %al,%eax
 1007c4c:	83 e8 20             	sub    $0x20,%eax
 1007c4f:	83 f8 10             	cmp    $0x10,%eax
 1007c52:	77 27                	ja     1007c7b <vsprintf+0x77>
 1007c54:	8b 04 85 c4 94 00 01 	mov    0x10094c4(,%eax,4),%eax
 1007c5b:	ff e0                	jmp    *%eax
 1007c5d:	83 4d e4 10          	orl    $0x10,-0x1c(%ebp)
 1007c61:	eb d7                	jmp    1007c3a <vsprintf+0x36>
 1007c63:	83 4d e4 04          	orl    $0x4,-0x1c(%ebp)
 1007c67:	eb d1                	jmp    1007c3a <vsprintf+0x36>
 1007c69:	83 4d e4 08          	orl    $0x8,-0x1c(%ebp)
 1007c6d:	eb cb                	jmp    1007c3a <vsprintf+0x36>
 1007c6f:	83 4d e4 20          	orl    $0x20,-0x1c(%ebp)
 1007c73:	eb c5                	jmp    1007c3a <vsprintf+0x36>
 1007c75:	83 4d e4 01          	orl    $0x1,-0x1c(%ebp)
 1007c79:	eb bf                	jmp    1007c3a <vsprintf+0x36>
 1007c7b:	c7 45 e0 ff ff ff ff 	movl   $0xffffffff,-0x20(%ebp)
 1007c82:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007c85:	0f b6 00             	movzbl (%eax),%eax
 1007c88:	0f be c0             	movsbl %al,%eax
 1007c8b:	89 04 24             	mov    %eax,(%esp)
 1007c8e:	e8 7d 0d 00 00       	call   1008a10 <isdigit>
 1007c93:	85 c0                	test   %eax,%eax
 1007c95:	74 10                	je     1007ca7 <vsprintf+0xa3>
 1007c97:	8d 45 0c             	lea    0xc(%ebp),%eax
 1007c9a:	89 04 24             	mov    %eax,(%esp)
 1007c9d:	e8 de fc ff ff       	call   1007980 <skip_atoi>
 1007ca2:	89 45 e0             	mov    %eax,-0x20(%ebp)
 1007ca5:	eb 2d                	jmp    1007cd4 <vsprintf+0xd0>
 1007ca7:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007caa:	0f b6 00             	movzbl (%eax),%eax
 1007cad:	3c 2a                	cmp    $0x2a,%al
 1007caf:	75 23                	jne    1007cd4 <vsprintf+0xd0>
 1007cb1:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007cb4:	83 c0 01             	add    $0x1,%eax
 1007cb7:	89 45 0c             	mov    %eax,0xc(%ebp)
 1007cba:	83 45 10 04          	addl   $0x4,0x10(%ebp)
 1007cbe:	8b 45 10             	mov    0x10(%ebp),%eax
 1007cc1:	8b 40 fc             	mov    -0x4(%eax),%eax
 1007cc4:	89 45 e0             	mov    %eax,-0x20(%ebp)
 1007cc7:	83 7d e0 00          	cmpl   $0x0,-0x20(%ebp)
 1007ccb:	79 07                	jns    1007cd4 <vsprintf+0xd0>
 1007ccd:	f7 5d e0             	negl   -0x20(%ebp)
 1007cd0:	83 4d e4 10          	orl    $0x10,-0x1c(%ebp)
 1007cd4:	c7 45 dc ff ff ff ff 	movl   $0xffffffff,-0x24(%ebp)
 1007cdb:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007cde:	0f b6 00             	movzbl (%eax),%eax
 1007ce1:	3c 2e                	cmp    $0x2e,%al
 1007ce3:	75 5b                	jne    1007d40 <vsprintf+0x13c>
 1007ce5:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007ce8:	83 c0 01             	add    $0x1,%eax
 1007ceb:	89 45 0c             	mov    %eax,0xc(%ebp)
 1007cee:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007cf1:	0f b6 00             	movzbl (%eax),%eax
 1007cf4:	0f be c0             	movsbl %al,%eax
 1007cf7:	89 04 24             	mov    %eax,(%esp)
 1007cfa:	e8 11 0d 00 00       	call   1008a10 <isdigit>
 1007cff:	85 c0                	test   %eax,%eax
 1007d01:	74 10                	je     1007d13 <vsprintf+0x10f>
 1007d03:	8d 45 0c             	lea    0xc(%ebp),%eax
 1007d06:	89 04 24             	mov    %eax,(%esp)
 1007d09:	e8 72 fc ff ff       	call   1007980 <skip_atoi>
 1007d0e:	89 45 dc             	mov    %eax,-0x24(%ebp)
 1007d11:	eb 20                	jmp    1007d33 <vsprintf+0x12f>
 1007d13:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007d16:	0f b6 00             	movzbl (%eax),%eax
 1007d19:	3c 2a                	cmp    $0x2a,%al
 1007d1b:	75 16                	jne    1007d33 <vsprintf+0x12f>
 1007d1d:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007d20:	83 c0 01             	add    $0x1,%eax
 1007d23:	89 45 0c             	mov    %eax,0xc(%ebp)
 1007d26:	83 45 10 04          	addl   $0x4,0x10(%ebp)
 1007d2a:	8b 45 10             	mov    0x10(%ebp),%eax
 1007d2d:	8b 40 fc             	mov    -0x4(%eax),%eax
 1007d30:	89 45 dc             	mov    %eax,-0x24(%ebp)
 1007d33:	83 7d dc 00          	cmpl   $0x0,-0x24(%ebp)
 1007d37:	79 07                	jns    1007d40 <vsprintf+0x13c>
 1007d39:	c7 45 dc 00 00 00 00 	movl   $0x0,-0x24(%ebp)
 1007d40:	c7 45 d8 ff ff ff ff 	movl   $0xffffffff,-0x28(%ebp)
 1007d47:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007d4a:	0f b6 00             	movzbl (%eax),%eax
 1007d4d:	3c 68                	cmp    $0x68,%al
 1007d4f:	74 14                	je     1007d65 <vsprintf+0x161>
 1007d51:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007d54:	0f b6 00             	movzbl (%eax),%eax
 1007d57:	3c 6c                	cmp    $0x6c,%al
 1007d59:	74 0a                	je     1007d65 <vsprintf+0x161>
 1007d5b:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007d5e:	0f b6 00             	movzbl (%eax),%eax
 1007d61:	3c 4c                	cmp    $0x4c,%al
 1007d63:	75 15                	jne    1007d7a <vsprintf+0x176>
 1007d65:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007d68:	0f b6 00             	movzbl (%eax),%eax
 1007d6b:	0f be c0             	movsbl %al,%eax
 1007d6e:	89 45 d8             	mov    %eax,-0x28(%ebp)
 1007d71:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007d74:	83 c0 01             	add    $0x1,%eax
 1007d77:	89 45 0c             	mov    %eax,0xc(%ebp)
 1007d7a:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007d7d:	0f b6 00             	movzbl (%eax),%eax
 1007d80:	0f be c0             	movsbl %al,%eax
 1007d83:	83 e8 58             	sub    $0x58,%eax
 1007d86:	83 f8 20             	cmp    $0x20,%eax
 1007d89:	0f 87 42 02 00 00    	ja     1007fd1 <vsprintf+0x3cd>
 1007d8f:	8b 04 85 08 95 00 01 	mov    0x1009508(,%eax,4),%eax
 1007d96:	ff e0                	jmp    *%eax
 1007d98:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1007d9b:	83 e0 10             	and    $0x10,%eax
 1007d9e:	85 c0                	test   %eax,%eax
 1007da0:	75 16                	jne    1007db8 <vsprintf+0x1b4>
 1007da2:	eb 0a                	jmp    1007dae <vsprintf+0x1aa>
 1007da4:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1007da7:	c6 00 20             	movb   $0x20,(%eax)
 1007daa:	83 45 ec 01          	addl   $0x1,-0x14(%ebp)
 1007dae:	83 6d e0 01          	subl   $0x1,-0x20(%ebp)
 1007db2:	83 7d e0 00          	cmpl   $0x0,-0x20(%ebp)
 1007db6:	7f ec                	jg     1007da4 <vsprintf+0x1a0>
 1007db8:	83 45 10 04          	addl   $0x4,0x10(%ebp)
 1007dbc:	8b 45 10             	mov    0x10(%ebp),%eax
 1007dbf:	83 e8 04             	sub    $0x4,%eax
 1007dc2:	8b 00                	mov    (%eax),%eax
 1007dc4:	89 c2                	mov    %eax,%edx
 1007dc6:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1007dc9:	88 10                	mov    %dl,(%eax)
 1007dcb:	83 45 ec 01          	addl   $0x1,-0x14(%ebp)
 1007dcf:	eb 0a                	jmp    1007ddb <vsprintf+0x1d7>
 1007dd1:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1007dd4:	c6 00 20             	movb   $0x20,(%eax)
 1007dd7:	83 45 ec 01          	addl   $0x1,-0x14(%ebp)
 1007ddb:	83 6d e0 01          	subl   $0x1,-0x20(%ebp)
 1007ddf:	83 7d e0 00          	cmpl   $0x0,-0x20(%ebp)
 1007de3:	7f ec                	jg     1007dd1 <vsprintf+0x1cd>
 1007de5:	e9 20 02 00 00       	jmp    100800a <vsprintf+0x406>
 1007dea:	83 45 10 04          	addl   $0x4,0x10(%ebp)
 1007dee:	8b 45 10             	mov    0x10(%ebp),%eax
 1007df1:	8b 40 fc             	mov    -0x4(%eax),%eax
 1007df4:	89 45 e8             	mov    %eax,-0x18(%ebp)
 1007df7:	83 7d e8 00          	cmpl   $0x0,-0x18(%ebp)
 1007dfb:	75 07                	jne    1007e04 <vsprintf+0x200>
 1007dfd:	c7 45 e8 bd 94 00 01 	movl   $0x10094bd,-0x18(%ebp)
 1007e04:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1007e07:	89 04 24             	mov    %eax,(%esp)
 1007e0a:	e8 ce f1 ff ff       	call   1006fdd <strlen>
 1007e0f:	89 45 f4             	mov    %eax,-0xc(%ebp)
 1007e12:	83 7d dc 00          	cmpl   $0x0,-0x24(%ebp)
 1007e16:	79 08                	jns    1007e20 <vsprintf+0x21c>
 1007e18:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1007e1b:	89 45 dc             	mov    %eax,-0x24(%ebp)
 1007e1e:	eb 0e                	jmp    1007e2e <vsprintf+0x22a>
 1007e20:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1007e23:	3b 45 dc             	cmp    -0x24(%ebp),%eax
 1007e26:	7e 06                	jle    1007e2e <vsprintf+0x22a>
 1007e28:	8b 45 dc             	mov    -0x24(%ebp),%eax
 1007e2b:	89 45 f4             	mov    %eax,-0xc(%ebp)
 1007e2e:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 1007e31:	83 e0 10             	and    $0x10,%eax
 1007e34:	85 c0                	test   %eax,%eax
 1007e36:	75 1d                	jne    1007e55 <vsprintf+0x251>
 1007e38:	eb 0a                	jmp    1007e44 <vsprintf+0x240>
 1007e3a:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1007e3d:	c6 00 20             	movb   $0x20,(%eax)
 1007e40:	83 45 ec 01          	addl   $0x1,-0x14(%ebp)
 1007e44:	8b 45 e0             	mov    -0x20(%ebp),%eax
 1007e47:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 1007e4a:	0f 9f c0             	setg   %al
 1007e4d:	83 6d e0 01          	subl   $0x1,-0x20(%ebp)
 1007e51:	84 c0                	test   %al,%al
 1007e53:	75 e5                	jne    1007e3a <vsprintf+0x236>
 1007e55:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 1007e5c:	eb 17                	jmp    1007e75 <vsprintf+0x271>
 1007e5e:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1007e61:	0f b6 10             	movzbl (%eax),%edx
 1007e64:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1007e67:	88 10                	mov    %dl,(%eax)
 1007e69:	83 45 ec 01          	addl   $0x1,-0x14(%ebp)
 1007e6d:	83 45 e8 01          	addl   $0x1,-0x18(%ebp)
 1007e71:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 1007e75:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1007e78:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 1007e7b:	7c e1                	jl     1007e5e <vsprintf+0x25a>
 1007e7d:	eb 0a                	jmp    1007e89 <vsprintf+0x285>
 1007e7f:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1007e82:	c6 00 20             	movb   $0x20,(%eax)
 1007e85:	83 45 ec 01          	addl   $0x1,-0x14(%ebp)
 1007e89:	8b 45 e0             	mov    -0x20(%ebp),%eax
 1007e8c:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 1007e8f:	0f 9f c0             	setg   %al
 1007e92:	83 6d e0 01          	subl   $0x1,-0x20(%ebp)
 1007e96:	84 c0                	test   %al,%al
 1007e98:	75 e5                	jne    1007e7f <vsprintf+0x27b>
 1007e9a:	e9 6b 01 00 00       	jmp    100800a <vsprintf+0x406>
 1007e9f:	83 45 10 04          	addl   $0x4,0x10(%ebp)
 1007ea3:	8b 45 10             	mov    0x10(%ebp),%eax
 1007ea6:	83 e8 04             	sub    $0x4,%eax
 1007ea9:	8b 00                	mov    (%eax),%eax
 1007eab:	8b 55 e4             	mov    -0x1c(%ebp),%edx
 1007eae:	89 54 24 14          	mov    %edx,0x14(%esp)
 1007eb2:	8b 55 dc             	mov    -0x24(%ebp),%edx
 1007eb5:	89 54 24 10          	mov    %edx,0x10(%esp)
 1007eb9:	8b 55 e0             	mov    -0x20(%ebp),%edx
 1007ebc:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1007ec0:	c7 44 24 08 08 00 00 	movl   $0x8,0x8(%esp)
 1007ec7:	00 
 1007ec8:	89 44 24 04          	mov    %eax,0x4(%esp)
 1007ecc:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1007ecf:	89 04 24             	mov    %eax,(%esp)
 1007ed2:	e8 fd fa ff ff       	call   10079d4 <number>
 1007ed7:	89 45 ec             	mov    %eax,-0x14(%ebp)
 1007eda:	e9 2b 01 00 00       	jmp    100800a <vsprintf+0x406>
 1007edf:	83 7d e0 ff          	cmpl   $0xffffffff,-0x20(%ebp)
 1007ee3:	75 0b                	jne    1007ef0 <vsprintf+0x2ec>
 1007ee5:	c7 45 e0 08 00 00 00 	movl   $0x8,-0x20(%ebp)
 1007eec:	83 4d e4 01          	orl    $0x1,-0x1c(%ebp)
 1007ef0:	83 45 10 04          	addl   $0x4,0x10(%ebp)
 1007ef4:	8b 45 10             	mov    0x10(%ebp),%eax
 1007ef7:	83 e8 04             	sub    $0x4,%eax
 1007efa:	8b 00                	mov    (%eax),%eax
 1007efc:	8b 55 e4             	mov    -0x1c(%ebp),%edx
 1007eff:	89 54 24 14          	mov    %edx,0x14(%esp)
 1007f03:	8b 55 dc             	mov    -0x24(%ebp),%edx
 1007f06:	89 54 24 10          	mov    %edx,0x10(%esp)
 1007f0a:	8b 55 e0             	mov    -0x20(%ebp),%edx
 1007f0d:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1007f11:	c7 44 24 08 10 00 00 	movl   $0x10,0x8(%esp)
 1007f18:	00 
 1007f19:	89 44 24 04          	mov    %eax,0x4(%esp)
 1007f1d:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1007f20:	89 04 24             	mov    %eax,(%esp)
 1007f23:	e8 ac fa ff ff       	call   10079d4 <number>
 1007f28:	89 45 ec             	mov    %eax,-0x14(%ebp)
 1007f2b:	e9 da 00 00 00       	jmp    100800a <vsprintf+0x406>
 1007f30:	83 4d e4 40          	orl    $0x40,-0x1c(%ebp)
 1007f34:	83 45 10 04          	addl   $0x4,0x10(%ebp)
 1007f38:	8b 45 10             	mov    0x10(%ebp),%eax
 1007f3b:	83 e8 04             	sub    $0x4,%eax
 1007f3e:	8b 00                	mov    (%eax),%eax
 1007f40:	8b 55 e4             	mov    -0x1c(%ebp),%edx
 1007f43:	89 54 24 14          	mov    %edx,0x14(%esp)
 1007f47:	8b 55 dc             	mov    -0x24(%ebp),%edx
 1007f4a:	89 54 24 10          	mov    %edx,0x10(%esp)
 1007f4e:	8b 55 e0             	mov    -0x20(%ebp),%edx
 1007f51:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1007f55:	c7 44 24 08 10 00 00 	movl   $0x10,0x8(%esp)
 1007f5c:	00 
 1007f5d:	89 44 24 04          	mov    %eax,0x4(%esp)
 1007f61:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1007f64:	89 04 24             	mov    %eax,(%esp)
 1007f67:	e8 68 fa ff ff       	call   10079d4 <number>
 1007f6c:	89 45 ec             	mov    %eax,-0x14(%ebp)
 1007f6f:	e9 96 00 00 00       	jmp    100800a <vsprintf+0x406>
 1007f74:	83 4d e4 02          	orl    $0x2,-0x1c(%ebp)
 1007f78:	83 45 10 04          	addl   $0x4,0x10(%ebp)
 1007f7c:	8b 45 10             	mov    0x10(%ebp),%eax
 1007f7f:	83 e8 04             	sub    $0x4,%eax
 1007f82:	8b 00                	mov    (%eax),%eax
 1007f84:	8b 55 e4             	mov    -0x1c(%ebp),%edx
 1007f87:	89 54 24 14          	mov    %edx,0x14(%esp)
 1007f8b:	8b 55 dc             	mov    -0x24(%ebp),%edx
 1007f8e:	89 54 24 10          	mov    %edx,0x10(%esp)
 1007f92:	8b 55 e0             	mov    -0x20(%ebp),%edx
 1007f95:	89 54 24 0c          	mov    %edx,0xc(%esp)
 1007f99:	c7 44 24 08 0a 00 00 	movl   $0xa,0x8(%esp)
 1007fa0:	00 
 1007fa1:	89 44 24 04          	mov    %eax,0x4(%esp)
 1007fa5:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1007fa8:	89 04 24             	mov    %eax,(%esp)
 1007fab:	e8 24 fa ff ff       	call   10079d4 <number>
 1007fb0:	89 45 ec             	mov    %eax,-0x14(%ebp)
 1007fb3:	eb 55                	jmp    100800a <vsprintf+0x406>
 1007fb5:	83 45 10 04          	addl   $0x4,0x10(%ebp)
 1007fb9:	8b 45 10             	mov    0x10(%ebp),%eax
 1007fbc:	8b 40 fc             	mov    -0x4(%eax),%eax
 1007fbf:	89 45 d4             	mov    %eax,-0x2c(%ebp)
 1007fc2:	8b 55 ec             	mov    -0x14(%ebp),%edx
 1007fc5:	8b 45 08             	mov    0x8(%ebp),%eax
 1007fc8:	29 c2                	sub    %eax,%edx
 1007fca:	8b 45 d4             	mov    -0x2c(%ebp),%eax
 1007fcd:	89 10                	mov    %edx,(%eax)
 1007fcf:	eb 39                	jmp    100800a <vsprintf+0x406>
 1007fd1:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007fd4:	0f b6 00             	movzbl (%eax),%eax
 1007fd7:	3c 25                	cmp    $0x25,%al
 1007fd9:	74 0a                	je     1007fe5 <vsprintf+0x3e1>
 1007fdb:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1007fde:	c6 00 25             	movb   $0x25,(%eax)
 1007fe1:	83 45 ec 01          	addl   $0x1,-0x14(%ebp)
 1007fe5:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007fe8:	0f b6 00             	movzbl (%eax),%eax
 1007feb:	84 c0                	test   %al,%al
 1007fed:	74 11                	je     1008000 <vsprintf+0x3fc>
 1007fef:	8b 45 0c             	mov    0xc(%ebp),%eax
 1007ff2:	0f b6 10             	movzbl (%eax),%edx
 1007ff5:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1007ff8:	88 10                	mov    %dl,(%eax)
 1007ffa:	83 45 ec 01          	addl   $0x1,-0x14(%ebp)
 1007ffe:	eb 09                	jmp    1008009 <vsprintf+0x405>
 1008000:	8b 45 0c             	mov    0xc(%ebp),%eax
 1008003:	83 e8 01             	sub    $0x1,%eax
 1008006:	89 45 0c             	mov    %eax,0xc(%ebp)
 1008009:	90                   	nop
 100800a:	8b 45 0c             	mov    0xc(%ebp),%eax
 100800d:	83 c0 01             	add    $0x1,%eax
 1008010:	89 45 0c             	mov    %eax,0xc(%ebp)
 1008013:	8b 45 0c             	mov    0xc(%ebp),%eax
 1008016:	0f b6 00             	movzbl (%eax),%eax
 1008019:	84 c0                	test   %al,%al
 100801b:	0f 85 f4 fb ff ff    	jne    1007c15 <vsprintf+0x11>
 1008021:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1008024:	c6 00 00             	movb   $0x0,(%eax)
 1008027:	8b 55 ec             	mov    -0x14(%ebp),%edx
 100802a:	8b 45 08             	mov    0x8(%ebp),%eax
 100802d:	89 d1                	mov    %edx,%ecx
 100802f:	29 c1                	sub    %eax,%ecx
 1008031:	89 c8                	mov    %ecx,%eax
 1008033:	c9                   	leave  
 1008034:	c3                   	ret    

01008035 <sprintf>:
 1008035:	55                   	push   %ebp
 1008036:	89 e5                	mov    %esp,%ebp
 1008038:	83 ec 28             	sub    $0x28,%esp
 100803b:	8d 45 0c             	lea    0xc(%ebp),%eax
 100803e:	83 c0 04             	add    $0x4,%eax
 1008041:	89 45 f4             	mov    %eax,-0xc(%ebp)
 1008044:	8b 45 0c             	mov    0xc(%ebp),%eax
 1008047:	8b 55 f4             	mov    -0xc(%ebp),%edx
 100804a:	89 54 24 08          	mov    %edx,0x8(%esp)
 100804e:	89 44 24 04          	mov    %eax,0x4(%esp)
 1008052:	8b 45 08             	mov    0x8(%ebp),%eax
 1008055:	89 04 24             	mov    %eax,(%esp)
 1008058:	e8 a7 fb ff ff       	call   1007c04 <vsprintf>
 100805d:	89 45 f0             	mov    %eax,-0x10(%ebp)
 1008060:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1008063:	c9                   	leave  
 1008064:	c3                   	ret    
 1008065:	00 00                	add    %al,(%eax)
	...

01008068 <inbuf_init>:
 1008068:	55                   	push   %ebp
 1008069:	89 e5                	mov    %esp,%ebp
 100806b:	c7 05 c0 86 05 01 c8 	movl   $0x10586c8,0x10586c0
 1008072:	86 05 01 
 1008075:	a1 c0 86 05 01       	mov    0x10586c0,%eax
 100807a:	a3 c4 86 05 01       	mov    %eax,0x10586c4
 100807f:	c7 05 c8 8a 05 01 00 	movl   $0x0,0x1058ac8
 1008086:	00 00 00 
 1008089:	5d                   	pop    %ebp
 100808a:	c3                   	ret    

0100808b <inbuf_empty>:
 100808b:	55                   	push   %ebp
 100808c:	89 e5                	mov    %esp,%ebp
 100808e:	a1 c8 8a 05 01       	mov    0x1058ac8,%eax
 1008093:	85 c0                	test   %eax,%eax
 1008095:	0f 9e c0             	setle  %al
 1008098:	0f b6 c0             	movzbl %al,%eax
 100809b:	5d                   	pop    %ebp
 100809c:	c3                   	ret    

0100809d <inbuf_full>:
 100809d:	55                   	push   %ebp
 100809e:	89 e5                	mov    %esp,%ebp
 10080a0:	a1 c8 8a 05 01       	mov    0x1058ac8,%eax
 10080a5:	3d ff 03 00 00       	cmp    $0x3ff,%eax
 10080aa:	0f 9f c0             	setg   %al
 10080ad:	0f b6 c0             	movzbl %al,%eax
 10080b0:	5d                   	pop    %ebp
 10080b1:	c3                   	ret    

010080b2 <inbuf_put>:
 10080b2:	55                   	push   %ebp
 10080b3:	89 e5                	mov    %esp,%ebp
 10080b5:	81 ec 28 01 00 00    	sub    $0x128,%esp
 10080bb:	8d 85 f4 fe ff ff    	lea    -0x10c(%ebp),%eax
 10080c1:	89 45 f4             	mov    %eax,-0xc(%ebp)
 10080c4:	8d 85 f4 fe ff ff    	lea    -0x10c(%ebp),%eax
 10080ca:	89 04 24             	mov    %eax,(%esp)
 10080cd:	e8 05 f3 ff ff       	call   10073d7 <getline>
 10080d2:	eb 3c                	jmp    1008110 <inbuf_put+0x5e>
 10080d4:	a1 c4 86 05 01       	mov    0x10586c4,%eax
 10080d9:	8b 55 f4             	mov    -0xc(%ebp),%edx
 10080dc:	0f b6 12             	movzbl (%edx),%edx
 10080df:	88 10                	mov    %dl,(%eax)
 10080e1:	83 c0 01             	add    $0x1,%eax
 10080e4:	a3 c4 86 05 01       	mov    %eax,0x10586c4
 10080e9:	a1 c8 8a 05 01       	mov    0x1058ac8,%eax
 10080ee:	83 c0 01             	add    $0x1,%eax
 10080f1:	a3 c8 8a 05 01       	mov    %eax,0x1058ac8
 10080f6:	a1 c4 86 05 01       	mov    0x10586c4,%eax
 10080fb:	3d c7 8a 05 01       	cmp    $0x1058ac7,%eax
 1008100:	76 0a                	jbe    100810c <inbuf_put+0x5a>
 1008102:	c7 05 c4 86 05 01 c8 	movl   $0x10586c8,0x10586c4
 1008109:	86 05 01 
 100810c:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 1008110:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1008113:	0f b6 00             	movzbl (%eax),%eax
 1008116:	84 c0                	test   %al,%al
 1008118:	75 ba                	jne    10080d4 <inbuf_put+0x22>
 100811a:	c9                   	leave  
 100811b:	c3                   	ret    

0100811c <inbuf_get>:
 100811c:	55                   	push   %ebp
 100811d:	89 e5                	mov    %esp,%ebp
 100811f:	83 ec 18             	sub    $0x18,%esp
 1008122:	a1 c8 8a 05 01       	mov    0x1058ac8,%eax
 1008127:	85 c0                	test   %eax,%eax
 1008129:	7f 05                	jg     1008130 <inbuf_get+0x14>
 100812b:	e8 82 ff ff ff       	call   10080b2 <inbuf_put>
 1008130:	a1 c0 86 05 01       	mov    0x10586c0,%eax
 1008135:	0f b6 10             	movzbl (%eax),%edx
 1008138:	88 55 f7             	mov    %dl,-0x9(%ebp)
 100813b:	83 c0 01             	add    $0x1,%eax
 100813e:	a3 c0 86 05 01       	mov    %eax,0x10586c0
 1008143:	a1 c8 8a 05 01       	mov    0x1058ac8,%eax
 1008148:	83 e8 01             	sub    $0x1,%eax
 100814b:	a3 c8 8a 05 01       	mov    %eax,0x1058ac8
 1008150:	a1 c0 86 05 01       	mov    0x10586c0,%eax
 1008155:	3d c7 8a 05 01       	cmp    $0x1058ac7,%eax
 100815a:	76 0a                	jbe    1008166 <inbuf_get+0x4a>
 100815c:	c7 05 c0 86 05 01 c8 	movl   $0x10586c8,0x10586c0
 1008163:	86 05 01 
 1008166:	0f b6 45 f7          	movzbl -0x9(%ebp),%eax
 100816a:	c9                   	leave  
 100816b:	c3                   	ret    

0100816c <inbuf_unget>:
 100816c:	55                   	push   %ebp
 100816d:	89 e5                	mov    %esp,%ebp
 100816f:	a1 c0 86 05 01       	mov    0x10586c0,%eax
 1008174:	83 e8 01             	sub    $0x1,%eax
 1008177:	a3 c0 86 05 01       	mov    %eax,0x10586c0
 100817c:	a1 c8 8a 05 01       	mov    0x1058ac8,%eax
 1008181:	83 c0 01             	add    $0x1,%eax
 1008184:	a3 c8 8a 05 01       	mov    %eax,0x1058ac8
 1008189:	a1 c0 86 05 01       	mov    0x10586c0,%eax
 100818e:	3d c8 86 05 01       	cmp    $0x10586c8,%eax
 1008193:	73 0a                	jae    100819f <inbuf_unget+0x33>
 1008195:	c7 05 c0 86 05 01 c7 	movl   $0x1058ac7,0x10586c0
 100819c:	8a 05 01 
 100819f:	5d                   	pop    %ebp
 10081a0:	c3                   	ret    

010081a1 <mystrtol>:
 10081a1:	55                   	push   %ebp
 10081a2:	89 e5                	mov    %esp,%ebp
 10081a4:	83 ec 38             	sub    $0x38,%esp
 10081a7:	c7 45 d8 00 00 00 00 	movl   $0x0,-0x28(%ebp)
 10081ae:	8b 45 08             	mov    0x8(%ebp),%eax
 10081b1:	89 45 f4             	mov    %eax,-0xc(%ebp)
 10081b4:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10081b7:	0f b6 00             	movzbl (%eax),%eax
 10081ba:	0f b6 c0             	movzbl %al,%eax
 10081bd:	89 45 e8             	mov    %eax,-0x18(%ebp)
 10081c0:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 10081c4:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10081c7:	89 04 24             	mov    %eax,(%esp)
 10081ca:	e8 b0 08 00 00       	call   1008a7f <isspace>
 10081cf:	85 c0                	test   %eax,%eax
 10081d1:	75 e1                	jne    10081b4 <mystrtol+0x13>
 10081d3:	83 7d e8 2d          	cmpl   $0x2d,-0x18(%ebp)
 10081d7:	75 19                	jne    10081f2 <mystrtol+0x51>
 10081d9:	c7 45 e4 01 00 00 00 	movl   $0x1,-0x1c(%ebp)
 10081e0:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10081e3:	0f b6 00             	movzbl (%eax),%eax
 10081e6:	0f be c0             	movsbl %al,%eax
 10081e9:	89 45 e8             	mov    %eax,-0x18(%ebp)
 10081ec:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 10081f0:	eb 1d                	jmp    100820f <mystrtol+0x6e>
 10081f2:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%ebp)
 10081f9:	83 7d e8 2b          	cmpl   $0x2b,-0x18(%ebp)
 10081fd:	75 10                	jne    100820f <mystrtol+0x6e>
 10081ff:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1008202:	0f b6 00             	movzbl (%eax),%eax
 1008205:	0f be c0             	movsbl %al,%eax
 1008208:	89 45 e8             	mov    %eax,-0x18(%ebp)
 100820b:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 100820f:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
 1008213:	74 06                	je     100821b <mystrtol+0x7a>
 1008215:	83 7d 0c 10          	cmpl   $0x10,0xc(%ebp)
 1008219:	75 34                	jne    100824f <mystrtol+0xae>
 100821b:	83 7d e8 30          	cmpl   $0x30,-0x18(%ebp)
 100821f:	75 2e                	jne    100824f <mystrtol+0xae>
 1008221:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1008224:	0f b6 00             	movzbl (%eax),%eax
 1008227:	3c 78                	cmp    $0x78,%al
 1008229:	74 0a                	je     1008235 <mystrtol+0x94>
 100822b:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100822e:	0f b6 00             	movzbl (%eax),%eax
 1008231:	3c 58                	cmp    $0x58,%al
 1008233:	75 1a                	jne    100824f <mystrtol+0xae>
 1008235:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1008238:	83 c0 01             	add    $0x1,%eax
 100823b:	0f b6 00             	movzbl (%eax),%eax
 100823e:	0f be c0             	movsbl %al,%eax
 1008241:	89 45 e8             	mov    %eax,-0x18(%ebp)
 1008244:	83 45 f4 02          	addl   $0x2,-0xc(%ebp)
 1008248:	c7 45 0c 10 00 00 00 	movl   $0x10,0xc(%ebp)
 100824f:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
 1008253:	75 15                	jne    100826a <mystrtol+0xc9>
 1008255:	83 7d e8 30          	cmpl   $0x30,-0x18(%ebp)
 1008259:	75 07                	jne    1008262 <mystrtol+0xc1>
 100825b:	b8 08 00 00 00       	mov    $0x8,%eax
 1008260:	eb 05                	jmp    1008267 <mystrtol+0xc6>
 1008262:	b8 0a 00 00 00       	mov    $0xa,%eax
 1008267:	89 45 0c             	mov    %eax,0xc(%ebp)
 100826a:	83 7d e4 00          	cmpl   $0x0,-0x1c(%ebp)
 100826e:	74 07                	je     1008277 <mystrtol+0xd6>
 1008270:	b8 00 00 00 80       	mov    $0x80000000,%eax
 1008275:	eb 05                	jmp    100827c <mystrtol+0xdb>
 1008277:	b8 ff ff ff 7f       	mov    $0x7fffffff,%eax
 100827c:	89 45 ec             	mov    %eax,-0x14(%ebp)
 100827f:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1008282:	89 c2                	mov    %eax,%edx
 1008284:	c1 fa 1f             	sar    $0x1f,%edx
 1008287:	f7 7d 0c             	idivl  0xc(%ebp)
 100828a:	89 55 dc             	mov    %edx,-0x24(%ebp)
 100828d:	8b 45 ec             	mov    -0x14(%ebp),%eax
 1008290:	89 c2                	mov    %eax,%edx
 1008292:	c1 fa 1f             	sar    $0x1f,%edx
 1008295:	f7 7d 0c             	idivl  0xc(%ebp)
 1008298:	89 45 ec             	mov    %eax,-0x14(%ebp)
 100829b:	83 7d e4 00          	cmpl   $0x0,-0x1c(%ebp)
 100829f:	74 13                	je     10082b4 <mystrtol+0x113>
 10082a1:	83 7d dc 00          	cmpl   $0x0,-0x24(%ebp)
 10082a5:	7e 0a                	jle    10082b1 <mystrtol+0x110>
 10082a7:	8b 45 0c             	mov    0xc(%ebp),%eax
 10082aa:	29 45 dc             	sub    %eax,-0x24(%ebp)
 10082ad:	83 45 ec 01          	addl   $0x1,-0x14(%ebp)
 10082b1:	f7 5d dc             	negl   -0x24(%ebp)
 10082b4:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 10082bb:	c7 45 e0 00 00 00 00 	movl   $0x0,-0x20(%ebp)
 10082c2:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10082c5:	89 04 24             	mov    %eax,(%esp)
 10082c8:	e8 43 07 00 00       	call   1008a10 <isdigit>
 10082cd:	85 c0                	test   %eax,%eax
 10082cf:	74 06                	je     10082d7 <mystrtol+0x136>
 10082d1:	83 6d e8 30          	subl   $0x30,-0x18(%ebp)
 10082d5:	eb 31                	jmp    1008308 <mystrtol+0x167>
 10082d7:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10082da:	89 04 24             	mov    %eax,(%esp)
 10082dd:	e8 c0 07 00 00       	call   1008aa2 <isalpha>
 10082e2:	85 c0                	test   %eax,%eax
 10082e4:	0f 84 d2 00 00 00    	je     10083bc <mystrtol+0x21b>
 10082ea:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10082ed:	89 04 24             	mov    %eax,(%esp)
 10082f0:	e8 d6 07 00 00       	call   1008acb <isupper>
 10082f5:	85 c0                	test   %eax,%eax
 10082f7:	74 07                	je     1008300 <mystrtol+0x15f>
 10082f9:	b8 37 00 00 00       	mov    $0x37,%eax
 10082fe:	eb 05                	jmp    1008305 <mystrtol+0x164>
 1008300:	b8 57 00 00 00       	mov    $0x57,%eax
 1008305:	29 45 e8             	sub    %eax,-0x18(%ebp)
 1008308:	8b 45 e8             	mov    -0x18(%ebp),%eax
 100830b:	3b 45 0c             	cmp    0xc(%ebp),%eax
 100830e:	0f 8d ab 00 00 00    	jge    10083bf <mystrtol+0x21e>
 1008314:	83 7d e0 00          	cmpl   $0x0,-0x20(%ebp)
 1008318:	0f 88 88 00 00 00    	js     10083a6 <mystrtol+0x205>
 100831e:	83 7d e4 00          	cmpl   $0x0,-0x1c(%ebp)
 1008322:	74 41                	je     1008365 <mystrtol+0x1c4>
 1008324:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1008327:	3b 45 ec             	cmp    -0x14(%ebp),%eax
 100832a:	7c 10                	jl     100833c <mystrtol+0x19b>
 100832c:	8b 45 f0             	mov    -0x10(%ebp),%eax
 100832f:	3b 45 ec             	cmp    -0x14(%ebp),%eax
 1008332:	75 18                	jne    100834c <mystrtol+0x1ab>
 1008334:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1008337:	3b 45 dc             	cmp    -0x24(%ebp),%eax
 100833a:	7e 10                	jle    100834c <mystrtol+0x1ab>
 100833c:	c7 45 e0 ff ff ff ff 	movl   $0xffffffff,-0x20(%ebp)
 1008343:	c7 45 f0 00 00 00 80 	movl   $0x80000000,-0x10(%ebp)
 100834a:	eb 5b                	jmp    10083a7 <mystrtol+0x206>
 100834c:	c7 45 e0 01 00 00 00 	movl   $0x1,-0x20(%ebp)
 1008353:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1008356:	0f af 45 0c          	imul   0xc(%ebp),%eax
 100835a:	89 45 f0             	mov    %eax,-0x10(%ebp)
 100835d:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1008360:	29 45 f0             	sub    %eax,-0x10(%ebp)
 1008363:	eb 42                	jmp    10083a7 <mystrtol+0x206>
 1008365:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1008368:	3b 45 ec             	cmp    -0x14(%ebp),%eax
 100836b:	7f 10                	jg     100837d <mystrtol+0x1dc>
 100836d:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1008370:	3b 45 ec             	cmp    -0x14(%ebp),%eax
 1008373:	75 18                	jne    100838d <mystrtol+0x1ec>
 1008375:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1008378:	3b 45 dc             	cmp    -0x24(%ebp),%eax
 100837b:	7e 10                	jle    100838d <mystrtol+0x1ec>
 100837d:	c7 45 e0 ff ff ff ff 	movl   $0xffffffff,-0x20(%ebp)
 1008384:	c7 45 f0 ff ff ff 7f 	movl   $0x7fffffff,-0x10(%ebp)
 100838b:	eb 1a                	jmp    10083a7 <mystrtol+0x206>
 100838d:	c7 45 e0 01 00 00 00 	movl   $0x1,-0x20(%ebp)
 1008394:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1008397:	0f af 45 0c          	imul   0xc(%ebp),%eax
 100839b:	89 45 f0             	mov    %eax,-0x10(%ebp)
 100839e:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10083a1:	01 45 f0             	add    %eax,-0x10(%ebp)
 10083a4:	eb 01                	jmp    10083a7 <mystrtol+0x206>
 10083a6:	90                   	nop
 10083a7:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10083aa:	0f b6 00             	movzbl (%eax),%eax
 10083ad:	0f b6 c0             	movzbl %al,%eax
 10083b0:	89 45 e8             	mov    %eax,-0x18(%ebp)
 10083b3:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 10083b7:	e9 06 ff ff ff       	jmp    10082c2 <mystrtol+0x121>
 10083bc:	90                   	nop
 10083bd:	eb 01                	jmp    10083c0 <mystrtol+0x21f>
 10083bf:	90                   	nop
 10083c0:	83 7d d8 00          	cmpl   $0x0,-0x28(%ebp)
 10083c4:	74 16                	je     10083dc <mystrtol+0x23b>
 10083c6:	83 7d e0 00          	cmpl   $0x0,-0x20(%ebp)
 10083ca:	74 08                	je     10083d4 <mystrtol+0x233>
 10083cc:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10083cf:	83 e8 01             	sub    $0x1,%eax
 10083d2:	eb 03                	jmp    10083d7 <mystrtol+0x236>
 10083d4:	8b 45 08             	mov    0x8(%ebp),%eax
 10083d7:	8b 55 d8             	mov    -0x28(%ebp),%edx
 10083da:	89 02                	mov    %eax,(%edx)
 10083dc:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10083df:	c9                   	leave  
 10083e0:	c3                   	ret    

010083e1 <get_strnum>:
 10083e1:	55                   	push   %ebp
 10083e2:	89 e5                	mov    %esp,%ebp
 10083e4:	83 ec 08             	sub    $0x8,%esp
 10083e7:	e8 30 fd ff ff       	call   100811c <inbuf_get>
 10083ec:	8b 55 08             	mov    0x8(%ebp),%edx
 10083ef:	88 02                	mov    %al,(%edx)
 10083f1:	8b 45 08             	mov    0x8(%ebp),%eax
 10083f4:	0f b6 00             	movzbl (%eax),%eax
 10083f7:	3c 2f                	cmp    $0x2f,%al
 10083f9:	7e 0a                	jle    1008405 <get_strnum+0x24>
 10083fb:	8b 45 08             	mov    0x8(%ebp),%eax
 10083fe:	0f b6 00             	movzbl (%eax),%eax
 1008401:	3c 39                	cmp    $0x39,%al
 1008403:	7e 43                	jle    1008448 <get_strnum+0x67>
 1008405:	8b 45 08             	mov    0x8(%ebp),%eax
 1008408:	0f b6 00             	movzbl (%eax),%eax
 100840b:	3c 60                	cmp    $0x60,%al
 100840d:	7e 13                	jle    1008422 <get_strnum+0x41>
 100840f:	8b 45 08             	mov    0x8(%ebp),%eax
 1008412:	0f b6 00             	movzbl (%eax),%eax
 1008415:	0f be c0             	movsbl %al,%eax
 1008418:	8b 55 0c             	mov    0xc(%ebp),%edx
 100841b:	83 c2 56             	add    $0x56,%edx
 100841e:	39 d0                	cmp    %edx,%eax
 1008420:	7e 26                	jle    1008448 <get_strnum+0x67>
 1008422:	8b 45 08             	mov    0x8(%ebp),%eax
 1008425:	0f b6 00             	movzbl (%eax),%eax
 1008428:	3c 40                	cmp    $0x40,%al
 100842a:	7e 13                	jle    100843f <get_strnum+0x5e>
 100842c:	8b 45 08             	mov    0x8(%ebp),%eax
 100842f:	0f b6 00             	movzbl (%eax),%eax
 1008432:	0f be c0             	movsbl %al,%eax
 1008435:	8b 55 0c             	mov    0xc(%ebp),%edx
 1008438:	83 c2 36             	add    $0x36,%edx
 100843b:	39 d0                	cmp    %edx,%eax
 100843d:	7e 09                	jle    1008448 <get_strnum+0x67>
 100843f:	e8 47 fc ff ff       	call   100808b <inbuf_empty>
 1008444:	85 c0                	test   %eax,%eax
 1008446:	74 9f                	je     10083e7 <get_strnum+0x6>
 1008448:	8b 45 08             	mov    0x8(%ebp),%eax
 100844b:	0f b6 00             	movzbl (%eax),%eax
 100844e:	3c 2f                	cmp    $0x2f,%al
 1008450:	7e 0a                	jle    100845c <get_strnum+0x7b>
 1008452:	8b 45 08             	mov    0x8(%ebp),%eax
 1008455:	0f b6 00             	movzbl (%eax),%eax
 1008458:	3c 39                	cmp    $0x39,%al
 100845a:	7e 3a                	jle    1008496 <get_strnum+0xb5>
 100845c:	8b 45 08             	mov    0x8(%ebp),%eax
 100845f:	0f b6 00             	movzbl (%eax),%eax
 1008462:	3c 60                	cmp    $0x60,%al
 1008464:	7e 13                	jle    1008479 <get_strnum+0x98>
 1008466:	8b 45 08             	mov    0x8(%ebp),%eax
 1008469:	0f b6 00             	movzbl (%eax),%eax
 100846c:	0f be c0             	movsbl %al,%eax
 100846f:	8b 55 0c             	mov    0xc(%ebp),%edx
 1008472:	83 c2 56             	add    $0x56,%edx
 1008475:	39 d0                	cmp    %edx,%eax
 1008477:	7e 1d                	jle    1008496 <get_strnum+0xb5>
 1008479:	8b 45 08             	mov    0x8(%ebp),%eax
 100847c:	0f b6 00             	movzbl (%eax),%eax
 100847f:	3c 40                	cmp    $0x40,%al
 1008481:	7e 18                	jle    100849b <get_strnum+0xba>
 1008483:	8b 45 08             	mov    0x8(%ebp),%eax
 1008486:	0f b6 00             	movzbl (%eax),%eax
 1008489:	0f be c0             	movsbl %al,%eax
 100848c:	8b 55 0c             	mov    0xc(%ebp),%edx
 100848f:	83 c2 36             	add    $0x36,%edx
 1008492:	39 d0                	cmp    %edx,%eax
 1008494:	7f 05                	jg     100849b <get_strnum+0xba>
 1008496:	e8 d1 fc ff ff       	call   100816c <inbuf_unget>
 100849b:	e8 7c fc ff ff       	call   100811c <inbuf_get>
 10084a0:	8b 55 08             	mov    0x8(%ebp),%edx
 10084a3:	88 02                	mov    %al,(%edx)
 10084a5:	8b 45 08             	mov    0x8(%ebp),%eax
 10084a8:	0f b6 00             	movzbl (%eax),%eax
 10084ab:	3c 2f                	cmp    $0x2f,%al
 10084ad:	7e 0a                	jle    10084b9 <get_strnum+0xd8>
 10084af:	8b 45 08             	mov    0x8(%ebp),%eax
 10084b2:	0f b6 00             	movzbl (%eax),%eax
 10084b5:	3c 39                	cmp    $0x39,%al
 10084b7:	7e 47                	jle    1008500 <get_strnum+0x11f>
 10084b9:	8b 45 08             	mov    0x8(%ebp),%eax
 10084bc:	0f b6 00             	movzbl (%eax),%eax
 10084bf:	3c 60                	cmp    $0x60,%al
 10084c1:	7e 13                	jle    10084d6 <get_strnum+0xf5>
 10084c3:	8b 45 08             	mov    0x8(%ebp),%eax
 10084c6:	0f b6 00             	movzbl (%eax),%eax
 10084c9:	0f be c0             	movsbl %al,%eax
 10084cc:	8b 55 0c             	mov    0xc(%ebp),%edx
 10084cf:	83 c2 56             	add    $0x56,%edx
 10084d2:	39 d0                	cmp    %edx,%eax
 10084d4:	7e 2a                	jle    1008500 <get_strnum+0x11f>
 10084d6:	8b 45 08             	mov    0x8(%ebp),%eax
 10084d9:	0f b6 00             	movzbl (%eax),%eax
 10084dc:	3c 40                	cmp    $0x40,%al
 10084de:	7e 13                	jle    10084f3 <get_strnum+0x112>
 10084e0:	8b 45 08             	mov    0x8(%ebp),%eax
 10084e3:	0f b6 00             	movzbl (%eax),%eax
 10084e6:	0f be c0             	movsbl %al,%eax
 10084e9:	8b 55 0c             	mov    0xc(%ebp),%edx
 10084ec:	83 c2 36             	add    $0x36,%edx
 10084ef:	39 d0                	cmp    %edx,%eax
 10084f1:	7e 0d                	jle    1008500 <get_strnum+0x11f>
 10084f3:	8b 45 08             	mov    0x8(%ebp),%eax
 10084f6:	c6 00 00             	movb   $0x0,(%eax)
 10084f9:	e8 6e fc ff ff       	call   100816c <inbuf_unget>
 10084fe:	c9                   	leave  
 10084ff:	c3                   	ret    
 1008500:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 1008504:	eb 95                	jmp    100849b <get_strnum+0xba>

01008506 <get_string>:
 1008506:	55                   	push   %ebp
 1008507:	89 e5                	mov    %esp,%ebp
 1008509:	83 ec 08             	sub    $0x8,%esp
 100850c:	e8 0b fc ff ff       	call   100811c <inbuf_get>
 1008511:	8b 55 08             	mov    0x8(%ebp),%edx
 1008514:	88 02                	mov    %al,(%edx)
 1008516:	8b 45 08             	mov    0x8(%ebp),%eax
 1008519:	0f b6 00             	movzbl (%eax),%eax
 100851c:	3c 20                	cmp    $0x20,%al
 100851e:	74 0a                	je     100852a <get_string+0x24>
 1008520:	8b 45 08             	mov    0x8(%ebp),%eax
 1008523:	0f b6 00             	movzbl (%eax),%eax
 1008526:	3c 0a                	cmp    $0xa,%al
 1008528:	75 09                	jne    1008533 <get_string+0x2d>
 100852a:	e8 5c fb ff ff       	call   100808b <inbuf_empty>
 100852f:	85 c0                	test   %eax,%eax
 1008531:	74 d9                	je     100850c <get_string+0x6>
 1008533:	8b 45 08             	mov    0x8(%ebp),%eax
 1008536:	0f b6 00             	movzbl (%eax),%eax
 1008539:	3c 20                	cmp    $0x20,%al
 100853b:	74 0f                	je     100854c <get_string+0x46>
 100853d:	8b 45 08             	mov    0x8(%ebp),%eax
 1008540:	0f b6 00             	movzbl (%eax),%eax
 1008543:	3c 0a                	cmp    $0xa,%al
 1008545:	74 05                	je     100854c <get_string+0x46>
 1008547:	e8 20 fc ff ff       	call   100816c <inbuf_unget>
 100854c:	e8 cb fb ff ff       	call   100811c <inbuf_get>
 1008551:	8b 55 08             	mov    0x8(%ebp),%edx
 1008554:	88 02                	mov    %al,(%edx)
 1008556:	8b 45 08             	mov    0x8(%ebp),%eax
 1008559:	0f b6 00             	movzbl (%eax),%eax
 100855c:	3c 20                	cmp    $0x20,%al
 100855e:	74 0a                	je     100856a <get_string+0x64>
 1008560:	8b 45 08             	mov    0x8(%ebp),%eax
 1008563:	0f b6 00             	movzbl (%eax),%eax
 1008566:	3c 0a                	cmp    $0xa,%al
 1008568:	75 0d                	jne    1008577 <get_string+0x71>
 100856a:	8b 45 08             	mov    0x8(%ebp),%eax
 100856d:	c6 00 00             	movb   $0x0,(%eax)
 1008570:	e8 f7 fb ff ff       	call   100816c <inbuf_unget>
 1008575:	c9                   	leave  
 1008576:	c3                   	ret    
 1008577:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 100857b:	eb cf                	jmp    100854c <get_string+0x46>

0100857d <scanf>:
 100857d:	55                   	push   %ebp
 100857e:	89 e5                	mov    %esp,%ebp
 1008580:	57                   	push   %edi
 1008581:	53                   	push   %ebx
 1008582:	81 ec 30 01 00 00    	sub    $0x130,%esp
 1008588:	c7 85 e3 fe ff ff 00 	movl   $0x0,-0x11d(%ebp)
 100858f:	00 00 00 
 1008592:	8d 95 e7 fe ff ff    	lea    -0x119(%ebp),%edx
 1008598:	bb fc 00 00 00       	mov    $0xfc,%ebx
 100859d:	b8 00 00 00 00       	mov    $0x0,%eax
 10085a2:	89 d1                	mov    %edx,%ecx
 10085a4:	83 e1 01             	and    $0x1,%ecx
 10085a7:	85 c9                	test   %ecx,%ecx
 10085a9:	74 08                	je     10085b3 <scanf+0x36>
 10085ab:	88 02                	mov    %al,(%edx)
 10085ad:	83 c2 01             	add    $0x1,%edx
 10085b0:	83 eb 01             	sub    $0x1,%ebx
 10085b3:	89 d1                	mov    %edx,%ecx
 10085b5:	83 e1 02             	and    $0x2,%ecx
 10085b8:	85 c9                	test   %ecx,%ecx
 10085ba:	74 09                	je     10085c5 <scanf+0x48>
 10085bc:	66 89 02             	mov    %ax,(%edx)
 10085bf:	83 c2 02             	add    $0x2,%edx
 10085c2:	83 eb 02             	sub    $0x2,%ebx
 10085c5:	89 d9                	mov    %ebx,%ecx
 10085c7:	c1 e9 02             	shr    $0x2,%ecx
 10085ca:	89 d7                	mov    %edx,%edi
 10085cc:	f3 ab                	rep stos %eax,%es:(%edi)
 10085ce:	89 fa                	mov    %edi,%edx
 10085d0:	89 d9                	mov    %ebx,%ecx
 10085d2:	83 e1 02             	and    $0x2,%ecx
 10085d5:	85 c9                	test   %ecx,%ecx
 10085d7:	74 06                	je     10085df <scanf+0x62>
 10085d9:	66 89 02             	mov    %ax,(%edx)
 10085dc:	83 c2 02             	add    $0x2,%edx
 10085df:	89 d9                	mov    %ebx,%ecx
 10085e1:	83 e1 01             	and    $0x1,%ecx
 10085e4:	85 c9                	test   %ecx,%ecx
 10085e6:	74 05                	je     10085ed <scanf+0x70>
 10085e8:	88 02                	mov    %al,(%edx)
 10085ea:	83 c2 01             	add    $0x1,%edx
 10085ed:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 10085f4:	8d 45 0c             	lea    0xc(%ebp),%eax
 10085f7:	89 45 f4             	mov    %eax,-0xc(%ebp)
 10085fa:	e9 95 01 00 00       	jmp    1008794 <scanf+0x217>
 10085ff:	8b 45 08             	mov    0x8(%ebp),%eax
 1008602:	0f b6 00             	movzbl (%eax),%eax
 1008605:	3c 25                	cmp    $0x25,%al
 1008607:	75 09                	jne    1008612 <scanf+0x95>
 1008609:	83 4d f0 01          	orl    $0x1,-0x10(%ebp)
 100860d:	e9 79 01 00 00       	jmp    100878b <scanf+0x20e>
 1008612:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1008615:	83 e0 01             	and    $0x1,%eax
 1008618:	84 c0                	test   %al,%al
 100861a:	0f 84 6b 01 00 00    	je     100878b <scanf+0x20e>
 1008620:	8b 45 08             	mov    0x8(%ebp),%eax
 1008623:	0f b6 00             	movzbl (%eax),%eax
 1008626:	0f be c0             	movsbl %al,%eax
 1008629:	83 f8 64             	cmp    $0x64,%eax
 100862c:	74 2f                	je     100865d <scanf+0xe0>
 100862e:	83 f8 64             	cmp    $0x64,%eax
 1008631:	7f 17                	jg     100864a <scanf+0xcd>
 1008633:	83 f8 2a             	cmp    $0x2a,%eax
 1008636:	0f 84 46 01 00 00    	je     1008782 <scanf+0x205>
 100863c:	83 f8 63             	cmp    $0x63,%eax
 100863f:	0f 84 b5 00 00 00    	je     10086fa <scanf+0x17d>
 1008645:	e9 3e 01 00 00       	jmp    1008788 <scanf+0x20b>
 100864a:	83 f8 73             	cmp    $0x73,%eax
 100864d:	74 68                	je     10086b7 <scanf+0x13a>
 100864f:	83 f8 78             	cmp    $0x78,%eax
 1008652:	0f 84 d3 00 00 00    	je     100872b <scanf+0x1ae>
 1008658:	e9 2b 01 00 00       	jmp    1008788 <scanf+0x20b>
 100865d:	c7 44 24 04 0a 00 00 	movl   $0xa,0x4(%esp)
 1008664:	00 
 1008665:	8d 85 e3 fe ff ff    	lea    -0x11d(%ebp),%eax
 100866b:	89 04 24             	mov    %eax,(%esp)
 100866e:	e8 6e fd ff ff       	call   10083e1 <get_strnum>
 1008673:	c7 44 24 04 0a 00 00 	movl   $0xa,0x4(%esp)
 100867a:	00 
 100867b:	8d 85 e3 fe ff ff    	lea    -0x11d(%ebp),%eax
 1008681:	89 04 24             	mov    %eax,(%esp)
 1008684:	e8 18 fb ff ff       	call   10081a1 <mystrtol>
 1008689:	89 45 ec             	mov    %eax,-0x14(%ebp)
 100868c:	8b 45 f0             	mov    -0x10(%ebp),%eax
 100868f:	83 e0 02             	and    $0x2,%eax
 1008692:	85 c0                	test   %eax,%eax
 1008694:	75 15                	jne    10086ab <scanf+0x12e>
 1008696:	83 45 f4 04          	addl   $0x4,-0xc(%ebp)
 100869a:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100869d:	8b 40 fc             	mov    -0x4(%eax),%eax
 10086a0:	89 45 e8             	mov    %eax,-0x18(%ebp)
 10086a3:	8b 45 e8             	mov    -0x18(%ebp),%eax
 10086a6:	8b 55 ec             	mov    -0x14(%ebp),%edx
 10086a9:	89 10                	mov    %edx,(%eax)
 10086ab:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 10086b2:	e9 d4 00 00 00       	jmp    100878b <scanf+0x20e>
 10086b7:	8d 85 e3 fe ff ff    	lea    -0x11d(%ebp),%eax
 10086bd:	89 04 24             	mov    %eax,(%esp)
 10086c0:	e8 41 fe ff ff       	call   1008506 <get_string>
 10086c5:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10086c8:	83 e0 02             	and    $0x2,%eax
 10086cb:	85 c0                	test   %eax,%eax
 10086cd:	0f 85 b7 00 00 00    	jne    100878a <scanf+0x20d>
 10086d3:	83 45 f4 04          	addl   $0x4,-0xc(%ebp)
 10086d7:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10086da:	8b 40 fc             	mov    -0x4(%eax),%eax
 10086dd:	89 45 e4             	mov    %eax,-0x1c(%ebp)
 10086e0:	8d 85 e3 fe ff ff    	lea    -0x11d(%ebp),%eax
 10086e6:	89 44 24 04          	mov    %eax,0x4(%esp)
 10086ea:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 10086ed:	89 04 24             	mov    %eax,(%esp)
 10086f0:	e8 9b e6 ff ff       	call   1006d90 <strcpy>
 10086f5:	e9 90 00 00 00       	jmp    100878a <scanf+0x20d>
 10086fa:	e8 1d fa ff ff       	call   100811c <inbuf_get>
 10086ff:	88 45 e3             	mov    %al,-0x1d(%ebp)
 1008702:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1008705:	83 e0 02             	and    $0x2,%eax
 1008708:	85 c0                	test   %eax,%eax
 100870a:	75 16                	jne    1008722 <scanf+0x1a5>
 100870c:	83 45 f4 04          	addl   $0x4,-0xc(%ebp)
 1008710:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1008713:	8b 40 fc             	mov    -0x4(%eax),%eax
 1008716:	89 45 e4             	mov    %eax,-0x1c(%ebp)
 1008719:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 100871c:	0f b6 55 e3          	movzbl -0x1d(%ebp),%edx
 1008720:	88 10                	mov    %dl,(%eax)
 1008722:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 1008729:	eb 60                	jmp    100878b <scanf+0x20e>
 100872b:	c7 44 24 04 10 00 00 	movl   $0x10,0x4(%esp)
 1008732:	00 
 1008733:	8d 85 e3 fe ff ff    	lea    -0x11d(%ebp),%eax
 1008739:	89 04 24             	mov    %eax,(%esp)
 100873c:	e8 a0 fc ff ff       	call   10083e1 <get_strnum>
 1008741:	c7 44 24 04 10 00 00 	movl   $0x10,0x4(%esp)
 1008748:	00 
 1008749:	8d 85 e3 fe ff ff    	lea    -0x11d(%ebp),%eax
 100874f:	89 04 24             	mov    %eax,(%esp)
 1008752:	e8 4a fa ff ff       	call   10081a1 <mystrtol>
 1008757:	89 45 ec             	mov    %eax,-0x14(%ebp)
 100875a:	8b 45 f0             	mov    -0x10(%ebp),%eax
 100875d:	83 e0 02             	and    $0x2,%eax
 1008760:	85 c0                	test   %eax,%eax
 1008762:	75 15                	jne    1008779 <scanf+0x1fc>
 1008764:	83 45 f4 04          	addl   $0x4,-0xc(%ebp)
 1008768:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100876b:	8b 40 fc             	mov    -0x4(%eax),%eax
 100876e:	89 45 e8             	mov    %eax,-0x18(%ebp)
 1008771:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1008774:	8b 55 ec             	mov    -0x14(%ebp),%edx
 1008777:	89 10                	mov    %edx,(%eax)
 1008779:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 1008780:	eb 09                	jmp    100878b <scanf+0x20e>
 1008782:	83 4d f0 02          	orl    $0x2,-0x10(%ebp)
 1008786:	eb 03                	jmp    100878b <scanf+0x20e>
 1008788:	eb 01                	jmp    100878b <scanf+0x20e>
 100878a:	90                   	nop
 100878b:	8b 45 08             	mov    0x8(%ebp),%eax
 100878e:	83 c0 01             	add    $0x1,%eax
 1008791:	89 45 08             	mov    %eax,0x8(%ebp)
 1008794:	8b 45 08             	mov    0x8(%ebp),%eax
 1008797:	0f b6 00             	movzbl (%eax),%eax
 100879a:	84 c0                	test   %al,%al
 100879c:	0f 85 5d fe ff ff    	jne    10085ff <scanf+0x82>
 10087a2:	b8 01 00 00 00       	mov    $0x1,%eax
 10087a7:	81 c4 30 01 00 00    	add    $0x130,%esp
 10087ad:	5b                   	pop    %ebx
 10087ae:	5f                   	pop    %edi
 10087af:	5d                   	pop    %ebp
 10087b0:	c3                   	ret    
 10087b1:	00 00                	add    %al,(%eax)
	...

010087b4 <malloc_init>:
 10087b4:	55                   	push   %ebp
 10087b5:	89 e5                	mov    %esp,%ebp
 10087b7:	53                   	push   %ebx
 10087b8:	83 ec 24             	sub    $0x24,%esp
 10087bb:	c7 45 f0 00 00 40 06 	movl   $0x6400000,-0x10(%ebp)
 10087c2:	c7 44 24 08 50 80 02 	movl   $0x28050,0x8(%esp)
 10087c9:	00 
 10087ca:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 10087d1:	00 
 10087d2:	c7 04 24 60 06 03 01 	movl   $0x1030660,(%esp)
 10087d9:	e8 b4 e8 ff ff       	call   1007092 <memset>
 10087de:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 10087e5:	eb 34                	jmp    100881b <malloc_init+0x67>
 10087e7:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10087ea:	c1 e0 02             	shl    $0x2,%eax
 10087ed:	89 c2                	mov    %eax,%edx
 10087ef:	c1 e2 0b             	shl    $0xb,%edx
 10087f2:	01 d0                	add    %edx,%eax
 10087f4:	8d 90 60 06 03 01    	lea    0x1030660(%eax),%edx
 10087fa:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10087fd:	89 02                	mov    %eax,(%edx)
 10087ff:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1008802:	8b 14 85 a0 95 00 01 	mov    0x10095a0(,%eax,4),%edx
 1008809:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100880c:	89 d3                	mov    %edx,%ebx
 100880e:	89 c1                	mov    %eax,%ecx
 1008810:	d3 e3                	shl    %cl,%ebx
 1008812:	89 d8                	mov    %ebx,%eax
 1008814:	01 45 f0             	add    %eax,-0x10(%ebp)
 1008817:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 100881b:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100881e:	8b 04 85 a0 95 00 01 	mov    0x10095a0(,%eax,4),%eax
 1008825:	83 f8 ff             	cmp    $0xffffffff,%eax
 1008828:	75 bd                	jne    10087e7 <malloc_init+0x33>
 100882a:	83 c4 24             	add    $0x24,%esp
 100882d:	5b                   	pop    %ebx
 100882e:	5d                   	pop    %ebp
 100882f:	c3                   	ret    

01008830 <malloc>:
 1008830:	55                   	push   %ebp
 1008831:	89 e5                	mov    %esp,%ebp
 1008833:	56                   	push   %esi
 1008834:	53                   	push   %ebx
 1008835:	83 ec 10             	sub    $0x10,%esp
 1008838:	8b 45 08             	mov    0x8(%ebp),%eax
 100883b:	89 45 ec             	mov    %eax,-0x14(%ebp)
 100883e:	83 7d 08 00          	cmpl   $0x0,0x8(%ebp)
 1008842:	7f 0a                	jg     100884e <malloc+0x1e>
 1008844:	b8 00 00 00 00       	mov    $0x0,%eax
 1008849:	e9 d1 00 00 00       	jmp    100891f <malloc+0xef>
 100884e:	81 7d 08 00 20 00 00 	cmpl   $0x2000,0x8(%ebp)
 1008855:	7e 0a                	jle    1008861 <malloc+0x31>
 1008857:	b8 00 00 00 00       	mov    $0x0,%eax
 100885c:	e9 be 00 00 00       	jmp    100891f <malloc+0xef>
 1008861:	c7 45 f0 ff ff ff ff 	movl   $0xffffffff,-0x10(%ebp)
 1008868:	eb 13                	jmp    100887d <malloc+0x4d>
 100886a:	8b 45 ec             	mov    -0x14(%ebp),%eax
 100886d:	89 c2                	mov    %eax,%edx
 100886f:	c1 ea 1f             	shr    $0x1f,%edx
 1008872:	01 d0                	add    %edx,%eax
 1008874:	d1 f8                	sar    %eax
 1008876:	89 45 ec             	mov    %eax,-0x14(%ebp)
 1008879:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 100887d:	83 7d ec 00          	cmpl   $0x0,-0x14(%ebp)
 1008881:	7f e7                	jg     100886a <malloc+0x3a>
 1008883:	8b 45 f0             	mov    -0x10(%ebp),%eax
 1008886:	ba 01 00 00 00       	mov    $0x1,%edx
 100888b:	89 d3                	mov    %edx,%ebx
 100888d:	89 c1                	mov    %eax,%ecx
 100888f:	d3 e3                	shl    %cl,%ebx
 1008891:	89 d8                	mov    %ebx,%eax
 1008893:	3b 45 08             	cmp    0x8(%ebp),%eax
 1008896:	74 04                	je     100889c <malloc+0x6c>
 1008898:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 100889c:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 10088a3:	eb 66                	jmp    100890b <malloc+0xdb>
 10088a5:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10088a8:	c1 e0 02             	shl    $0x2,%eax
 10088ab:	89 c2                	mov    %eax,%edx
 10088ad:	c1 e2 0b             	shl    $0xb,%edx
 10088b0:	01 d0                	add    %edx,%eax
 10088b2:	03 45 f4             	add    -0xc(%ebp),%eax
 10088b5:	05 60 06 03 01       	add    $0x1030660,%eax
 10088ba:	0f b6 40 04          	movzbl 0x4(%eax),%eax
 10088be:	84 c0                	test   %al,%al
 10088c0:	75 45                	jne    1008907 <malloc+0xd7>
 10088c2:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10088c5:	c1 e0 02             	shl    $0x2,%eax
 10088c8:	89 c2                	mov    %eax,%edx
 10088ca:	c1 e2 0b             	shl    $0xb,%edx
 10088cd:	01 d0                	add    %edx,%eax
 10088cf:	05 60 06 03 01       	add    $0x1030660,%eax
 10088d4:	8b 10                	mov    (%eax),%edx
 10088d6:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10088d9:	8b 5d f4             	mov    -0xc(%ebp),%ebx
 10088dc:	89 de                	mov    %ebx,%esi
 10088de:	89 c1                	mov    %eax,%ecx
 10088e0:	d3 e6                	shl    %cl,%esi
 10088e2:	89 f0                	mov    %esi,%eax
 10088e4:	01 d0                	add    %edx,%eax
 10088e6:	89 45 e8             	mov    %eax,-0x18(%ebp)
 10088e9:	8b 45 f0             	mov    -0x10(%ebp),%eax
 10088ec:	c1 e0 02             	shl    $0x2,%eax
 10088ef:	89 c2                	mov    %eax,%edx
 10088f1:	c1 e2 0b             	shl    $0xb,%edx
 10088f4:	01 d0                	add    %edx,%eax
 10088f6:	03 45 f4             	add    -0xc(%ebp),%eax
 10088f9:	05 60 06 03 01       	add    $0x1030660,%eax
 10088fe:	c6 40 04 01          	movb   $0x1,0x4(%eax)
 1008902:	8b 45 e8             	mov    -0x18(%ebp),%eax
 1008905:	eb 18                	jmp    100891f <malloc+0xef>
 1008907:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 100890b:	8b 45 f0             	mov    -0x10(%ebp),%eax
 100890e:	8b 04 85 a0 95 00 01 	mov    0x10095a0(,%eax,4),%eax
 1008915:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 1008918:	7f 8b                	jg     10088a5 <malloc+0x75>
 100891a:	b8 00 00 00 00       	mov    $0x0,%eax
 100891f:	83 c4 10             	add    $0x10,%esp
 1008922:	5b                   	pop    %ebx
 1008923:	5e                   	pop    %esi
 1008924:	5d                   	pop    %ebp
 1008925:	c3                   	ret    

01008926 <free>:
 1008926:	55                   	push   %ebp
 1008927:	89 e5                	mov    %esp,%ebp
 1008929:	53                   	push   %ebx
 100892a:	83 ec 10             	sub    $0x10,%esp
 100892d:	8b 45 08             	mov    0x8(%ebp),%eax
 1008930:	89 45 f8             	mov    %eax,-0x8(%ebp)
 1008933:	81 7d f8 ff ff 3f 06 	cmpl   $0x63fffff,-0x8(%ebp)
 100893a:	0f 86 c2 00 00 00    	jbe    1008a02 <free+0xdc>
 1008940:	81 6d f8 00 00 40 06 	subl   $0x6400000,-0x8(%ebp)
 1008947:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 100894e:	eb 36                	jmp    1008986 <free+0x60>
 1008950:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1008953:	8b 14 85 a0 95 00 01 	mov    0x10095a0(,%eax,4),%edx
 100895a:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100895d:	89 d3                	mov    %edx,%ebx
 100895f:	89 c1                	mov    %eax,%ecx
 1008961:	d3 e3                	shl    %cl,%ebx
 1008963:	89 d8                	mov    %ebx,%eax
 1008965:	3b 45 f8             	cmp    -0x8(%ebp),%eax
 1008968:	77 2d                	ja     1008997 <free+0x71>
 100896a:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100896d:	8b 14 85 a0 95 00 01 	mov    0x10095a0(,%eax,4),%edx
 1008974:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1008977:	89 d3                	mov    %edx,%ebx
 1008979:	89 c1                	mov    %eax,%ecx
 100897b:	d3 e3                	shl    %cl,%ebx
 100897d:	89 d8                	mov    %ebx,%eax
 100897f:	29 45 f8             	sub    %eax,-0x8(%ebp)
 1008982:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 1008986:	8b 45 f4             	mov    -0xc(%ebp),%eax
 1008989:	8b 04 85 a0 95 00 01 	mov    0x10095a0(,%eax,4),%eax
 1008990:	83 f8 ff             	cmp    $0xffffffff,%eax
 1008993:	75 bb                	jne    1008950 <free+0x2a>
 1008995:	eb 01                	jmp    1008998 <free+0x72>
 1008997:	90                   	nop
 1008998:	8b 45 f4             	mov    -0xc(%ebp),%eax
 100899b:	8b 04 85 a0 95 00 01 	mov    0x10095a0(,%eax,4),%eax
 10089a2:	83 f8 ff             	cmp    $0xffffffff,%eax
 10089a5:	74 62                	je     1008a09 <free+0xe3>
 10089a7:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10089aa:	ba 01 00 00 00       	mov    $0x1,%edx
 10089af:	89 d3                	mov    %edx,%ebx
 10089b1:	89 c1                	mov    %eax,%ecx
 10089b3:	d3 e3                	shl    %cl,%ebx
 10089b5:	89 d8                	mov    %ebx,%eax
 10089b7:	83 e8 01             	sub    $0x1,%eax
 10089ba:	23 45 f8             	and    -0x8(%ebp),%eax
 10089bd:	85 c0                	test   %eax,%eax
 10089bf:	75 44                	jne    1008a05 <free+0xdf>
 10089c1:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10089c4:	89 c1                	mov    %eax,%ecx
 10089c6:	d3 6d f8             	shrl   %cl,-0x8(%ebp)
 10089c9:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10089cc:	c1 e0 02             	shl    $0x2,%eax
 10089cf:	89 c2                	mov    %eax,%edx
 10089d1:	c1 e2 0b             	shl    $0xb,%edx
 10089d4:	01 d0                	add    %edx,%eax
 10089d6:	03 45 f8             	add    -0x8(%ebp),%eax
 10089d9:	05 60 06 03 01       	add    $0x1030660,%eax
 10089de:	0f b6 40 04          	movzbl 0x4(%eax),%eax
 10089e2:	84 c0                	test   %al,%al
 10089e4:	74 22                	je     1008a08 <free+0xe2>
 10089e6:	8b 45 f4             	mov    -0xc(%ebp),%eax
 10089e9:	c1 e0 02             	shl    $0x2,%eax
 10089ec:	89 c2                	mov    %eax,%edx
 10089ee:	c1 e2 0b             	shl    $0xb,%edx
 10089f1:	01 d0                	add    %edx,%eax
 10089f3:	03 45 f8             	add    -0x8(%ebp),%eax
 10089f6:	05 60 06 03 01       	add    $0x1030660,%eax
 10089fb:	c6 40 04 00          	movb   $0x0,0x4(%eax)
 10089ff:	90                   	nop
 1008a00:	eb 07                	jmp    1008a09 <free+0xe3>
 1008a02:	90                   	nop
 1008a03:	eb 04                	jmp    1008a09 <free+0xe3>
 1008a05:	90                   	nop
 1008a06:	eb 01                	jmp    1008a09 <free+0xe3>
 1008a08:	90                   	nop
 1008a09:	83 c4 10             	add    $0x10,%esp
 1008a0c:	5b                   	pop    %ebx
 1008a0d:	5d                   	pop    %ebp
 1008a0e:	c3                   	ret    
	...

01008a10 <isdigit>:
 1008a10:	55                   	push   %ebp
 1008a11:	89 e5                	mov    %esp,%ebp
 1008a13:	83 7d 08 2f          	cmpl   $0x2f,0x8(%ebp)
 1008a17:	7e 0d                	jle    1008a26 <isdigit+0x16>
 1008a19:	83 7d 08 39          	cmpl   $0x39,0x8(%ebp)
 1008a1d:	7f 07                	jg     1008a26 <isdigit+0x16>
 1008a1f:	b8 01 00 00 00       	mov    $0x1,%eax
 1008a24:	eb 05                	jmp    1008a2b <isdigit+0x1b>
 1008a26:	b8 00 00 00 00       	mov    $0x0,%eax
 1008a2b:	5d                   	pop    %ebp
 1008a2c:	c3                   	ret    

01008a2d <isxdigit>:
 1008a2d:	55                   	push   %ebp
 1008a2e:	89 e5                	mov    %esp,%ebp
 1008a30:	83 7d 08 2f          	cmpl   $0x2f,0x8(%ebp)
 1008a34:	7e 06                	jle    1008a3c <isxdigit+0xf>
 1008a36:	83 7d 08 39          	cmpl   $0x39,0x8(%ebp)
 1008a3a:	7e 18                	jle    1008a54 <isxdigit+0x27>
 1008a3c:	83 7d 08 60          	cmpl   $0x60,0x8(%ebp)
 1008a40:	7e 06                	jle    1008a48 <isxdigit+0x1b>
 1008a42:	83 7d 08 66          	cmpl   $0x66,0x8(%ebp)
 1008a46:	7e 0c                	jle    1008a54 <isxdigit+0x27>
 1008a48:	83 7d 08 40          	cmpl   $0x40,0x8(%ebp)
 1008a4c:	7e 0d                	jle    1008a5b <isxdigit+0x2e>
 1008a4e:	83 7d 08 46          	cmpl   $0x46,0x8(%ebp)
 1008a52:	7f 07                	jg     1008a5b <isxdigit+0x2e>
 1008a54:	b8 01 00 00 00       	mov    $0x1,%eax
 1008a59:	eb 05                	jmp    1008a60 <isxdigit+0x33>
 1008a5b:	b8 00 00 00 00       	mov    $0x0,%eax
 1008a60:	5d                   	pop    %ebp
 1008a61:	c3                   	ret    

01008a62 <islower>:
 1008a62:	55                   	push   %ebp
 1008a63:	89 e5                	mov    %esp,%ebp
 1008a65:	83 7d 08 60          	cmpl   $0x60,0x8(%ebp)
 1008a69:	7e 0d                	jle    1008a78 <islower+0x16>
 1008a6b:	83 7d 08 7a          	cmpl   $0x7a,0x8(%ebp)
 1008a6f:	7f 07                	jg     1008a78 <islower+0x16>
 1008a71:	b8 01 00 00 00       	mov    $0x1,%eax
 1008a76:	eb 05                	jmp    1008a7d <islower+0x1b>
 1008a78:	b8 00 00 00 00       	mov    $0x0,%eax
 1008a7d:	5d                   	pop    %ebp
 1008a7e:	c3                   	ret    

01008a7f <isspace>:
 1008a7f:	55                   	push   %ebp
 1008a80:	89 e5                	mov    %esp,%ebp
 1008a82:	83 7d 08 20          	cmpl   $0x20,0x8(%ebp)
 1008a86:	74 0c                	je     1008a94 <isspace+0x15>
 1008a88:	83 7d 08 0a          	cmpl   $0xa,0x8(%ebp)
 1008a8c:	74 06                	je     1008a94 <isspace+0x15>
 1008a8e:	83 7d 08 0d          	cmpl   $0xd,0x8(%ebp)
 1008a92:	75 07                	jne    1008a9b <isspace+0x1c>
 1008a94:	b8 01 00 00 00       	mov    $0x1,%eax
 1008a99:	eb 05                	jmp    1008aa0 <isspace+0x21>
 1008a9b:	b8 00 00 00 00       	mov    $0x0,%eax
 1008aa0:	5d                   	pop    %ebp
 1008aa1:	c3                   	ret    

01008aa2 <isalpha>:
 1008aa2:	55                   	push   %ebp
 1008aa3:	89 e5                	mov    %esp,%ebp
 1008aa5:	83 7d 08 60          	cmpl   $0x60,0x8(%ebp)
 1008aa9:	7e 06                	jle    1008ab1 <isalpha+0xf>
 1008aab:	83 7d 08 7a          	cmpl   $0x7a,0x8(%ebp)
 1008aaf:	7e 0c                	jle    1008abd <isalpha+0x1b>
 1008ab1:	83 7d 08 40          	cmpl   $0x40,0x8(%ebp)
 1008ab5:	7e 0d                	jle    1008ac4 <isalpha+0x22>
 1008ab7:	83 7d 08 5a          	cmpl   $0x5a,0x8(%ebp)
 1008abb:	7f 07                	jg     1008ac4 <isalpha+0x22>
 1008abd:	b8 01 00 00 00       	mov    $0x1,%eax
 1008ac2:	eb 05                	jmp    1008ac9 <isalpha+0x27>
 1008ac4:	b8 00 00 00 00       	mov    $0x0,%eax
 1008ac9:	5d                   	pop    %ebp
 1008aca:	c3                   	ret    

01008acb <isupper>:
 1008acb:	55                   	push   %ebp
 1008acc:	89 e5                	mov    %esp,%ebp
 1008ace:	83 7d 08 40          	cmpl   $0x40,0x8(%ebp)
 1008ad2:	7e 0d                	jle    1008ae1 <isupper+0x16>
 1008ad4:	83 7d 08 5a          	cmpl   $0x5a,0x8(%ebp)
 1008ad8:	7f 07                	jg     1008ae1 <isupper+0x16>
 1008ada:	b8 01 00 00 00       	mov    $0x1,%eax
 1008adf:	eb 05                	jmp    1008ae6 <isupper+0x1b>
 1008ae1:	b8 00 00 00 00       	mov    $0x0,%eax
 1008ae6:	5d                   	pop    %ebp
 1008ae7:	c3                   	ret    

01008ae8 <toupper>:
 1008ae8:	55                   	push   %ebp
 1008ae9:	89 e5                	mov    %esp,%ebp
 1008aeb:	83 7d 08 60          	cmpl   $0x60,0x8(%ebp)
 1008aef:	7e 0e                	jle    1008aff <toupper+0x17>
 1008af1:	83 7d 08 7a          	cmpl   $0x7a,0x8(%ebp)
 1008af5:	7f 08                	jg     1008aff <toupper+0x17>
 1008af7:	8b 45 08             	mov    0x8(%ebp),%eax
 1008afa:	83 e8 20             	sub    $0x20,%eax
 1008afd:	eb 03                	jmp    1008b02 <toupper+0x1a>
 1008aff:	8b 45 08             	mov    0x8(%ebp),%eax
 1008b02:	5d                   	pop    %ebp
 1008b03:	c3                   	ret    
