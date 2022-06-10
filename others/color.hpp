#ifndef COLOR_HPP
# define COLOR_HPP
#include <string.h>
#include <iomanip>

# define C_DEBUG YELLOW
# define BLACK              "\033[30m"
# define RED                "\033[31m"
# define GREEN              "\033[32m"
# define YELLOW             "\033[33m"
# define BLUE               "\033[34m"
# define MAGENTA            "\033[35m"
# define CYAN               "\033[36m"
# define WHITE              "\033[37m"
# define GREY               "\033[90m"

# define RED_B              "\033[31;01m"
# define WHITE_B            "\033[37;01m"
# define GREY_B             "\033[90;01m"
# define GREEN_B            "\033[32;01m"

# define COLOR(id)          "\033[38;5;"#id"m"
# define COLOR_BOLD(id)     "\033[38;5;"#id";01m"
# define CORAIL             COLOR(168)
# define GREEN_TREE         COLOR(106)
# define BROWN              COLOR(137)
# define SKY_BLUE           COLOR(69)
# define LIGHT_BLUE         COLOR(39)
# define LIGHT_PINK         COLOR(170)
# define PINK               COLOR(164)
# define ORANGE             COLOR(130)
# define DARK_RED           COLOR(88)

# define C_G_CORAIL             COLOR_BOLD(168)
# define C_G_GREEN_TREE         COLOR_BOLD(106)
# define C_G_BROWN              COLOR_BOLD(137)
# define C_G_SKY_BLUE           COLOR_BOLD(69)
# define C_G_LIGHT_BLUE         COLOR_BOLD(39)
# define C_G_LIGHT_PINK         COLOR_BOLD(170)
# define C_G_PINK               COLOR_BOLD(164)
# define C_G_ORANGE             COLOR_BOLD(130)
# define C_G_DARK_RED           COLOR_BOLD(88)

// https://robotmoon.com/256-colors/

