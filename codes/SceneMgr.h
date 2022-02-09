#pragma once

typedef enum {
	eScene_Menu,    //���j���[���
	eScene_Game,    //�Q�[�����
	eScene_Config,  //�ݒ���
	eScene_End,  //�G���f�B���O
	eScene_None,    //����
} eScene;

//������
void SceneMgr_Initialize();

//�I������
void SceneMgr_Finalize();

//�X�V
void SceneMgr_Update();

//�`��
void SceneMgr_Draw();

// ���� nextScene �ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene nextScene);
