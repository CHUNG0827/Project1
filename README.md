# Branch prediction_Project1

# 介紹:
Branch prediction的基本版， input為T和N序列，output為預測結果和miss次數
使用語言:C++

# main program: 
branch prediction.cpp

# input file:
input.txt(內容為T和N的序列，長度不限)

![](https://i.imgur.com/SNAlpdE.jpg)


# 執行結果:
![](https://i.imgur.com/iElOhw6.jpg)

# Output file:
output.txt(內容為miss之次數)




# 系統流程:
1.建立state table 例如: 00 SN SN SN SN  N  T MISS

2.讀入檔案之內容字串

3.根據predictor的內容預測T或N並和讀到的字元做比較

4.根據讀入的字元修改predictor

5.持續預測直到input字元讀完
6.顯示執行結果並將miss次數寫入output file](https://)