# define C_001        COLOR(1)
# define C_002        COLOR(2)
# define C_003        COLOR(3)
# define C_004        COLOR(4)
# define C_005        COLOR(5)
# define C_006        COLOR(6)
# define C_007        COLOR(7)
# define C_008        COLOR(8)
# define C_009        COLOR(9)
# define C_010        COLOR(10)
# define C_011        COLOR(11)
# define C_012        COLOR(12)
# define C_013        COLOR(13)
# define C_014        COLOR(14)
# define C_015        COLOR(15)
# define C_016        COLOR(16)
# define C_017        COLOR(17)
# define C_018        COLOR(18)
# define C_019        COLOR(19)
# define C_020        COLOR(20)
# define C_021        COLOR(21)
# define C_022        COLOR(22)
# define C_023        COLOR(23)
# define C_024        COLOR(24)
# define C_025        COLOR(25)
# define C_026        COLOR(26)
# define C_027        COLOR(27)
# define C_028        COLOR(28)
# define C_029        COLOR(29)
# define C_030        COLOR(30)
# define C_031        COLOR(31)
# define C_032        COLOR(32)
# define C_033        COLOR(33)
# define C_034        COLOR(34)
# define C_035        COLOR(35)
# define C_036        COLOR(36)
# define C_037        COLOR(37)
# define C_038        COLOR(38)
# define C_039        COLOR(39)
# define C_040        COLOR(40)
# define C_041        COLOR(41)
# define C_042        COLOR(42)
# define C_043        COLOR(43)
# define C_044        COLOR(44)
# define C_045        COLOR(45)
# define C_046        COLOR(46)
# define C_047        COLOR(47)
# define C_048        COLOR(48)
# define C_049        COLOR(49)
# define C_050        COLOR(50)
# define C_051        COLOR(51)
# define C_052        COLOR(52)
# define C_053        COLOR(53)
# define C_054        COLOR(54)
# define C_055        COLOR(55)
# define C_056        COLOR(56)
# define C_057        COLOR(57)
# define C_058        COLOR(58)
# define C_059        COLOR(59)
# define C_060        COLOR(60)
# define C_061        COLOR(61)
# define C_062        COLOR(62)
# define C_063        COLOR(63)
# define C_064        COLOR(64)
# define C_065        COLOR(65)
# define C_066        COLOR(66)
# define C_067        COLOR(67)
# define C_068        COLOR(68)
# define C_069        COLOR(69)
# define C_070        COLOR(70)
# define C_071        COLOR(71)
# define C_072        COLOR(72)
# define C_073        COLOR(73)
# define C_074        COLOR(74)
# define C_075        COLOR(75)
# define C_076        COLOR(76)
# define C_077        COLOR(77)
# define C_078        COLOR(78)
# define C_079        COLOR(79)
# define C_080        COLOR(80)
# define C_081        COLOR(81)
# define C_082        COLOR(82)
# define C_083        COLOR(83)
# define C_084        COLOR(84)
# define C_085        COLOR(85)
# define C_086        COLOR(86)
# define C_087        COLOR(87)
# define C_088        COLOR(88)
# define C_089        COLOR(89)
# define C_090        COLOR(90)
# define C_091        COLOR(91)
# define C_092        COLOR(92)
# define C_093        COLOR(93)
# define C_094        COLOR(94)
# define C_095        COLOR(95)
# define C_096        COLOR(96)
# define C_097        COLOR(97)
# define C_098        COLOR(98)
# define C_099        COLOR(99)
# define C_100        COLOR(100)
# define C_101        COLOR(101)
# define C_102        COLOR(102)
# define C_103        COLOR(103)
# define C_104        COLOR(104)
# define C_105        COLOR(105)
# define C_106        COLOR(106)
# define C_107        COLOR(107)
# define C_108        COLOR(108)
# define C_109        COLOR(109)
# define C_110        COLOR(110)
# define C_111        COLOR(111)
# define C_112        COLOR(112)
# define C_113        COLOR(113)
# define C_114        COLOR(114)
# define C_115        COLOR(115)
# define C_116        COLOR(116)
# define C_117        COLOR(117)
# define C_118        COLOR(118)
# define C_119        COLOR(119)
# define C_120        COLOR(120)
# define C_121        COLOR(121)
# define C_122        COLOR(122)
# define C_123        COLOR(123)
# define C_124        COLOR(124)
# define C_125        COLOR(125)
# define C_126        COLOR(126)
# define C_127        COLOR(127)
# define C_128        COLOR(128)
# define C_129        COLOR(129)
# define C_130        COLOR(130)
# define C_131        COLOR(131)
# define C_132        COLOR(132)
# define C_133        COLOR(133)
# define C_134        COLOR(134)
# define C_135        COLOR(135)
# define C_136        COLOR(136)
# define C_137        COLOR(137)
# define C_138        COLOR(138)
# define C_139        COLOR(139)
# define C_140        COLOR(140)
# define C_141        COLOR(141)
# define C_142        COLOR(142)
# define C_143        COLOR(143)
# define C_144        COLOR(144)
# define C_145        COLOR(145)
# define C_146        COLOR(146)
# define C_147        COLOR(147)
# define C_148        COLOR(148)
# define C_149        COLOR(149)
# define C_150        COLOR(150)
# define C_151        COLOR(151)
# define C_152        COLOR(152)
# define C_153        COLOR(153)
# define C_154        COLOR(154)
# define C_155        COLOR(155)
# define C_156        COLOR(156)
# define C_157        COLOR(157)
# define C_158        COLOR(158)
# define C_159        COLOR(159)
# define C_160        COLOR(160)
# define C_161        COLOR(161)
# define C_162        COLOR(162)
# define C_163        COLOR(163)
# define C_164        COLOR(164)
# define C_165        COLOR(165)
# define C_166        COLOR(166)
# define C_167        COLOR(167)
# define C_168        COLOR(168)
# define C_169        COLOR(169)
# define C_170        COLOR(170)
# define C_171        COLOR(171)
# define C_172        COLOR(172)
# define C_173        COLOR(173)
# define C_174        COLOR(174)
# define C_175        COLOR(175)
# define C_176        COLOR(176)
# define C_177        COLOR(177)
# define C_178        COLOR(178)
# define C_179        COLOR(179)
# define C_180        COLOR(180)
# define C_181        COLOR(181)
# define C_182        COLOR(182)
# define C_183        COLOR(183)
# define C_184        COLOR(184)
# define C_185        COLOR(185)
# define C_186        COLOR(186)
# define C_187        COLOR(187)
# define C_188        COLOR(188)
# define C_189        COLOR(189)
# define C_190        COLOR(190)
# define C_191        COLOR(191)
# define C_192        COLOR(192)
# define C_193        COLOR(193)
# define C_194        COLOR(194)
# define C_195        COLOR(195)
# define C_196        COLOR(196)
# define C_197        COLOR(197)
# define C_198        COLOR(198)
# define C_199        COLOR(199)
# define C_200        COLOR(200)
# define C_201        COLOR(201)
# define C_202        COLOR(202)
# define C_203        COLOR(203)
# define C_204        COLOR(204)
# define C_205        COLOR(205)
# define C_206        COLOR(206)
# define C_207        COLOR(207)
# define C_208        COLOR(208)
# define C_209        COLOR(209)
# define C_210        COLOR(210)
# define C_211        COLOR(211)
# define C_212        COLOR(212)
# define C_213        COLOR(213)
# define C_214        COLOR(214)
# define C_215        COLOR(215)
# define C_216        COLOR(216)
# define C_217        COLOR(217)
# define C_218        COLOR(218)
# define C_219        COLOR(219)
# define C_220        COLOR(220)
# define C_221        COLOR(221)
# define C_222        COLOR(222)
# define C_223        COLOR(223)
# define C_224        COLOR(224)
# define C_225        COLOR(225)
# define C_226        COLOR(226)
# define C_227        COLOR(227)
# define C_228        COLOR(228)
# define C_229        COLOR(229)
# define C_230        COLOR(230)
# define C_231        COLOR(231)
# define C_232        COLOR(232)
# define C_233        COLOR(233)
# define C_234        COLOR(234)
# define C_235        COLOR(235)
# define C_236        COLOR(236)
# define C_237        COLOR(237)
# define C_238        COLOR(238)
# define C_239        COLOR(239)
# define C_240        COLOR(240)
# define C_241        COLOR(241)
# define C_242        COLOR(242)
# define C_243        COLOR(243)
# define C_244        COLOR(244)
# define C_245        COLOR(245)
# define C_246        COLOR(246)
# define C_247        COLOR(247)
# define C_248        COLOR(248)
# define C_249        COLOR(249)
# define C_250        COLOR(250)
# define C_251        COLOR(251)
# define C_252        COLOR(252)
# define C_253        COLOR(253)
# define C_254        COLOR(254)
# define C_255        COLOR(255)

