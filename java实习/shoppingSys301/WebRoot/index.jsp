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
	<style type="text/css">
		.btnCls{width: 290px;border: 1px solid gray;height: 30px}
	</style>
	
	<script type="text/javascript">
	
		function userReg(){
			 document.getElementById("myForm").action="/shoppingSys/register.jsp";
			 document.getElementById("myForm").submit();
		}
	
	</script>
  </head>
  
  <body>
  
  	<%@include file="/navigationbar.jsp" %>
  <!--  form action 表示提交表单时，浏览器访问服务器上的哪个资源  
  
  http://www.sina.com 直接访问新浪网
  
  
  http://localhost:8080/shoppingSys/index.jsp
  http://localhost:8080/shoppingSys/userServlet
  在访问资源前未加/ 表示相对的跳转
  
  在访问资源前加上 / 表示相对于web服务器的根做跳转
 http://localhost:8080/userServlet
 
  -->
  <br/>
  <br/>
  <br/>
  <br/>
  <br/>
  <br/>
    <form id="myForm" action="/shoppingSys/userServlet" method="post"  >
    	<table  align="center" >
    		<tr>
    			
    			<td><input class="btnCls" type="text" name="userName" placeholder="请输入用户名"> </td><!-- 提交表单时，在服务端通过name取出input元素的值 -->
    		</tr>
    		<tr>
    			
    			<td><input class="btnCls"   type="password" name="pwd" placeholder="请输入密码"> </td><!-- 提交表单时，在服务端通过name取出input元素的值 -->
    		</tr>
    		<tr>
   				
   				<td><input type="image" src="/shoppingSys/images/login.png">&nbsp;
   				<a href="javaScript:userReg()"><img src="/shoppingSys/images/regeist.png"/></a></td>
   					
    		</tr>
    		<tr>
    			
    			<td><%=request.getAttribute("info")==null?"":request.getAttribute("info") %></td><!-- 提交表单时，在服务端通过name取出input元素的值 -->
    		</tr>
    	</table>
    </form>
  </body>
</html>
