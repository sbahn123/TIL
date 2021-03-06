# Django 웹 프레임워크

## 일반적인 특징

장고는 현재 가장 많이 사용되는 파이썬 웹 프레임워크다. 2003년 로렌스 저널-월드 신문을 만들던 웹 개발팀의 내부 프로젝트로 시작했으며, 2005년 오픈소스 프로젝트로 공개되었다. 구글 앱 엔진에서 장고를 사용하면서 대표적인 웹 프레임워크로 자리매김하고 있다.

### MVC 패턴 기반 MTV

MVC 패턴을 기반으로 한 프레임워크이다. 장고는 View, Template, Controller라고 부른다. 장고에서 View는 데이터를 가져오고 변형하는 컴포넌트인 반명 Template가 데이터를 사용자에게 보여주는 컴포넌트이다.

> View가 Controller고 Template가 View인 느낌..

### 객체 관계 매핑

장고의 객체 관계 맥핑(ORM, Object-Relational Mapping)은 데이터베이스 시스템과 모델을 연결시키는 다리과 같은 역할을 한다. 이미 구축한 데이터베이스 시스템을 다른 데이터베이스로 변경하는 경우에도 설정을 쉽게 변경할 수 있으며 편리하다.

> rails의 db 마이그레이션이랑 비슷한거냐고 했다가 CC8님한테 개털렸다.

### 자동으로 구성되는 관리자 화면

장고는 웹 서버의 콘텐츠, 데이터베이스에 대한 관리 기능을 제공하는 관리자 화면을 제공한다. 개발자가 별도로 관리 기능을 개발할 필요가 없다.

### 우아한 URL 설계 (!)

웹 프로그래밍을 할 때 URL 디자인은 필수인데, 장고에서는 유연하면서도 강력한 기능을 제공한다. 파이썬 프레임워크의 우아한 URL 방식을 채택하여 다른 프레임워크에서도 그대로 사용할 수 있다.

### 자체 템플릿 시스템

내부적으로 확장 가능하고 디자인이 쉬운 강력한 템플릿 시스템을 갖고 있다. HTML과 같은 텍스트형 언어를 쉽게 다룰 수 있게 개발되었다.

### 캐시 시스템

동적 페이지는 서버에 많은 부하를 줄 수 있다. 그래서 캐시 시스템을 사용하여 자주 이용되는 내용을 저장하고 이를 재사용 함으로써 성능을 높여준다. 장고는 캐시 시스템으로 캐시용 페이지를 메모리, 데이터베이스 내부, 파일 시스템 중 아무 곳에나 저장할 수 있다. 캐시 단위를 페이지에서부터 사이트 전체 또는 특정 뷰의 결과, 템플릿의 일부 영역만을 지정하여 저장해 둘 수 있다.

### 다국어 지원

장고는 동일한 소스코드를 다른 나라에서도 사용할 수 있도록 텍스트의 번역, 날짜/시간/숫자의 포맷, 타임존의 지정 등과 같은 다국어 환경을 제공한다. 간단한 작업만으로 메시지를 하나 이상의 언어로 번역해주기 때문에 다국어를 제공하는 웹 사이트에 아주 유용하게 사용할 수 있다.

### 풍부한 개발 환경

장고는 다양한 기능을 제공한다. 대표적으로 텍스트용 웹 서버를 포함하고 있어 개발 과정에서 아파치 등의 사용 웹 서버가 없어도 테스트를 진행할 수 있다. 또한 디버깅 모드를 사용할 경우에는 에러를 쉽게 파악하고 해결할 수 있도록 상세한 메시지를 보여준다.

### 소스 변경사항 자동 반영

장고에서는 .py 파일의 변경 여부를 감시하고 있다가 변경되면 실행 파일에 변경 내역을 바로 반영해준다. 장고 테스트용 웹 서버를 실행 중인 상태에서 소스 파일을 수정할 경우에도 웹 서버를 다시 시작할 필요 없이 자동으로 새로운 파일이 반영된다.

