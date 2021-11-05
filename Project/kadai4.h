#pragma once
#include "component.h"
#include "input_observer.h"
#include "position.h"
#include "Shape.h"
#include "ShapeStrategy.h"
#include "vector"

//横のブロックの数
#define		BLOCKX			10
//ブロックのオフセットX位置
#define		BLOCKOFFSETX	300
//ブロックのオフセットY位置
#define		BLOCKOFFSETY	100
//ブロックの幅
#define		BLOCKWIDTH		40
//ブロックの高さ
#define		BLOCKHEIGHT		20
//ブロックの間隔
#define		BLOCKMARGIN		2

//TODO GameObjectnにPosition持たせてもいいかも
class kadai4 : public Component {

    InputObserver* input_ = nullptr;
    class chain
    {
        GameObject* line_;
        GameObject* circle_;
    public:
        Position* circle_posititon;
        Position* line_posititon;
        
        Shape& build(GameObject*& obj, CRectangle rectangle, MofU32 color)
        {
            obj->AddComponent<Position>();
            return obj->AddComponent<Shape>()->SetShape(rectangle, color);
        }

        void SetLine(Vector2 pos)
        {
            line_->GetComponent<Shape>()->SetShape({ {0,0},{pos - line_posititon->GetPosition()} });
        }

        chain(GameObject* obj)
        {
            line_ = obj->Instantiate();
            build(line_, { 0,0,0,0 }, MOF_XRGB(0, 255, 0)).SetShapePattern(new ShapeLine());
            line_posititon = line_->GetComponent<Position>();
            line_posititon->SetPosition({ -20,-20 });

            circle_ = obj->Instantiate();
            build(circle_, { -10,-10,10,10 }, MOF_XRGB(0, 255, 0)).SetShapePattern(new ShapeCircle());
            circle_posititon = circle_->GetComponent<Position>();
            circle_posititon->SetPosition({ -20,-20 });
        }
    };
    const int CHAIN_COUNT = 2;
    std::vector<chain*> chain_objects_;
    GameObject* cursor_obj_ = nullptr;

    std::vector<GameObject*> block_objects_;

    CRectangle rect_{ 0,0, BLOCKWIDTH, BLOCKHEIGHT };
    const CRectangle circle_ = CRectangle(-10, -10, 10, 10 );
    Vector2 mouse_pos_{ 0,0 };

    int clickCount = 0;
    float		expTime = 0;

    Shape& build(GameObject*& obj,CRectangle rectangle, MofU32 color)
    {
        obj->AddComponent<Position>();
        return obj->AddComponent<Shape>()->SetShape(rectangle, color);
    }
public:
    kadai4()
    {
        
    }
    void Start() override
    {

        for (int i = 0; i < BLOCKX; ++i)
        {
            GameObject* block_obj_ = parent_->Instantiate();
            build(block_obj_, rect_, MOF_XRGB(255, 0, 0)).SetShapePattern(new ShapeFillRect());
            block_objects_.emplace_back(block_obj_);
            block_obj_->GetComponent<Position>()->Move({ static_cast<float>((BLOCKOFFSETX + (BLOCKWIDTH + BLOCKMARGIN) * i)) ,BLOCKOFFSETY});
        }

        for (int i = 0; i < CHAIN_COUNT; ++i)
        {
            chain_objects_.emplace_back(new chain(parent_->Instantiate()));
        }
        cursor_obj_ = parent_->Instantiate();
        build(cursor_obj_, { -10,-10,10,10 }, MOF_XRGB(0, 255, 0)).SetShapePattern(new ShapeFillCircle());

    }
    void Update() override
    {

        cursor_obj_->GetComponent<Position>()->SetPosition(mouse_pos_);
        if (clickCount > 0)
        {
            chain_objects_[(clickCount - 1)% CHAIN_COUNT]->SetLine(mouse_pos_);
        }
        expTime += CUtilities::GetFrameSecond();
    }
    void Render() override
    {
        CGraphicsUtilities::RenderString(10, 10, "提出        :1F09SP　林愛守");
        CGraphicsUtilities::RenderString(10, 40, "マウス座標  :%d,%d",(int)mouse_pos_.x, (int)mouse_pos_.y);
        CGraphicsUtilities::RenderString(10, 70, "クリック回数:%03d",clickCount);
        CGraphicsUtilities::RenderString(10, 100,"経過時間    :%6.2f", expTime);
    }

    kadai4& set_input_(InputObserver* input)
    {
        input_ = input;
        input_->mouse_observer->Subscribe([&](auto dir)
            {
                mouse_pos_ = dir;
            });
        input_->mouse_push_observer->Subscribe([&](auto dir)
            {
                chain_objects_[clickCount % CHAIN_COUNT]->circle_posititon->SetPosition(dir);
                chain_objects_[clickCount % CHAIN_COUNT]->line_posititon->SetPosition(dir);
                clickCount++;
                
            });
        return *this;
    }
};
