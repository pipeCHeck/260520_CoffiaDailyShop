Transform

struct Vector2f {
	float x,
	float y
}
public:
	# 그냥 값반환
	GetPosition
	GetRotation
	GetScale
	
	# 이동 회전 크기 수정
	SetPosition
	ModifyPosition
	SetRotation	
	ModifyRotation
	SetScale	
	ModifyScale

private:
	Vector2f pos;
	float rot;
	Vector2f sca;




오브젝트
Transform transform	// 위치회전크기 값
Transform aniTransform	// 애니메이션에 의해 수정될 위치회전크기값(실제로는 트랜스폼+애니트랜스폼 값으로 렌더)
					// 애니메이션에 의해 값을 직접적으로 바꾸면 애니메이션 적용마다 위치가 꼬임
vector<비트맵>	// 오브젝트가 가지고 있는 비트맵
Animation 		// 지금 적용 중인 애니메이션


# 비트맵 관여
원하는 비트맵을 검색(string 키값) => 해당 비트맵 반환

# 이미지 간의 z포지션 변경
특정 비트맵을 맨 앞으로(string 키값)
특정 비트맵을 맨 뒤로(string 키값)
특정 비트맵을 다른 비트맵 앞으로(string 키값, string 목표키값)
특정 비트맵을 다른 비트맵 뒤로(string 키값, string 목표키값)
특정 비트맵을 특정 인덱스로(string 키값, string 인덱스)






비트맵
Transform transform		// 위치회전크기 값
Transform aniTransform	// 애니메이션에 의해 수정될 위치회전크기값
Transform parTransform	// 부모 비트맵에 의해 수정될 위치회전크기값
string nickname	// 비트맵 검색을 위해 사용되는 키값 
Vector2f pivot	// 회전을 위한 피벗
int curIndex	// 스프라이트 시트의 경우, 현재 출력할 
bool active		// 이미지를 띄울지말지 여부(false이면 그냥 렌더 스킵)
부모 비트맵	// 부모의 위치회전크기 값에 영향을 받음

void SetNickName(string 키값) { 키값 설정 }
void 부모 비트맵(string 키값 = null) { 널이면 부모없음, 키값들어가면 부모로 지정 }
void SetPivot(flaot x, float y)	{피벗값 설정}
		(Vector2f pivot)
void SetActive(bool 여부) {active 값 설정}

Transform 실제 트랜스폼값 반환() { transform + aniTransform + parTransform }





class Animation 

// 각각 위치변경, 회전값변경, 크기변경, 
enum KeyFrameType {
	pos, rot, sca, sprite, active,
}

enum EaseType {
	Linear, EaseIn, EaseOut, EaseInOut,
}

struct KeyFrame {
	float 시작 시간
	string 비트맵 키값
	KeyFrameType 어떤 애니메이션을 줄지 타입
	float value1, value2 // 위치크기면 xy, 회전이면 1만 사용
	float duration	// sprite, active 면 의미없음
	EaseType 보간여부
}

vector<KeyFrame> Get


private:
	vector<KeyFrame> aniKey;
	bool isLoop;



길드 내 잡화 상점에서 물건을 구매하는 주인공
돈이 없어지거나 게임 오버

플레이어 스탯: 자산, 체력, 공격력, 커피아의 호감도

게임 루프
커피아의 잡화 상점 -> 물건 구매 및 준비 -> 전투 -> 결과 확인

하루 시작
커피아와 인사
보유 골드/5 + 2 골드 획득
처치해야 할 몬스터 확인(체력과 공격력이 뜸)

하루 진행
정보 출력: 나와 몬스터의 공격력과 체력을 비교하여 클리어 가능한지 여부 확인
	(다만 능력치만 해당함. 변수 능력에 의한 값은 포함되지 않음)
	(돈 슬라임이라고 치고 방패가 없으면 체력이 1 더 까인다~ 이런 내용)
커피아 클릭: 몬스터에 대한 정보를 제공(능력치 말고 팁에 대한 내용)
	그냥 랜덤 잡다한 대화 등등, 호감도에 따라 가격이 오르거나 할인되거나 선물 받거나 등등 이벤트
물건 구매: 골드를 사용하여 물건구매
	포션: 체력 회복
	무기: 공격력 증가
	방패: 이번 전투에서 사용될 임시 체력 획득
상점 나가기: 인사하고 나감. 화면 암전되고, 결과 확인
	결과 승리시, 몬스터 보상골드 획득.
	패배시, 커피아 호감도-2. 치료비로 7골드 감소(다음턴에 체력 5로 회복).

예시 상황: 
골드 10골드, 플레이어 공격력2, 체력5
슬라임(공격력 1/ 체력3) - 보상 3골드 (숨겨진 정보: 처치시 폭발 1피해)

선택지 예시1
방어구 구매: 골드 소모 후 체력 증진
(골드7, 공격력2, 체력7, 호감도+1)

선택지 예시2
바로 상점 나가기: 슬라임과전투
(슬라임 전투로 체력이 2까임 + 숨겨진 정보 내용에 따라 체력이 1 추가로 까임)
(다음날 플레이어의 스탯: 골드10, 공격력2, 체력2, 호감도변화없음)

선택지 예시3
커피아 클릭: 랜덤 대화 출력(처음 대화는 몬스터에 대한 정보)
	(이후 대화는 호감도에 따라 그냥 대화/물건할인/선물 등)
	(호감도+1 / 대화로 인한 호감도는 하루에 1로 한정)





커피아 클릭:	
물건 구매 클릭:	




처치해야하는 적 정보를 보고

커피아와 인사 2골드 획득, 처치해야 할 몬스터 확인(체력과 공격력이 뜸)





앞머리
앞머리_꼬리
앞머리_사이드

HairF
HairF_Bang
HairSide
HairSideL_0
HairSideL_1

HairB_Head
HairB_Head_SideTuftL
HairB_Head_SideTuftR
HairB










