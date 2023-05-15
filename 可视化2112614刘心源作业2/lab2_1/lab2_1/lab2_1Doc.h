
// lab2_1Doc.h : Clab2_1Doc 类的接口
//


#pragma once


class Clab2_1Doc : public CDocument
{
protected: // 仅从序列化创建
	Clab2_1Doc();
	DECLARE_DYNCREATE(Clab2_1Doc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~Clab2_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	void SetStr(CString &string);//设置类变量string
	int Get(CString &string);//将类变量str传入参数mystr
	CString str;//向文档写入字符串变量&保存文档读出内容的字符串变量
};
