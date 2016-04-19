#-*- coding:utf-8 -*-
import xlrd
import os 

def main():
    data = xlrd.open_workbook("test.xls")
    table = data.sheet_by_name(u't1')
    """
        a=u"你好啊！modiz"
        print a
        print table.row_values(1)
    """
    rows = table.nrows
    cols = table.ncols
    print rows,cols
    Ta = [[0 for col in range(cols)] for row in range(rows)]
    collegeName = []
    for i in range(rows):
        for j in range(cols):
            Ta[i][j] = table.cell(i,j)
    sId = table.col_values(0)
    L1 = []
    for i in Ta:
        k = i[0].value
        if not k in L1:
            L1.append(k)
            collegeName.append(i[7].value)

    print u"挂科人数:",len(L1)-1
    courseName = table.col_values(3)
    courseNameL = set(courseName)
    name = ""
    k = 0
    for i in courseNameL:
        #print u"课程:",i,u"挂科的人数是:",courseName.count(i),u"人"
        if (k < courseName.count(i)):
            name = i
            k = courseName.count(i)
    print u"挂科人数最多的课程是",name,u"啊！",u"挂了足足有",k,u"人！"
    
    collegeNameL = set(collegeName)
    name=""
    k = 0
    for i in collegeNameL:
        if (k < collegeName.count(i)):
            name = i;
            k = collegeName.count(i)
    print u"恭喜荣获挂科人数最多的学院是:",name,u"挂了有",k,u"人!"

if __name__=="__main__":
    main()
    os.system("pause")