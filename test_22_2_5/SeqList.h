#pragma once
#define N 100
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>
#include<string.h>

////��̬˳���(���Ƽ�)
//struct SeqList
//{
//	int a[N];
//	int size;
//};

typedef int SeqDataType;//����typedef����������������

typedef struct SeqList
{
	SeqDataType* a;//ָ��̬���ٵ�����
	int size;//��Ч���ݸ���
	int capacity;//����
}SeqList,SEQ;


//��ʼ��
void SeqListInit(SeqList* pseq);
//����
void SeqListDestory(SeqList* pseq);
//��ӡ
void SeqListPrint(SeqList* pseq);

//β��
void SeqListPushBack(SeqList* pseq, SeqDataType x);
//ͷ��
void SeqListPushFront(SeqList* pseq, SeqDataType x);
//βɾ
void SeqListPopBack(SeqList* pseq);
//ͷɾ
void SeqListPopFront(SeqList* pseq);
//����
int SeqListFind(SeqList* pseq,SeqDataType x);
//�м����
void SeqListInsert(SeqList* pseq, int pos, SeqDataType x);
//�м����
void SeqListErase(SeqList* pseq, int pos);
//�޸�
void SeqListModify(SeqList* pseq, int pos, SeqDataType x);