# hui

一个简单的脚本语言


```
func test() {
	var arr = [(1 + 2) * 3, 4, 5, 3.14, .233e-2, "hui"];
	const n = len(arr);
	for (var i = 0; i < n; i += 1) {
		if (i == 0) {
			print(arr[i]);
		} else {
			print(", ", arr[i]);
		}
			
	}
}

test();
```