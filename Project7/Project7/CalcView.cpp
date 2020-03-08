#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Calc.h"
#endif

#include "CalcDoc.h"
#include "CalcView.h"
#include "Options.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalcView

IMPLEMENT_DYNCREATE(CCalcView, CView)

BEGIN_MESSAGE_MAP(CCalcView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_ENGINEERCALCULATOR_AREAOFRECTANGLE, &CCalcView::OnEngineercalculatorAreaofrectangle)
END_MESSAGE_MAP()

// CCalcView construction/destruction

CCalcView::CCalcView()
{
	// TODO: add construction code here

}

CCalcView::~CCalcView()
{
}

BOOL CCalcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}
#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Calc.h"
#endif

#include "CalcDoc.h"
#include "CalcView.h"
#include "Options.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalcView

IMPLEMENT_DYNCREATE(CCalcView, CView)

BEGIN_MESSAGE_MAP(CCalcView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_ENGINEERCALCULATOR_AREAOFRECTANGLE, &CCalcView::OnEngineercalculatorAreaofrectangle)
END_MESSAGE_MAP()

// CCalcView construction/destruction

CCalcView::CCalcView()
{
	// TODO: add construction code here

}

CCalcView::~CCalcView()
{
}

BOOL CCalcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}
// CCalcView drawing
CString j("Area: %d", area);

void CCalcView::OnDraw(CDC* pDC)
{
	CCalcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect clientRect;
	GetClientRect(clientRect);


	double n = 20;
	float p = 9;
	CClientDC aDC(this);
	CString ma("");




	pDC->TextOutW(y, x, j);


	COLORREF qRectangleColor = RGB(255, 0, 0);
	CPen qRectanglePen(PS_SOLID, 7, qRectangleColor);
	CPen* pqOrigPen = pDC->SelectObject(&qRectanglePen);
	pDC->Rectangle(100, 100, 100 + length, 100 + width);





}

void CCalcView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}


void CCalcView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCalcView diagnostics

#ifdef _DEBUG
void CCalcView::AssertValid() const
{
	CView::AssertValid();
}

void CCalcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCalcDoc* CCalcView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCalcDoc)));
	return (CCalcDoc*)m_pDocument;
}
#endif //_DEBUG


// CCalcView message handlers


void CCalcView::OnEngineercalculatorAreaofrectangle()
{
	// TODO: Add your command handler code here
	Options calcDialog;
	if (calcDialog.DoModal() == IDOK){
		width = calcDialog.width;
		length = calcDialog.length;
		area = width*length;
		CString ga("%d", area);
		calcDialog.result.Append(ga);
		a = area;
		x = 10;
		y = 10;



	}

	Invalidate();
	UpdateWindow();
}
