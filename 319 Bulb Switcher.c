/*
初始时有 n 个灯泡关闭。 第 1 轮，你打开所有的灯泡。 第 2 轮，每两个灯泡你关闭一次。 第 3 轮，每三个灯泡切换一次开关（如果关闭则开启，如果开启则关闭）。第 i 轮，每 i 个灯泡切换一次开关。 对于第 n 轮，你只切换最后一个灯泡的开关。 找出 n 轮后有多少个亮着的灯泡。
思路：计算每个灯泡开关的次数，为奇数则亮，这个次数和第i个数是否能够被多少个数整除有关，比如4（1，2，4）则他会一直亮着，另外所有的非开方数都是成对存在整除数，因此都是关闭（比如6：1，2，3，6  7：1，7）只有能开方的数存在有奇数个数的整除数（4:1，2，4  16:1，2，4，8，16），因为会有两个因子相同，再观察规律1（1），2（1），3（1），4（2），5（2），6（2）7（2），8（2），9（3）...可知只需计算sqrt（n）
*/

int bulbSwitch(int n){
	return (int)sqrt(n);
}
