import java.util.*;
import java.io.*;

class Solution {
    private static HashMap<Integer, Integer> inCar; // 입실 시간
    private static HashMap<Integer, Integer> timeCar; // 누적 값
    private static int[] answer;
    
    public int[] solution(int[] fees, String[] records) {
        inCar = new HashMap<>();
        timeCar =  new HashMap<>();
        
        carInfo(records); // 차량 계산
        etcInfo(); // 출차 안 한 차 계산
        answer = new int[timeCar.size()];
        calPrice(fees); // 요금 계산
        
        return answer;
    }
    
    private static void carInfo(String[] records) {
        for(int i=0; i<records.length; i++) {
            String[] strArr = records[i].split(" ");
            // 시간
            int hour = Integer.parseInt(strArr[0].substring(0,2));
            int minute = Integer.parseInt(strArr[0].substring(3,5));
            int time = hour * 60 + minute;
            
            // 차량 번호
            int carNum = Integer.parseInt(strArr[1]);
            
            if(strArr[2].equals("IN")) { // 입차
                inCar.put(carNum, time);
            } else { // 출차
                int inTime = inCar.get(carNum);
                timeCar.put(carNum, timeCar.getOrDefault(carNum, 0) + (time - inTime));
            }
        }
    }
    
    private static void etcInfo() {
        for(Map.Entry<Integer, Integer> m : inCar.entrySet()) {
            int carNum = m.getKey();
            int inTime = m.getValue();
            timeCar.put(carNum, timeCar.getOrDefault(carNum, 0) + (1439 - inTime));
        }
    }
    
    private static void calPrice(int[] fees){
        List<int[]> list = new ArrayList<>();
        
        int baseTime = fees[0];
        int basePrice = fees[1];
        int oneMinute = fees[2];
        int onePrice = fees[3];
        
        for(Map.Entry<Integer, Integer> m : timeCar.entrySet()) {
            int carNum = m.getKey();
            int time = m.getValue();
            
            if(time <= baseTime) { // 기본 요금
                list.add(new int[] {carNum, basePrice});
            } else { // 초과
                int price = basePrice;
                time -= baseTime;
                // 올림
                int t = time / oneMinute + (time % oneMinute == 0 ? 0 : 1);
                price += t * onePrice;
                list.add(new int[] {carNum, price});
            }
        }
        // 차량 번호로 오름차순
        Collections.sort(list, (o1, o2) -> Integer.compare(o1[0], o2[0]));
        for(int i=0; i<list.size(); i++) {
            answer[i] = list.get(i)[1];
        }
    }
}