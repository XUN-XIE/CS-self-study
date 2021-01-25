numerous alternatives:
1. block format
2. free list format
3. placement
4. splitting
5. coalescing

# textbook version
__conclusion in book__:
1. Next fit run faster than first fit
2. Next fit worse memory utilization than first fit 
3. Best fit has best memory utilization
4. Best fit has worst running time

when implicit free list
time sequence: Next fit < First fit < Best fit
utilization :  Best fit > First fit > Next fit
trade-off

__conditions__:
1. header and footer
2. implicit free list
3. first fit
4. 
5. immediate boundary-tag caolescing

### First fit
output:
Results for mm malloc:
trace  valid  util     ops      secs  Kops
 0       yes   99%    5694  0.008730   652
 1       yes   99%    5848  0.008134   719
 2       yes   99%    6648  0.013603   489
 3       yes  100%    5380  0.010189   528
 4       yes   66%   14400  0.000228 63158
 5       yes   92%    4800  0.008386   572
 6       yes   92%    4800  0.007443   645
 7       yes   55%   12000  0.253606    47
 8       yes   51%   24000  0.392841    61
 9       yes   27%   14401  0.124782   115
10       yes   34%   14401  0.003537  4071
Total          74%  112372  0.831479   135

Perf index = 44 (util) + 9 (thru) = 53/100

lazy coal:
Results for mm malloc:
trace  valid  util     ops      secs  Kops
 0       yes   99%    5694  0.012128   469
 1       yes   99%    5848  0.010578   553
 2       yes   99%    6648  0.019364   343
 3       yes  100%    5380  0.016942   318
 4       yes   66%   14400  0.000147 97693
 5       yes   92%    4800  0.017612   273
 6       yes   90%    4800  0.016478   291
 7       yes   55%   12000  0.305789    39
 8       yes   51%   24000  0.407617    59
 9       yes   27%   14401  0.125196   115
10       yes   38%   14401  0.003506  4108
Total          74%  112372  0.935357   120

Perf index = 45 (util) + 8 (thru) = 53/100
### Next fit
output:
Results for mm malloc:
trace  valid  util     ops      secs  Kops
 0       yes   91%    5694  0.002057  2769
 1       yes   92%    5848  0.001351  4328
 2       yes   95%    6648  0.003901  1704
 3       yes   97%    5380  0.004106  1310
 4       yes   66%   14400  0.000155 92664
 5       yes   91%    4800  0.004635  1036
 6       yes   89%    4800  0.004372  1098
 7       yes   55%   12000  0.025735   466
 8       yes   51%   24000  0.010657  2252
 9       yes   27%   14401  0.126621   114
10       yes   45%   14401  0.003471  4148
Total          73%  112372  0.187061   601

Perf index = 44 (util) + 40 (thru) = 84/100

lazy coal:
Results for mm malloc:
trace  valid  util     ops      secs  Kops
 0       yes   84%    5694  0.007102   802
 1       yes   89%    5848  0.004114  1422
 2       yes   91%    6648  0.014440   460
 3       yes   96%    5380  0.016307   330
 4       yes   66%   14400  0.000201 71500
 5       yes   91%    4800  0.013504   355
 6       yes   89%    4800  0.013267   362
 7       yes   55%   12000  0.078044   154
 8       yes   51%   24000  0.031620   759
 9       yes   27%   14401  0.132257   109
10       yes   45%   14401  0.003484  4134
Total          71%  112372  0.314339   357

Perf index = 43 (util) + 24 (thru) = 67/100

### Best fit (似乎和 first fit 一样，后期验证其他组合，如果区别大，说明这个实验写错了)
output:
Results for mm malloc:
trace  valid  util     ops      secs  Kops
 0       yes   99%    5694  0.010703   532
 1       yes   99%    5848  0.011370   514
 2       yes   99%    6648  0.016773   396
 3       yes  100%    5380  0.011632   463
 4       yes   66%   14400  0.000163 88127
 5       yes   96%    4800  0.018434   260
 6       yes   95%    4800  0.018794   255
 7       yes   55%   12000  0.249800    48
 8       yes   51%   24000  0.405409    59
 9       yes   31%   14401  0.132249   109
10       yes   30%   14401  0.003714  3878
Total          75%  112372  0.879041   128

Perf index = 45 (util) + 9 (thru) = 53/100

lazy coal:
Results for mm malloc:
trace  valid  util     ops      secs  Kops
 0       yes   99%    5694  0.014940   381
 1       yes   99%    5848  0.014523   403
 2       yes  100%    6648  0.025459   261
 3       yes  100%    5380  0.022358   241
 4       yes   66%   14400  0.000171 84359
 5       yes   95%    4800  0.030051   160
 6       yes   94%    4800  0.029184   164
 7       yes   55%   12000  0.318047    38
 8       yes   51%   24000  0.429627    56
 9       yes   24%   14401  0.129198   111
10       yes   30%   14401  0.003819  3771
Total          74%  112372  1.017375   110

Perf index = 44 (util) + 7 (thru) = 52/100




# 实验结果分析
1. Next fit 效果最佳。并且和 eager coalescing 比较配合，因为 lazy coalescing 导致有很多块需要 Next fit 去遍历，导致 时间变慢！
2. Best fit 的效果貌似和 first fit 相同。（也可能算法写错了？）
3. 穿了一些和书中 的结论，不相符的一些情况
