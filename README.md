# **manipulator_moveit**

![IMG_2710_AdobeExpress (3).gif](IMG_2710_AdobeExpress (3).gif)

매니퓰레이터 로봇을 위한 간단한 MoveIt 패키지입니다. 패키지에는 로봇의 URDF 모델과 MoveIt용 구성 파일이 포함되어 있습니다.

## ****Installation****

1. 필요한 종속 항목을 설치합니다.
    
    ```bash
    sudo apt install ros-melodic-moveit
    ```
    
2. 이 리포지토리를 catkin 작업 공간에 복제합니다.
    
    ```bash
    cd ~/catkin_ws/src
    git clone https://github.com/ggh-png/manipulator_moveit.git
    ```
    
3. 패키지를 빌드합니다.
    
    ```bash
    cd ~/catkin_ws
    catkin_make
    ```
    

## ****Usage****

데모를 실행하려면 다음 명령을 실행하십시오.

```bash
roslaunch moveit_arduino demo.launch 
```

이렇게 하면 로봇의 동작을 계획하고 실행할 수 있는 MoveIt 및 Rviz가 시작됩니다.

## **URDF 모델**

로봇의 URDF 모델은 디렉토리에 있습니다 **`urdf`**. 여기에는 로봇의 시각 및 충돌 모델이 포함됩니다.

## **구성 파일**

MoveIt의 구성 파일은 디렉토리에 있습니다 **`config`**. 여기에는 로봇의 계획 그룹, 관절 제한 및 엔드 이펙터 정보가 포함됩니다.
