
// lab2_1Doc.h : Clab2_1Doc ��Ľӿ�
//


#pragma once


class Clab2_1Doc : public CDocument
{
protected: // �������л�����
	Clab2_1Doc();
	DECLARE_DYNCREATE(Clab2_1Doc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~Clab2_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	void SetStr(CString &string);//���������string
	int Get(CString &string);//�������str�������mystr
	CString str;//���ĵ�д���ַ�������&�����ĵ��������ݵ��ַ�������
};
