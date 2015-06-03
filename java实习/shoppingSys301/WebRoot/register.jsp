<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'index.jsp' starting page</title>
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->
  </head>
  
  <body>
  
   <%@ include file="/navigationbar.jsp" %>
  
    <form action="/shoppingSys/RegisterServlet" method="post">
    	<br/><br/><br/><br/><br/>
    	<table border="1" align="center">
    		<tr>
    			<td>用户名:</td>
    			<td><input type="text" name="userName" placeholder="请输入用户名"> </td><!-- 提交表单时，在服务端通过name取出input元素的值 -->
    		</tr>
    		<tr>
    			<td>密码:</td>
    			<td><input type="password" name="pwd"> </td><!-- 提交表单时，在服务端通过name取出input元素的值 -->
    		</tr>
    		<tr>
    			<td>确认密码:</td> 
    			<td><input type="password" name="confirmPwd"> </td><!-- 提交表单时，在服务端通过name取出input元素的值 -->
    		</tr>
    		<tr>
    			<td colspan="2">
    				<input type="image" src="/shoppingSys/images/btn.png">
    			</td>
    		</tr>
    	</table>
    </form>
  </body>
</html>