# define C_G_001        COLOR_BOLD(1)
# define C_G_002        COLOR_BOLD(2)
# define C_G_003        COLOR_BOLD(3)
# define C_G_004        COLOR_BOLD(4)
# define C_G_005        COLOR_BOLD(5)
# define C_G_006        COLOR_BOLD(6)
# define C_G_007        COLOR_BOLD(7)
# define C_G_008        COLOR_BOLD(8)
# define C_G_009        COLOR_BOLD(9)
# define C_G_010        COLOR_BOLD(10)
# define C_G_011        COLOR_BOLD(11)
# define C_G_012        COLOR_BOLD(12)
# define C_G_013        COLOR_BOLD(13)
# define C_G_014        COLOR_BOLD(14)
# define C_G_015        COLOR_BOLD(15)
# define C_G_016        COLOR_BOLD(16)
# define C_G_017        COLOR_BOLD(17)
# define C_G_018        COLOR_BOLD(18)
# define C_G_019        COLOR_BOLD(19)
# define C_G_020        COLOR_BOLD(20)
# define C_G_021        COLOR_BOLD(21)
# define C_G_022        COLOR_BOLD(22)
# define C_G_023        COLOR_BOLD(23)
# define C_G_024        COLOR_BOLD(24)
# define C_G_025        COLOR_BOLD(25)
# define C_G_026        COLOR_BOLD(26)
# define C_G_027        COLOR_BOLD(27)
# define C_G_028        COLOR_BOLD(28)
# define C_G_029        COLOR_BOLD(29)
# define C_G_030        COLOR_BOLD(30)
# define C_G_031        COLOR_BOLD(31)
# define C_G_032        COLOR_BOLD(32)
# define C_G_033        COLOR_BOLD(33)
# define C_G_034        COLOR_BOLD(34)
# define C_G_035        COLOR_BOLD(35)
# define C_G_036        COLOR_BOLD(36)
# define C_G_037        COLOR_BOLD(37)
# define C_G_038        COLOR_BOLD(38)
# define C_G_039        COLOR_BOLD(39)
# define C_G_040        COLOR_BOLD(40)
# define C_G_041        COLOR_BOLD(41)
# define C_G_042        COLOR_BOLD(42)
# define C_G_043        COLOR_BOLD(43)
# define C_G_044        COLOR_BOLD(44)
# define C_G_045        COLOR_BOLD(45)
# define C_G_046        COLOR_BOLD(46)
# define C_G_047        COLOR_BOLD(47)
# define C_G_048        COLOR_BOLD(48)
# define C_G_049        COLOR_BOLD(49)
# define C_G_050        COLOR_BOLD(50)
# define C_G_051        COLOR_BOLD(51)
# define C_G_052        COLOR_BOLD(52)
# define C_G_053        COLOR_BOLD(53)
# define C_G_054        COLOR_BOLD(54)
# define C_G_055        COLOR_BOLD(55)
# define C_G_056        COLOR_BOLD(56)
# define C_G_057        COLOR_BOLD(57)
# define C_G_058        COLOR_BOLD(58)
# define C_G_059        COLOR_BOLD(59)
# define C_G_060        COLOR_BOLD(60)
# define C_G_061        COLOR_BOLD(61)
# define C_G_062        COLOR_BOLD(62)
# define C_G_063        COLOR_BOLD(63)
# define C_G_064        COLOR_BOLD(64)
# define C_G_065        COLOR_BOLD(65)
# define C_G_066        COLOR_BOLD(66)
# define C_G_067        COLOR_BOLD(67)
# define C_G_068        COLOR_BOLD(68)
# define C_G_069        COLOR_BOLD(69)
# define C_G_070        COLOR_BOLD(70)
# define C_G_071        COLOR_BOLD(71)
# define C_G_072        COLOR_BOLD(72)
# define C_G_073        COLOR_BOLD(73)
# define C_G_074        COLOR_BOLD(74)
# define C_G_075        COLOR_BOLD(75)
# define C_G_076        COLOR_BOLD(76)
# define C_G_077        COLOR_BOLD(77)
# define C_G_078        COLOR_BOLD(78)
# define C_G_079        COLOR_BOLD(79)
# define C_G_080        COLOR_BOLD(80)
# define C_G_081        COLOR_BOLD(81)
# define C_G_082        COLOR_BOLD(82)
# define C_G_083        COLOR_BOLD(83)
# define C_G_084        COLOR_BOLD(84)
# define C_G_085        COLOR_BOLD(85)
# define C_G_086        COLOR_BOLD(86)
# define C_G_087        COLOR_BOLD(87)
# define C_G_088        COLOR_BOLD(88)
# define C_G_089        COLOR_BOLD(89)
# define C_G_090        COLOR_BOLD(90)
# define C_G_091        COLOR_BOLD(91)
# define C_G_092        COLOR_BOLD(92)
# define C_G_093        COLOR_BOLD(93)
# define C_G_094        COLOR_BOLD(94)
# define C_G_095        COLOR_BOLD(95)
# define C_G_096        COLOR_BOLD(96)
# define C_G_097        COLOR_BOLD(97)
# define C_G_098        COLOR_BOLD(98)
# define C_G_099        COLOR_BOLD(99)
# define C_G_100        COLOR_BOLD(100)
# define C_G_101        COLOR_BOLD(101)
# define C_G_102        COLOR_BOLD(102)
# define C_G_103        COLOR_BOLD(103)
# define C_G_104        COLOR_BOLD(104)
# define C_G_105        COLOR_BOLD(105)
# define C_G_106        COLOR_BOLD(106)
# define C_G_107        COLOR_BOLD(107)
# define C_G_108        COLOR_BOLD(108)
# define C_G_109        COLOR_BOLD(109)
# define C_G_110        COLOR_BOLD(110)
# define C_G_111        COLOR_BOLD(111)
# define C_G_112        COLOR_BOLD(112)
# define C_G_113        COLOR_BOLD(113)
# define C_G_114        COLOR_BOLD(114)
# define C_G_115        COLOR_BOLD(115)
# define C_G_116        COLOR_BOLD(116)
# define C_G_117        COLOR_BOLD(117)
# define C_G_118        COLOR_BOLD(118)
# define C_G_119        COLOR_BOLD(119)
# define C_G_120        COLOR_BOLD(120)
# define C_G_121        COLOR_BOLD(121)
# define C_G_122        COLOR_BOLD(122)
# define C_G_123        COLOR_BOLD(123)
# define C_G_124        COLOR_BOLD(124)
# define C_G_125        COLOR_BOLD(125)
# define C_G_126        COLOR_BOLD(126)
# define C_G_127        COLOR_BOLD(127)
# define C_G_128        COLOR_BOLD(128)
# define C_G_129        COLOR_BOLD(129)
# define C_G_130        COLOR_BOLD(130)
# define C_G_131        COLOR_BOLD(131)
# define C_G_132        COLOR_BOLD(132)
# define C_G_133        COLOR_BOLD(133)
# define C_G_134        COLOR_BOLD(134)
# define C_G_135        COLOR_BOLD(135)
# define C_G_136        COLOR_BOLD(136)
# define C_G_137        COLOR_BOLD(137)
# define C_G_138        COLOR_BOLD(138)
# define C_G_139        COLOR_BOLD(139)
# define C_G_140        COLOR_BOLD(140)
# define C_G_141        COLOR_BOLD(141)
# define C_G_142        COLOR_BOLD(142)
# define C_G_143        COLOR_BOLD(143)
# define C_G_144        COLOR_BOLD(144)
# define C_G_145        COLOR_BOLD(145)
# define C_G_146        COLOR_BOLD(146)
# define C_G_147        COLOR_BOLD(147)
# define C_G_148        COLOR_BOLD(148)
# define C_G_149        COLOR_BOLD(149)
# define C_G_150        COLOR_BOLD(150)
# define C_G_151        COLOR_BOLD(151)
# define C_G_152        COLOR_BOLD(152)
# define C_G_153        COLOR_BOLD(153)
# define C_G_154        COLOR_BOLD(154)
# define C_G_155        COLOR_BOLD(155)
# define C_G_156        COLOR_BOLD(156)
# define C_G_157        COLOR_BOLD(157)
# define C_G_158        COLOR_BOLD(158)
# define C_G_159        COLOR_BOLD(159)
# define C_G_160        COLOR_BOLD(160)
# define C_G_161        COLOR_BOLD(161)
# define C_G_162        COLOR_BOLD(162)
# define C_G_163        COLOR_BOLD(163)
# define C_G_164        COLOR_BOLD(164)
# define C_G_165        COLOR_BOLD(165)
# define C_G_166        COLOR_BOLD(166)
# define C_G_167        COLOR_BOLD(167)
# define C_G_168        COLOR_BOLD(168)
# define C_G_169        COLOR_BOLD(169)
# define C_G_170        COLOR_BOLD(170)
# define C_G_171        COLOR_BOLD(171)
# define C_G_172        COLOR_BOLD(172)
# define C_G_173        COLOR_BOLD(173)
# define C_G_174        COLOR_BOLD(174)
# define C_G_175        COLOR_BOLD(175)
# define C_G_176        COLOR_BOLD(176)
# define C_G_177        COLOR_BOLD(177)
# define C_G_178        COLOR_BOLD(178)
# define C_G_179        COLOR_BOLD(179)
# define C_G_180        COLOR_BOLD(180)
# define C_G_181        COLOR_BOLD(181)
# define C_G_182        COLOR_BOLD(182)
# define C_G_183        COLOR_BOLD(183)
# define C_G_184        COLOR_BOLD(184)
# define C_G_185        COLOR_BOLD(185)
# define C_G_186        COLOR_BOLD(186)
# define C_G_187        COLOR_BOLD(187)
# define C_G_188        COLOR_BOLD(188)
# define C_G_189        COLOR_BOLD(189)
# define C_G_190        COLOR_BOLD(190)
# define C_G_191        COLOR_BOLD(191)
# define C_G_192        COLOR_BOLD(192)
# define C_G_193        COLOR_BOLD(193)
# define C_G_194        COLOR_BOLD(194)
# define C_G_195        COLOR_BOLD(195)
# define C_G_196        COLOR_BOLD(196)
# define C_G_197        COLOR_BOLD(197)
# define C_G_198        COLOR_BOLD(198)
# define C_G_199        COLOR_BOLD(199)
# define C_G_200        COLOR_BOLD(200)
# define C_G_201        COLOR_BOLD(201)
# define C_G_202        COLOR_BOLD(202)
# define C_G_203        COLOR_BOLD(203)
# define C_G_204        COLOR_BOLD(204)
# define C_G_205        COLOR_BOLD(205)
# define C_G_206        COLOR_BOLD(206)
# define C_G_207        COLOR_BOLD(207)
# define C_G_208        COLOR_BOLD(208)
# define C_G_209        COLOR_BOLD(209)
# define C_G_210        COLOR_BOLD(210)
# define C_G_211        COLOR_BOLD(211)
# define C_G_212        COLOR_BOLD(212)
# define C_G_213        COLOR_BOLD(213)
# define C_G_214        COLOR_BOLD(214)
# define C_G_215        COLOR_BOLD(215)
# define C_G_216        COLOR_BOLD(216)
# define C_G_217        COLOR_BOLD(217)
# define C_G_218        COLOR_BOLD(218)
# define C_G_219        COLOR_BOLD(219)
# define C_G_220        COLOR_BOLD(220)
# define C_G_221        COLOR_BOLD(221)
# define C_G_222        COLOR_BOLD(222)
# define C_G_223        COLOR_BOLD(223)
# define C_G_224        COLOR_BOLD(224)
# define C_G_225        COLOR_BOLD(225)
# define C_G_226        COLOR_BOLD(226)
# define C_G_227        COLOR_BOLD(227)
# define C_G_228        COLOR_BOLD(228)
# define C_G_229        COLOR_BOLD(229)
# define C_G_230        COLOR_BOLD(230)
# define C_G_231        COLOR_BOLD(231)
# define C_G_232        COLOR_BOLD(232)
# define C_G_233        COLOR_BOLD(233)
# define C_G_234        COLOR_BOLD(234)
# define C_G_235        COLOR_BOLD(235)
# define C_G_236        COLOR_BOLD(236)
# define C_G_237        COLOR_BOLD(237)
# define C_G_238        COLOR_BOLD(238)
# define C_G_239        COLOR_BOLD(239)
# define C_G_240        COLOR_BOLD(240)
# define C_G_241        COLOR_BOLD(241)
# define C_G_242        COLOR_BOLD(242)
# define C_G_243        COLOR_BOLD(243)
# define C_G_244        COLOR_BOLD(244)
# define C_G_245        COLOR_BOLD(245)
# define C_G_246        COLOR_BOLD(246)
# define C_G_247        COLOR_BOLD(247)
# define C_G_248        COLOR_BOLD(248)
# define C_G_249        COLOR_BOLD(249)
# define C_G_250        COLOR_BOLD(250)
# define C_G_251        COLOR_BOLD(251)
# define C_G_252        COLOR_BOLD(252)
# define C_G_253        COLOR_BOLD(253)
# define C_G_254        COLOR_BOLD(254)
# define C_G_255        COLOR_BOLD(255)

