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

	<style type="text/css">
   
    	#olitem li{float:left;border:2px solid gray;list-style-type: none;margin: 2px}    		
		table{float: left;margin: 20px;}
		
		#olitem li:HOVER{border:2px solid  #FF7A4D;}
    </style>
    
  </head>
  
  <body>
     <%@include file="/navigationbar.jsp" %>		
     
     	<ul id="olitem">
     	
				
		<%
			ArrayList<Goods2> goodsList= (ArrayList<Goods2>)request.getAttribute("glist"); 
			for (Goods2 g : goodsList) {
		%>
			<li>
				<a href="/shoppingSys/goumai.jsp?goodsgid=<%=g.getGid()%>">
					<table border="0">
					<tr><td colspan="2">
						<img src="/shoppingSys/<%=g.getImage()%>" width="250" height="260"></td>
					</tr>
					<tr ><td colspan="2"><b><%=g.getGname()%></b></td></tr>
					<tr>
						<td>价格：<%=g.getPrice()%></td>
						<td>市场价格：<%=g.getSalprice()%></td>
					</tr>
					</table>
				</a>
			</li>
		<%
			}//for循环结束
		%>
     	</ul>	
	</body>
</html>
