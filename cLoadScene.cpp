#include "stdafx.h"
#include "cLoadScene.h"


cLoadScene::cLoadScene()
{
}


cLoadScene::~cLoadScene()
{
}

void cLoadScene::Init()
{
	m_NowLoad = 0;

	//이미지 추가
	//Load("ChageBG", "./")
	//이미지는 여기서 추가시킨다. 순서대로 이름, 경로, 이미지 갯수
	Load("TitleBg", "./Image/1.Title/BackGround/TitleBG.bmp");
	Load("InGameBG", "./Image/2.InGame/BackGround/InGameBG.bmp");
	Load("MainGameBg", "./Image/3.MainGame/BackGround/MainGameBG.bmp");
	Load("ShopBg", "./Image/4.Shop/ShopBg.bmp");

	Load("Game_Logo", "./Image/1.Title/Ui/game_logo.bmp");

	//button      title   
	Load("Start_Nomal", "./Image/1.Title/Ui/Start_Nomal.bmp");
	Load("Start_OnCursor", "./Image/1.Title/Ui/Start_OnCursor.bmp");
	Load("Start_Click", "./Image/1.Title/Ui/Start_Click.bmp");

	Load("Exit_Nomal", "./Image/1.Title/Ui/Exit_Nomal.bmp");
	Load("Exit_OnCursor", "./Image/1.Title/Ui/Exit_OnCursor.bmp");
	Load("Exit_Click", "./Image/1.Title/Ui/Exit_Click.bmp");

	Load("Option_Nomal", "./Image/1.Title/UI/Option_button(0).bmp");
	Load("Option_OnCursor", "./Image/1.Title/UI/Option_button(1).bmp");
	Load("Option_Click", "./Image/1.Title/UI/Option_button(2).bmp");

	Load("HowToPlay_Nomal", "./Image/1.Title/UI/how_to_play(0).bmp");
	Load("HowToPlay_OnCursor", "./Image/1.Title/UI/how_to_play(1).bmp");
	Load("HowToPlay_Click", "./Image/1.Title/UI/how_to_play(2).bmp");


	//ingame
	Load("Notice_Nomal", "./Image/2.InGame/UI/notice_icon.bmp");
	Load("Notice_OnCursor", "./Image/2.InGame/UI/notice_icon2.bmp");
	Load("Notice_Click", "./Image/2.InGame/UI/notice_icon3.bmp");

	Load("Info_Nomal", "./Image/2.InGame/UI/Store_Information_button(0).bmp");
	Load("Info_OnCursor", "./Image/2.InGame/UI/Store_Information_button(1).bmp");
	Load("Info_Click", "./Image/2.InGame/UI/Store_Information_button(2).bmp");

	Load("OrderList_Nomal", "./Image/2.InGame/Orders/OrderList.bmp");
	Load("OrderList_OnCursor", "./Image/2.InGame/Orders/OrderList.bmp");
	Load("OrderList_Click", "./Image/2.InGame/Orders/OrderList.bmp");

	//making window button
	Load("Making_Nomal", "./Image/2.InGame/UI/Making_button(0).bmp");
	Load("Making_OnCursor", "./Image/2.InGame/UI/Making_button(1).bmp");
	Load("Making_Click", "./Image/2.InGame/UI/Making_button(2).bmp");

	Load("order_Contents", "./Image/2.InGame/Ui/order_Contents.bmp");//주문들어가는 창 밑바닥

	Load("option_BGM_On_Nomal",		"./Image/UI/Option/BGM_on.bmp");
	Load("option_BGM_On_OnCursor",	"./Image/UI/Option/BGM_on2.bmp");
	Load("option_BGM_On_Click",		"./Image/UI/Option/BGM_on3.bmp");

	Load("option_BGM_Off_Nomal",	"./Image/UI/Option/BGM_off.bmp");
	Load("option_BGM_Off_OnCursor", "./Image/UI/Option/BGM_off2.bmp");
	Load("option_BGM_Off_Click",	"./Image/UI/Option/BGM_off3.bmp");

	Load("option_effect_On_Nomal",		"./Image/UI/Option/sound_off.bmp");
	Load("option_effect_On_OnCursor",	"./Image/UI/Option/sound_off2.bmp");
	Load("option_effect_On_Click",		"./Image/UI/Option/sound_off3.bmp");

	Load("option_effect_Off_Nomal",		"./Image/UI/Option/sound_on.bmp");
	Load("option_effect_Off_OnCursor",	"./Image/UI/Option/sound_on2.bmp");
	Load("option_effect_Off_Click",		"./Image/UI/Option/sound_on3.bmp");

	Load("Option_wnd_Nomal", "./Image/UI/Option/option_window.bmp");
	Load("Option_wnd_OnCursor", "./Image/UI/Option/option_window.bmp");
	Load("Option_wnd_Click", "./Image/UI/Option/option_window.bmp");



	//closet
	//closet dress button
	Load("Closet_Top_Nomal", "./Image/3.MainGame/UI/Closet/jacket_button(0).bmp");
	Load("Closet_Top_OnCursor", "./Image/3.MainGame/UI/Closet/jacket_button(1).bmp");
	Load("Closet_Top_Click", "./Image/3.MainGame/UI/Closet/jacket_button(2).bmp");

	Load("Closet_Bottom_Nomal", "./Image/3.MainGame/UI/Closet/skirt_button(0).bmp");
	Load("Closet_Bottom_OnCursor", "./Image/3.MainGame/UI/Closet/skirt_button(1).bmp");
	Load("Closet_Bottom_Click", "./Image/3.MainGame/UI/Closet/skirt_button(2).bmp");

	Load("Closet_Accessory_Nomal",		"./Image/3.MainGame/UI/Closet/accessory_button(0).bmp");
	Load("Closet_Accessory_OnCursor",	"./Image/3.MainGame/UI/Closet/accessory_button(1).bmp");
	Load("Closet_Accessory_Click",		"./Image/3.MainGame/UI/Closet/accessory_button(2).bmp");

	Load("Closet_Shoes_Nomal", "./Image/3.MainGame/UI/Closet/shoes_button(0).bmp");
	Load("Closet_Shoes_OnCursor", "./Image/3.MainGame/UI/Closet/shoes_button(1).bmp");
	Load("Closet_Shoes_Click", "./Image/3.MainGame/UI/Closet/shoes_button(2).bmp");

	Load("Clear_Nomal", "./Image/3.MainGame/UI/clear_button.bmp");
	Load("Clear_OnCursor", "./Image/3.MainGame/UI/clear_button.bmp");
	Load("Clear_Click", "./Image/3.MainGame/UI/clear_button.bmp");
	//Dress Preview button
	Load("Top_1_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_jacket_0(0).bmp");
	Load("Top_1_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_jacket_0(1).bmp");
	Load("Top_1_Click",		"./Image/3.MainGame/UI/Icon/cloth_jacket_0(2).bmp");
	Load("Top_2_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_icon_jacket_1(0).bmp");
	Load("Top_2_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_icon_jacket_1(1).bmp");
	Load("Top_2_Click",		"./Image/3.MainGame/UI/Icon/cloth_icon_jacket_1(2).bmp");
	Load("Top_3_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_icon_jacket_3(0).bmp");
	Load("Top_3_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_icon_jacket_3(1).bmp");
	Load("Top_3_Click",		"./Image/3.MainGame/UI/Icon/cloth_icon_jacket_3(2).bmp");
	Load("Top_4_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_icon_jacket_4(0).bmp");
	Load("Top_4_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_icon_jacket_4(1).bmp");
	Load("Top_4_Click",		"./Image/3.MainGame/UI/Icon/cloth_icon_jacket_4(2).bmp");


	Load("Bottom_1_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_icon_skirt_01(0).bmp");
	Load("Bottom_1_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_icon_skirt_01(1).bmp");
	Load("Bottom_1_Click",		"./Image/3.MainGame/UI/Icon/cloth_icon_skirt_01(2).bmp");
	Load("Bottom_2_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_icon_skirt_02(0).bmp");
	Load("Bottom_2_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_icon_skirt_02(1).bmp");
	Load("Bottom_2_Click",		"./Image/3.MainGame/UI/Icon/cloth_icon_skirt_02(2).bmp");
	Load("Bottom_3_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_icon_skirt_03(0).bmp");
	Load("Bottom_3_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_icon_skirt_03(1).bmp");
	Load("Bottom_3_Click",		"./Image/3.MainGame/UI/Icon/cloth_icon_skirt_03(2).bmp");
	Load("Bottom_4_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_icon_skirt_04(0).bmp");
	Load("Bottom_4_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_icon_skirt_04(1).bmp");
	Load("Bottom_4_Click",		"./Image/3.MainGame/UI/Icon/cloth_icon_skirt_04(2).bmp");
	
	
	Load("Accessory_1_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_accessory_01(0).bmp");
	Load("Accessory_1_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_accessory_01(1).bmp");
	Load("Accessory_1_Click",		"./Image/3.MainGame/UI/Icon/cloth_accessory_01(2).bmp");
	Load("Accessory_2_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_accessory_02(0).bmp");
	Load("Accessory_2_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_accessory_02(1).bmp");
	Load("Accessory_2_Click",		"./Image/3.MainGame/UI/Icon/cloth_accessory_02(2).bmp");
	Load("Accessory_3_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_accessory_03(0).bmp");
	Load("Accessory_3_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_accessory_03(1).bmp");
	Load("Accessory_3_Click",		"./Image/3.MainGame/UI/Icon/cloth_accessory_03(2).bmp");
	Load("Accessory_4_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_accessory_04(0).bmp");
	Load("Accessory_4_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_accessory_04(0).bmp");
	Load("Accessory_4_Click",		"./Image/3.MainGame/UI/Icon/cloth_accessory_04(0).bmp");
	
	Load("Shoes_1_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_icon_shoes_01(0).bmp");
	Load("Shoes_1_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_icon_shoes_01(1).bmp");
	Load("Shoes_1_Click",		"./Image/3.MainGame/UI/Icon/cloth_icon_shoes_01(2).bmp");
	Load("Shoes_2_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_icon_shose_02(0).bmp");
	Load("Shoes_2_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_icon_shose_02(1).bmp");
	Load("Shoes_2_Click",		"./Image/3.MainGame/UI/Icon/cloth_icon_shose_02(2).bmp");
	Load("Shoes_3_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_icon_shose_03(0).bmp");
	Load("Shoes_3_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_icon_shose_03(1).bmp");
	Load("Shoes_3_Click",		"./Image/3.MainGame/UI/Icon/cloth_icon_shose_03(2).bmp");
	Load("Shoes_4_Nomal",		"./Image/3.MainGame/UI/Icon/cloth_icon_shose_04(0).bmp");
	Load("Shoes_4_OnCursor",	"./Image/3.MainGame/UI/Icon/cloth_icon_shose_04(1).bmp");
	Load("Shoes_4_Click",		"./Image/3.MainGame/UI/Icon/cloth_icon_shose_04(2).bmp");


	Load("GameExit_No_Nomal", "./Image/UI/Game_Exit_No_Nomal.bmp");
	Load("GameExit_No_OnCursor", "./Image/UI/Game_Exit_No_OnCursor.bmp");
	Load("GameExit_No_Click", "./Image/UI/Game_Exit_No_Click.bmp");

	Load("GameExit_Yes_Nomal", "./Image/UI/Game_Exit_Yes_Nomal.bmp");
	Load("GameExit_Yes_OnCursor", "./Image/UI/Game_Exit_Yes_OnCursor.bmp");
	Load("GameExit_Yes_Click", "./Image/UI/Game_Exit_Yes_Click.bmp");


	Load("Mannequin", "./Image/3.MainGame/UI/Mannequin.bmp");

	Load("Top_1", "./Image/3.MainGame/Dress/Top/jacket_01.bmp");
	Load("Top_2", "./Image/3.MainGame/Dress/Top/jacket_02.bmp");
	Load("Top_3", "./Image/3.MainGame/Dress/Top/jacket_03.bmp");
	Load("Top_4", "./Image/3.MainGame/Dress/Top/jacket_04.bmp");
	Load("Top_5", "./Image/3.MainGame/Dress/Top/jacket_05.bmp");
	Load("Top_6", "./Image/3.MainGame/Dress/Top/jacket_06.bmp");
	Load("Top_7", "./Image/3.MainGame/Dress/Top/jacket_07.bmp");

	Load("Bottom_1", "./Image/3.MainGame/Dress/Bottom/skirt.bmp");
	Load("Bottom_2", "./Image/3.MainGame/Dress/Bottom/skirt_02.bmp");
	Load("Bottom_3", "./Image/3.MainGame/Dress/Bottom/skirt_03.bmp");
	Load("Bottom_4", "./Image/3.MainGame/Dress/Bottom/skirt_04.bmp");
	Load("Bottom_5", "./Image/3.MainGame/Dress/Bottom/skirt_05.bmp");
	Load("Bottom_6", "./Image/3.MainGame/Dress/Bottom/skirt_06.bmp");
	//Load("Bottom_4""./Image/3.MainGame3/Dress/Top, "./Image/DImage/4.MainGame3/pants_04.bmp");

	Load("Shoes_1", "./Image/3.MainGame/Dress/Shoes/shose_01.bmp");
	Load("Shoes_2", "./Image/3.MainGame/Dress/Shoes/shose_02.bmp");
	Load("Shoes_3", "./Image/3.MainGame/Dress/Shoes/shose_03.bmp");
	Load("Shoes_4", "./Image/3.MainGame/Dress/Shoes/shose_04.bmp"); 

	Load("Accessory_1", "./Image/3.MainGame/Dress/Accessory/accessory_01.bmp");
	Load("Accessory_2", "./Image/3.MainGame/Dress/Accessory/accessory_02.bmp");
	Load("Accessory_3", "./Image/3.MainGame/Dress/Accessory/accessory_03.bmp");
	Load("Accessory_4", "./Image/3.MainGame/Dress/Accessory/accessory_04.bmp");
	Load("Accessory_5", "./Image/3.MainGame/Dress/Accessory/accessory_05.bmp");

	Load("Next_Nomal", "./Image/3.MainGame/UI/Closet/next.bmp");
	Load("Next_OnCursor", "./Image/3.MainGame/UI/Closet/next.bmp");
	Load("Next_Click", "./Image/3.MainGame/UI/Closet/next.bmp");
	Load("Before_Nomal", "./Image/3.MainGame/UI/Closet/before.bmp");
	Load("Before_OnCursor", "./Image/3.MainGame/UI/Closet/before.bmp");
	Load("Before_Click", "./Image/3.MainGame/UI/Closet/before.bmp");

	//마우서 커서 
	Load("MouseCursor_nomal", "./Image/Ui/MouseCursor/MouseCur.bmp");
	Load("MouseCursor_onclick", "./Image/Ui/MouseCursor/MouseCur(1).bmp");
	Load("MouseCursor_upclick", "./Image/Ui/MouseCursor/MouseCur(2).bmp");

	////댓글들 로딩
	//Load("1", "./Image/5.Comment/Comment1.bmp");
	//Load("2", "./Image/5.Comment/Comment2.bmp");
	//Load("3", "./Image/5.Comment/Comment3.bmp");


	//메인 화면 바뀌는 마네킹들
	Load("M_1", "./Image/2.InGame/BackGround/mannequinSet1.bmp");
	Load("M_2", "./Image/2.InGame/BackGround/mannequinSet2.bmp");
	Load("M_3", "./Image/2.InGame/BackGround/mannequinSet3.bmp");
	//Load("M_4", "./Image/2.InGame/BackGround/mannequinSet4.bmp");

	//사기버튼
	Load("Buy_Nomal", "./Image/4.Shop/Buy.bmp");
	Load("Buy_OnCursor", "./Image/4.Shop/Buy.bmp");
	Load("Buy_Click", "./Image/4.Shop/Buy.bmp");

	//메인 화면에서 상점으로
	Load("GoShop_Nomal", "./Image/2.InGame/UI/GoShop.bmp");
	Load("GoShop_OnCursor", "./Image/2.InGame/UI/GoShop(1).bmp");
	Load("GoShop_Click", "./Image/2.InGame/UI/GoShop(2).bmp");

	Load("Order_1", "./Image/2.InGame/Orders/Order1.bmp");
	Load("Order_2", "./Image/2.InGame/Orders/Order2.bmp");
	Load("Order_3", "./Image/2.InGame/Orders/Order3.bmp");
	Load("Order_4", "./Image/2.InGame/Orders/Order4.bmp");

	Load("Select", "./Image/3.MainGame/UI/Closet/select.bmp");


	Load("Comment1_Good", "./Image/5.Comment/comment_good1.bmp");
	Load("Comment2_Good", "./Image/5.Comment/comment_good2.bmp");
	Load("Comment3_Good", "./Image/5.Comment/comment_good3.bmp");
	Load("Comment4_Good", "./Image/5.Comment/comment_good4.bmp");

	Load("Comment1_Bad", "./Image/5.Comment/comment_bad1.bmp");
	Load("Comment2_Bad", "./Image/5.Comment/comment_bad2.bmp");
	Load("Comment3_Bad", "./Image/5.Comment/comment_bad3.bmp");
	Load("Comment4_Bad", "./Image/5.Comment/comment_bad4.bmp");









	Load("Top_Product_1_Nomal", "./Image/4.Shop/Product/Top_Product_1.bmp");
	Load("Top_Product_1_OnCursor", "./Image/4.Shop/Product/Top_Product_1.bmp");
	Load("Top_Product_1_Click", "./Image/4.Shop/Product/Top_Product_1.bmp");

	Load("ResultBg", "./Image/6.Result/BackGround/ResultBg.bmp");
	Load("Good_ResultBg", "./Image/6.Result/BackGround/Good_ResultBg.bmp");
	Load("Bad_ResultBg", "./Image/6.Result/BackGround/Bad_ResultBg.bmp");
	Load("MyMoney", "./Image/2.InGame/Ui/have_money.bmp");
	Load("CommentWnd", "./Image/2.InGame/Ui/Comment/Comment_window.bmp");

	//메인화면 마네킹 넘기기 버튼

	Load("PageDown", "./Image/2.InGame/BackGround/page_bottonDown.bmp");
	//Load("PageDown_OnCursor", "./Image/2.InGame/BackGround/page_bottonDown(1).bmp");
	//Load("PageDown_Click", "./Image/2.InGame/BackGround/page_bottonDown(2).bmp");

	Load("PageUp_Nomal",	"./Image/2.InGame/BackGround/page_bottonUp.bmp");
	Load("PageUp_OnCursor", "./Image/2.InGame/BackGround/page_bottonUP(1).bmp");
	Load("PageUp_Click",	"./Image/2.InGame/BackGround/page_bottonUp(2).bmp");

	Load("HelpWnd_Nomal",	"./Image/Ui/HelpWnd.bmp");
	Load("HelpWnd_OnCursor", "./Image/Ui/HelpWnd.bmp");
	Load("HelpWnd_Click",	"./Image/Ui/HelpWnd.bmp");

	m_MaxLoad = m_Load.size();
}

void cLoadScene::Update()
{
	if (m_NowLoad != m_MaxLoad) {
		IMAGE->AddImage(
			m_Load[m_NowLoad].key,
			m_Load[m_NowLoad].path,
			m_Load[m_NowLoad].count
		);

		m_NowLoad++;
	}
	else {
		//이미지 추가가 다 되었으면 Scene을 변경한다.
		SCENE->ChangeScene("Title");
	}
}

void cLoadScene::Render()
{
	Point Pos;
	Pos.x = 0;
	Pos.y = 0;

	//IMAGE->Render(IMAGE->FindImage("Loading"), Pos, false);
}

void cLoadScene::Release()
{

}