<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    
    <style type="text/css">
    	
    	#index{background-color: red}/*id选择器*/
    	
    	.myStyle{color: white;}/*类选择器，字体颜色:白色*/
    	
    	
    
    	#ol2 li{color: white;font-size:24px;font-weight: bold; text-decoration:underline; }
    	
    	h1{text-shadow: 4px 4px 2px gray}
    	
    	
    	/*border: 1px solid red 给html元素加上边框，边框1px 实线 红色
    	
    	float: left 将块级元素（前后换后处理的元素，都是块级元素），从左到右依次摆放
    	*/
    	#ol3 li{border: 1px solid red;height: 50px;width: 150px;
    		background-color: #FF7A4D;color: white;float: left;
    		list-style-type: none;text-align: center;line-height:50px}    		
    		
    	#ol3 li a{color: white;text-decoration: none;}
    	/*鼠标移动到li上时，改变背景颜色 Selector : hover { sRules } */
    	#ol3 li:hover{background-color: red;}
    </style>
    
  </head>
  
  <body>
    	<ol id="ol3">
    		<li ><a href="/shoppingSys/mainServlet">首页</a></li>
    		<li ><a href="/shoppingSys/register.jsp">用户注册</a></li>
    		<li ><a href="/shoppingSys/index.jsp">用户登陆</a></li>
    		<li><a href="#">我的订单</a></li>
    		<li><a href="/shoppingSys/carS">购物车</a></li>
    		<li><a href="#">搜索</a></li>
    	</ol>
    	
    	<div style="clear: both"></div>
    	
  </body>
</html>

