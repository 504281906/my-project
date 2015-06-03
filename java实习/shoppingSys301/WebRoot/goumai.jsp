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
  
    <form action="/shoppingSys/goumai?hh=<%=request.getParameter("goodsgid")%>" method="post">
    	<br/><br/><br/><br/><br/>
    	<table border="1" align="center">
    		<tr>
    			<td>商品编号为:</td>
    			<td><%=request.getParameter("goodsgid")%></td>
    		</tr>
    		<tr>
    			<td>请输入购买数量:</td>
    			<td><input type="text" name="numm"> </td>
    		</tr>
    		<tr>
    			<td colspan="2">
    				<input type="image" src="/shoppingSys/images/btn2.gif">
    			</td>
    		</tr>
    	</table>
    </form>
  </body>
</html>
