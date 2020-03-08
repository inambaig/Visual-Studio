#pragma once


class CCalcView : public CView
{
protected: // create from serialization only
	CCalcView();
	DECLARE_DYNCREATE(CCalcView)

	// Attributes
public:
	CCalcDoc* GetDocument() const;
	double w, l, a;
	int x, y;


	// Operations
public:

	// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

	// Implementation
public:
	virtual ~CCalcView();
private:
	double width;
	double length;
	double area;

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEngineercalculatorAreaofrectangle();
};

#ifndef _DEBUG  // debug version in CalcView.cpp
inline CCalcDoc* CCalcView::GetDocument() const
{
	return reinterpret_cast<CCalcDoc*>(m_pDocument);
}
#endif
