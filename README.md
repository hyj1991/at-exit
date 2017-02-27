# at-exit-hook

##Install
npm install at-exit-hook

##Instruction
This is a package which you can register some js function, that can be called before the node process exit.

##Usage
```js
const atExit = require('at-exit-hook');

//register single function
atExit(function before(){
	console.log('I will be called before process exit!');
});

//register function arrays also supported
atExit([function callback1(){
	console.log('I will be called 1');
}, function callback2(){
	console.log('I will be called 2');
}])
```

Attention：You can at most set 5 functions that can be called before process exit!


##安装
npm install at-exit-hook

##说明简介
用来注册回调函数，这些回调函数会在你的Node进程推出前被执行，相当于给Node进程设置了一个退出前的钩子。

##如何使用
```js
const atExit = require('at-exit-hook');

//注册单独的一个回调函数
atExit(function before(){
	console.log('I will be called before process exit!');
});

//注册回调函数组成的数组同样是支持的
atExit([function callback1(){
	console.log('I will be called 1');
}, function callback2(){
	console.log('I will be called 2');
}])
```
注意：你最多可以设置5个推出前执行的回调函数！