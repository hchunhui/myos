#ifndef _OBJECT_H_FILE_INCLUDED_

#define _OBJECT_H_FILE_INCLUDED_

class CGame;

class CObject
{
public:
	int Type;//该对象是何种角色或物体。取值为：
				//1		主角人物。
				//2		无生命物体。如砖块、水管等。
				//3		妖怪。
				//4		子弹。
				//5		金币、蘑菇等可被吃的物体。
	int LiveState;//活动状态。取值为：
				//1		正常
				//2		正在死亡
				//3		已死亡
	int XPos,YPos;//该对象左上角在地图上的位置。
	int Width,Height;//对象的宽度和高度。
	int Layer;//该对象的图像在显示时的层次。取值为：
				//0		背景层。
				//-1	背景层之后。
				//1		背景层之前。
	virtual const int * GetImage(bool * HInv,bool * VInv)=0;
	/*
		取得该对象当前的图像数据。
		参数：
			[o]HInv		是否左右翻转。
			[o]VInv		是否上下翻转。
		返回值：
			返回图像数据指针。该指针指向一个二维数组，数组的大小与物体的大小一致。每个元素表示一个像素。
	*/
	virtual void Clock();
	/*
		执行一次时序信号动作。
	*/
	virtual bool Block(CObject * Other);
	/*
		在移动过程中遇到阻挡。
		参数：
			[i]Other	阻挡自己的对象。如果为NULL，则表示受到地图边界阻挡。
		返回值：
			true		接受阻挡，停止移动。
			false		不理会阻挡，继续移动。
	*/
	virtual void Bump(CObject * Other,int Mode,bool Volun);
	/*
		与其他对象发生碰撞。
		参数：
			[i]Other	与之碰撞的另一个对象。
			[i]Mode		碰撞方式。取值为：
						1		碰到对方顶部。
						2		碰到对方底部。
						3		碰到对方侧面。
			[i]Volun	取值为：true:自己主动碰对方；false:自己被对方碰到。
	*/
	virtual void Attack(CObject * Other,int Mode);
	/*
		遭到其他对象的攻击。
		参数：
			[i]Other	发起攻击的对象。
			[i]Mode		攻击方式。取值为：
						1		接触式攻击。如妖怪与主角接触即可杀死主角；主角使用了无敌隐身后与妖怪接触可杀死妖怪；子弹与妖怪接触可杀死妖怪等。
						2		踩踏式攻击。仅限于主角踩踏妖怪。
						3		头顶式攻击。如主角顶到砖块、砖块顶到妖怪等。
	*/
	virtual ~CObject() {};
	CObject(CGame * Game,int Tp,int X,int Y,int W,int H,int Ly);
protected:
	CGame * m_Game;
	int m_HorzSpeed;//当前水平运动速度（向右为正）
	int m_VertSpeed;//当前竖直运动速度（向下为正）
};

#endif