## 장고에서의 애플리케이션 개발 방식

웹 사이트 설계할 때 가장 먼저 하는 것은 프로그램이 해야 할 일을 적당한 크기로 나누어서 모듈화 하는 것이다. 장고는 애플리케이션 개념을 웹 서버 개발 측면에서 좀 더 구체화 하고 있다. 전체 프로그램을 프로젝트(Project), 모듈화된 단위 프로그램을 애플리케이션(Application)이라 부른다.

### MTV 패턴

* 모델(Model): 데이터베이스에 저장되는 데이터
* 템플릿(Template): 사용자에게 보여지는 부분
* 뷰(View): 실질적으로 프로그램 로직이 동작하여 처리하는 부분

#### MTV 모델에 따른 처리 과정

* 클라이언트로부터 요청을 받으면 URLconf 모듈을 이용하여 URL을 분석한다.
* URL 분석 결과를 통해 해당 URL에 대한 처리를 담당할 뷰를 결정한다.
* 뷰는 자신의 로직을 실행하면서, 만일 데이터베이스 처리가 필요하면 모델을 통해 처리하고 그 결과를 반환받는다.
* 뷰는 자신의 로직 처리가 끝나면 템플릿을 사용하여 클라이언트에 전송할 HTML 파일을 생성한다.
* 뷰는 최종 결과로 HTML 파일을 클라이언트에게 보내 응답한다.

### Model - DB 설계

사용될 데이터에 대한 정의를 담고 있는 장고의 클래스이다. ORM 기법을 이용하여 데이터베이스를 클래스로 맵핑한다. 모델 클래스는 하나의 테이블, 모댈 클래스의 속성은 테이블의 컬럼.

#### ORM 장점

* SQL을 직접 작성할 필요가 없다.
* 필요에 따라 데이터베이스를 변경하기 좋다. ORM을 통한 API는 변경할 필요가 없으므로.

### ORM 예시

우선 model.py를 만든다.

```
from django.dv import models


class Person(model.Model):
  first_name = models.CharField(max_len=30)
  ...
```

이렇개 만들면 위 person 모델은 내부적으로 SQL 명령을 사용하여 테이블을 생성한다.

```
CREATE TABLE myapp_person (
  "id serial" NOT NULL PRIMARY KEY,
  "first_name" varchar(30) NOT NULL,
);
```

#### django 모델 태이블 생성 규칙

* 테이블 애플리케이션명과 테이블 클래스명을 밑주로 연결하고, 모두 소문자. 원한다면 다른 이름으로 지정할 수 있다.
* Primart key는 Person 클래스에 정의하지 않아도 장고에서 자동 부여. 개발자가 재설정 가능.

### Template - 화면 UI 설계

#### 확장자와 주의할 점

.html 확장자를 가지며, 장고의 템플릿 시스템 문법에 맞게 작성해야 한다. 유의할 점은 적절한 디렉토리에 위치해야 한다는 것.

#### 템플릿 파일 찾는 법

* TEMPLATE DIRS 및 INSTALLED_APPS에서 지정된 디렉토리를 검색한다.
* 이 항목들은 프로젝트 설정 파일인 settings.py 파일에 정의되어 있다. 여러 개의 디렉토리를 지정할 수 있으며 지정된 순서대로 디렉토리를 검색하여 템플릿 파일을 찾는다.

#### settings.py의 예

```
INSTALLED_APPS = (
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes'
    'polls'
    ...
)

TEMPLATE_DIRS = ['/home/elkiss/work/python/templates']
```

이렇게 정의 한다면 다음과 같은 순서대로 템플릿 디렉토리를 검색한다.

```
/home/elkiss/work/python/templates
/usr/lib/python3.4/site-packages/django/contrib/admin/template
/usr/lib/python3.4/site-packages/django/contrib/auth/template
/usr/lib/python3.4/site-packages/django/contrib/contenttypes/template
/home/elkiss/work/python/polls/templates
...
```