# define C_G_BLACK      "\033[30;01m"
# define C_G_RED        "\033[31;01m"
# define C_G_GREEN      "\033[32;01m"
# define C_G_YELLOW     "\033[33;01m"
# define C_G_BLUE       "\033[34;01m"
# define C_G_MAGENTA    "\033[35;01m"
# define C_G_CYAN       "\033[36;01m"
# define C_G_WHITE      "\033[37;01m"
# define C_G_GRAY       "\033[90;01m"

# define C_B_BLACK      "\033[40m"
# define C_B_RED        "\033[41m"
# define C_B_GREEN      "\033[42m"
# define C_B_YELLOW     "\033[43m"
# define C_B_BLUE       "\033[44m"
# define C_B_MAGENTA    "\033[45m"
# define C_B_CYAN       "\033[46m"
# define C_B_WHITE      "\033[47m"
# define C_B_GRAY       "\033[100m"

# define C_RES          "\033[0m"

# define MINUS_STR "----------------------------------------------------------------------------------------------------"
# define TEST "\033[36;01m(%s:%d:0) \033[31;01m%s\033[0m %.*s>\033[35;01m%d\033[0m\n", __FILE__, __LINE__, __FUNCTION__, (int)(70 - (strlen(__FUNCTION__) + strlen(__FILE__) + 3)), MINUS_STR, __LINE__
# define _TEST_ C_G_WHITE "[" CORAIL " DEBUG" C_G_WHITE " ] line: " C_G_GREEN << std::setw(4) << __LINE__ << C_G_WHITE " at " C_G_BLUE << std::setw(15) << std::right << __FUNCTION__ << "()" << C_G_WHITE " in " C_G_MAGENTA << __FILE__ << C_RES
#endif
