function solution(nums) {
    let half = nums.length / 2;
    const poketSet = new Set(nums);
    if(half > poketSet.size) {
        return poketSet.size;
    }
    return half;
}