#### 순서 주의

TEMPLATE_DIRS 항목에 정의된 디렉토리를 먼저 찾고, 그 다음에 INSTALLED_APPS 항목의 디렉토리를 찾는다는 점을 유의해야 한다.

### URLconf - URL 설계

우아한(?) URL. URL을 정의하기 위해서는 urls.py 파일에 URL과 처리 함수(뷰; view)를 매핑하는 파이썬 코드를 작성줘야 한다. 이러한 URL과 뷰의 맥핑을 URLconf라고 한다.

#### URLconf 예시

```
from django.conf.urls import patterns, url

from . import views

urlpatterns = patterns('',
  url(r'^articles/2003/$', views.special_case_2003),
  url(r'^articles/(\d{4})/$', views.year_archive),
  url(r'^articles/(\d{4})/(\d{2})/$', views.month_archive),
  url(r'^articles/(\d{4})/(\d{2}/(\d+))/$', views.artivle_detail)
)
```


> 이게 뭐다? 우아함! 엘레강스!

#### 장점

* URL과 처리 함수를 매핑하는 방법은 개발자에게 많은 유연성을 준다.
* URL 자체에 처리 로직이 들어가면 이름 변경이 어려워진다. 반면 URLconf를 사용하면 URL과 뷰 함수를 서로 자유롭게 연결할 수 있다.

#### 웹 클라가 웹 서버에 페이지 요청 시, 장고가 URL을 분석하는 순서

* setting.py 파일의 ROOT_URLCONF 항목을 읽어 URLconf(urls.py)의 위치를 알아낸다.
* URLconf 모듈을 로딩하여 urlpatterns 변수에 지정되는 URL 리스트를 검사한다.
* URL 리스트에서 내용을 검색한다.
* 매치가 된 URL의 뷰를 호출한다. 뷰는 함수 또는 클래스. 호출 시 HttpRequest 객체와 매칭할 때 추출된 단어들을 뷰에 인자로 넘겨준다.
* 리스트 끝까지 검사했는데도 매칭이 실패하면 에러 처리하는 뷰를 호출.

#### 정규표현식에 사용되는 문자들

| 표현       | 의미                                                |
| ---      | ---                                               |
| .(dot)   | 모든 문자 하나(any single character)                    |
| ^(Caret) | 문자열의 시작                                           |
| $        | 문자열의 끝                                            |
| []       | [] 괄호에 있는 문자 하나, 예를 들어 [akx]라면 a또는 k또는 z          |
| [^]      | []괄호에 있는 문자 이외의 문자 하나, 만일 [^ab]라면 a와 b를 제외한 문자 하나 |
|*|0번 이상 반복, {0,}와 동일|
|+|1번 이상 반복, {1,}와 동일|
|?|0번 또는 1번 반복, {0,1}과 동일|
|{n}|n번 반복|
|{m,n}|최소 m번에서 최대 n번까지 반복|
|[a-z]|a-z 임의의문자, 즉 영문 소문자 한개|
|\w|영문, 숫자 또는 밑줄(_) 한 개, [0-9a-zA-Z_]와 동일|
|\d|숫자 한 개, [0-9]와 동일|

### View - 로직 설계

뷰는 웹 요청을 받아 데이터베이스 접속 등 해당 애플리케이션의 로직에 맞는 처리를 하고, 그 결과 데이터를 HTML로 변환하기 위해 템플릿 처리 후 HTML로 된 응답 데이터를 웹 클라이언트로 반환한다.

#### Simple View 예시(클래스 아닌 함수로 뷰 작성한 예시)

```
from django.http import HttpResponse
import current_datetime(request):
  now = datetime.datetime.now()
  html = "<html><body>It is now %s. </body></html>" % now
  return HttpResponse(html)
```

뷰 함수는 첫 번째 인자로 HttpRequest 객체를 받는다. 필요한 처리 후 HttpResponse 리턴.
