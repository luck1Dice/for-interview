這是模仿KTV 訂位的簡化，系統詳細的演示都在assignment9.doc裡 ，可以學擇日期、時間、地點、人數並訂位，也可以取消訂位以及查看訂位 ，至於開頭的數字在NumAvailBoxes.txt中其內容意義


2024/5/12    ->  預約日期開頭
   1   4   2   3   2   2   1   0   0   0   0   1   3   0   2   1   1   3   4   2   2   4   0   4 
   
   3   1   2   3   3   4   1   0   0   0   0   1   3   3   2   4   2   2   2   4   3   1   4   3
   
   1   0   0   2   3   1   0   0   0   0   0   2   4   3   1   0   0   4   0   0   1   1   3   3
   
   4   3   4   4   1   0   1   0   0   0   0   1   1   3   4   4   1   3   2   3   3   2   4   1
   
   3   0   4   3   4   0   2   0   0   0   0   1   3   1   1   0   4   2   0   4   2   3   2   2
   
   1   0   1   1   0   2   0   0   0   0   0   4   1   2   0   0   1   4   1   0   2   1   2   2
   

  一排(橫)代表一天 24 小時 一個一小時
  每7天一個地點，如果讀進去沒有滿7天則不讀入過期訂單且自己補足7天(預設100)
