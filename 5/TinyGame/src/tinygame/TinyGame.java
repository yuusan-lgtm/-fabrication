/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tinygame;

import java.util.Scanner;

public class TinyGame {

    public static void main(String[] args) {
        //マップのサイズを定義
        int mapSizeX = 14, mapSizeY = 9;
        
        //自キャラの現在位置を保持する変数を定義。X,Yともに(開始時の座標-1)で初期化。
        //マップの配列が0始まりのため。
        int myCharX = 1, myCharY = 1;
        
        //マップを2次元配列で定義
        char[][] map= {{'#','#','#','#','#','#','#','#','#' ,'#','#','#','#','#'},
                                {'#', ' ', ' ' , ' ', ' ','#', ' ' , ' ', ' ' , ' ', ' ' , ' ', ' ' ,'#'},
                                {'#', ' ', ' ' , ' ', ' ','#', ' ' , ' ', ' ' , ' ', ' ' , ' ', ' ' ,'#'},
                                {'#', ' ', ' ' , ' ', ' ','#', ' ' , ' ', '#', ' ', ' ' ,'#', ' ' ,'#'},
                                {'#', ' ', ' ' , ' ', ' ','#', ' ' , ' ', '#', ' ', ' ' ,'#', ' ' ,'#'},
                                {'#', ' ', ' ' , ' ', ' ', ' ', ' ' , ' ', '#', ' ', ' ' ,'#', ' ' ,'#'},
                                {'#', ' ', ' ' , ' ', ' ', ' ', ' ' , ' ', '#', ' ', ' ' , ' ', ' ' ,'#'},
                                {'#', ' ', ' ' , ' ', ' ', ' ', ' ' , ' ', '#', ' ', ' ' , ' ', ' ' ,'#'},
                                {'#','#','#','#','#','#','#','#','#','#','#' ,'#','#','#'},};
        
        //ゲーム実行中はずっとループ
        while(true){//mainLoop
            //現在のマップ状況（自キャラの位置を含む）を出力する関数
            printMap(map, mapSizeX, mapSizeY, myCharX, myCharY);
        
            //自キャラの移動方向の入力を促すメッセージを表示
            System.out.print("移動方向を入力(上:w, 左:a, 右:d, 下:s)>");
            
            //移動方向を正しく入力するまでループ
            while(true){//inputMoveLoop
                //標準入力（コンソール）を1行読み取り、moveに代入
                String move = new Scanner(System.in).nextLine();
                
                //入力がw, a, s, d以外なら再入力を促す。
                if(!move.equals("w") && !move.equals("a") && !move.equals("s") && !move.equals("d")){
                    System.out.println("移動方向が読み取れません。再度入力してください。");
                    System.out.print("移動方向を入力(上:w, 左:a, 右:d, 下:s)>");
                }
                else{//正しい入力の場合は自キャラの位置を更新
                    //moveがwなら、自キャラを上に1マス動かす。
                    if(move.equals("w")){
                        //マップは左上が(0,0)なので、上に1マス動かすにはY座標を1減らす
                        myCharY = myCharY - 1;
                    }
                    //moveがaなら、自キャラを左に1マス動かす。
                    else if(move.equals("a")){
                        //マップは左上が(0,0)なので、左に1マス動かすにはX座標を1減らす
                        myCharX = myCharX - 1;
                    }
                    else if(move.equals("s")){
                        myCharY = myCharY + 1;
                    }
                    else if(move.equals("d")){
                        myCharX = myCharX + 1;
                    }
                    //移動方向入力のためのループを抜ける
                    //ループ内でのbreakは、ループを1段階抜ける命令
                    break;
                }//else
            }//inputMoveLoop
            
            //衝突判定をする。isCollisionは衝突判定のためのメソッド。
            if(isCollision(map, myCharX, myCharY)){
                //ぶつかったらメッセージを表示
                System.out.println("ぶつかったぞ!!  ゲームオーバー!!");
                //breakでメインループを抜ける。
                break;
            }
        }//mainLoop
    }
    
    private static void printMap(char[][] map, int mapSizeX, int mapSizeY, int myCharX, int myCharY){
        //Y軸のループ
        for (int i = 0 ; i < mapSizeY ; i++){
            //X軸のループ
            for (int j = 0 ; j < mapSizeX ; j++){
                //その座標に自キャラがいる場合、マップではなく自キャラを描画
                if(myCharX == j && myCharY == i){
                    //自キャラは'@'にしてみた
                    System.out.print("@");
                }
                else{//その座標に自キャラがいなければ、マップを描画
                    //その座標のマップの内容を描画s
                    System.out.print(map[i][j]);
                }
            }//for (int j = 0 ; j < mapSizeX ; j++)
            System.out.println();
        }//for (int i = 0 ; i < mapSizeY ; i++)
    }//private static void printMap(char[][] map, int mapSizeX, int mapSizeY, int myCharX, int myCharY){

    private static boolean isCollision(char[][] map, int myCharX, int myCharY){
        //自キャラの位置が空白なら衝突なし：false
        if (map[myCharY][myCharX]== ' '){
            return false;
        }
        else{////自キャラの位置が空白でなかったら衝突あり：true
            return true;
        }
    }//private static boolean isCollision(char[][] map, int myCharX, int myCharY)
    
}//public class TinyGame
