<?php

namespace Rector\Php80\Tests\Rector\If_\NullsafeOperatorRector\Fixture;

class SomeClassMultipleIf
{
    public function f($o)
    {
        $o2 = $o->mayFail1();
        if ($o2 === null) {
            return null;
        }

        $mayFail2 = $o2->mayFail2();
        if ($mayFail2 === null) {
            return null;
        }

        return $mayFail2->mayFail3();
    }
}

?>
-----
<?php

namespace Rector\Php80\Tests\Rector\If_\NullsafeOperatorRector\Fixture;

class SomeClassMultipleIf
{
    public function f($o)
    {
        return $o?->mayFail1()?->mayFail2()?->mayFail3();
    }
}

?>