#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<string.h>

typedef int SeqDataType;//����typedef����������������
typedef struct SeqList
{
	SeqDataType* a;//ָ��̬���ٵ�����
	size_t size;//��Ч���ݸ���
	size_t capacity;//����
}SeqList;

//��ʼ��
void SeqListInit(SeqList* pseq);
//����
void SeqListDestory(SeqList* pseq);
//��ӡ
void SeqListPrint(SeqList* pseq);
//����
void SeqCheckCapacity(SeqList* pseq);
//β��
void SeqListPushBack(SeqList* pseq, SeqDataType x);
//ͷ��
void SeqListPushFront(SeqList* pseq, SeqDataType x);
//βɾ
void SeqListPopBack(SeqList* pseq);
//ͷɾ
void SeqListPopFront(SeqList* pseq);
//����
int SeqListFind(SeqList* pseq, SeqDataType x);
//�м����
void SeqListInsert(SeqList* pseq, size_t pos, SeqDataType x);
//�м����
void SeqListErase(SeqList* pseq, size_t pos);
//�޸�
void SeqListModify(SeqList* pseq, size_t pos, SeqDataType x);