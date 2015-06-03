<%@page import="com.vo.Goods2"%>
<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<% 
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'wellcome.jsp' starting page</title>
    
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
     <%@include file="/navigationbar.jsp" %>
  
  
     <h1>商品列表</h1>
     
     <%
        ArrayList<Goods2> goodsList= (ArrayList<Goods2>)request.getAttribute("glist");
        for(Goods2 g:goodsList){
      %>
      	<%=g.getGname()%><br/>
      	<img src="/shoppingSys/<%=g.getImage()%>"><br/>
      	&nbsp&nbsp&nbsp&nbsp价格：<%=g.getPrice()%>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
      	 市场价格：<%=g.getSalprice()%>
      	<hr/>
      <%
      	}//for循环结束
       %>
	</table>
  </body>
</html>
