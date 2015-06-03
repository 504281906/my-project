<%@page import="com.vo.Goods3"%>
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
    </style>
  </head>
  <body>
     <%@include file="/navigationbar.jsp" %>
     	<ul>
     	 <td id="go">购物车列表:</td>
		<%
			ArrayList<Goods3>goodsList=(ArrayList<Goods3>)request.getAttribute("glist");
			//doubl k=(double) request.getAttribute("money");
			int k=0;
			for (Goods3 g : goodsList) {
		%>
			<li>
					<table border="0">
					<tr><td colspan="2">
						<img src="/shoppingSys/<%=g.getImage()%>" width="100" height="108"></td>
					</tr>
					<tr ><td colspan="2"><b><%=g.getGname()%></b></td></tr>
					<tr>
						<td>市场价格：<%=g.getSalprice()%></td>
						<td>购买数量：<%=g.getNumb()%></td>
					</tr>
					</table>
			</li>
		<%
			k+=g.getNumb()*g.getSalprice();
			}//for循环结束
		%>
		<table>
		<tr>
			<td>总价为：<% out.print(k);%></td>
		</tr>
		</table>
		<a href="end.jsp">
			<td colspan="0">
    				<input type="image" src="/shoppingSys/images/btn3.gif">
    		</td>
    	</a>
     	</ul>
	</body>
</html>