#include "world.h"
#include "icon.h"

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    this->_player.initObj("player");
    this->_player.setPosX(5);
    this->_player.setPosY(5);

    //monster
    this->_monster.initObj("monster");
    this->_monster.setPosX(5);
    this->_monster.setPosY(8);

    //monster1
    this->_monster1.initObj("monster1");
    this->_monster1.setPosX(7);
    this->_monster1.setPosY(7);

    //stone 4 5
    RPGObj obj1, obj2, obj3,obj4,obj5,obj6;
    obj1.initObj("stone");
    obj1.setPosX(4);
    obj1.setPosY(3);

    obj2.initObj("stone");
    obj2.setPosX(6);
    obj2.setPosY(5);

    obj3.initObj("fruit");
    obj3.setPosX(6);
    obj3.setPosY(8);

    obj4.initObj("grass1");
    obj4.setPosX(4);
    obj4.setPosY(5);

    obj5.initObj("stone1");
    obj5.setPosX(10);
    obj5.setPosY(10);

    obj6.initObj("fruit1");
    obj6.setPosX(12);
    obj6.setPosY(6);

    this->_objs.push_back(obj1);
    this->_objs.push_back(obj2);
    this->_objs.push_back(obj3);
    this->_objs.push_back(obj4);
    this->_objs.push_back(obj5);
    this->_objs.push_back(obj6);
}


void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;//die dai fang wen qi
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        if((*it).flag==true)
        (*it).show(painter);//yi ci die dai fang wen
    }
    if(_player.flag==true){
        this->_player.show(painter);
    }
//    if(_player.flag==false){
//        _player.flag=true;
//    }
    this->_monster.show(painter);
    this->_monster1.show(painter);
}

void World::handlePlayerMove(int direction, int steps){
    this->_player.move(direction, steps);
    if((_player.getPosX()==4 && _player.getPosY()+1==3) ||(_player.getPosX()==6 && _player.getPosY()+1==5) || (_player.getPosX()==10 && _player.getPosY()+1==10))
    {
        if(direction==1){
            direction=2;
            this->_player.move(direction, steps);
        }
        else if(direction==2)
        {
            direction=1;
            this->_player.move(direction, steps);
        }
        else if(direction==3)
        {
            direction=4;
            this->_player.move(direction, steps);
        }
        else if(direction==4)
        {
            direction=3;
            this->_player.move(direction, steps);
        }
    }
    if(_player.getPosX()==6 && _player.getPosY()+1==8){
         _objs[2].flag=false;
    }
    if(_player.getPosX()==4 && _player.getPosY()+1==5){
         _objs[3].flag=false;
    }
    if(_player.getPosX()==12 && _player.getPosY()+1==6){
         _objs[5].flag=false;
    }
    if(_player.getPosX()==_monster.getPosX() && _player.getPosY()==_monster.getPosY() )
    {
        this->_player.flag=false;
    }
    if(_player.getPosX()==_monster1.getPosX() && _player.getPosY()==_monster1.getPosY() )
    {
        this->_player.flag=false;
    }
}

void World::randommove(int direction, int steps)
{
    this->_monster.move(direction,steps);
    if((_monster.getPosX()==4 && _monster.getPosY()==3) ||(_monster.getPosX()==6 && _monster.getPosY()==5) ||(_monster.getPosX()==6 && _monster.getPosY()==8) || (_monster.getPosX()==4 && _monster.getPosY()==5) ||(_monster.getPosX()==12 && _monster.getPosY()==6)){
        if(direction==1){
            direction=2;
            this->_monster.move(direction, steps);
        }
        else if(direction==2)
        {
            direction=1;
            this->_monster.move(direction, steps);
        }
        else if(direction==3)
        {
            direction=4;
            this->_monster.move(direction, steps);
        }
        else if(direction==4)
        {
            direction=3;
            this->_monster.move(direction, steps);
        }
      }
}

void World::randommove1(int direction, int steps)
{
    this->_monster1.move(direction,steps);
    if((_monster1.getPosX()==4 && _monster1.getPosY()==3) ||(_monster1.getPosX()==6 && _monster1.getPosY()==5) ||(_monster1.getPosX()==6 && _monster1.getPosY()==8) || (_monster1.getPosX()==4 && _monster1.getPosY()==5) ||(_monster1.getPosX()==12 && _monster1.getPosY()==6) ){
        if(direction==1){
            direction=2;
            this->_monster1.move(direction, steps);
        }
        else if(direction==2)
        {
            direction=1;
            this->_monster1.move(direction, steps);
        }
        else if(direction==3)
        {
            direction=4;
            this->_monster1.move(direction, steps);
        }
        else if(direction==4)
        {
            direction=3;
            this->_monster1.move(direction, steps);
        }
      }
}
